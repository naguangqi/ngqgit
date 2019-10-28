#include "head.h"

void sort_5() {
	char filename[100]; //文件名称
	char txt[10000]; //文件内容
	FILE *fp; //文件指针

	printf("请输入文件名称(后缀为.txt):");
	scanf("%s", &filename);

	int a, b, c, d;
	a = access(filename, F_OK);
	b = access(filename, R_OK);
	c = access(filename, W_OK);
	d = access(filename, X_OK);

	printf("存在？%s,可读？%s,可写？%s,可运行？%s\n",myboolean(a),myboolean(b),myboolean(c),myboolean(d));
}

char * myboolean(int p)/*此函数为了方便结果而定义的布尔运算*/
{
	char *f =NULL;
	if(p<0)
	return f="否";
	if(p==0)
	return f="是";
}
