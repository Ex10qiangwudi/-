#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

struct magazine_information//杂志信息
{
	char name[20];//杂志名称
	char no[10];//杂志编号
	double price;//杂志价格
	char type[10];//杂志类型
	magazine_information *next;
};

struct magazine_subscribe//杂志订阅信息
{
	char name[20];//客户订阅的杂志名称
	char no[10];//客户编号
	double total_amount;//订阅总金额
	magazine_subscribe *next;
};

struct customer_information//客户信息
{
	char name[20];//客户姓名
	char no[10];//客户编号
	char magazine[200];//客户订阅的杂志名称
	customer_information *next;
};

struct administrator//管理员用户名及密码
{
	char account[15];//管理员账号
	char password[20];//管理员密码
	char name[20];//管理员姓名
	char no[10];//管理员工号
	administrator *next;
};

	void registered_boss()//总管理员注册
{
	FILE *fp;
	administrator *p=NULL;
	int i;
	if((fp=fopen("administrator.txt","a+"))==NULL)
	{
		printf("Can not open file administrator.txt.\n");
		return;
	}
	p=(administrator *)malloc(sizeof(administrator));
	memset(p,0,sizeof(administrator));
	printf("请输入用户名账号（以字母或下划线开头，15个字符以内）：");
	gets(p->account);
	fflush(stdin);
	printf("请输入密码（6个字符以上，20个字符以内）：");
	for(i=0;i<20;i++)
		{
			p->password[i]=getch();
			if(p->password[i]=='\r')
				break;
			printf("*");
		}
	p->password[i]=0;
	fflush(stdin);
	printf("\n请输入管理员姓名：");
	gets(p->name);
	fflush(stdin);
	printf("请输入管理员工号：");
	gets(p->no);
	fwrite(p,sizeof(administrator),1,fp);
	fclose(fp);
	free(p);	
}
void registered(administrator *head)//管理员注册
{
	FILE *fp;
	administrator *p=NULL,*tail=head;
	int flag=1,i;
	if((fp=fopen("administrator.txt","r"))==NULL)
	{
		printf("Can not open file administrator.txt.\n");
		return;
	}
	while(1)
	{
		p=(administrator *)malloc(sizeof(administrator));
		memset(p,0,sizeof(administrator));
		if(fread(p,sizeof(administrator),1,fp)==0)
		{
			free(p);
			break;
		}
		tail->next=p;
		tail=p;
	}
	fclose(fp);
	if((fp=fopen("administrator.txt","a+"))==NULL)
	{
		printf("Can not open file administrator.txt.\n");
		return;
	}
	p=(administrator *)malloc(sizeof(administrator));
	memset(p,0,sizeof(administrator));
	while(1)
	{
		printf("请输入用户名账号（以字母或下划线开头，15个字符以内）：");
		gets(p->account);
		fflush(stdin);
		printf("请输入密码（6个字符以上，20个字符以内）：");
		for(i=0;i<20;i++)
		{
			p->password[i]=getch();
			if(p->password[i]=='\r')
				break;
			printf("*");
		}
		p->password[i]=0;
		fflush(stdin);
		printf("\n请输入管理员姓名：");
		gets(p->name);
		fflush(stdin);
		printf("请输入管理员工号：");
		gets(p->no);
		tail=head->next;
		while(tail!=NULL)
		{
			if(strcmp(p->account,tail->account)==0)	
			{
				flag=0;
				printf("此用户名以被注册\n");
				break;
			}
			tail=tail->next;
		}
		if(flag)
			break;
	}
	printf("注册成功，请牢记您的账号和密码\n");
	fwrite(p,sizeof(administrator),1,fp);
	fclose(fp);
	free(p);
}

