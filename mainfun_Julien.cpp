/*
此源文件的功能为：
对学生信息的增删改查
(包含人机交互)
*/
#include "stumgsys20.h"
//增
void insetNode(Node *listHeadNode)
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
    newdata.colid = Col_changeToInt(colinput);
    newdata.sexid = Sex_changeToInt(sexinput);
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