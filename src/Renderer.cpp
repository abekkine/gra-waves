#include "Renderer.h"

void Renderer::Render()
{
	glColor3f( 1.0, 1.0, 1.0 );
	glPointSize( 2.0 );
	glBegin( GL_POINTS );
		glVertex2d( 100.0, 100.0 );
	glEnd();
}