void Modify_password(administrator *head)//管理员密码修改
{
	FILE *fp;
	administrator *p=NULL,*tail=head;
	char account[15],password[20],password_second[20];
	int i;
	if((fp=fopen("administrator.txt","r"))==NULL)
	{
		printf("Can not open file administrator.txt.\n");
		return;
	}
	while(1)
	{
		p=(administrator *)malloc(sizeof(administrator));
		memset(p,0,sizeof(administrator));
		if(fread(p,sizeof(administrator),1,fp)==0)
		{
			free(p);
			break;
		}
		tail->next=p;
		tail=p;
	}
	fclose(fp);
	do
	{
		tail=head->next;
		memset(account,0,15);
		printf("请输入要修改密码的账号：");
		gets(account);
		fflush(stdin);
		while(tail!=NULL)
		{
			if(strcmp(tail->account,account)==0)
				break;
			tail=tail->next;
		}
		if(tail!=NULL)
			break;
		else
		{
			printf("无此账号，请检查您的账号是否正确。\n");
			continue;
		}

	}while(1);
	if(tail!=NULL)
	{
		do
		{
			memset(password,0,20);
			printf("请输入初始密码：");
			for(i=0;i<20;i++)
			{
				password[i]=getch();
				if(password[i]=='\r')
					break;
				printf("*");
			}
			password[i]=0;
			fflush(stdin);
			if(strcmp(tail->password,password)==0)
				break;
			else
			{
				printf("初始密码不正确，请重新输入。\n");
				continue;
			}

		}while(1);
		printf("\n");
		do
		{
			memset(password,0,20);
			printf("请输入新密码：");
			for(i=0;i<20;i++)
			{
				password[i]=getch();
				if(password[i]=='\r')
					break;
				printf("*");
			}
			password[i]=0;
			fflush(stdin);
			memset(password_second,0,20);
			printf("\n");
			printf("请再次输入新密码：");
			for(i=0;i<20;i++)
			{
				password_second[i]=getch();
				if(password_second[i]=='\r')
					break;
				printf("*");
			}
			password_second[i]=0;
			fflush(stdin);
			if(strcmp(password_second,password)==0)
				break;
			else
			{
				printf("两次输入的密码不相同，请重新输入新密码。");
				continue;
			}
		}while(1);
		memset(tail->password,0,20);
		strcpy(tail->password,password_second);
		printf("\n修改成功。\n");
	}
	if((fp=fopen("administrator.txt","w+"))==NULL)
	{
		printf("Can not open file administrator.txt.\n");
		return;
	}
	tail=head->next;
	while(tail!=NULL)
	{
		fwrite(tail,sizeof(administrator),1,fp);
		tail=tail->next;
	}
	fclose(fp);
}

void magazine_input()//杂志信息输入
{
	FILE *fp;
	magazine_information *p=NULL;
	if((fp=fopen("magazine_information.txt","a+"))==NULL)
	{
		printf("Can not open file magazine_information.txt.\n");
		return;
	}
	do
	{
		printf("注：输入结束请在杂志编号时输入out\n");
		p=(magazine_information *)malloc(sizeof(magazine_information));
		memset(p,0,sizeof(magazine_information));
		printf("请输入杂志编号：");
		scanf("%s",p->no);
		if(strcmp(p->no,"out")==0)
		{
			free(p);
			break;
		}
		fflush(stdin);
		printf("请输入杂志名称：");
		scanf("%s",p->name);
		fflush(stdin);
		printf("请输入杂志类型：");
		scanf("%s",p->type);
		printf("请输入杂志价格：");
		scanf("%lf",&p->price);
		fwrite(p,sizeof(magazine_information),1,fp);
	}while(1);
	fclose(fp);
}

