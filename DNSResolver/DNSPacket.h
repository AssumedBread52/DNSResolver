#ifndef DNSPACKET_H

#define DNSPACKET_H

class DNSPacket{
private:
	unsigned char* packet;
public:
	DNSPacket(Lookup lookup){
		int packet_size = sizeof(QueryHeader) + sizeof(DNSHeader) + strlen((char*)lookup.getLookupName()) + 2;
		packet = new unsigned char[packet_size];
		DNSHeader* dns_header = (DNSHeader*)packet;
		QueryHeader* query_header = (QueryHeader*)(packet + packet_size - sizeof(QueryHeader));
		query_header->setClass();
		query_header->setType(lookup.isTypeA());
		query_header->nameToQueryFormat(lookup.getLookupName(), (unsigned char*)(dns_header + 1));
		dns_header->setID();
		dns_header->setFlags();
		dns_header->setCount();
	}
	unsigned char* getPacket(){
		return packet;
	}
};

#endif