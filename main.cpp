#include "chat/chat.h"

#include <sstream>
#include <iostream>
#include <time.h>

std::string ToString( int i )
{
  std::ostringstream out;
  out << i;
  return out.str();
}


int main()
{
  ed::com::socket_connection s("localhost", 3030);
  ed::gateway gw(s);
  chat t(gw);
  
  while (true)
  {
    gw.Workflow();
    ed::Sleep(30);
    int time = clock();
    t.Send(ToString(time));
  }
  return 239;
}