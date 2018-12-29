LIBRARY := MyLib
LIBRARY_FILENAME :=
SHARED_FLAG :=

ifeq ($(OS),Windows_NT)
	@echo Run win.bat
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		SHARED_FLAG += -shared
		LIBRARY_FILENAME += lib$(LIBRARY).so
else
	endif
	ifeq ($(UNAME_S),Darwin)
		SHARED_FLAG += -dynamiclib
		LIBRARY_FILENAME += lib$(LIBRARY).dylib
	endif
endif

ifeq ($(detected_OS), Darwin)
	shared_flag := -dynamiclib
	library_name := libMyLib.dylib
endif

all: vars lib main run copy

vars:
	@echo LIBRARY:$(LIBRARY)
	@echo SHARED_FLAG:$(SHARED_FLAG)
	@echo LIBRARY_FILENAME:$(LIBRARY_FILENAME)

lib: MyLib.cpp
	g++ -fPIC -Wall $(SHARED_FLAG) -o $(LIBRARY_FILENAME) MyLib.cpp

main: main.cpp
	g++ -Wall -L. -o main main.cpp -l$(LIBRARY)

run:
	LD_LIBRARY_PATH=. ./main

copy:
	cp -f $(LIBRARY_FILENAME) ../datafiles/

clean:
	rm main $(LIBRARY_FILENAME)
