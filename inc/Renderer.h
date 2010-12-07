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

    private:
        bool fBodiesAvailable;
        BodyVectorType bodies;
        bool fWavesAvailable;
        WaveVectorType waves;

        void RenderBodies();
        void RenderWaves();
        void RenderSingleWave( Vector center, double radius, double age );

};

#endif

