#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void scoring(int score,int n)//ͳ�Ʒ������������
{
	printf("��������%d\n��ȷ��%d��\n����%d��\n��ȷ�ʣ�%.2lf\n",n,score,n-score,(double)score/(double)n);
	if((double)score>=(double)n*0.8)
		printf("��������������,���������\n");
	else if((double)score>=(double)n*0.6)
		printf("�����������ã������Ŭ��\n");
	else if((double)score<(double)n*0.6)
		printf("���������ϲ�벻Ҫ����\n");
	system("pause");
}

int multiply(int n)//�˷�
{
	int a,b,k;
	srand(time(NULL));
	a=rand()%100;//���µ�if-else��Ϊ�˱�֤����������˵Ľ��������100
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
		printf("�ش���ȷ\n");
		return n+1;
	}
	else
	{
		printf("�ش����,��ȷ��Ϊ��%d\n",a*b);
		return n;
	}
}
int divide(int n)//����
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
	printf("%d �� %d =",a,b);
	scanf("%d",&k);
	if(k==a/b)
	{
		printf("�ش���ȷ\n");
		return n+1;
	}
	else
	{
		printf("�ش����,��ȷ��Ϊ��%d\n",a*b);
		return n;
	}
}
void multiply_divide()//�˷�����
{
	int i,n,score=0,j;
	char str[2]={'*','/'};
	srand(time(NULL));
	printf("�������Ҫ��ϰ������(ע������������100)��");
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

void generate(int *a,int *b,int *c,int *score)//�Ӽ�����Ŀ���������
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
		printf("�ش���ȷ\n");
		*score += 1;
	}
	else
		printf("�ش����,��ȷ����%d\n",m);
}
void add_subtract()//�Ӽ���
{
	int a,b,c,n,i,score=0;
	printf("�������Ҫ��ϰ������(ע������������100)��");
	scanf("%d",&n);	
	for(i=1;i<=n;i++)
	{
		generate(&a,&b,&c,&score);
	}
	scoring(score,n);
}

void menu()//�˵���
{
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);//�����ɫ
	SetConsoleTextAttribute(hConsole,12);
	printf("\n\n\n\n\n\n\n\n");
	printf("                                               ��ӭʹ��Сѧ���Ӽ��˳���ϰ��\n");
	printf("\n\n");
	printf("                                                        1���˳���ϰ\n");
	printf("\n\n");
	printf("                                                        2���Ӽ���ϰ\n");
	printf("\n\n");
	printf("                                                      Esc���˳�����\n");
	printf("\n\n");
}

void perform()//��ʼʹ�ó���
{
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);//�����ɫ
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
			printf("                                                    ��лʹ�ã�����\n");
			break;
		}
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("                            ������ʾ���������ͳ�Ʒ����Ĺ���Ϊÿ��1�֣��û��ɸ����Լ�����������������ʼ����\n");
		printf("\n\n\n");
		printf("                                               ����enter����ϰ��ʽ��ʼ\n");
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