#include "func89.h"

// ĞŞ¸ÄÃÜÂë
void UpdataPW()
{
    char a[20];
    scanf("%s",a);
    FILE *fp = fopen("pw.txt", "w");
    fprintf(fp,"%s\n",a);	
    fclose(fp);
    return;
}
