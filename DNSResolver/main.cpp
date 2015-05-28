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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int main(){
	system("PAUSE");
	return 0;
}