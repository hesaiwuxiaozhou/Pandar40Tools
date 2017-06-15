#include "LidarDataParser.h"
/*
*   HS_L40_Parse: 
*   Parse an UDP packet<recvbuf> which has <len> bytes to HS_LIDAR_L40_Packet<packet>.
*/
int HS_L40_Parse(HS_LIDAR_L40_Packet *packet , const unsigned char* recvbuf , const int len)
{
    if(len != HS_LIDAR_L40_PACKET_SIZE)
        return -1;

    int index = 0;
    int block = 0;
    // 6x BLOCKs
    for(block = 0 ; block < HS_LIDAR_L40_BLOCK_NUM ; block ++)
    {
        int unit;
        packet->blocks[block].sob = (recvbuf[index] & 0xff)| ((recvbuf[index + 1] & 0xff)<< 8);
        packet->blocks[block].Azimuth = (recvbuf[index + 2]& 0xff) | ((recvbuf[index + 3]& 0xff) << 8);
        index += HS_LIDAR_L40_SOP_ANGLE_SIZE;
        // 40x units
        for(unit = 0 ; unit < HS_LIDAR_L40_UNIT_NUM ; unit++)
        {
            packet->blocks[block].units[unit].distance = (recvbuf[index]& 0xff) | ((recvbuf[index + 1]& 0xff) << 8) | ((recvbuf[index + 2]& 0xff) << 16 );
            packet->blocks[block].units[unit].reflectivity = (recvbuf[index + 3]& 0xff) | ((recvbuf[index + 4]& 0xff) << 8);
            index += HS_LIDAR_L40_SERIAL_UNIT_SIZE;
        }
    }

    memcpy(packet->reserved , recvbuf + index , HS_LIDAR_L40_RESERVED_SIZE);
    index += HS_LIDAR_L40_RESERVED_SIZE; // skip reserved bytes

    packet->engine_velocity = (recvbuf[index]& 0xff)| (recvbuf[index + 1]& 0xff) << 8;
    index += HS_LIDAR_L40_ENGINE_VELOCITY;
    // printf("speed %d\n", packet->engine_velocity * 6 /11);

    packet->timestamp = (recvbuf[index]& 0xff)| (recvbuf[index + 1]& 0xff) << 8 |
                        ((recvbuf[index + 2 ]& 0xff) << 16) | ((recvbuf[index + 3]& 0xff) << 24);
    // printf("timestamp %u \n", packet->timestamp);
    index += HS_LIDAR_L40_TIMESTAMP_SIZE;

    packet->factory[0] = recvbuf[index]& 0xff;
    packet->factory[1] = recvbuf[index + 1]& 0xff;
    index += HS_LIDAR_L40_FACTORY_SIZE;
    // printf("Index size should be %d  , result is : %d \n", HS_LIDAR_L40_PACKET_SIZE , index);
    return 0;
}