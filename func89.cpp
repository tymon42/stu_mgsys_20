#include "func89.h"

// ĞŞ¸ÄÃÜÂë
void UpdataPW()
{
    char a[20];
    scanf("%s",a);
    FILE *fp = fopen("ps.txt", "w");
    fprintf(fp,"%s\n",a);	
    fclose(fp);
    return;
}
