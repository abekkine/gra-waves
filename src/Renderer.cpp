#include <math.h>
#include "Renderer.h"

Renderer::Renderer()
{
    fBodiesAvailable = false;
    fWavesAvailable = false;
}

void Renderer::Render()
{
    if( fBodiesAvailable )
    {
        RenderBodies();
    }

    if( fWavesAvailable )
    {
        RenderWaves();
    }
}

void Renderer::RegisterBodies( BodyVectorType& bodies )
{
    Renderer::bodies = bodies;
    fBodiesAvailable = true;
}

void Renderer::RegisterWaves( WaveVectorType& waves )
{
    Renderer::waves = waves;
    fWavesAvailable = true;
}

void Renderer::RenderBodies()
{
    BodyVectorType::iterator iBody;
    Vector pos;

	glColor3f( 1.0, 1.0, 1.0 );
	glPointSize( 2.0 );
	glBegin( GL_POINTS );

        for( iBody=bodies.begin(); iBody!=bodies.end(); ++iBody )
        {
            pos =(*iBody)->GetPosition();
    		glVertex2d( pos.x, pos.y );
        }

	glEnd();

}

void Renderer::RenderWaves()
{
    WaveVectorType::iterator iWave;
    Vector center;
    Scalar radius;
    Scalar age;

    for( iWave=waves.begin(); iWave!=waves.end(); ++iWave )
    {
        center = (*iWave)->GetCenter();
        radius = (*iWave)->Radius();
        age = (*iWave)->Age();
        RenderSingleWave( center, radius, age );
    }
}

void Renderer::RenderSingleWave( Vector center, double radius, double age )
{
    double alpha;
    double color;

    color = (100.0 - age)/100.0;

    glColor4f( 0.0, 0.0, 1.0, color );
    //glBegin( GL_POLYGON );
    glBegin( GL_LINE_STRIP );
        for( alpha=0.0; alpha<2.0*M_PI; alpha+=0.1*M_PI )
        {
            glVertex2d( center.x + radius * cos(alpha), center.y + radius * sin(alpha) );
        }
        glVertex2d( center.x + radius, center.y );
    glEnd();
}

