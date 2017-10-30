#define [LASER_COUNT (40)
static double block_offset[BLOCKS_PER_PACKET];
static double laser_offset[LASER_COUNT];

void GenerateTimeOffset()
{
    block_offset[5] = 55.1f * 0.0 + 45.18f;
    block_offset[4] = 55.1f * 1.0 + 45.18f;
    block_offset[3] = 55.1f * 2.0 + 45.18f;
    block_offset[2] = 55.1f * 3.0 + 45.18f;
    block_offset[1] = 55.1f * 4.0 + 45.18f;
    block_offset[0] = 55.1f * 5.0 + 45.18f;

    laser_offset[3] = 0.93f * 1.0f;
    laser_offset[35] = 0.93f * 2.0f;
    laser_offset[39] = 0.93f * 3.0f;
    laser_offset[23] = 0.93f * 3.0f + 1.6f * 1.0f;
    laser_offset[16] = 0.93f * 3.0f + 1.6f * 2.0f;
    laser_offset[27] = 0.93f * 4.0f + 1.6f * 2.0f;
    laser_offset[11] = 0.93f * 4.0f + 1.6f * 3.0f;
    laser_offset[31] = 0.93f * 5.0f + 1.6f * 3.0f;
    laser_offset[28] = 0.93f * 6.0f + 1.6f * 3.0f;
    laser_offset[15] = 0.93f * 6.0f + 1.6f * 4.0f;
    laser_offset[2] = 0.93f * 7.0f + 1.6f * 4.0f;
    laser_offset[34] = 0.93f * 8.0f + 1.6f * 4.0f;
    laser_offset[38] = 0.93f * 9.0f + 1.6f * 4.0f;
    laser_offset[20] = 0.93f * 9.0f + 1.6f * 5.0f;
    laser_offset[13] = 0.93f * 9.0f + 1.6f * 6.0f;
    laser_offset[24] = 0.93f * 9.0f + 1.6f * 7.0f;
    laser_offset[8] = 0.93f * 9.0f + 1.6f * 8.0f;
    laser_offset[30] = 0.93f * 10.0f + 1.6f * 8.0f;
    laser_offset[25] = 0.93f * 11.0f + 1.6f * 8.0f;
    laser_offset[12] = 0.93f * 11.0f + 1.6f * 9.0f;
    laser_offset[1] = 0.93f * 12.0f + 1.6f * 9.0f;
    laser_offset[33] = 0.93f * 13.0f + 1.6f * 9.0f;
    laser_offset[37] = 0.93f * 14.0f + 1.6f * 9.0f;
    laser_offset[17] = 0.93f * 14.0f + 1.6f * 10.0f;
    laser_offset[10] = 0.93f * 14.0f + 1.6f * 11.0f;
    laser_offset[21] = 0.93f * 14.0f + 1.6f * 12.0f;
    laser_offset[5] = 0.93f * 14.0f + 1.6f * 13.0f;
    laser_offset[29] = 0.93f * 15.0f + 1.6f * 13.0f;
    laser_offset[22] = 0.93f * 15.0f + 1.6f * 14.0f;
    laser_offset[9] = 0.93f * 15.0f + 1.6f * 15.0f;
    laser_offset[0] = 0.93f * 16.0f + 1.6f * 15.0f;
    laser_offset[32] = 0.93f * 17.0f + 1.6f * 15.0f;
    laser_offset[36] = 0.93f * 18.0f + 1.6f * 15.0f;
    laser_offset[14] = 0.93f * 18.0f + 1.6f * 16.0f;
    laser_offset[7] = 0.93f * 18.0f + 1.6f * 17.0f;
    laser_offset[18] = 0.93f * 18.0f + 1.6f * 18.0f;
    laser_offset[4] = 0.93f * 19.0f + 1.6f * 18.0f;
    laser_offset[26] = 0.93f * 20.0f + 1.6f * 18.0f;
    laser_offset[19] = 0.93f * 20.0f + 1.6f * 19.0f;
    laser_offset[6] = 0.93f * 20.0f + 1.6f * 20.0f;
}
