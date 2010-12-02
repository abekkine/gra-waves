#!/usr/bin/python

import sys

try:
	f = open( 'todo.txt', 'r' )
	content = f.readlines()
	f.close()
except Exception, err:
	content = []
	pass

# trim empty lines.
if '\n' in content:
    content.remove( '\n' )

id_numbers = []
line_no = 1
for line in content:
    line_array = line.split( '|' )
    id_string = line_array[0]
    if len( line_array )>2:
        message = line_array[2]
        if '{TODO}' in message:
            msg = message.strip().split()
            msg.remove( '{TODO}' )
            if len( msg )==0:
                # Unused new item exists.
                print "Use existing new item."
                sys.exit( 1 )
    else:
        # Missing message field.
        print "Missing message field in todo list."
        print "Line( %s )" % line
        sys.exit( 1 )

    try:
        id_number = int( id_string, 10 )
        if id_number not in [n[0] for n in id_numbers]:
            id_numbers.append( (id_number, line_no) )
        else:
            # Duplicate id number:
            print "Duplicate Id Number detected."
            sys.exit( 1 )
    except Exception, err:
        # Simply ignore the line.
        pass
    line_no = line_no + 1


if len( id_numbers )>0:
	id_numbers.sort()
	new_no = id_numbers[-1:][0][0]+1 
	new_id_string = '{0:04d}'.format( new_no )
	new_line = '%s | OPEN | {TODO}\n' % new_id_string
	content.append( new_line )
else:
	content.append( '0001 | OPEN | {TODO}' )

f = open( 'todo.txt', 'w' )
f.writelines( content )
f.close()

