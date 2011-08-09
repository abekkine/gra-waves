#ifndef GLDISPLAY_H
#define GLDISPLAY_H

#include <SDL/SDL.h>
#include <GL/gl.h>

class GLDisplay {

    public:
        GLDisplay();
        ~GLDisplay();
        
        void SetScreenSize( int width, int height );
        void SetViewport( double left, double right, double bottom, double top, double near=-1.0, double far=1.0 );
        bool Init();
        void PreRender();
        void PostRender();
        virtual void Render()=0;
        virtual void UserKeys( int keycode, bool shift, bool ctrl );
        void Update();
        void Reshape(int w, int h);
        void PollEvents();
        void SetBGColor( unsigned int color );
        void SetBGAlpha( float alpha );
        void Zoom( double factor );

    public:
        static void ExitFunction();

    public:
        bool quitSignal;

    private:
        double zoomFactor;
        int m_keyCode;
        SDL_Event m_event;
        SDL_Surface *m_screen;
        int m_screen_width;
        int m_screen_height;
        float bgRed;
        float bgGreen;
        float bgBlue;
        float bgAlpha;
        double vpLeft;
        double vpRight;
        double vpBottom;
        double vpTop;
        double vpNear;
        double vpFar;

        // Methods.
        void InitVars();
        void GL_Init();
        void ProcessKeys( SDL_Event &event );
};


#endif

