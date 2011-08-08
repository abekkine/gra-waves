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
    quitSignal = false;
    m_screen_width = -1;
    m_screen_height = -1;
    bgRed = bgGreen = bgBlue = 0.0;
    bgAlpha = 1.0;
    vpLeft = -100.0;
    vpRight = 100.0;
    vpBottom = -100.0;
    vpTop = 100.0;
    vpNear = -1.0;
    vpFar = 1.0;
    zoomFactor = 1.0;
}

void GLDisplay::Zoom( double factor )
{
    zoomFactor *= factor;
    
    if( m_screen != NULL )
    {
        Reshape( m_screen->w, m_screen->h );
    }
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

void GLDisplay::GL_Init()
{
    glShadeModel( GL_SMOOTH );
    glClearColor( bgRed, bgGreen, bgBlue, bgAlpha );
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

    glOrtho( vpLeft * zoomFactor, vpRight * zoomFactor, vpBottom * zoomFactor, vpTop * zoomFactor, vpNear, vpFar );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void GLDisplay::PollEvents()
{
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
                quitSignal = true;
                break;
        }
    }
}

void GLDisplay::UserKeys( int keycode, bool shift, bool ctrl )
{
    keycode = keycode;
    shift = shift;
    ctrl = ctrl;
}

void GLDisplay::ProcessKeys( SDL_Event &event )
{
    bool shiftState;
    bool ctrlState;
    SDLMod modifier = SDL_GetModState(); 
    m_keyCode = (int) event.key.keysym.sym;

    shiftState = ( (modifier & (KMOD_LSHIFT|KMOD_RSHIFT)) != 0);
    ctrlState  = ( (modifier & (KMOD_LCTRL|KMOD_RCTRL)) != 0);

    UserKeys( m_keyCode, shiftState, ctrlState );
}

void GLDisplay::ConvertColor( unsigned int rgb, float& r, float& g, float& b )
{
    r = ( (rgb>>16) & 0xff ) / 255.0;
    g = ( (rgb>>8) & 0xff ) / 255.0;
    b = ( rgb & 0xff ) / 255.0;
}

void GLDisplay::SetBGColor( unsigned int color )
{
    ConvertColor( color, bgRed, bgGreen, bgBlue );
}

void GLDisplay::SetBGAlpha( float alpha )
{
    bgAlpha = alpha;
}

void GLDisplay::SetViewport( double left, double right, double bottom, double top, double near, double far )
{
    vpLeft = left;
    vpRight = right;
    vpBottom = bottom;
    vpTop = top;
    vpNear = near;
    vpFar = far;

    if( m_screen != NULL )
    {
        Reshape(m_screen->w, m_screen->h);
    }
}
