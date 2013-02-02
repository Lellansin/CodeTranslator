
#include <stdio.h>

#include "keywords.h"
#include "file.h"
#include "list.h"

void help(void);

int main(int argc, char *argv[])
{
	// 初始化配置
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
	printf("代码翻译工具 v0.1\n");
	printf("语法：Linh 代码文件\n");
}

