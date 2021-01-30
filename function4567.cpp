/*
此源文件的功能为：
    1.对学生信息的增删改查(包含人机交互)
    2.对文件进行操作
*/
#include "function4567.h"
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
        printf("%lf",curNode->data.score[i]);
        if(i==4) printf("\n");
        else printf(" ");
    }
}
//将学院名字转化为代码
//如果警告不需要理
int Col_changeToInt(ColNode *colist,char col[64],int collen)
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
//如果警告不需要理
int Sex_changeToInt(SexNode *sexlist,char sex[4],int sexlen)
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
//如果警告不需要理
Data Col_changeToChar(ColNode *colist,Data tempData,int collen)
{
    ColNode *pMove = colist->next;
    for(int i=0;i<collen;i++)
    {
        if(tempData.colid = pMove->col.colnum)
        {
            strcpy(tempData.col,pMove->col.col);
            return tempData;
        }
        pMove = pMove->next;
    }
}
//将性别代码转化为名字
//如果警告不需要理
Data Sex_changeToChar(SexNode *sexlist,Data tempData,int sexlen)
{
    SexNode *pMove = sexlist->next;
    for(int i=0;i<sexlen;i++)
    {
        if(tempData.sexid = pMove->sex.sexnum)
        {
            strcpy(tempData.sex,pMove->sex.sex);
            return tempData;
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
//增
void insetNode(Node *listHeadNode,ColNode *colHeadNode,SexNode *sexHeadNode,int collen,int sexlen)
{
    char colinput[64];
    char sexinput[4];
    Data newdata;
    cout<<"【添加学生及其成绩】"<<endl;
    cout<<"请输入学生信息：(每一项信息请用空格分隔)"<<endl;
    cout<<"学号 姓名 学院 性别 成绩1 成绩2 成绩3 成绩4"<<endl;
    scanf("%d%s%s%s",&newdata.id,
    newdata.name,colinput,sexinput);
    for(int i=0;i<4;i++)
    {
        scanf("%d",newdata.score[i]);
    }
    newdata.colid = Col_changeToInt(colHeadNode,colinput,collen);
    newdata.sexid = Sex_changeToInt(sexHeadNode,sexinput,sexlen);
    insetNodeByHead(listHeadNode,newdata);
    cout<<"增加学生信息成功！"<<endl;
    //存入文件
    saveInfoToFile(listHeadNode);
}
//删
//通过姓名(char)删除信息
void deleNodeByName(Node *listHeadNode)
{
    char delename[64];
    Node *deleStu;
    cout<<"【删除学生成绩】"<<endl;
    cout<<"请输入需要删除的学生的姓名：";
    scanf("%s",delename);
    deleStu = searchNodeByName(listHeadNode,delename);
    if( deleNode == NULL )
    {
        cout<<"Error:未找到相关学生的信息"<<endl;
    }
    else
    {
        printNode(deleStu);
        Menu_DeleNodeByName();
        int chose;
        cin>>chose;
        switch (chose)
        {
        case 1:
            deleNode(listHeadNode,deleStu);
            saveInfoToFile(listHeadNode);
            break;
        
        case 2:
        case 3:
        case 4:
        case 5:
            cout<<"请输入该学生成绩"<<chose-1<<"的新成绩"<<endl;
            scanf("%d",deleStu->data.score[chose-2]);
            saveInfoToFile(listHeadNode);
            break;

        case 0:
            break;
        default:
            cout<<"选择错误，已取消本次操作。"<<endl;
            break;
        }
    }
}
//改
void changeNodeByName(Node *listHeadNode)
{
    cout<<"【修改学生成绩】"<<endl;
    char searchname[64];
    cout<<"请输入学生的姓名：";
    scanf("%s",searchname);
    Node *searchNode;
    searchNode = searchNodeByName(listHeadNode,searchname);
    if( searchNode == NULL )
    {
        cout<<"Error:未找到相关学生的信息"<<endl;
    }
    else
    {
        char chose;
        printNode(searchNode);
        cout<<"确认修改该学生成绩？(Y/N)"<<endl;
        scanf("%c",&chose);
        switch (chose)
        {
        case 'Y':
        case 'y':
            cout<<"请输入该学生的四次成绩"<<endl;
            for(int i=0;i<4;i++)
            {
                scanf("%d",searchNode->data.score[i]);
            }
            cout<<"成绩修改成功!"<<endl;
            saveInfoToFile(listHeadNode);
            break;
        
        case 'N':
        case 'n':
            cout<<"操作取消"<<endl;
            break;

        default:
            cout<<"键入错误，已取消该次操作"<<endl;
            break;
        }
    }
}
//查
void searchByName(Node *listHeadNode)
{
    cout<<"【查询学生成绩】"<<endl;
    char searchname[64];
    cout<<"请输入需要查询的学生姓名："<<endl;
    scanf("%s",searchname);
    cout<<"该名学生信息如下："<<endl;
    printNode(searchNodeByName(listHeadNode,searchname));
}
//输出指定学院学生
void *searchColNodeByColid(Node *listHeadNode,int chose)
{
    Node *pMove = listHeadNode->next;
    while(1)
    {
        if(pMove == NULL)
            break;
        else if( pMove->data.colid == chose )
        {
            printNode(pMove);
        }
        pMove = pMove->next;
    }
}
void printColStu(Node *listHeadNode,ColNode *colHeadNode,int collen)
{
    ColNode *pMove = colHeadNode->next;
    int chose;
    cout<<"【输出给定学院的学生】"<<endl;
    cout<<"请选择需要所需寻找的学院："<<endl;
    for(int i=0;i<collen;i++)
    {
        printf("%d、%s\n",i+1,pMove->col.col);
    }
    cin>>chose;
    cout<<"该学院的学生及成绩如下："<<endl;
    searchColNodeByColid(listHeadNode,chose);
}

/*对文件进行操作*/

//处理注释行
int readFromFile(FILE *fp)
{
    char readinfo[128],*ps=readinfo;
    while(1)
    {
        fscanf(fp,"%s",readinfo);
        if( *ps != '#')
            break;
    }
    int num=0;
    while(*ps)
    {
        num = num*10 + *ps++ -'0';
    }
    return num;
}
//读取学院代码
int readColFromFile(ColNode *colHeadNode)
{
    //此处的输出请在调用前进行
    //cout<<"正在读取文件(1/3)"<<endl;
    FILE *fp;
    Col tempData;
    //C_Code.txt为学院代码文件
    fp=fopen("C_Code.txt","r");
    if (fp == NULL)
    {
        fprintf(stdout,"file(r)");
        cout<<"读取文件失败。(1101)"<<endl;
        exit(1);
    }
    int collen = readFromFile(fp);
    for(int i=0;i<collen;i++)
    {
        fscanf(fp,"%d%s",&tempData.colnum,tempData.col);
        insetColNodeByHead(colHeadNode,tempData);
        memset(&tempData,0,sizeof(tempData));
    }
    fclose(fp);
    return collen;
}
//读取性别代码
int readSexFromFile(SexNode *sexHeadNode)
{
    //此处的输出请在调用前进行
    //cout<<"正在读取文件(2/3)"<<endl;
    FILE *fp;
    Sex tempData;
    //S_Code.txt为性别代码文件
    fp=fopen("S_Code.txt","r");
    if (fp == NULL)
    {
        fprintf(stdout,"file(r)");
        cout<<"读取文件失败。(1102)"<<endl;
        exit(1);
    }
    int sexlen = readFromFile(fp);
    for(int i=0;i<sexlen;i++)
    {
        fscanf(fp,"%d%s",&tempData.sexnum,tempData.sex);
        insetSexNodeByHead(sexHeadNode,tempData);
        memset(&tempData,0,sizeof(tempData));
    }
    fclose(fp);
    return sexlen;
}
//从文件中读取学生信息
void readStuInfoFromFile(Node *listHeadNode,ColNode *colHeadNode,SexNode *sexHeadNode,int collen,int sexlen)
{
    //此处的输出请在调用前进行
    //cout<<"正在读取文件(3/3)"<<endl;
    FILE *fp;
    fp = fopen("Stu_Info.txt(tab)","r");
    if (fp == NULL)
    {
        fprintf(stdout,"w");
        cout<<"读取文件失败。(1103)"<<endl;
        exit(1);
    }
    Data tempData;
    while(fp)
    {
        fscanf(fp,"%d\t%s\t%d\t%d",
        &tempData.id,
        tempData.name,
        &tempData.colid,
        &tempData.sexid);
        for(int i=0;i<4;i++)
        {
            fscanf(fp,"\t%d",&tempData.score[i]);
        }
        tempData = Col_changeToChar(colHeadNode,tempData,collen);
        tempData = Sex_changeToChar(sexHeadNode,tempData,sexlen);
        tempData.average = coutAve(tempData);
        insetNodeByHead(listHeadNode,tempData);
        memset(&tempData,0,sizeof(tempData));
    }
    fclose(fp);
}
//将信息写入文件
void saveInfoToFile(Node *listHeadNode)
{
    FILE *fp = fopen("Stu_Info.txt","w");
    if (fp == NULL)
    {
        fprintf(stdout,"w");
        cout<<"更新数据失败。(1201)"<<endl;
        exit(1);
    }
    Node *pMove = listHeadNode->next;
    while (pMove)
    {
        fprintf(fp,"%d\t%s\t%d\t%d\t",
        pMove->data.id,
        pMove->data.name,
        pMove->data.colid,
        pMove->data.sexid);
        for(int i=0;i<4;i++)
        {
            fprintf(fp,"%d",pMove->data.score[i]);
            if(i!=4)
            {
                fprintf(fp,"\t");
            }
            else
            {
                fprintf(fp,"\n");
            }
        }
        pMove = pMove->next;
    }
    fclose(fp);
}