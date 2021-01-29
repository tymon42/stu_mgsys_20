#ifndef __FUCTION4567_H__
#define __FUCTION4567_H__
#include "list.h"
#include <iostream>
using namespace std;
//前置功能
int Col_changeToInt(ColNode*,char [],int);
int Sex_changeToInt(SexNode*,char [],int);
Data Col_changeToChar(ColNode*,Data,int);
Data Sex_changeToChar(SexNode*,Data,int);
void Menu_DeleNodeByName();
double coutAve(Data);
//增删改查
void insetNode(Node*,ColNode*,SexNode*,int,int);
void deleNodeByName(Node*);
void changeNodeByName(Node*);
void searchByName(Node*);
//对文件进行操作
int readFromFile(FILE*);
int readColFromFile(ColNode*,int);
int readSexFromFile(SexNode*,int);
void readStuInfoFromFile(Node*,ColNode*,SexNode*,int,int);
void saveInfoToFile(Node*);

#endif