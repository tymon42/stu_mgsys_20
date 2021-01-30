/*
按姓名排序，输出
按平均成绩排序，输出
输出给定学院学生*/ 
void sortOnName1(Node *p)//从小到大 按姓名 排序 
{
	Data *mid;
	
	while(*p->next)
	{
		if(strcmp(p->data->name,p->next->data->name)>0)
		{
			*mid=p->data;
			p->data=p->next->data;
			p->next->data=*mid;
		}
		p=p->next;
	}
} 
void sortOnName2(Node *p)//从大到小 按姓名 排序 
{
	Data *mid;
	
	while(*p->next)
	{
		if(strcmp(p->data->name,p->next->data->name)<0)
		{
			*mid=p->data;
			p->data=p->next->data;
			p->next->data=*mid;
		}
		p=p->next;
	}
} 

void sortaverage(Node *p)  //按平均成绩从大到小排序 
{
	Data *mid;
	
	while(*p->next)
	{
		if(p->data->average<p->next->data->average)
		{
			*mid=p->data;
			p->data=p->next->data;
			p->next->data=*mid;
		}
		p=p->next;
	}
}


