#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void input(char *txt)
{
	FILE *fp;
	int i,T=0,a=3;//a�ǵ���ʱ������T����ȷ�ַ�����
	char str[101];
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);//�����ɫ
	time_t start,end;
	memset(str,0,100);
	if((fp=fopen("input.txt","a+"))==NULL)
	{
		printf("Can not open file input.txt.\n");
		return;
	}
	printf("\n");
	while(a>=0)
	{
		printf("%d\n",a);
		Sleep(1000);
		a-=1;
	}
	start=time(NULL);
	for(i=0;i<100;i++)
	{
		str[i]=getch();
		if(str[i]==txt[i])
		{
			SetConsoleTextAttribute(hConsole,7);
			printf("%c",str[i]);
			T++;
		}
		else
		{
			SetConsoleTextAttribute(hConsole,4);
			printf("%c",str[i]);
		}
	}
	end=time(NULL);
	str[i]=0;
	fprintf(fp,"%s\n\n",str);
	fclose(fp);
	SetConsoleTextAttribute(hConsole,7);
	printf("\n\n��ʱ��%d��\n��ȷ�ʣ�%.2lf\n\n\n",end-start,(double)T/100);
	system("pause");
}
void article_generated(char *txt)//�������ɲ�д���ļ�����
{
	FILE *fp;
	int a,d=0,i=0;
	if((fp=fopen("article.txt","a+"))==NULL)
	{
		printf("Can not open file article.txt.\n");
		return;
	}
	srand(time(NULL));
	while(i<100)
	{
		a=rand()%8+2;//a����������ɵĵ��ʵ���ĸ����
		d += a;//d��i���Ǽ�¼�ַ������ı���
		txt[i++]=rand()%26+'A';
		for(i;i<d;i++)
			txt[i]=rand()%26+'a';
		txt[i++]=' ';
		d++;
	}
	txt[i]=0;
	printf("%s\n",txt);
	fprintf(fp,"%s\n\n",txt);
	fclose(fp);
}
void menu()//�˵�
{
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t****************************\n");
	printf("\t\t\t\t                * ��ӭʹ��Ӣ�Ĵ�����ϰ���� *\n\n");
	printf("\t\t\t\t                *      ��enter��ʼ��ϰ     *\n");
	printf("\t\t\t\t\t\t****************************\n\n");
}
void perform()//ִ�г���
{
	char str,ch,txt[101];
	menu();
	str=getchar();
	if(str=='\n')
	{	
		do
		{
			system("cls");
			printf("**********************************************************************************************************************\n");
			printf("��ܰ��ʾ���ڵ���ʱ������ʼ���룬������ȷ���ַ��ǰ�ɫ�ģ�������ַ��Ǻ�ɫ��\n\n\n");
			memset(txt,0,101);
			article_generated(txt);
			input(txt);
			printf("�����밴������������밴Ese\n");
			fflush(stdin);
			ch=getch();
			if(ch==27)
				break;
		}while(1);
	}
}
void main()
{
	perform();
}