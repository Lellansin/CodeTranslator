#include "keywords.h"

// �ؼ�������
keyword keywords[100];
// �ؼ�����Ŀ
int kw_count;

// ���ùؼ���
void setKeyword(char *name, char *value, int type)
{
	strcpy( keywords[kw_count].name, name);
	strcpy( keywords[kw_count].value, value);
	keywords[kw_count].type = type;
	kw_count++;
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