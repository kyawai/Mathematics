
#include <cmath>

#include "MCG_GFX_Lib.h"



int main( int argc, char *argv[] )
{

	glm::ivec2 windowSize( 800, 800 );

	if( !MCG::Init( windowSize ) )
	{
		return -1;
	}
	MCG::SetBackground( glm::ivec3(0,0,0) );

	glm::ivec2 pixelPosition = windowSize / 2;
	glm::ivec3 pixelColour( 0, 0, 0 );



	//interpolated colours (square)
	for (int xcount = 0, x = 100; x < 400; x++, xcount++)  
	{
		pixelPosition.x = x;
		if (xcount == 255)
		{
			xcount--;
		}
		for (int ycount = 0,  y = 100; y < 400; y++, ycount++)
		{
			pixelPosition.y = y;
			if (ycount == 255)
			{
				ycount--;
			}

			glm::ivec3 pixelColour(255-ycount,0+ycount, 0+xcount );

			MCG::DrawPixel(pixelPosition, pixelColour);
		}

	}
	
	//trig ratio modulated curves
	//bottom curve
	for (int acount = 0, x = 50; x < 360; acount+=1, x+=1)
	{
		if (acount == 255)
		{
			acount--;
		}
		glm::ivec3 pixelColour(255, 0-acount, 50+acount);
		pixelPosition.y = (((((-1 * sin(x*3.141 / 90)) + 1)*(80 / 2))) + 600);
		pixelPosition.x = ((x / 0.5) + 0.5);

		MCG::DrawPixel(pixelPosition, pixelColour);
	}

	float timer = 0.0f;

	//simple animation
	//curve changing colour
	//second from bottom curve
	while( MCG::ProcessFrame() )
	{
		MCG::SetBackground(glm::ivec3(0, 0, 0));
		for (int xcount = 0, x = 100; x < 400; x++, xcount++)   //bottom
	{
		pixelPosition.x = x;
		if (xcount == 255)
		{
			xcount--;
		}
		for (int ycount = 0,  y = 100; y < 400; y++, ycount++)
		{
			pixelPosition.y = y;
			if (ycount == 255)
			{
				ycount--;
			}

			glm::ivec3 pixelColour(255-ycount,0+ycount, 0+xcount );

			MCG::DrawPixel(pixelPosition, pixelColour);
		}

	}
	
	//trig ratio modulated curves
	//bottom curve
	for (int acount = 0, x = 50; x < 360; acount+=1, x+=1)
	{
		if (acount == 255)
		{
			acount--;
		}
		glm::ivec3 pixelColour(255, 0-acount, 50+acount);
		pixelPosition.y = (((((-1 * sin(x*3.141 / 90)) + 1)*(80 / 2))) + 600);
		pixelPosition.x = ((x / 0.5) + 0.5);

		MCG::DrawPixel(pixelPosition, pixelColour);
	}

		for (int bcount =0, b = 100 ; b < 300; bcount++, b++)
		{
			if (bcount == 255)
			{
				bcount--;
			}
			if (bcount == 0)
			{
				bcount++;
			}
			glm::ivec3 pixelColour(255, 40-bcount, 50+bcount + ((int)(sin(timer) * 100.0f)));
			pixelPosition.y = (((((-1 * sin(b*3.141 / 60)) + 1)*(80 / 2))) + 450) ;
			pixelPosition.x = ((b / 0.5) + 0.5);

			MCG::DrawPixel(pixelPosition, pixelColour);

		}
		//simple animation
		//red to pink colours moving up
		for (int ccount = 0, c = 100; c < 500;ccount++, c++)
		{
			pixelPosition.y = c;
			pixelPosition.x = 700;
			for (int dcount = 0, d = 700; d < 725; dcount++, d++)
			{
				pixelPosition.x = d;
				glm::ivec3 pixelColour(255 - dcount, 0 + dcount, 0 + ccount + ((int)(timer) * 100.0f));
				MCG::DrawPixel(pixelPosition, pixelColour);
			}
		}
		//moving rectangles
		//simple animation
		for (int e = 500; e < 510; e++) 
		{

			for (int f = 200; f < 250; f++)
			{
				pixelPosition.x = e + (int)(sin(timer) *100.0f/4);
				pixelPosition.y = f + (int)(sin(timer) *100.0f/4);
				glm::ivec3 pixelColour(255, 0, 0 );
				MCG::DrawPixel(pixelPosition, pixelColour);
			}
		}
		for (int g = 500; g < 510; g++)
		{
			for (int h = 200; h < 250; h++ )
			{
				pixelPosition.x = g - (int)(sin(timer) *100.0f/4);
				pixelPosition.y = h - (int)(sin(timer) *100.0f/4);
				glm::ivec3 pixelColour(0, 255, 0);
				MCG::DrawPixel(pixelPosition, pixelColour);
			}
		}
		for (int g = 500; g < 510; g++)
		{
			for (int h = 200; h < 250; h++)
			{
				pixelPosition.x = g + (int)(sin(timer) *100.0f / 4);
				pixelPosition.y = h - (int)(sin(timer) *100.0f / 4);
				glm::ivec3 pixelColour(0,0,255);
				MCG::DrawPixel(pixelPosition, pixelColour);
			}
		}
		for (int g = 500; g < 510; g++)
		{
			for (int h = 200; h < 250; h++)
			{
				pixelPosition.x = g - (int)(sin(timer) *100.0f / 4);
				pixelPosition.y = h + (int)(sin(timer) *100.0f / 4);
				glm::ivec3 pixelColour(255, 255, 0);
				MCG::DrawPixel(pixelPosition, pixelColour);
			}
		}
		for (int g = 455; g < 555; g++)
		{
			for (int h = 220; h < 230; h++)
			{
				pixelPosition.x = g;
				pixelPosition.y = h + (int)(sin(timer) *100.0f/2);
				glm::ivec3 pixelColour(192,5,248);
				MCG::DrawPixel(pixelPosition, pixelColour);
			}
		}
		for (int g = 455; g < 555; g++)
		{
			for (int h = 220; h < 230; h++)
			{
				pixelPosition.x = g;
				pixelPosition.y = h - (int)(sin(timer) *100.0f/2);
				glm::ivec3 pixelColour(255,255,255);
				MCG::DrawPixel(pixelPosition, pixelColour);
			}
		}
		timer += 1.0f / 60.0f;

	}
	return 0;

}
