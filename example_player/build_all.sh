#!/bin/sh
 
scons target=release bits=32
scons target=release bits=64
scons target=debug bits=32
scons target=debug bits=64

if [ -d "../../../export/libs" ]; then
  rm -rf ../../../export/libs
fi

mv libs/ ../../../export