void customer_input()//客户信息输入
{
	FILE *fp;
	customer_information *p=NULL;
	char ch='\n';
	if((fp=fopen("customer_information.txt","a+"))==NULL)
	{
		printf("Can not open file customer_information.txt.\n");
		return;
	}
	do
	{
		printf("注：输入结束请在客户编号时输入out\n");
		p=(customer_information *)malloc(sizeof(customer_information));
		memset(p,0,sizeof(customer_information));
		printf("请输入客户编号：");
		scanf("%s",p->no);
		if(strcmp(p->no,"out")==0)
		{
			free(p);
			break;
		}
		fflush(stdin);
		printf("请输入客户姓名：");
		scanf("%s",p->name);
		fflush(stdin);
		printf("请输入客户订阅的杂志名称（若客户订阅了多本杂志，杂志名称直接用“，”或“ ”隔开）：");
		scanf("%s",p->magazine);
		fwrite(p,sizeof(customer_information),1,fp);
		fprintf(fp,"%c",ch);
	}while(1);
	fclose(fp);
}

void magazine_modify(magazine_information *head)//杂志信息修改
{
	FILE *fp;
	magazine_information *p=NULL,*tail=head;
	char name[20],no[10],type[10],Q;
	if((fp=fopen("magazine_information.txt","r"))==NULL)
	{
		printf("Can not open file magazine_information.txt.\n");
		return;
	}
	while(1)
	{
		p=(magazine_information *)malloc(sizeof(magazine_information));
		memset(p,0,sizeof(magazine_information));
		if(fread(p,sizeof(magazine_information),1,fp)==0)
		{
			free(p);
			break;
		}
		tail->next=p;
		tail=p;
	}
	fclose(fp);
	do
	{
		tail=head->next;
		memset(name,0,20);
		printf("请输入要修改的杂志名称：");
		gets(name);
		fflush(stdin);
		while(tail!=NULL)
		{
			if(strcmp(tail->name,name)==0)
				break;
			tail=tail->next;
		}
		if(tail!=NULL)
			break;
		else
		{
			printf("库中无此杂志，请检查杂志名称是否正确。\n");
			continue;
		}
	}while(1);
	do
	{
		printf("1.修改杂志编号\n2.修改杂志类型\n3.修改杂志价格\nEsc.结束修改\n");
		Q=getch();
		fflush(stdin);
		if(Q==27)
			break;
		switch(Q)
		{
			case '1':
				printf("请输入新的编号：");
				memset(no,0,10);
				gets(no);
				strcpy(tail->no,no);
				printf("修改成功。\n");
				break;
			case '2':
				printf("请输入新的类型：");
				memset(type,0,10);
				gets(type);
				strcpy(tail->type,type);
				printf("修改成功。\n");
				break;
			case '3':
				printf("请输入新的价格：");
				scanf("%lf",&tail->price);
				printf("修改成功。\n");
				break;
		}
	}while(1);
	if((fp=fopen("magazine_information.txt","w+"))==NULL)
	{
		printf("Can not open file magazine_information.txt.\n");
		return;
	}
	tail=head->next;
	while(tail!=NULL)
	{
		fwrite(p,sizeof(magazine_information),1,fp);
		tail=tail->next;
	}
	fclose(fp);
}

void customer_refer1(magazine_information *head)//客户查阅总的杂志信息
{
	FILE *fp;
	magazine_information *p=NULL,*tail=head;
	if((fp=fopen("magazine_information.txt","r"))==NULL)
	{
		printf("Can not open file magazine_information.txt.\n");
		return;
	}
	while(1)
	{
		p=(magazine_information *)malloc(sizeof(magazine_information));
		memset(p,0,sizeof(magazine_information));
		if(fread(p,sizeof(magazine_information),1,fp)==0)
		{
			free(p);
			break;
		}
		tail->next=p;
		tail=p;
	}
	tail=head->next;
	printf("杂志编号\t杂志名称\t杂志类型\t杂志价格\n");
	while(tail!=NULL)
	{
		printf("%s\t\t%s\t\t%s\t\t%.2lf\n",tail->no,tail->name,tail->type,tail->price);
		tail=tail->next;
	}
	fclose(fp);
	system("pause");
}

