#!/bin/bash

NUMTODO=$(grep -r "\/\/ TODO :" * | wc -l)
NUMDONE=$(grep -r "\/\/ DONE :" * | wc -l)
NUMTOTAL=$((NUMTODO+NUMDONE))
PERCENT=$((100*NUMDONE/NUMTOTAL))

echo "Completed/Total : $NUMDONE/$NUMTOTAL"
echo "Completion Percetage : %$PERCENT"

