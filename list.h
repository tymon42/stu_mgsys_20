#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//存储学生信息的结构体
typedef struct Data
{
    int id;
    char name[64];
    int colid;
    int sexid;
    char col[64];
    char sex[4];
    int score[4];
    double average;
}Data;
//链表节点结构体
typedef struct Node 
{
    Data data;
    Node *next;
}Node;
//学院代码结构体
typedef struct Col
{
    int colnum;
    char col[64];
}Col;
//学院代码链表节点
typedef struct ColNode
{
    Col col;
    ColNode *next;
}ColNode;
//文件读取性别代码结构体
typedef struct Sex
{
    int sexnum;
    char sex[64];
}Sex;
//性别代码结构体
typedef struct SexNode
{
    Sex sex;
    SexNode *next;
}SexNode;

Node *CreateInfoList ();
ColNode *CreateColList ();
SexNode *CreateSexList ();
Node *createNode(Data);
void *insetNodeByHead (Node*,Data);
Node *searchNodeByName(Node*,char []);
void deleNode(Node*,Node*);
ColNode *createColNode(Col);
void *insetColNodeByHead (ColNode*,Col);
SexNode *createSexNode(Sex);
void *insetSexNodeByHead (SexNode*,Sex);

#endif