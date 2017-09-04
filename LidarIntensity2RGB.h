#ifndef _LIDAR_INTENSITY_RGB_H

#define _LIDAR_INTENSITY_RGB_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
Description: get RGB Color from Intensity
Parameters :
	@Intensity:(int) , Retrive Intensity from Pandar40 LiDAR data packet.
	@RGB, unsigned char[3] , the RGB result will be stored in this c-array
Return:
	void
**/
void HS_getColorMapFromIntensity(int Intensity , unsigned char *RGB /* 3bytes */);

#ifdef __cplusplus
}
#endif

#endif