void customer_refer2(magazine_information *head)//客户用关键词查阅杂志信息
{
	FILE *fp;
	magazine_information *p=NULL,*tail=head;
	char name[20],no[10],type[10];
	int Q;
	if((fp=fopen("magazine_information.txt","r"))==NULL)
	{
		printf("Can not open file magazine_information.txt.\n");
		return;
	}
	while(1)
	{
		p=(magazine_information *)malloc(sizeof(magazine_information));
		memset(p,0,sizeof(magazine_information));
		if(fread(p,sizeof(magazine_information),1,fp)==0)
		{
			free(p);
			break;
		}
		tail->next=p;
		tail=p;
	}
	do
	{
		system("cls");
		tail=head->next;
		printf("1.用杂志编号查找\n2.用杂志名称查找\n3.用杂志类型查找\nEsc.退出查找\n");
		Q=getch();
		if(Q==27)
			break;
		fflush(stdin);
		switch(Q)
		{
			case '1':
				memset(no,0,10);
				printf("请输入杂志编号：");
				gets(no);
				printf("杂志编号\t杂志名称\t杂志类型\t杂志价格\n");
				while(tail!=NULL)
				{
					if(strcmp(tail->no,no)==0)
						printf("%s\t\t%s\t\t%s\t\t%.2lf\n",tail->no,tail->name,tail->type,tail->price);
					tail=tail->next;
				}
				system("pause");
				break;
			case '2':
				memset(name,0,20);
				printf("请输入杂志名称：");
				gets(name);
				printf("杂志编号\t杂志名称\t杂志类型\t杂志价格\n");
				while(tail!=NULL)
				{
					if(strcmp(tail->name,name)==0)
						printf("%s\t\t%s\t\t%s\t\t%.2lf\n",tail->no,tail->name,tail->type,tail->price);
					tail=tail->next;
				}
				system("pause");
				break;
			case '3':
				memset(type,0,10);
				printf("请输入杂志类型：");
				gets(type);
				printf("杂志编号\t杂志名称\t杂志类型\t杂志价格\n");
				while(tail!=NULL)
				{
					if(strcmp(tail->type,type)==0)
						printf("%s\t\t%s\t\t%s\t\t%.2lf\n",tail->no,tail->name,tail->type,tail->price);
					tail=tail->next;
				}
				system("pause");
				break;
		}
	}while(1);
	fclose(fp);
}

void customer_modify(customer_information *head)//客户信息修改
{
	FILE *fp;
	customer_information *p=NULL,*tail=head;
	char no[10],magazine[200];
	if((fp=fopen("customer_information.txt","r"))==NULL)
	{
		printf("Can not open file customer_information.txt.\n");
		return;
	}
	while(1)
	{
		p=(customer_information *)malloc(sizeof(customer_information));
		memset(p,0,sizeof(customer_information));
		if(fread(p,sizeof(customer_information),1,fp)==0)
		{
			free(p);
			break;
		}
		tail->next=p;
		tail=p;
	}
	fclose(fp);
	do
	{
		tail=head->next;
		memset(no,0,10);
		printf("请输入要修改的客户的编号：");
		gets(no);
		fflush(stdin);
		while(tail!=NULL)
		{
			if(strcmp(tail->no,no)==0)
				break;
			tail=tail->next;
		}
		if(tail!=NULL)
			break;
		else
		{
			printf("客户信息库中无此人,请检查输入的编号是否正确。\n");
			continue;
		}
	}while(1);
	printf("请输入客户新的杂志订阅信息：");
	memset(magazine,0,200);
	gets(magazine);
	strcpy(tail->magazine,magazine);
	printf("修改成功。\n");
	if((fp=fopen("customer_information.txt","w+"))==NULL)
	{
		printf("Can not open file customer_information.txt.\n");
		return;
	}
	tail=head->next;
	while(tail!=NULL)
	{
		fwrite(p,sizeof(customer_information),1,fp);
		tail=tail->next;
	}
	fclose(fp);
}

