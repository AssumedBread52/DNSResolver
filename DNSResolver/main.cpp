/*
                                        +-----------+
   +------+                             |user output|
   |Lookup|                             +-----------+
   +------+                                   ^
      |                                       |
      v                                     +--------+
+-----------------+ IP  +--------------+    |Response|
|Decide Query Type|---->|Query Type PTR|    | parser |
+-----------------+     +--------------+    +--------+
       |                    |                 ^
       | host               |                 | response
       v                    v                 |
+------------+          +-----------+  +------------+
|Query Type A|--------->|   Query   |->| UDP sender |
+------------+          |Constructor|  |and receiver|
                        +-----------+  +------------+
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>

#include "Lookup.h"

#pragma comment(lib, "ws2_32.lib")

int main(int argument_count, char** argument_values){
	if (argument_count != 2){
		printf("Usage: DNSResolver.exe [lookup string]\n");
		system("PAUSE");
		return 0;
	}
	Lookup lookup = Lookup(argument_values[1]);
	system("PAUSE");
	return 0;
}