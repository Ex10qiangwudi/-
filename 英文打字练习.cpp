#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void input(char *txt)
{
	FILE *fp;
	int i,T=0,a=3;//a是倒计时变量，T是正确字符个数
	char str[101];
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);//字体变色
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
	printf("\n\n用时：%d秒\n正确率：%.2lf\n\n\n",end-start,(double)T/100);
	system("pause");
}
void article_generated(char *txt)//文章生成并写入文件函数
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
		a=rand()%8+2;//a代表随机生成的单词的字母个数
		d += a;//d和i都是记录字符个数的变量
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
void menu()//菜单
{
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t****************************\n");
	printf("\t\t\t\t                * 欢迎使用英文打字练习程序 *\n\n");
	printf("\t\t\t\t                *      按enter开始练习     *\n");
	printf("\t\t\t\t\t\t****************************\n\n");
}
void perform()//执行程序
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
			printf("温馨提示：在倒计时结束后开始输入，输入正确的字符是白色的，错误的字符是红色的\n\n\n");
			memset(txt,0,101);
			article_generated(txt);
			input(txt);
			printf("继续请按任意键，结束请按Ese\n");
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