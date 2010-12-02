#include <GLDisplay.h>

GLDisplay::GLDisplay()
{
	InitVars();
}

GLDisplay::~GLDisplay()
{
}

void GLDisplay::InitVars()
{
	m_screen_width = -1;
	m_screen_height = -1;
}

void GLDisplay::SetScreenSize( int width, int height )
{
	m_screen_width = width;
	m_screen_height = height;
}

bool GLDisplay::Init()
{
	bool result = false;
	int rc;

	rc = SDL_Init( SDL_INIT_VIDEO );
	if( rc < 0 )
	{
		fprintf( stderr, "Unable to init SDL: %s\n", SDL_GetError() );
	}
	else
	{
		atexit( SDL_Quit );

		m_screen = SDL_SetVideoMode( m_screen_width, m_screen_height, 16, SDL_OPENGL );
		if( m_screen == NULL )
		{
			fprintf( stderr, "Unable to set %dx%d video: %s\n", m_screen_width, m_screen_height, SDL_GetError() );
		}
		else
		{
			// try to enable text rendering support.
			GL_Init();
			Reshape(m_screen->w, m_screen->h);
			result = true;
		}
	}

	return result;
}

void GLDisplay::PreRender()
{
	// Clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void GLDisplay::PostRender()
{
	// Swap buffers.
    SDL_GL_SwapBuffers();
}

void GLDisplay::Render()
{
}

void GLDisplay::Update()
{
	PreRender();
	Render();
	PostRender();
}

bool GLDisplay::CheckQuit()
{
	bool result = false;

	if( CheckKeyPress( SDLK_ESCAPE ) || CheckKeyPress( SDLK_q ) )
	{
		result = true;
	}

	return result;
}

void GLDisplay::GL_Init()
{
	glShadeModel( GL_SMOOTH );
	glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );
	glClearDepth( 1.0f );
	glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
}

void GLDisplay::Reshape(int width, int height)
{
	if( height == 0 )
	{
		height = 1;
	}

	glViewport( 0, 0, width, height );

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	glOrtho( 0.0f, width, height, 0.0f, -1.0f, 1.0f );

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

bool GLDisplay::PollEvents()
{
	bool result = false;
	
	while( SDL_PollEvent(&m_event) )
	{
		switch( m_event.type )
		{
			case SDL_VIDEORESIZE:
				m_screen = SDL_SetVideoMode(m_event.resize.w, m_event.resize.h, 16, SDL_OPENGL|SDL_RESIZABLE);
				if( m_screen )
				{
					Reshape(m_screen->w, m_screen->h);
				}
				else
				{
					puts( "Unable to set video mode on reshape." );
			    }
	        	break;

			case SDL_KEYDOWN:
				ProcessKeys( m_event );
				break;

			case SDL_QUIT:
				result = true;
				break;
		}
	}

	return result;
}

bool GLDisplay::CheckKeyPress( int key )
{
    bool result = false;
    m_keys = SDL_GetKeyState(NULL);

    if ( m_keys[key] )
    {
        result = true;
    }

    return result;

}

int GLDisplay::GetKey()
{
	int keyCode = m_keyCode;

	m_keyCode = -1;

	return keyCode;
}

void GLDisplay::ProcessKeys( SDL_Event &event )
{
	m_keyCode = (int) event.key.keysym.sym;
	switch( m_keyCode )
	{
		case 'z':
			break;

		case 'x':
			break; 

		case 'c':
			break;

		case 'p':
			break;
	}
}

