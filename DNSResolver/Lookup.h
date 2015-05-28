#ifndef LOOKUP_H

#define LOOKUP_H

class Lookup{
private:
	char* name;
	bool type_a;
public:
	Lookup(char* new_name){
		name = new char[strlen(new_name)];
		unsigned long IP = inet_addr(new_name);
		if (IP == INADDR_NONE){
			type_a = true;
			strcpy(name, new_name);
		}
		else{
			type_a = false;
			char* period3 = strrchr(new_name, '.');
			int size_of_period3 = strlen(period3);
			strncpy(name, period3 + 1, size_of_period3 - 1);
			name[size_of_period3 - 1] = '.';
			*period3 = '\0';
			char* period2 = strrchr(new_name, '.');
			int size_of_period2 = strlen(period2);
			strncpy(name + size_of_period3, period2 + 1, size_of_period2 - 1);
			name[size_of_period2 + size_of_period3 - 1] = '.';
			*period2 = '\0';
			char* period1 = strrchr(new_name, '.');
			int size_of_period1 = strlen(period1);
			strncpy(name + size_of_period3 + size_of_period2, period1 + 1, size_of_period1 - 1);
			name[size_of_period1 + size_of_period2 + size_of_period3 - 1] = '.';
			*period1 = '\0';
			strcpy(name + size_of_period1 + size_of_period2 + size_of_period3, new_name);
			*period1 = '.';
			*period2 = '.';
			*period3 = '.';
		}
	}
	bool isTypeA(){
		return type_a;
	}
};

#endif