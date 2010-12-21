#include <math.h>
#include "Renderer.h"

Renderer::Renderer()
{
    fBodiesAvailable = false;
    fBodyDisplayEnable = true;
    fWavesAvailable = false;
    fWaveDisplayEnable = false;

    bodyRed = bodyGreen = bodyBlue = 1.0;
    waveRed = waveGreen = 0.0;
    waveBlue = 1.0;
}

void Renderer::Render()
{
    if( fWavesAvailable && fWaveDisplayEnable )
    {
        RenderWaves();
    }

    if( fBodiesAvailable && fBodyDisplayEnable )
    {
        RenderBodies();
    }
}

void Renderer::UserKeys( int keycode, bool shift, bool ctrl )
{
    // In order to avoid warning messages when modifier keys are not being used.
    ctrl = ctrl;
    shift = shift;

    switch( keycode )
    {
        case 'z':
            if( shift )
            {
                // Zoom in
                Zoom( 1.25 );
            }
            else
            {
                // Zoom out
                Zoom( 0.8 );
            }
            break;
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

    glColor3f( bodyRed, bodyGreen, bodyBlue );
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
    bool alive;

    for( iWave=waves.begin(); iWave!=waves.end(); ++iWave )
    {
        center = (*iWave)->GetCenter();
        radius = (*iWave)->Radius();
        age = (*iWave)->Age();
        alive = (*iWave)->IsAlive();
        if( alive )
        {
            RenderSingleWave( center, radius, age );
        }
    }
}

void Renderer::RenderSingleWave( Vector center, double radius, double age )
{
    double theta;
    double alpha;

    alpha = (Wave::WAVE_LIFETIME - age)/Wave::WAVE_LIFETIME;

    glColor4f( waveRed, waveGreen, waveBlue, alpha );
    //glBegin( GL_POLYGON );
    glBegin( GL_LINE_STRIP );
        for( theta=0.0; theta<2.0*M_PI; theta+=0.1*M_PI )
        {
            glVertex2d( center.x + radius * cos(theta), center.y + radius * sin(theta) );
        }
        glVertex2d( center.x + radius, center.y );
    glEnd();
}

void Renderer::BodyDisplay( bool enable )
{
    fBodyDisplayEnable = enable;
}

void Renderer::WaveDisplay( bool enable )
{
    fWaveDisplayEnable = enable;
}

void Renderer::SetBodyColor( unsigned int color )
{
    ConvertColor( color, bodyRed, bodyGreen, bodyBlue );
}

void Renderer::SetWaveColor( unsigned int color )
{
    ConvertColor( color, waveRed, waveGreen, waveBlue );
}

