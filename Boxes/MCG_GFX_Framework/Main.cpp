#include <cmath>
#include <iostream>
#include "MCG_GFX_Lib.h"
#include <windows.h>
#include <GLM/vec3.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtx/transform.hpp>

int main( int argc, char *argv[] )
{

	glm::ivec2 windowSize( 400,400 );

	if( !MCG::Init( windowSize ) )
	{
		return -1;
	}
	glm::vec2 origin(1.0f, 1.0f);

	MCG::SetBackground( glm::ivec3(0,0,0) );


	glm::ivec2 pixelPosition(0,0);

	glm::ivec3 pixelColour( 255, 105, 180 );






	float timer = 0.0f;

	while( MCG::ProcessFrame() )
	{
		// rotating cube
		MCG::SetBackground( glm::ivec3(0,0,0 ) );

		for (float x = 250; x < 300; x++)
		{
			for (float y = 250; y < 300; y++)
			{
				for (float z = 0; z<50;z++)
				{
					glm::ivec3 pixelColour(100-x, 50+x,100-y);
					glm::ivec4 pixelPosition(x, y, z, 1.0f);
					glm::mat4 rotate = glm::rotate((1.5f) + (int)((timer) *100.0f), glm::vec3(1.0f, 1.0f, 0.0f));
					glm::vec4 newline = rotate * pixelPosition;
					MCG::DrawPixel(newline, pixelColour);
				}
			} 

		}
		//scaled & rotating cube
		for (float x = 250; x < 300; x++)
		{
			for (float y = 250; y < 300; y++)
			{
				for (float z = 0; z<50; z++)
				{
					glm::ivec3 pixelColour(100 + x, 50 + x, 100 - y);
					glm::ivec4 pixelPosition(x, y, z, 1.0f);
					glm::mat4 rotate = glm::rotate((1.5f) + (int)((timer) *200.0f), glm::vec3(1.0f, 1.0f, 0.0f));
					glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
					glm::vec4 newline = rotate * pixelPosition * scale;
					MCG::DrawPixel(newline, pixelColour);
				}
			}

		}
		timer += 1.0f / 60.0f;

	}

	return 0;
	

}
