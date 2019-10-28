#include "head.h"

void sort_4() {
	char filename[100]; //文件名称
	char txt[10000]; //文件内容
	FILE *fp; //文件指针
	int choice;//权限选择

	printf("请输入文件名称(后缀为.txt):");
	scanf("%s", &filename);

	int a, b, c, d;
	a = access(filename, F_OK);
	b = access(filename, R_OK);
	c = access(filename, W_OK);
	d = access(filename, X_OK);

	printf("存在？%s,可读？%s,可写？%s,可运行？%s\n",myboolean(a),myboolean(b),myboolean(c),myboolean(d));

	printf("请选择需要修改的权限(单选)：\n");
	printf("1.可读\n");
	printf("2.可写\n");
	printf("3.可执行\n");
	printf("4.可读写执行\n");
	printf("请选择：");
	scanf("%d", &choice);

	switch (button)
		{
		case 1: chmod(filename, S_IRUSR); break;
		case 2: chmod(filename, S_IWUSR); break;
		case 3: chmod(filename, S_IXUSR); break;
		case 4: chmod(filename, S_IRWXU); break;

		default: printf("输入有误，请重新输入！");

			break;
		}
}	
