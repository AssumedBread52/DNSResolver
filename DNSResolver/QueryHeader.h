#ifndef QUERYHEADER_H

#define QUERYHEADER_H

/* DNS Query Classes */
#define DNS_INET 1

/* DNS Query Types */
#define DNS_A 1 /* name -> IP */
#define DNS_NS 2 /* name server */
#define DNS_CNAME 5 /* canonical name */
#define DNS_PTR 12 /* IP -> name */
#define DNS_HINFO 13 /* host info/SOA */
#define DNS_MX 15 /* mail exchange */
#define DNS_AXFR 252 /* request for zone transfer */
#define DNS_ANY 255 /* all records */

#pragma pack(push, 1)
class QueryHeader{
private:
	unsigned short query_type;
	unsigned short query_class;
public:
	void setType(bool type_a){
		if (type_a){
			query_type = DNS_A;
		}
		else{
			query_type = DNS_PTR;
		}
	}
	void setClass(){
		query_class = DNS_INET;
	}
	unsigned short getType(){
		return query_type;
	}
	unsigned short getClass(){
		return query_class;
	}
	void nameToQueryFormat(unsigned char* name, unsigned char* new_name){
		unsigned char* dns = new_name;
		int block = 0;
		strcat((char*)name, ".");
		for (int i = 0; i < (int)strlen((char*)name); i++){
			if (name[i] == '.'){
				*dns++ = i - block;
				for (; block < i; block++){
					*dns++ = name[block];
				}
				block++;
			}
		}
		*dns++ = '\0';
	}
};
#pragma pack(pop)

#endif