void customer_infor_refer(customer_information *head)
{
	FILE *fp;
	customer_information *p=NULL,*tail=head;
	char no[10];
	if((fp=fopen("customer_information.txt","r"))==NULL)
	{
		printf("Can not open file customer_information.txt.\n");
		return;
	}
	while(1)
	{
		p=(customer_information *)malloc(sizeof(customer_information));
		memset(p,0,sizeof(customer_information));
		if(fread(p,sizeof(customer_information),1,fp)==0)
		{
			free(p);
			break;
		}
		tail->next=p;
		tail=p;
	}
	fclose(fp);
	tail=head->next;
	printf("请输入要查找的客户编号：");
	memset(no,0,10);
	gets(no);
	printf("客户编号\t\t客户姓名\t\t客户订阅的杂志名称\n");
	while(tail!=NULL)
	{
		if(strcmp(tail->no,no)==0)
			printf("%s\t%s\t%s\n",tail->no,tail->name,tail->magazine);
		tail=tail->next;
	}
}

void subscribe_input()//杂志订阅信息输入
{
	FILE *fp;
	magazine_subscribe *p=NULL;
	char ch='\n';
	if((fp=fopen("magazine_subscribe.txt","a+"))==NULL)
	{
		printf("Can not open file magazine_subscribe.txt.\n");
		return;
	}
	do
	{
		printf("输入结束请在输入客户编号时输入out\n");
		p=(magazine_subscribe *)malloc(sizeof(magazine_subscribe));
		memset(p,0,sizeof(magazine_subscribe));
		printf("请输入客户编号：");
		fflush(stdin);
		gets(p->no);
		if(strcmp(p->no,"out")==0)
		{
			free(p);
			break;
		}
		fflush(stdin);
		printf("请输入客户订阅的杂志名称：");
		gets(p->name);
		printf("请输入客户订阅的总金额：");
		scanf("%lf",&p->total_amount);
		fwrite(p,sizeof(magazine_subscribe),1,fp);
		fprintf(fp,"%c",ch);
	}while(1);
	fclose(fp);
}

void subscribe_modify(magazine_subscribe *head)//杂志订阅信息修改
{
	FILE *fp;
	magazine_subscribe *p=NULL,*tail=head;
	char no[10],name[20];
	int Q;
	if((fp=fopen("magazine_subscribe.txt","r"))==NULL)
	{
		printf("Can not open file magazine_subscribe.txt.\n");
		return;
	}
	while(1)
	{
		p=(magazine_subscribe *)malloc(sizeof(magazine_subscribe));
		memset(p,0,sizeof(magazine_subscribe));
		if(fread(p,sizeof(magazine_subscribe),1,fp)==0)
		{
			free(p);
			break;
		}
		tail->next=p;
		tail=p;
	}
	fclose(fp);
	do
	{
		tail=head->next;
		printf("1.修改客户编号\n2.修改客户订阅的杂志名称\nEsc.退出修改\n请选择执行命令：");
		Q=getch();
		if(Q==27)
			break;
		switch(Q)
		{
			case '1':
				do
				{
					tail=head->next;
					memset(no,0,10);
					printf("请输入要修改的客户编号：");
					gets(no);
					fflush(stdin);
					while(tail!=NULL)
					{
						if(strcmp(tail->no,no)==0)
							break;
						tail=tail->next;
					}
					if(tail!=NULL)
						break;
					else
					{
						printf("杂志订阅信息库中无此客户编号，请检查是否输入正确并重新输入。\n");
						continue;
					}
				}while(1);
				memset(no,0,10);
				printf("请输入新的客户编号：");
				gets(no);
				strcpy(tail->no,no);
				break;
			case '2':
				do
				{
					tail=head->next;
					memset(name,0,20);
					printf("请输入要修改的客户订阅的杂志名称：");
					gets(name);
					fflush(stdin);
					while(tail!=NULL)
					{
						if(strcmp(tail->name,name)==0)
							break;
						tail=tail->next;
					}
					if(tail!=NULL)
						break;
					else
					{
						printf("杂志订阅信息库中无此客户编号，请检查是否输入正确并重新输入。\n");
						continue;
					}
				}while(1);
				memset(name,0,20);
				printf("请输入新的客户订阅的杂志名称：");
				gets(name);
				strcpy(tail->name,name);
				printf("请输入新的订阅总金额：");
				scanf("%lf",&tail->total_amount);
				break;	
		}
	}while(1);
	if((fp=fopen("magazine_subscribe.txt","w+"))==NULL)
	{
		printf("Can not open file magazine_subscribe.txt.\n");
		return;
	}
	tail=head->next;
	while(tail!=NULL);
		fprintf(fp,"%s\t%s\t%.2lf\n",tail->no,tail->name,tail->total_amount);
	fclose(fp);
}

