#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFSIZE 128

using std::string;

extern "C" {

  // convert std::string to pointer to char (for C)
  char *ToStringPtr(const string& in) {
    const std::string::size_type size = in.size();
    char *buffer = new char[size + 1];
    memcpy(buffer, in.c_str(), size + 1);
    return buffer;
  }

  // get ipv4 address (of non-loopback)
  // borrowed from https://stackoverflow.com/questions/212528/get-the-ip-address-of-the-machine
  char *LanIP(void) {
    string retval = "";
    struct ifaddrs * ifAddrStruct = NULL;
    struct ifaddrs * ifa = NULL;
    void * tmpAddrPtr = NULL;

    getifaddrs(&ifAddrStruct);

    // loop thru the interfaces
    for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
      if (!ifa->ifa_addr) {
        continue;
      }
      if (ifa->ifa_addr->sa_family == AF_INET) { // IP4
        tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
        char addressBuffer[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
        //printf("%s IP Address %s\n", ifa->ifa_name, addressBuffer);
        // we do not care about the loopback interfaces
        if (strcmp(ifa->ifa_name, "lo0") != 0) {
          retval += addressBuffer;
          break; // only want the first one
        }
      }
    }
    if (ifAddrStruct != NULL) {
      freeifaddrs(ifAddrStruct);
    }

    return ToStringPtr(retval);
  }

}
