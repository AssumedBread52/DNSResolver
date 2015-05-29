#ifndef DNSHEADER_H

#define DNSHEADER_H

/* flags */
#define DNS_QUERY (0<<15) /* query */
#define DNS_RESPONSE (1<<15) /* response */
#define DNS_STANDARD_QUERY (0<<11) /* opcode = 4 bits */
#define DNS_AA (1<<10) /* authoritative answer */
#define DNS_TC (1<<9) /* truncated */
#define DNS_RD (1<<8) /* recursion desired */
#define DNS_RA (1<<7) /* recursion available */

class DNSHeader{
private:
	unsigned short id;
	unsigned short flags;
	unsigned short question_count;
	unsigned short answer_count;
	unsigned short authority_record_count;
	unsigned short additional_record_count;
public:
	void setID(){
		srand(time(NULL));
		id = rand() % 65536;
	}
	void setFlags(){
		flags = htons(DNS_QUERY | DNS_RD | DNS_STANDARD_QUERY);
	}
	void setCount(){
		question_count = 1;
		answer_count = 0;
		authority_record_count = 0;
		additional_record_count = 0;
	}
	unsigned short getID(){
		return id;
	}
	unsigned short getFlags(){
		return flags;
	}
	unsigned short getQuestionCount(){
		return question_count;
	}
	unsigned short getAnswerCount(){
		return answer_count;
	}
	unsigned short getAuthorityRecordCount(){
		return authority_record_count;
	}
	unsigned short getAdditionalRecordCount(){
		return additional_record_count;
	}
};

#endif