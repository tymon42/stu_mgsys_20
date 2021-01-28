/*
此源文件的功能为：
    1.定义结构体
    2.使用链表实现信息增删查(不包括人机交互)
*/
#include <string.h>
#include <stdlib.h>
int collen;
int sexlen;
//存储学生信息的结构体
typedef struct Data
{
    int id;
    char name[64];
    int colid;
    int sexid;
    char col[64];
    char sex[4];
    double score[4];
    double average;
}Data;
Data *pstu;
//链表节点结构体
typedef struct Node 
{
    Data data;
    Node *next;
}Node;
//文件读取学院代码结构体
typedef struct Col
{
    int colnum;
    char col[64];
}Col;
Col *pcol;
//文件读取性别代码结构体
typedef struct Sex
{
    int sexnum;
    char sex[64];
}Sex;
Sex *psex;
//创建链表头
Node *CreateList ()
{
    Node *listHeadNode = (Node *)malloc(sizeof(Node));
    listHeadNode->next = NULL;
    return listHeadNode;
}
//创建节点
Node *createNode(Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data ;
    newNode -> next = NULL ;
    return newNode;
}
//增
//头插法插入数据到链表
void *insetNodeByHead (Node *listheadNode,Data data)
{
    Node *nweNode = createNode(data);
    nweNode -> next = listheadNode -> next;
    listheadNode->next = nweNode;
}
//查
//使用name(char)查找节点
Node *searchNodeByName(Node *listHeadNode,char searchname[64])
{
    Node *pMove = listHeadNode->next;
    if (pMove == NULL)
    return pMove;
    else
    {
        while (strcmp(pMove->data.name,searchname)!=0)
        {
            pMove = pMove->next;
            if (pMove == NULL)
            break;
        }
        return pMove;
    }
}
//删
//使用name(char)删除节点
void deleNode(Node *listHeadNode ,Node *dele)
{
    Node *p = listHeadNode->next;
    Node *q = p->next;
    while ( strcmp(q->data.name,dele->data.name)!=0 )
    {   
        p = p->next;
        q = q->next;
        if(q == NULL)
        return;
    }
    p->next = q->next;
    return;
}