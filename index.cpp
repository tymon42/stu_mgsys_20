#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "list.h"
#include "function4567.h"
#include "func89.h"

#define COURSE_NUM 4	 // 最多的考试科目数
#define LEN sizeof(Node) // 数据结构的长度

int Menu(void);

int main()
{
	int i;
	// 登录
	FILE *fp;
	char strLine[20]; //读取缓冲区
	char ps[20];
	if ((fp = fopen("pw.txt", "r")) == NULL) //判断文件是否存在及可读
	{
		printf("Open Falied!");
		return -1;
	}
	while (!feof(fp)) //循环读取每一行，直到文件尾
	{
		fgets(strLine, 20, fp); //将fp所指向的文件一行内容读到strLine缓冲区
								// printf(strLine);
	}
	fclose(fp);
	printf("请输入密码：");
	while (1)
	{
		scanf("%s", ps);
		if (*ps == *strLine)
			break;
		else
		{
			printf("请输入密码：");
			continue;
		}
	}

	Node head;
	// = (Node *)malloc(LEN);
	printf("\t\t\t*****************************************************************\n");
	printf("\t\t\t\t\t初始化中……\n");
	printf("\t\t\t*****************************************************************\n");
	Node *info_list;
	ColNode *col_list;
	SexNode *Sex_list;
	info_list = CreateInfoList();
	col_list = CreateColList();
	Sex_list = CreateSexList();
	// extern int ColLen = readColFromFile(col_list);
	// extern int SexLen = readSexFromFile(Sex_list);

	while (1)
	{
		system("cls"); //清屏
		i = Menu();
		switch (i)
		{
		case 1:
			system("cls"); //清屏
			break;
		case 2:
			system("cls"); //清屏
			break;
		case 3:
			system("cls"); //清屏
			break;
		case 4:
			system("cls"); //清屏
			printf("\n\n\n");
			// insetNode(info_list,col_list,Sex_list);
			break;
		case 5:
			system("cls"); //清屏
			printf("\n\n\n");
			break;
		case 6:
			system("cls"); //清屏
			printf("\n\n\n");
			break;
		case 7:
			system("cls"); //清屏
			printf("\n\n\n");
			break;
		case 8:
			system("cls"); //清屏
			printf("\n\n\n");
			printf("\t\t\t更改密码:\n");
			UpdataPW();
			printf("\n\n\n");
			break;
		case 9:
			system("cls"); //清屏
			printf("\n\n\n");
			break;
		case 0:
			system("cls"); //清屏
			// TODO: 返回上一级菜单
			return 0;
		default:
			system("cls"); //清屏
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput error!\n");
			printf("\t\t\t******************************************************************************\n");
		}
	}

	return 0;
}
// 创建菜单
int Menu(void)
{
	int i;
	printf("\n\n");
	printf("\t\t\t                         学生成绩管理系统\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\t\t\t*                Management for Students' scores\n");
	printf("\t\t\t*                1.  按姓名排序，输出\n");
	printf("\t\t\t*                2.  按平均成绩排序，输出\n");
	printf("\t\t\t*                3.  输出给定学院学生\n");
	printf("\t\t\t*                4.  添加学生及其成绩\n");
	printf("\t\t\t*                5.  修改给定学生成绩信息\n");
	printf("\t\t\t*                6.  按姓名查询学生，输出\n");
	printf("\t\t\t*                7.  删除学生成绩\n");
	printf("\t\t\t*                8.  修改系统密码\n");
	printf("\t\t\t*                9.  输出挂科学生信息并强调其挂掉的科目\n");
	printf("\t\t\t*                0.  返回上一级菜单\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t*****************输入选项:");
	scanf("%d", &i);
	return i;
}