#include "LidarIndensity2RGB.h"

/**
Description: get RGB Color from Indensity
Parameters :
	@Indensity:(int) , Retrive Indensity from Pandar40 LiDAR data packet.
	@RGB, unsigned char[3] , the RGB result will be stored in this c-array
Return:
	void
**/
void HS_getColorMapFromIndensity(int Indensity , unsigned char *RGB /* 3bytes */)
{
	unsigned int Indensity_map = (Indensity >> 8) & 0xff;
	if(Indensity_map <= 100)
	{
		if(Indensity_map <= 34)
		{
			// constant blue , + green
			int Green = (Indensity_map * 255 / 34); // map to 256 range
			RGB[0] = 0x0;
			RGB[1] = Green  & 0xff;
			RGB[2] = 0xff;
		}
		else if(Indensity_map <= 67)
		{
			// constant green , -blue
			int Blue = (((67 - Indensity_map) * 255) / 33); // map to 256 range
			RGB[0] = 0x0;
			RGB[1] = 0xff;
			RGB[2] = Blue & 0xff ;
		}
		else
		{
			// constant green , + red
			int Red = (((Indensity_map - 67) * 255) / 33); // map to 256 range
			RGB[0] = Red & 0xff;
			RGB[1] = 0xff;
			RGB[2] = 0x0;

		}
	}
	else
	{
		// constant red , - green
		int Green = (((255 - Indensity_map) * 255) / (256 - 100)); // map to 256 range
		RGB[0] = 0xff;
		RGB[1] = Green  & 0xff;
		RGB[2] = 0x0;
	}
}