#include <stdio.h>
#include <version.h>
#include <GraWaves.h>

int main( int argc, char *argv[] )
{
	// Display version information.
	printf( "Hg.%s\n", VERSION_STRING );

	GraWaves* gWaves = new GraWaves( atoi( argv[1] ) );

	gWaves->Initialize();

	gWaves->Run();

	return 0;
}


