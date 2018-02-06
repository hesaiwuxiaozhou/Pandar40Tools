#include "Pandar40PLidarDataParser.h"

/**
 * HS_Pandar40P_Parse:
 * Parse a UDP packet<recvbuf> which has <len> bytes to HS_Pandar40P_Packet<packet>.
 */
int HS_Pandar40P_Parse(HS_Pandar40P_Packet *packet , const unsigned char* recvbuf , const int len)
{
    if(len != HS_Pandar40P_PACKET_SIZE)
        return -1;

    int index = 0;
    int block = 0;
    // 4x BLOCKs
    for(block = 0 ; block < HS_Pandar40P_BLOCK_NUM ; block ++)
    {
        int unit;
        packet->blocks[block].sob = (recvbuf[index] & 0xff)| ((recvbuf[index + 1] & 0xff)<< 8);
        packet->blocks[block].Azimuth = (recvbuf[index + 2]& 0xff) | ((recvbuf[index + 3]& 0xff) << 8);
        index += HS_Pandar40P_SOP_ANGLE_SIZE;
        // 40x units
        for(unit = 0 ; unit < HS_Pandar40P_UNIT_NUM ; unit++)
        {
            packet->blocks[block].units[unit].distance = (recvbuf[index]& 0xff) | ((recvbuf[index + 1]& 0xff) << 8);
            packet->blocks[block].units[unit].reflectivity = (recvbuf[index + 2]& 0xff);
            index += HS_Pandar40P_SERIAL_UNIT_SIZE;
        }
    }
    packet->downcavity_temp[0] = (recvbuf[index + 3] & 0xff) ;
    packet->downcavity_temp[1] = (recvbuf[index + 4] & 0xff) ;


    packet->status_id = recvbuf[index + 2]& 0xff;
    packet->status_data = (recvbuf[index]& 0xff) | ((recvbuf[index + 1]& 0xff) << 8);

    packet->error_per_second = (recvbuf[index + 6] & 0xff) | (recvbuf[index + 7]& 0xff) << 8;

    index += HS_Pandar40P_RESERVED_SIZE; // skip reserved bytes

    packet->engine_velocity = (recvbuf[index]& 0xff)| (recvbuf[index + 1]& 0xff) << 8;
    index += HS_Pandar40P_ENGINE_VELOCITY;

    packet->timestamp = (recvbuf[index]& 0xff)| (recvbuf[index + 1]& 0xff) << 8 |
                        ((recvbuf[index + 2 ]& 0xff) << 16) | ((recvbuf[index + 3]& 0xff) << 24);
    index += HS_Pandar40P_TIMESTAMP_SIZE;

    packet->echo = recvbuf[index]& 0xff;
    packet->factory = recvbuf[index + 1]& 0xff;

    index += HS_Pandar40P_ECHO_SIZE;
    index += HS_Pandar40P_FACTORY_SIZE;
    return 0;
}