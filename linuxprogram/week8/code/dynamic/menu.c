#include "head.h"

void menu() {

	while (1) {
		printf("********************************\n");
		printf("         0.退出\n");
		printf("         1.创建新文件\n");
		printf("         2.写文件\n");
		printf("         3.读文件\n");
		printf("         4.修改文件权限\n");
		printf("         5.查看当前文件的权限\n");
		printf("********************************\n");
		printf("        Please input your choice(0-6):");
		scanf("%d", &button);
		//printf("%d", button);

		if(button == 0) break;
		else if(button == 1) sort_1();
		else if(button == 2) sort_2();
		else if(button == 3) sort_3();
		else if(button == 4) sort_4();
		else if(button == 5) sort_5();
		else{printf("输入有误，请重新输入！\n");}

/*		switch (button)
		{
		case 0: sort_0(); break;
		case 1: sort_1(); break;
		case 2: sort_2(); break;
		case 3: sort_3(); break;
		case 4: sort_4(); break;
		case 5: sort_5(); break;

		default: printf("输入有误，请重新输入！");

			break;
		}
*/
	}

}
