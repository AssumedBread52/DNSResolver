#ifndef LOOKUP_H

#define LOOKUP_H

class Lookup{
private:
	unsigned char* name;
	unsigned char* server;
	bool type_a;
public:
	Lookup(char* new_name, char* server_name){
		name = new unsigned char[strlen(new_name)];
		unsigned long IP = inet_addr(new_name);
		if (IP == INADDR_NONE){
			type_a = true;
			strcpy((char*)name, new_name);
		}
		else{
			type_a = false;
			char* period3 = strrchr(new_name, '.');
			int size_of_period3 = strlen(period3);
			strncpy((char*)name, period3 + 1, size_of_period3 - 1);
			name[size_of_period3 - 1] = '.';
			*period3 = '\0';
			char* period2 = strrchr(new_name, '.');
			int size_of_period2 = strlen(period2);
			strncpy((char*)name + size_of_period3, period2 + 1, size_of_period2 - 1);
			name[size_of_period2 + size_of_period3 - 1] = '.';
			*period2 = '\0';
			char* period1 = strrchr(new_name, '.');
			int size_of_period1 = strlen(period1);
			strncpy((char*)name + size_of_period3 + size_of_period2, period1 + 1, size_of_period1 - 1);
			name[size_of_period1 + size_of_period2 + size_of_period3 - 1] = '.';
			*period1 = '\0';
			strcpy((char*)name + size_of_period1 + size_of_period2 + size_of_period3, new_name);
			*period1 = '.';
			*period2 = '.';
			*period3 = '.';
		}
		server = new unsigned char[strlen(server_name)];
		strcpy((char*)server, server_name);
	}
	unsigned char* getLookupName(){
		return name;
	}
	bool isTypeA(){
		return type_a;
	}
};

#endif