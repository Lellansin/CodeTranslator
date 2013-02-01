

#ifndef _KEYWORDS_H_

	#define _KEYWORDS_H_

	#define KEYWORK 0
	#define OPERATOR 1
	#define FUNCTION 2

	typedef struct {
		char name[20];
		char value[20];
		int type;
	} keyword ;


	void init_keywords(void);

	void setKeyword(char *name, char *value, int type);

#endif

