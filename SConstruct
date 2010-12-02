# Helper library for Simba SCons builds.
import os
import buildlib

TARGET_NAME = 'grawvs'

env = Environment()

clean_files = []
clean_files.append( '.sconsign.dblite' )
clean_files.append( 'results.xml' )
clean_files.append( 'bin/core' )
env.Clean( 'default', clean_files )

env.ParseConfig( 'sdl-config --cflags --libs' )
env.Append( CPPFLAGS = [ '-g', '-Wall' ] )
env.Append( CPPPATH = [ 'inc' ] )
env.Append( LIBS = [ 'GL' ] )

files = Glob( 'src/*.cpp' )

target_path = 'bin/%s' % TARGET_NAME
env.Program( target = target_path, source = files )

