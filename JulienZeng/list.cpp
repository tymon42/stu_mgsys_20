/*
此源文件的功能为：
    1.定义结构体
    2.使用链表实现信息增删查(不包括人机交互)
*/
#include "stumgsys20.h"

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
//创建节点
ColNode *createColNode(Col data)
{
    ColNode *newNode = (ColNode *)malloc(sizeof(ColNode));
    newNode -> col = data ;
    newNode -> next = NULL ;
    return newNode;
}
//头插法插入数据到链表
void *insetColNodeByHead (ColNode *listheadNode,Col data)
{
    ColNode *nweNode = createColNode(data);
    nweNode -> next = listheadNode -> next;
    listheadNode->next = nweNode;
}
SexNode *createSexNode(Sex data)
{
    SexNode *newNode = (SexNode *)malloc(sizeof(SexNode));
    newNode -> sex = data ;
    newNode -> next = NULL ;
    return newNode;
}
//头插法插入数据到链表
void *insetSexNodeByHead (SexNode *listheadNode,Sex data)
{
    SexNode *nweNode = createSexNode(data);
    nweNode -> next = listheadNode -> next;
    listheadNode->next = nweNode;
}