#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
//
long int refindSize(char* file[]);
int main (void)
 {
system("chcp 1251");
system("cls");
DIR *dp;
struct dirent *ep;
long int razmer = 0;
int i;
char DIRp[200];
//
printf("������� ��� �������� (������ D:/) ");
    if (fgets(DIRp, 40, stdin))
    {
        DIRp[strcspn(DIRp, "\n")] = 0;
        printf("%39s\n", DIRp);
    }
dp = opendir (DIRp);
//
if (dp != NULL)
 {
   while (ep = readdir (dp))
   {
   puts (ep->d_name);   //��������� ������
   long int res = refindSize(ep->d_name);
 if (res != -1) {razmer += res; printf("AAAAAAAAAAAAAAAAAAAAAAAA");}
   }
   (void) closedir (dp);
 }
else
 {perror ("��� ����� �����������");}
//

//
printf("��� %d",razmer);
return 0;
 }

long int refindSize(char* filename[])  //�� ��������� ���� ������� �� �������� �� ���������� �� ������ ��������
{
int pop = strlen(filename); // ��������
    printf("�������: %39s  %d \n", filename, pop);  // ��������� ������
    FILE* fp = fopen(filename, "r");
    fseek(fp, 0L, SEEK_END);
      long int res = ftell(fp);
      fclose(fp);
    return res;
}
