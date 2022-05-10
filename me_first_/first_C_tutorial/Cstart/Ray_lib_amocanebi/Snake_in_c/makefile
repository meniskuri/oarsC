SET RAYLIB_PATH=C:\raylib\raylib
SET COMPILER_PATH=C:\raylib\mingw\bin
ENV_SET PATH=$(COMPILER_PATH)
SET CC=gcc 
SET CFLAGS=$(RAYLIB_PATH)\src\raylib.rc.data -s -static -Os -std=c99 -Wall -I$(RAYLIB_PATH)\src -Iexternal -DPLATFORM_DESKTOP -g
SET LDFLAGS=-lraylib -lopengl32 -lgdi32 -lwinmm
