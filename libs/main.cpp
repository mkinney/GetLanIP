#include <stdio.h>
#include <stdlib.h>
#include <string>

using std::string;

#ifdef WIN
#define DLL _declspec(dllimport)
#else
#define DLL
#endif

extern "C" DLL char *LanIP(void);

int main() {
  fprintf(stderr, "LanIP:%s\n", LanIP());
  return 0;
}
