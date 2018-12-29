LIBRARY := MyLib
LIBRARY_FILENAME :=
SHARED_FLAG :=
RUN_COMMAND :=
COMPILE_LIB :=
COMPILE_MAIN :=

ifeq ($(OS),Windows_NT)
	@echo Run win.bat
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		SHARED_FLAG += -shared
		LIBRARY_FILENAME += lib$(LIBRARY).so
		EXTRA_FILES_TO_CLEAN += 
		RUN_COMMAND += LD_LIBRARY_PATH=. main
		COMPILE_LIB += g++ -fPIC -Wall $(SHARED_FLAG) -o $(LIBRARY_FILENAME) MyLib.cpp
		COMPILE_MAIN += g++ -Wall -L. -o main main.cpp -l$(LIBRARY)
else
	endif
	ifeq ($(UNAME_S),Darwin)
		SHARED_FLAG += -dynamiclib
		LIBRARY_FILENAME += lib$(LIBRARY).dylib
		EXTRA_FILES_TO_CLEAN += 
		RUN_COMMAND += main
		COMPILE_LIB += g++ -fPIC -Wall $(SHARED_FLAG) -o $(LIBRARY_FILENAME) MyLib.cpp
		COMPILE_MAIN += g++ -Wall -L. -o main main.cpp -l$(LIBRARY)
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
	@echo COMPILE_LIB:$(COMPILE_LIB)
	@echo COMPILE_MAIN:$(COMPILE_MAIN)
	@echo RUN_COMMAND:$(RUN_COMMAND)

lib: MyLib.cpp
	$(COMPILE_LIB)

main: main.cpp
	$(COMPILE_MAIN)

run:
	$(RUN_COMMAND)

copy:
	cp -f $(LIBRARY_FILENAME) ../datafiles/

clean:
	rm main $(LIBRARY_FILENAME) $(EXTRA_FILES_TO_CLEAN)
