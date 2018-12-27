#include <stdio.h>
#include <stdlib.h>
#include <string>

using std::string;

extern "C" {
  char *LanIP(void);
}

int main() {
  fprintf(stderr, "LanIP:%s\n", LanIP());
  return 0;
}
