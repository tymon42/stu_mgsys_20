#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

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
//创建链表
Node *list = NULL;
ColNode *colist = NULL;
SexNode *sexlist = NULL;

#ifndef __STUMGSYS20_H__
#define __STUMGSYS20_H__
//链表
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
//文件操作
int readFromFile(FILE*);
void readColFromFile(ColNode*);
void readSexFromFile(SexNode*);
void readStuInfoFromFile(Node*);
void saveInfoToFile(Node*);
void printNode(Node*);
//前置功能
int Col_changeToInt(char []);
int Sex_changeToInt(char []);
Data Col_changeToChar(Data);
Data Sex_changeToChar(Data);
void Menu_DeleNodeByName();
double coutAve(Data);
//增删改查
void insetNode(Node*);
void deleNodeByName(Node*);
void changeNodeByName(Node*);
void searchByName(Node*);

#endif