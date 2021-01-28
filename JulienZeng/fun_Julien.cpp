#include "stumgsys20.h"
//打印节点
//！！！！格式需要更改！！！！
void printNode(Node *curNode)
{
    cout<<"\t学号\t姓名\t学院\t性别\t成绩1\t成绩2\t成绩3\t成绩4"<<endl;
    printf("%d %s %s %s ",curNode->data.id,
    curNode->data.name,
    curNode->data.col,
    curNode->data.sex);
    for(int i=0;i<4;i++)
    {
        printf("%lf ",curNode->data.score[i]);
    }
}
//将学院名字转化为代码
int Col_changeToInt(char col[64])
{
    ColNode *pMove = colist->next;
    for(int i=0;i<collen;i++)
    {
        if( strcmp(pMove->col.col,col)==0 )
        {
            return pMove->col.colnum;
        }
        pMove = pMove->next;
    }
}
//将性别转化为代码
int Sex_changeToInt(char sex[4])
{
    SexNode *pMove = sexlist->next;
    for(int i=0;i<sexlen;i++)
    {
        if( strcmp(pMove->sex.sex,sex)==0 )
        {
            return pMove->sex.sexnum;
        }
        pMove = pMove->next;
    }
}
//将学院代码转化为名字
Data Col_changeToChar(Data tempData)
{
    ColNode *pMove = colist->next;
    for(int i=0;i<collen;i++)
    {
        if(tempData.colid = pMove->col.colnum)
        {
            strcpy(tempData.col,pMove->col.col);
            break;
        }
        pMove = pMove->next;
    }
}
//将性别代码转化为名字
Data Sex_changeToChar(Data tempData)
{
    SexNode *pMove = sexlist->next;
    for(int i=0;i<sexlen;i++)
    {
        if(tempData.sexid = pMove->sex.sexnum)
        {
            strcpy(tempData.sex,pMove->sex.sex);
            break;
        }
        pMove = pMove->next;
    }
}
//菜单格式！！！
void Menu_DeleNodeByName()
{
    cout<<"请确定您需要进行的操作："<<endl;
    cout<<"1.删除该学生所有信息"<<endl;
    cout<<"2.将该学生的成绩1归零"<<endl;
    cout<<"3.将该学生的成绩2归零"<<endl;
    cout<<"4.将该学生的成绩3归零"<<endl;
    cout<<"5.将该学生的成绩4归零"<<endl;
    cout<<"0.取消操作并返回上一层"<<endl;
}
double coutAve(Data tempData)
{
    double sum = 0;
    for(int i=0;i<4;i++)
    {
        sum += tempData.score[i];
    }
    return sum/4;
}