#define LASER_COUNT (40)
#define BLOCKS_PER_PACKET (10)
static double block_offset[BLOCKS_PER_PACKET];
static double laser_offset[LASER_COUNT];

void GenerateTimeOffset()
{
    for (int i = 0; i < BLOCKS_PER_PACKET; i++) {
        block_offset[i] = 55.56f * (i - BLOCKS_PER_PACKET);
    }

    laser_offset[7]  = 0;
    laser_offset[20] = 1.6f * 1;
    laser_offset[27] = 1.6f * 2;
    laser_offset[5]  = 0.93f * 1 + 1.6f * 2;
    laser_offset[19] = 0.93f * 2 + 1.6f * 2;
    laser_offset[8]  = 0.93f * 2 + 1.6f * 3;
    laser_offset[15] = 0.93f * 2 + 1.6f * 4;
    laser_offset[37] = 0.93f * 2 + 1.6f * 5;
    laser_offset[33] = 0.93f * 3 + 1.6f * 5;
    laser_offset[1]  = 0.93f * 4 + 1.6f * 5;
    laser_offset[10] = 0.93f * 5 + 1.6f * 5;
    laser_offset[23] = 0.93f * 5 + 1.6f * 6;
    laser_offset[30] = 0.93f * 5 + 1.6f * 7;
    laser_offset[6]  = 0.93f * 6 + 1.6f * 7;
    laser_offset[22] = 0.93f * 6 + 1.6f * 8;
    laser_offset[11] = 0.93f * 6 + 1.6f * 9;
    laser_offset[18] = 0.93f * 6 + 1.6f * 10;
    laser_offset[38] = 0.93f * 6 + 1.6f * 11;
    laser_offset[34] = 0.93f * 7 + 1.6f * 11;
    laser_offset[2]  = 0.93f * 8 + 1.6f * 11;
    laser_offset[13] = 0.93f * 9 + 1.6f * 11;
    laser_offset[26] = 0.93f * 9 + 1.6f * 12;
    laser_offset[31] = 0.93f * 10 + 1.6f * 12;
    laser_offset[9]  = 0.93f * 11 + 1.6f * 12;
    laser_offset[25] = 0.93f * 11 + 1.6f * 13;
    laser_offset[14] = 0.93f * 11 + 1.6f * 14;
    laser_offset[21] = 0.93f * 11 + 1.6f * 15;
    laser_offset[39] = 0.93f * 11 + 1.6f * 16;
    laser_offset[35] = 0.93f * 12 + 1.6f * 16;
    laser_offset[3]  = 0.93f * 13 + 1.6f * 16;
    laser_offset[16] = 0.93f * 14 + 1.6f * 16;
    laser_offset[29] = 0.93f * 14 + 1.6f * 17;
    laser_offset[32] = 0.93f * 15 + 1.6f * 17;
    laser_offset[12] = 0.93f * 16 + 1.6f * 17;
    laser_offset[28] = 0.93f * 16 + 1.6f * 18;
    laser_offset[17] = 0.93f * 17 + 1.6f * 18;
    laser_offset[24] = 0.93f * 17 + 1.6f * 19;
    laser_offset[40] = 0.93f * 17 + 1.6f * 20;
    laser_offset[36] = 0.93f * 18 + 1.6f * 20;
    laser_offset[4]  = 0.93f * 19 + 1.6f * 20;
}


