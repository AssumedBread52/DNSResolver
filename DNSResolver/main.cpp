/*
                                      +-----------+
      +------+                        |user output|
      |Lookup|                        +-----------+
      +------+                              ^
         |                                  |
         v                              +--------+
+-----------------+ IP +--------------+ |Response|
|Decide Query Type|--->|Query Type PTR| | parser |
+-----------------+    +--------------+ +--------+
         |                     |              ^
        / host                  \              \ response
       v                         v              |
+------------+            +-----------+  +------------+
|Query Type A|----------->|   Query   |->| UDP sender |
+------------+            |Constructor|  |and receiver|
                          +-----------+  +------------+
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>
#include <WinSock2.h>

#include "Lookup.h"
#include "QueryHeader.h"
#include "DNSHeader.h"
#include "DNSPacket.h"

#pragma comment(lib, "ws2_32.lib")

int main(int argument_count, char** argument_values){
	if (argument_count != 3){
		printf("Usage: DNSResolver.exe [lookup string] [DNS server IP]\n");
		system("PAUSE");
		return 0;
	}
	Lookup lookup = Lookup(argument_values[1], argument_values[2]);
	DNSPacket dns_packet = DNSPacket(lookup);
	system("PAUSE");
	return 0;
}