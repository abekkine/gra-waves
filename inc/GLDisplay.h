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
        void Update();
        void Reshape(int w, int h);
        bool CheckQuit();
        bool PollEvents();
        bool CheckKeyPress( int key );
        int GetKey();
        void SetBGColor( unsigned int color );
        void SetBGAlpha( float alpha );

    protected:
        void ConvertColor( unsigned int rgb, float& r, float& g, float& b );
        
    
    private:
        int m_keyCode;
        SDL_Event m_event;
         Uint8 *m_keys;
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

