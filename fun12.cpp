#include "fun12.h"
/*
按姓名排序，输出
按平均成绩排序，输出
*/ 
//sum为学生总数 
void sortOnName1(Node *p,int sum)//从小到大 按姓名 排序 
{
	Data *mid;
	Node *px=p->next;
	
	int i,j;
	for(i=0;i<num;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
				if(strcmp(p->data.name,p->next.data.name)>0)
			{
				*mid=p->data;
				p->data=p->next.data;
				p->next.data=*mid;
			}
			px=px->next;	
		}
		p=p->next;
		px=p->next;
	}

} 
void sortOnName2(Node *p,int num)//从大到小 按姓名 排序 
{
	Data *mid;
	Node *px=p->next;
	
	int i,j;
	for(i=0;i<num;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
				if(strcmp(p->data.name,p->next.data.name)<0)
			{
				*mid=p->data;
				p->data=p->next.data;
				p->next.data=*mid;
			}
			px=px->next;	
		}
		p=p->next;
		px=p->next;
	}

}

void sortaverage(Node *p,int num)  //按平均成绩从大到小排序 
{
	Data *mid;
	Node *px=p->next;
	
	int i,j;
	for(i=0;i<num;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
				if(p->data.average<p->next.data.average)
			{
				*mid=p->data;
				p->data=p->next.data;
				p->next.data=*mid;
			}
			px=px->next;	
		}
		p=p->next;
		px=p->next;
	}
}


