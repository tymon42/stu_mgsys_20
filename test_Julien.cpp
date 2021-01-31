#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "list.h"
#include "function4567.h"
#include "func89.h"
#include "fun12.h"

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

    int num,collen,sexlen;
	printf("\t\t\t*****************************************************************\n");
	printf("\t\t\t\t\t初始化中……\n");
	printf("\t\t\t*****************************************************************\n");
	Node *info_list;
	ColNode *col_list;
	SexNode *Sex_list;
	info_list = CreateInfoList();
	col_list = CreateColList();
	Sex_list = CreateSexList();
	Node *pMove = info_list;

    //读取学院代码
	printf("\t\t\t*****************************************************************\n");
	printf("\t\t\t\t\t正在读取文档(1/3)……\n");
	printf("\t\t\t*****************************************************************\n");
    collen = readColFromFile(col_list);

    //读取性别代码
	printf("\t\t\t*****************************************************************\n");
	printf("\t\t\t\t\t正在读取文档(2/3)……\n");
	printf("\t\t\t*****************************************************************\n");
    sexlen = readSexFromFile(Sex_list);

    //读取学生信息
	printf("\t\t\t*****************************************************************\n");
	printf("\t\t\t\t\t正在读取文档(3/3)……\n");
	printf("\t\t\t*****************************************************************\n");
    num = readStuInfoFromFile(info_list,col_list,Sex_list,collen,sexlen);

    printf("\t\t\t*****************************************************************\n");
	printf("\t\t\t\t\t系统初始化已完成\n");
	printf("\t\t\t*****************************************************************\n");
    system("pause");

	while (1)
	{
		system("cls"); //清屏
		i = Menu();
		int a = 3;
		switch (i)
		{
		case 1:
			system("cls"); //清屏
			printf("\t\t\t1.从小到大按姓名排序。\n");
			printf("\t\t\t2.从大到小按姓名排序。\n");
			printf("\t\t\t0.返回主菜单。\n");
			scanf("%d",&a);
			switch(a)
			{
				case 1:
					system("cls");
					sortOnName1(info_list,num);
					do
					{
						printNode(pMove);
						pMove = pMove->next;
					} while (pMove);
					system("pause");
					pMove = info_list;
					break;
				case 2:
					system("cls");
					sortOnName2(info_list,num);
					do
					{
						printNode(pMove);
						pMove = pMove->next;
					} while (pMove);
					system("pause");
					pMove = info_list;
					break;
				case 0:
					pMove = info_list;
					break;
				default:
					pMove = info_list;
					break;
			}

			break;
		case 2:
			system("cls"); //清屏

			break;
		case 3:
			system("cls"); //清屏
            printColStu(info_list,col_list,collen);
            system("pause");
			break;
		case 4:
			system("cls"); //清屏
			printf("\n\n\n");
			
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
			FindBadBoy(info_list);
			system("pause");
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