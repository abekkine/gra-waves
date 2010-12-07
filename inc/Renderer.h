#ifndef RENDERER_H
#define RENDERER_H

#include <GLDisplay.h>
#include <Body.h>
#include <Wave.h>

class Renderer : public GLDisplay {

	public:
        Renderer();
		void Render();
        void RegisterBodies( BodyVectorType& bodies );
        void RegisterWaves( WaveVectorType& waves );
        void BodyDisplay( bool enable );
        void WaveDisplay( bool enable );

    private:
        bool fBodiesAvailable;
        bool fBodyDisplayEnable;
        BodyVectorType bodies;
        bool fWavesAvailable;
        bool fWaveDisplayEnable;
        WaveVectorType waves;

        void RenderBodies();
        void RenderWaves();
        void RenderSingleWave( Vector center, double radius, double age );

};

#endif

