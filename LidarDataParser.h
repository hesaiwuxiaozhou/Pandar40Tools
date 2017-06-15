#ifndef _LIDAR_DATA_PASER_H
#define _LIDAR_DATA_PARSER_H

// Start of Packet & Packet Angle size , SOF 2bytes , Angle 2 bytes
#define HS_LIDAR_L40_SOP_ANGLE_SIZE (4)
// Unit size = distance(3bytes) + reflectivity(2bytes) for each Line
#define HS_LIDAR_L40_SERIAL_UNIT_SIZE (5)
// Unit num = Line 40 
#define HS_LIDAR_L40_UNIT_NUM (40)
// Every udp packet has 6 blocks
#define HS_LIDAR_L40_BLOCK_NUM (6)
// Block size = unit num * unit size + SOP + Angle
#define HS_LIDAR_L40_SERIAL_BLOCK_SIZE (HS_LIDAR_L40_SERIAL_UNIT_SIZE * HS_LIDAR_L40_UNIT_NUM + HS_LIDAR_L40_SOP_ANGLE_SIZE)
// Block tail = timestamp ( 4 bytes ) + factory num (2 bytes)
#define HS_LIDAR_L40_TIMESTAMP_SIZE (4)
#define HS_LIDAR_L40_FACTORY_SIZE (2)
#define HS_LIDAR_L40_RESERVED_SIZE (8)
#define HS_LIDAR_L40_ENGINE_VELOCITY (2)
#define HS_LIDAR_L40_TAIL_SIZE (HS_LIDAR_L40_TIMESTAMP_SIZE + HS_LIDAR_L40_FACTORY_SIZE + HS_LIDAR_L40_RESERVED_SIZE + HS_LIDAR_L40_ENGINE_VELOCITY)
// total packet size
#define HS_LIDAR_L40_PACKET_SIZE (HS_LIDAR_L40_SERIAL_BLOCK_SIZE * HS_LIDAR_L40_BLOCK_NUM + HS_LIDAR_L40_TAIL_SIZE)

/*
 *   Type Definition
 */
typedef struct HS_LIDAR_L40_Unit_s{
    int distance; // *2mm , real distance =  distance * 2 mm; max distance: (2^24 â€?1) * 2mm = 33554.43m
    unsigned short reflectivity; // reflectivity  
}HS_LIDAR_L40_Unit;


typedef struct HS_LIDAR_L40_Block_s{
    unsigned short sob;
    unsigned short Azimuth; // packet angle  ,Azimuth = RealAzimuth * 100
    HS_LIDAR_L40_Unit units[HS_LIDAR_L40_UNIT_NUM];
}HS_LIDAR_L40_Block;

typedef struct HS_LIDAR_L40_Packet_s{
    HS_LIDAR_L40_Block blocks[HS_LIDAR_L40_BLOCK_NUM];
    unsigned char reserved[HS_LIDAR_L40_RESERVED_SIZE];
    unsigned short engine_velocity; // real velocity = <engine_velocity> * 6/11 round/min
    unsigned int timestamp; // ms
    unsigned char factory[2];
}HS_LIDAR_L40_Packet;

/*
*   HS_L40_Parse: 
*   Parse an UDP packet<recvbuf> which has <len> bytes to HS_LIDAR_L40_Packet<packet>.
*/
int HS_L40_Parse(HS_LIDAR_L40_Packet *packet , const unsigned char* recvbuf , const int len);


//TODO:
/*
 *   Constant Definition
 */
// elevation angle of each line for HS Line 40 Lidar, Line 1 - Line 40
static float hesai_elev_angle_map[] = {
6.96,
5.976,
4.988,
3.996,
2.999,
2.001,
1.667,
1.333,
1.001,
0.667,
0.333,
0,
-0.334,
-0.667,
-1.001,
-1.334,
-1.667,
-2.001,
-2.331,
-2.667,
-3,
-3.327,
-3.663,
-3.996,
-4.321,
-4.657,
-4.986,
-5.311,
-5.647,
-5.974,
-6.957,
-7.934,
-8.908,
-9.871,
-10.826,
-11.772,
-12.705,
-13.63,
-14.543,
-15.444
};

// Line 40 Lidar azimuth Horizatal offset ,  Line 1 - Line 40
static float hesai_horizatal_azimuth_offset_map[] = {
0.005,
0.006,
0.006,
0.006,
-2.479,
-2.479,
2.491,
-4.953,
-2.479,
2.492,
-4.953,
-2.479,
2.492,
-4.953,
0.007,
2.491,
-4.953,
0.006,
4.961,
-2.479,
0.006,
4.96,
-2.478,
0.006,
4.958,
-2.478,
2.488,
4.956,
-2.477,
2.487,
2.485,
2.483,
0.004,
0.004,
0.003,
0.003,
-2.466,
-2.463,
-2.46,
-2.457
};

#endif