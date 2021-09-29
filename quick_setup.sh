#!/bin/sh


SRCPATH="source/"
EXPPATH="export/"

## create folderstructure
if [ ! -d "$EXPPATH" ]; then
  mkdir "$EXPPATH" 
  mkdir "$EXPPATH/executes"
  mkdir "$EXPPATH/libs"
  cd "$EXPPATH/executes"
  mkdir HTML Windows Linux Android
  cd ../..
fi
if [ ! -d "$SRCPATH" ]; then
  mkdir "$SRCPATH"
  mkdir "$SRCPATH/native_librarys"
fi

mv example_player/ "$SRCPATH/native_librarys"
mv vscode/ "$SRCPATH/.vscode/" 
mv source.code-workspace "$SRCPATH"



##Clone all godot-dependencys

cd "$SRCPATH"

git clone --recursive https://github.com/godotengine/godot-cpp -b 3.2
git clone --recursive https://github.com/godotengine/godot -b 3.2



##Build C++-Bindings

cd godot-cpp/

if [ ! -f bin/libgodot-cpp.linux.debug.64.a ]; then
    scons generate_bindings=yes target=debug bits=64 -j8
fi

if [ ! -f bin/libgodot-cpp.linux.debug.32.a ]; then
    scons generate_bindings=yes target=debug bits=32 -j8
fi

if [ ! -f bin/libgodot-cpp.linux.release.64.a ]; then
    scons generate_bindings=yes target=release bits=64 -j8
fi

if [ ! -f bin/libgodot-cpp.linux.release.32.a ]; then
    scons generate_bindings=yes target=release bits=32 -j8
fi


cd ../


####DEMO STUFF - delete if you dont need

##Just moving a demo-modul into engine
if [ -d ../calculator/ ]; then
  mv ../calculator/ godot/modules
fi

##Build the example Native-libs
cd native_librarys/example_player/
sh build_all.sh
cd ../..

####END DEMO STUFF


cd godot/

##Build the engine
if [ ! -f ../../godot.* ]; then
    scons -j8
    cp bin/*.* ../../
fi

echo Everything is done, Terminal can be closed
exit 0
