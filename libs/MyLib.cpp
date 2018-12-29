#undef UNICODE

#include <string>

#ifdef WIN
  #include <winsock2.h>
  #include <ws2tcpip.h>
#define DLL _declspec(dllexport)
#else
#define DLL  
  #include <unistd.h>
  #include <netdb.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <string.h>
#endif

#include <stdio.h>

using std::string;

#ifdef WIN
  // link with Ws2_32.lib
  #pragma comment (lib, "Ws2_32.lib")
#endif

// convert std::string to pointer to char (for C)
char *ToStringPtr(const string& in) {
  const std::string::size_type size = in.size();
  char *buffer = new char[size + 1];
  memcpy(buffer, in.c_str(), size + 1);
  return buffer;
}

extern "C" {

DLL char *LanIP(void) {
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

} // extern
