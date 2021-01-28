/*
本函数实现的功能：
读取文件到链表

*/
//处理注释并读取数据长度
int readFromFile(FILE *fp)
{
    char readinfo[64],*ps=readinfo;
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
void readColFromFile()
{
    cout<<"正在读取文件(1/3)"<<endl;
    FILE *fp;
    //C_Code.txt为学院代码文件
    fp=fopen("C_Code.txt","r");
    if (fp == NULL)
    {
        fprintf(stdout,"file(r)");
        cout<<"读取文件失败。(1101)"<<endl;
        exit(1);
    }
    collen = readFromFile(fp);
    pcol = (Col *)malloc(collen*sizeof(Col));
    for(int i=0;i<collen;i++)
    {
        fscanf(fp,"%d%s",&(pcol+i)->colnum,(pcol+i)->col);
    }
    fclose(fp);
}
//读取性别代码
void readSexFromFile()
{
    cout<<"正在读取文件(2/3)"<<endl;
    FILE *fp;
    //S_Code.txt为性别代码文件
    fp=fopen("S_Code.txt","r");
    if (fp == NULL)
    {
        fprintf(stdout,"file(r)");
        cout<<"读取文件失败。(1102)"<<endl;
        exit(1);
    }
    sexlen = readFromFile(fp);
    psex = (Sex *)malloc(collen*sizeof(Sex));
    for(int i=0;i<sexlen;i++)
    {
        fscanf(fp,"%d%s",&(psex+i)->sexnum,(psex+i)->sex);
    }
    fclose(fp);
}
//从文件中读取学生信息
void readStuInfoFromFile(Node *listHeadNode)
{
    FILE *fp;
    fp = fopen("Stu_Info.txt","r");
    if (fp == NULL)
    {
        fprintf(stdout,"w");
        cout<<"读取文件失败。(1103)"<<endl;
        exit(1);
    }
    Data tempData;
    while(fp)
    {
        fscanf(fp,"%d%s%d%d",
        &tempData.id,
        tempData.name,
        &tempData.colid,
        &tempData.sexid);
        for(int i=0;i<4;i++)
        {
            fscanf(fp,"%d",&tempData.score[i]);
        }
        insetNodeByHead(listHeadNode,tempData);
        memset(&tempData,0,sizeof(tempData));
    }
    fclose(fp);
}
//将信息写入文件
void saveInfoToFile(struct Node* listHeadNode)
{
    FILE *fp = fopen("Stu_Info.txt","w");
    struct Node* pMove = listHeadNode->next;
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