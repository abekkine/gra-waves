#include <Wave.h>

// TODO : Constant [conLifetime] will be initialized.
Wave::Wave():conSpeed( WAVE_SPEED )
{
	// TODO : Call [initVars] for general initialization.
}

// TODO : Constructor will use [body] instead of [center].
// TODO : Constant [conLifetime] will be initialized.
Wave::Wave( Vector& center ):conSpeed( WAVE_SPEED )
{
	// TODO : Call [initVars] for general initialization.
	// TODO : Use [body] reference for special initialization.
}

Wave::~Wave()
{
	// TODO : cleanup any allocated objects.
}

void Wave::initVars()
{
	// TODO : initialize member variables.
}

// DONE : change to void function.
// TODO : All Update methods should accept [double timeStep] as parameter.
void Wave::Update()
{
	// TODO : increment wave age.
	// TODO : check wave age and deactive it if necessary.
	// TODO : update wave radius.
}

// TODO : implement [IsAlive] method.
