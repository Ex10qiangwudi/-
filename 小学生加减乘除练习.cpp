#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void scoring(int score,int n)//统计分数及输出评语
{
	printf("总题数：%d\n正确：%d题\n错误：%d题\n正确率：%.2lf\n",n,score,n-score,(double)score/(double)n);
	if((double)score>=(double)n*0.8)
		printf("计算能力较优秀,请继续保持\n");
	else if((double)score>=(double)n*0.6)
		printf("计算能力良好，请继续努力\n");
	else if((double)score<(double)n*0.6)
		printf("计算能力较差，请不要气馁\n");
	system("pause");
}

int multiply(int n)//乘法
{
	int a,b,k;
	srand(time(NULL));
	a=rand()%100;//以下的if-else是为了保证这两个数相乘的结果不超过100
	if(a>50)
		b=1;
	else if(a>33)
		b=rand()%2;
	else if(a>25)
		b=rand()%3;
	else if(a>20)
		b=rand()%4;
	else if(a>16)
		b=rand()%5;
	else if(a>14)
		b=rand()%6;
	else if(a>12)
		b=rand()%7;
	else if(a=12)
		b=rand()%8;
	else if(a=11)
		b=rand()%9;
	else
		b=rand()%10;
	printf("%d x %d =",a,b);
	scanf("%d",&k);
	if(k==a*b)
	{
		printf("回答正确\n");
		return n+1;
	}
	else
	{
		printf("回答错误,正确答案为：%d\n",a*b);
		return n;
	}
}
int divide(int n)//除法
{
	int a,b,k;
	srand(time(NULL));
	while(1)
	{
		a=rand()%100;
		b=rand()%99+1;
		if(a%b==0)
			break;
	}
	printf("%d ÷ %d =",a,b);
	scanf("%d",&k);
	if(k==a/b)
	{
		printf("回答正确\n");
		return n+1;
	}
	else
	{
		printf("回答错误,正确答案为：%d\n",a*b);
		return n;
	}
}
void multiply_divide()//乘法除法
{
	int i,n,score=0,j;
	char str[2]={'*','/'};
	srand(time(NULL));
	printf("请输出您要练习的题数(注：题数不超过100)：");
	scanf("%d",&n);
	for(j=1;j<=n;j++)
	{
		i=rand()%1;
		switch(str[i])
		{
			case '*':	score=multiply(score); break;
			case '/':	score=divide(score); break;
		}
	}
	scoring(score,n);
}

void generate(int *a,int *b,int *c,int *score)//加减法题目生成与答题
{
	int i,n,m,k;
	char str[2]={'+','-'};
	srand(time(NULL));
	*a=rand()%100;
	i=rand()%1;
	while(1)
	{
		*b=rand()%100;
		if(str[i]=='+')
		{
			n=(*a)+(*b);
			if(n<=100)
			{
				printf("%d + %d",*a,*b);
				break;
			}
			else
				continue;
		}
		else
		{
			n=a-b;
			if(n>0)
			{
				printf("%d - %d",*a,*b);
				break;
			}
			else
				continue;
		}
	}
	i=rand()%1;
	while(1)
	{
		*c=rand()%100;
		if(str[i]=='+')
		{
			m=n+(*c);
			if(m<=100)
			{
				printf(" + %d =",*c);
				break;
			}
			else
				continue;
		}
		else
		{
			m=n-(*c);
			if(n>0)
			{
				printf(" - %d =",*c);
				break;
			}
			else
				continue;
		}
	}
	scanf("%d",&k);
	if(k==m)
	{
		printf("回答正确\n");
		*score += 1;
	}
	else
		printf("回答错误,正确答案是%d\n",m);
}
void add_subtract()//加减法
{
	int a,b,c,n,i,score=0;
	printf("请输出您要练习的题数(注：题数不超过100)：");
	scanf("%d",&n);	
	for(i=1;i<=n;i++)
	{
		generate(&a,&b,&c,&score);
	}
	scoring(score,n);
}

void menu()//菜单栏
{
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);//字体变色
	SetConsoleTextAttribute(hConsole,12);
	printf("\n\n\n\n\n\n\n\n");
	printf("                                               欢迎使用小学生加减乘除练习器\n");
	printf("\n\n");
	printf("                                                        1、乘除练习\n");
	printf("\n\n");
	printf("                                                        2、加减练习\n");
	printf("\n\n");
	printf("                                                      Esc、退出程序\n");
	printf("\n\n");
}

void perform()//开始使用程序
{
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);//字体变色
	char str,ch;
	do
	{
		menu();
		ch=getch();
		fflush(stdin);
		system("cls");
		if(ch==27)
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                    感谢使用！！！\n");
			break;
		}
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("                            友情提示：本程序的统计分数的规则为每题1分，用户可根据自己的需求输入题数后开始答题\n");
		printf("\n\n\n");
		printf("                                               按下enter后练习正式开始\n");
		str=getchar();
		if(str=='\n')
			system("cls");
		SetConsoleTextAttribute(hConsole,15);
		switch(ch)
		{
			case '1': multiply_divide(); break;
			case '2': add_subtract(); break;
			case 27: break;
		}
		system("cls");
	}while(1);
}

void main()
{
	perform();
}