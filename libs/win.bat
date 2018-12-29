C:\Users\mikekinney\Documents\GameMakerStudio2\GetLanIP\libs
cl /EHsc /DWIN /LD MyLib.cpp
cl /EHsc main.cpp /link MyLib.lib
main
copy /Y MyLib.dll ..\datafiles\
del *.obj *.exp *.dll *.exe *.lib
