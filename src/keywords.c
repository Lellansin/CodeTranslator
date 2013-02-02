#include <string.h>

#include "keywords.h"

_CONFIG Config;

// ���ùؼ���
void setKeyword(char *name, char *value, int type)
{
	strcpy( Config.keywords[Config.count].name, name);
	strcpy( Config.keywords[Config.count].value, value);
	Config.keywords[Config.count].type = type;
	Config.count++;
}


// ��ʼ���ؼ���
void init_keywords(void)
{
	setKeyword("��", "if", KEYWORK);
	setKeyword("����", "else", KEYWORK);

	setKeyword("��ת", "switch", KEYWORK);
	setKeyword("����", "case", KEYWORK);

	setKeyword("��", "while", KEYWORK);
	setKeyword("ִ��", "do", KEYWORK);
	setKeyword("ѭ��", "for", KEYWORK);

	setKeyword("����", "#include", KEYWORK);

	setKeyword("������", "main", KEYWORK);
	setKeyword("����", "return", KEYWORK);

	setKeyword("����", "int", KEYWORK);
	setKeyword("������", "float", KEYWORK);
	setKeyword("�ַ�", "char", KEYWORK);
	setKeyword("�ַ�ָ��", "char *", KEYWORK);	

	setKeyword("��ӡ", "printf", FUNCTION);
	setKeyword("����", "scanf", FUNCTION);	

	/*setKeyword("��", "\"");
	setKeyword("��", "\"");
	setKeyword("��", "(");
	setKeyword("��", ")");
	setKeyword("��", ";");*/
}