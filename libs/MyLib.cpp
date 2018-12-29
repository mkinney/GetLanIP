#undef UNICODE

#include <string>

#ifdef WIN
  #include <winsock2.h>
  #include <ws2tcpip.h>
#else
  #include <unistd.h>
  #include <netdb.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
#endif

#include <stdio.h>

using std::string;

#ifdef WIN
  // link with Ws2_32.lib
  #pragma comment (lib, "Ws2_32.lib")
#endif

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
    string retval;
    char myhostname[256];

#ifdef WIN32
    WSADATA wsaData;
    WORD wVersionRequested = MAKEWORD(2, 0);
    if(::WSAStartup(wVersionRequested, &wsaData) != 0)
      return ToStringPtr(retval);
#endif
    gethostname(myhostname, sizeof(myhostname));
    struct hostent *host = gethostbyname(myhostname);
    if (host == NULL) {
#ifdef WIN32
      WSACleanup();
#endif
      return ToStringPtr(retval);
    }
    //printf("name: %s\n",host->h_name);
    retval = inet_ntoa((*(struct in_addr *)host->h_addr_list[0]));
#ifdef WIN32
    WSACleanup();
#endif
    return ToStringPtr(retval);
  } // LanIP

}
