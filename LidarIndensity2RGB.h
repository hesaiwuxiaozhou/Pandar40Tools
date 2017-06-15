#ifndef _LIDAR_INDENSITY_RGB_H

#define _LIDAR_INDENSITY_RGB_H


/**
Description: get RGB Color from Indensity
Parameters :
	@Indensity:(int) , Retrive Indensity from Pandar40 LiDAR data packet.
	@RGB, unsigned char[3] , the RGB result will be stored in this c-array
Return:
	void
**/
void HS_getColorMapFromIndensity(int Indensity , unsigned char *RGB /* 3bytes */);

#endif