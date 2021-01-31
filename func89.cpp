#include "func89.h"

void UpdataPW()
{
    char a[20];
    printf("输入新密码：");
    scanf("%s", a);
    FILE *fp = fopen("pw.txt", "w");
    fprintf(fp, "%s\n", a);
    fclose(fp);
    return;
}

void FindBadBoy(Node *p)
{
    Node *pMove = p->next;
    while(pMove!=NULL)
    {
        for (int i = 0; i < 4; i++)
        {
            if (pMove->data.score[i] < 60)
                printf("%s的成绩%d不及格，成绩为%d\n", pMove->data.name, i + 1, pMove->data.score[i]);
        }
        pMove = pMove->next;
    }
    return;
}