void subscribe_infor_refer(magazine_subscribe *head)//订阅信息查询
{
	FILE *fp;
	magazine_subscribe *p=NULL,*tail=head;
	char no[10];
	if((fp=fopen("magazine_subscribe.txt","r"))==NULL)
	{
		printf("Can not open file magazine_subscribe.txt.\n");
		return;
	}
	while(1)
	{
		p=(magazine_subscribe *)malloc(sizeof(magazine_subscribe));
		memset(p,0,sizeof(magazine_subscribe));
		if(fread(p,sizeof(magazine_subscribe),1,fp)==0)
		{
			free(p);
			break;
		}
		tail->next=p;
		tail=p;
	}
	fclose(fp);	
	printf("请输入要查询的客户编号：");
	memset(no,0,10);
	gets(no);
	tail=head->next;
	printf("客户编号\t客户订阅的杂志名称\t订阅总金额\n");
	while(tail!=NULL)
	{
		if(strcmp(tail->no,no)==0)
			printf("%s\t%s\t%.2lf\n",tail->no,tail->name,tail->total_amount);
		tail=tail->next;
	}
}

void login_boss(administrator *head)//总管理员登录
{
	FILE *fp;
	administrator *p=NULL,*tail=head;
	char account[15],password[20];
	int i;
	if((fp=fopen("administrator.txt","r"))==NULL)
	{
		printf("Can not open file administrator.txt.\n");
		return;
	}
	while(1)
	{
		p=(administrator *)malloc(sizeof(administrator));
		memset(p,0,sizeof(administrator));
		if(fread(p,sizeof(administrator),1,fp)==0)
		{
			free(p);
			break;
		}
		tail->next=p;
		tail=p;
	}
	fclose(fp);
	do
	{
		tail=head->next;
		memset(account,0,15);
		memset(password,0,20);
		printf("请输入账号：");
		gets(account);
		fflush(stdin);
		printf("请输入密码：");
		for(i=0;i<20;i++)
		{
			password[i]=getch();
			if(password[i]=='\r')
				break;
			printf("*");
		}
		password[i]=0;
		fflush(stdin);
		if(strcmp(account,tail->account)!=0)
		{
			printf("账号输入错误\n");
			continue;
		}
		else if(strcmp(password,tail->password)==0)
			break;
		else
			printf("\n密码输入错误\n");
	}while(1);
	printf("\n欢迎您，总管理员\n");
}

void login(administrator *head)//管理员登录
{
	FILE *fp;
	administrator *p=NULL,*tail=head;
	char account[15],password[20];
	int i;
	if((fp=fopen("administrator.txt","r"))==NULL)
	{
		printf("Can not open file administrator.txt.\n");
		return;
	}
	while(1)
	{
		p=(administrator *)malloc(sizeof(administrator));
		memset(p,0,sizeof(administrator));
		if(fread(p,sizeof(administrator),1,fp)==0)
		{
			free(p);
			break;
		}
		tail->next=p;
		tail=p;
	}
	fclose(fp);
	do
	{
		tail=head->next;
		memset(account,0,15);
		memset(password,0,20);
		printf("请输入账号：");
		gets(account);
		fflush(stdin);
		printf("请输入密码：");
		for(i=0;i<20;i++)
		{
			password[i]=getch();
			if(password[i]=='\r')
				break;
			printf("*");
		}
		password[i]=0;
		printf("\n");
		fflush(stdin);
		while(tail!=NULL)
		{
			if(strcmp(tail->account,account)==0)
				break;
			tail=tail->next;
		}
		if(tail==NULL)
		{
			printf("\n账号输入错误。\n");
			continue;
		}
		if(strcmp(tail->password,password)==0)
		{
			printf("欢迎进入本管理系统。\n");
			break;
		}
		else
			printf("\n密码输入错误\n");
	}while(1);
}

