#include <cmath>
#include <iostream>
#include "MCG_GFX_Lib.h"
#include <windows.h>
#include <GLM/vec3.hpp>


int main( int argc, char *argv[] )
{

	glm::ivec2 windowSize( 500,500 );

	if( !MCG::Init( windowSize ) )
	{
		return -1;
	}
	glm::vec2 origin(1.0f, 1.0f);

	MCG::SetBackground( glm::ivec3(0,0,0) );


	glm::ivec2 pixelPosition(50,50);

	glm::ivec3 pixelColour( 255, 0, 0 );


	//collision, when the lines collide with the red lines, the animation restart and they go back to their original 
	//coordinates, then the animation starts again
	//***!!! It moves very slow, please be patient !!!***
	float timer = 0.0f;

	while( MCG::ProcessFrame() )
	{
		// Set every pixel to the same colour
		MCG::SetBackground( glm::ivec3( 0, 0, 0 ) );

		// Change our pixel's X coordinate according to time
		for (int y = 100; y < 400; y++)
		{
			glm::ivec3 pixelColour(255, 0, 0);
			glm::vec2 pixelPosition(100, y);
			glm::vec2 firstLine = pixelPosition;
			MCG::DrawPixel(pixelPosition, pixelColour);
			for (int y = 100; y < 400; y++)
			{
				glm::ivec3 pixelColour(255, 0, 0);
				glm::vec2 pixelPosition(400, y);
				glm::vec2 secondLine = pixelPosition;
				MCG::DrawPixel(pixelPosition, pixelColour);
				for (int x = 100; x < 175; x++)
				{
					glm::ivec3 pixelColour(0, 255, 0);
					pixelPosition.y = 300;
					pixelPosition.x = x+(int)(sin(timer)*2000.0f);
					glm::vec2 newLine = pixelPosition;

					if (newLine == secondLine)
					{
						timer = 0;
					}
					MCG::DrawPixel(newLine, pixelColour);

				}
				for (int x = 325; x < 400; x++)
				{
					glm::ivec3 pixelColour(0,0,255);
					pixelPosition.y = 200;
					pixelPosition.x =x+(int)(sin(timer)*-2000.0f);
					glm::vec2 newLine = pixelPosition;

					if (newLine == firstLine)
					{
						timer = 0;
					}
					MCG::DrawPixel(newLine, pixelColour);

				}
			}
		}
		timer += 1.0f / 60.0f;
		MCG::DrawPixel( pixelPosition, pixelColour );

	}

	return 0;
	

}
