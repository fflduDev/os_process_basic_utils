#!/bin/sh

#comment or change the signal number  & note the diff.  2 is SIGINT

#run automatically when the shell receives a signal or a certain event happens.
#2 maps to SIGINT which occurs on ctrl-c

#run help trap for more info

trap 'increment' 2


increment()
{
  echo "Caught SIGINT ..."
  X=`expr ${X} + 500`
  if [ "${X}" -gt "2000" ]
  then
    echo "Okay, I'll quit ..."
    exit 1
  fi
}

### main script
X=0
while :
do
  echo "X=$X"
  X=`expr ${X} + 1`
  sleep 1
done