void menu()//菜单界面
{
	printf("**********************************************************\n");
	printf("*               欢迎使用杂志订阅管理系统                 *\n");
	printf("*                     1.总管理员通道                     *\n");
	printf("*                     2.管理员通道                       *\n");
	printf("*                     3.客户通道                         *\n");
	printf("*                   Esc.退出系统                         *\n");
	printf("**********************************************************\n");
	printf("温馨提示：如果是第一次使用本系统，请先进入总管理员通道并注册一个总管理员账号，便于后续使用\n");
}

void magazine_management()//杂志管理
{
	char a;
	magazine_information *headmi=NULL;
	headmi=(magazine_information *)malloc(sizeof(magazine_information));
	memset(headmi,0,sizeof(magazine_information));
	do
	{
		printf("1.杂志信息输入\n2.杂志信息修改\n3.杂志信息查询\nEsc.退出\n");
		a=getch();
		if(a==27)
			break;
		switch(a)
		{
			case '1': magazine_input();	break;
			case '2': magazine_modify(headmi); break;
			case '3': customer_refer2(headmi); break;
		}
	}while(1);
	free(headmi);
}

void customer_management()//客户管理
{
	char a;
	customer_information *headc=NULL;
	headc=(customer_information *)malloc(sizeof(customer_information));
	memset(headc,0,sizeof(customer_information));
	do
	{
		printf("1.客户信息输入\n2.客户信息修改\n3.客户信息查询\nEsc.退出\n");
		a=getch();
		if(a==27)
			break;
		switch(a)
		{
			case '1': customer_input(); break;
			case '2': customer_modify(headc); break;
			case '3': customer_infor_refer(headc); break;
		}
	}while(1);
	free(headc);
}

void subscribe_management()//订阅管理
{
	char a;
	magazine_subscribe *headms=NULL;
	headms=(magazine_subscribe *)malloc(sizeof(magazine_subscribe));
	memset(headms,0,sizeof(magazine_subscribe));
	do
	{
		printf("1.订阅信息输入\n2.订阅信息修改\n3.订阅信息查询\nEsc.退出\n");
		a=getch();
		if(a==27)
			break;
		switch(a)
		{
			case '1': subscribe_input(); break;
			case '2': subscribe_modify(headms); break;
			case '3': subscribe_infor_refer(headms); break;
		}
	}while(1);
	free(headms);
}

void administrator_delete(administrator *head)//管理员删除
{
	FILE *fp;
	administrator *p=NULL,*q=NULL;
	char no[10],ch='\n';
	printf("请输入要删除的管理员工号：");
	gets(no);
	p=head;
	q=head->next;
	while(q!=NULL)
	{
		if(strcmp(no,q->no)==0)
		{
			p->next=q->next;
			free(q);
			break;
		}
		p=p->next;
		q=q->next;
	}
	printf("删除成功\n");
	p=head->next;
	if((fp=fopen("administrator.txt","w+"))==NULL)
	{
		printf("Can not open file administrator.txt.\n");
		return;
	}
	while(p!=NULL)
	{
		fwrite(p,sizeof(administrator),1,fp);
		fprintf(fp,"%c",ch);
		p=p->next;
	}
	fclose(fp);
}

