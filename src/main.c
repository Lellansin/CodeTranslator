
#include <stdio.h>

#include "keywords.h"
#include "file.h"
#include "list.h"

void help(void);

int main(int argc, char *argv[])
{
	// ��ʼ������
	init_keywords();

	if(argc == 1)
	{
		help();
	}else if(argc == 2)
	{
		process(argv[1]);
	}else if(argc == 3){
		//process(argv[1], argv[2]);
	}

	return 0;
}

void help()
{
	printf("���뷭�빤�� v0.1\n");
	printf("�﷨��Linh �����ļ�\n");
}

