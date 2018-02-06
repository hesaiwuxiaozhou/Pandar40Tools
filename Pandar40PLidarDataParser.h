#ifndef _Pandar40PLidarDataParser_H
#define _Pandar40PLidarDataParser_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Pandar40-Dual Macros
 */
// Start of Packet & Packet Angle size , SOF 2bytes , Angle 2 bytes
// Start of Packet & Packet Angle size , SOF 2bytes , Angle 2 bytes
#define HS_Pandar40P_SOP_ANGLE_SIZE (4)
// Unit size = distance(2bytes) + reflectivity(1bytes) for each Line
#define HS_Pandar40P_SERIAL_UNIT_SIZE (3)
// Unit num = Line 40
#define HS_Pandar40P_UNIT_NUM (40)
// Every udp packet has 8 blocks
#define HS_Pandar40P_BLOCK_NUM (10)
// Block size = unit num * unit size + SOP + Angle
#define HS_Pandar40P_SERIAL_BLOCK_SIZE (HS_Pandar40P_SERIAL_UNIT_SIZE * HS_Pandar40P_UNIT_NUM + HS_Pandar40P_SOP_ANGLE_SIZE)
// Block tail = timestamp ( 4 bytes ) + factory num (2 bytes)
#define HS_Pandar40P_TIMESTAMP_SIZE (4)
#define HS_Pandar40P_ECHO_SIZE (1)
#define HS_Pandar40P_FACTORY_SIZE (1)
#define HS_Pandar40P_RESERVED_SIZE (8)
#define HS_Pandar40P_ENGINE_VELOCITY (2)
#define HS_Pandar40P_TAIL_SIZE (HS_Pandar40P_TIMESTAMP_SIZE + HS_Pandar40P_ECHO_SIZE + HS_Pandar40P_FACTORY_SIZE + HS_Pandar40P_RESERVED_SIZE + HS_Pandar40P_ENGINE_VELOCITY)
// total packet size
#define HS_Pandar40P_PACKET_SIZE (HS_Pandar40P_SERIAL_BLOCK_SIZE * HS_Pandar40P_BLOCK_NUM + HS_Pandar40P_TAIL_SIZE)
//---------------------------------------------------------------------------

/**
 * Pandar40-Dual data type
 */
typedef struct HS_Pandar40P_Unit_s{
    unsigned int distance; // *4mm , real distance =  distance * 4 mm;
    unsigned short reflectivity; // reflectivity
}HS_Pandar40P_Unit;


typedef struct HS_Pandar40P_Block_s{
    unsigned short sob;
    unsigned short Azimuth; // packet angle  ,Azimuth = RealAzimuth * 100
    HS_Pandar40P_Unit units[HS_Pandar40P_UNIT_NUM];
}HS_Pandar40P_Block;

typedef struct HS_Pandar40P_Packet_s{
    HS_Pandar40P_Block blocks[HS_Pandar40P_BLOCK_NUM];
    unsigned int upcavity_temp;
    unsigned int downcavity_temp[4];
    unsigned char status_id;
    unsigned short status_data;
    unsigned char reserved;
    unsigned short error_per_second;
    unsigned short engine_velocity; // real velocity = <engine_velocity> * 6/11 round/min
    unsigned int timestamp; // ms
    unsigned int echo;
    unsigned char factory;
}HS_Pandar40P_Packet;

/**
 * HS_Pandar40P_Parse:
 * Parse a UDP packet<recvbuf> which has <len> bytes to HS_Pandar40P_Packet<packet>.
 */
int HS_Pandar40P_Parse(HS_Pandar40P_Packet *packet , const unsigned char* recvbuf , const int len);

#ifdef __cplusplus
}
#endif

#endif
