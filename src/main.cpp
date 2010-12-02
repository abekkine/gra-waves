#include <stdio.h>
#include <unistd.h>
#include <GraWaves.h>

int main( int argc, char *argv[] )
{
	GraWaves* gWaves = new GraWaves( atoi( argv[1] ) );

	gWaves->Initialize();

	gWaves->Run();

	return 0;
}


