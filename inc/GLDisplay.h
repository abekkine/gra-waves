#ifndef GLDISPLAY_H
#define GLDISPLAY_H

#include <SDL/SDL.h>
#include <GL/gl.h>

class GLDisplay {

	public:
		GLDisplay();
		~GLDisplay();
		
		void SetScreenSize( int width, int height );
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
	
	private:
		int m_keyCode;
		SDL_Event m_event;
	 	Uint8 *m_keys;
		SDL_Surface *m_screen;
		int m_screen_width;
		int m_screen_height;

		// Methods.
		void InitVars();
		void GL_Init();
		void ProcessKeys( SDL_Event &event );
};

#endif