void administrator_management()//管理员管理
{
	FILE *fp;
	administrator *heada=NULL,*p=NULL,*tail=NULL;
	char a;
	heada=(administrator *)malloc(sizeof(administrator));
	memset(heada,0,sizeof(administrator));
	if((fp=fopen("administrator.txt","r"))==NULL)
	{
		printf("Can not open file administrator.txt.\n");
		return;
	}
	tail=heada;
	while(1)
	{
		p=(administrator *)malloc(sizeof(administrator));
		memset(p,0,sizeof(administrator));
		if(fread(p,sizeof(administrator),1,fp)==0)
		{
			free(p);
			break;
		}
		tail->next=p;
		tail=p;
	}
	fclose(fp);
	do
	{
		printf("1.查看管理员信息\n2.删除管理员\nEsc.退出\n");
		a=getch();
		if(a==27)
			break;
		switch(a)
		{
			case '1':
				tail=heada->next;
				printf("工号\t姓名\t账号\t\t密码\n");
				while(tail!=NULL)
				{
					printf("%s\t%s\t%s\t%s\n",tail->no,tail->name,tail->account,tail->password);
					tail=tail->next;
				}
				break;
			case '2': administrator_delete(heada); break;
		}
	}while(1);
	free(heada);
}

void administrator_function()//管理员功能
{
	administrator *heada=NULL;
	char a,b;
	heada=(administrator *)malloc(sizeof(administrator));
	memset(heada,0,sizeof(administrator));
	do
	{
		system("cls");
		printf("欢迎进入管理员通道\n1.登录\n2.注册\nEsc.退出\n");
		a=getch();
		if(a==27)
			break;
		switch(a)
		{
			case '1':
				login(heada);				
				do
				{
					system("cls");
					printf("1.杂志信息管理\n2.客户信息管理\n3.订阅信息管理\n4.密码修改\nEsc.注销\n");
					b=getch();
					if(b==27)
						break;
					switch(b)
					{
						case '1':	magazine_management(); break;
						case '2': customer_management(); break;
						case '3': subscribe_management(); break;
						case '4': Modify_password(heada); break;
					}
					if(b=='4')
						break;
				}while(1);
				break;
			case '2': registered(heada); break;
		}
	}while(1);
	free(heada);
}

void administrator_boss()//总管理员功能
{
	administrator *heada=NULL;
	char a,b;
	heada=(administrator *)malloc(sizeof(administrator));
	memset(heada,0,sizeof(administrator));
	do
	{
		printf("欢迎进入总管理员通道\n1.登录\n2.注册\nEsc.退出\n");
		a=getch();
		if(a==27)
			break;
		switch(a)
		{
			case '1':
				login_boss(heada);
				do
				{
					printf("1.杂志信息管理\n2.客户信息管理\n3.订阅信息管理\n4.密码修改\n5.管理员管理\nEsc.注销\n");
					b=getch();
					if(b==27)
						break;
					switch(b)
					{
						case '1': magazine_management(); break;
						case '2': customer_management(); break;
						case '3': subscribe_management(); break;
						case '4': Modify_password(heada); break;
						case '5': administrator_management(); break;
					}
				}while(1);
				break;
			case '2': registered_boss(); break;
		}
		if(a=='2')
			break;
	}while(1);
	free(heada);		
}

void perform()//执行函数
{
	char Q,a;
	magazine_information *headmi=NULL;
	headmi=(magazine_information *)malloc(sizeof(magazine_information));
	memset(headmi,0,sizeof(magazine_information));
	do
	{
		system("cls");
		menu();
		Q=getch();
		if(Q==27)
			break;
		system("cls");
		switch(Q)
		{
			case '1':	administrator_boss(); break;
			case '2':	administrator_function(); break;
			case '3':
				do
				{
					system("cls");
					printf("1.杂志信息总查询\n2.杂志信息关键词查询\nEsc.退出\n");
					a=getch();
					if(a==27)
						break;
					switch(a)
					{
						case '1': customer_refer1(headmi); break;
						case '2': customer_refer2(headmi); break;
					}
				}while(1);
		}
	}while(1);
	free(headmi);
}

void main()
{
	perform();
}