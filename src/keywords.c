#include <string.h>

#include "keywords.h"

_CONFIG Config;

// 设置关键字
void setKeyword(char *name, char *value, int type)
{
	strcpy( Config.keywords[Config.count].name, name);
	strcpy( Config.keywords[Config.count].value, value);
	Config.keywords[Config.count].type = type;
	Config.count++;
}


// 初始化关键字
void init_keywords(void)
{
	setKeyword("若", "if", KEYWORK);
	setKeyword("否则", "else", KEYWORK);

	setKeyword("跳转", "switch", KEYWORK);
	setKeyword("条件", "case", KEYWORK);

	setKeyword("当", "while", KEYWORK);
	setKeyword("执行", "do", KEYWORK);
	setKeyword("循环", "for", KEYWORK);

	setKeyword("引入", "#include", KEYWORK);

	setKeyword("主函数", "main", KEYWORK);
	setKeyword("返回", "return", KEYWORK);

	setKeyword("整形", "int", KEYWORK);
	setKeyword("浮点型", "float", KEYWORK);
	setKeyword("字符", "char", KEYWORK);
	setKeyword("字符指针", "char *", KEYWORK);	

	setKeyword("打印", "printf", FUNCTION);
	setKeyword("输入", "scanf", FUNCTION);	

	/*setKeyword("“", "\"");
	setKeyword("”", "\"");
	setKeyword("（", "(");
	setKeyword("）", ")");
	setKeyword("；", ";");*/
}