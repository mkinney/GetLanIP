all: lib main run copy

lib: MyLib.cpp
	g++ -Wall -dynamiclib -o libMyLib.dylib MyLib.cpp

main: main.cpp
	g++ -Wall -L. -lMyLib -o main main.cpp

run:
	./main

copy:
	cp -f libMyLib.dylib ../datafiles/

clean:
	rm main libMyLib.dylib
