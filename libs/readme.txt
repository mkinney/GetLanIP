If Linux or Mac, run "make".

If Windows, start Visual Studio Command Prompt, change to this directory and run: "win.bat"

The default target "all", will:
1) build the library
2) compile a sample "main" program for testing
3) run the "main" program above
4) copy the library to ../datafiles (which is the "Included Files" from GMS GUI)

Note: Assumes that the host resolves correctly in /etc/hosts. For instance, you should be able to run `hostname` then ping that hostname to get the ip.
