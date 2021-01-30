#include "func89.h"

void UpdataPW()
{
    char a[20];
    printf(" ‰»Î–¬√‹¬Î£∫");
    scanf("%s",a);
    FILE *fp = fopen("pw.txt", "w");
    fprintf(fp,"%s\n",a);	
    fclose(fp);
    return;
}

void FindBadBoy(Node *p,int num)
{
	for (int j = 0; j < num; j++,p++)
	for (int i = 0; i < 4; i++)
	{
		if(p->data.score[i]<60)
			printf("%S???%d?????%lf\n",p->data.name,i+1,p->data.score[i]);
	}
}
