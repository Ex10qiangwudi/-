#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

struct magazine_information//��־��Ϣ
{
	char name[20];//��־����
	char no[10];//��־���
	double price;//��־�۸�
	char type[10];//��־����
	magazine_information *next;
};

struct magazine_subscribe//��־������Ϣ
{
	char name[20];//�ͻ����ĵ���־����
	char no[10];//�ͻ����
	double total_amount;//�����ܽ��
	magazine_subscribe *next;
};

struct customer_information//�ͻ���Ϣ
{
	char name[20];//�ͻ�����
	char no[10];//�ͻ����
	char magazine[200];//�ͻ����ĵ���־����
	customer_information *next;
};

struct administrator//����Ա�û���������
{
	char account[15];//����Ա�˺�
	char password[20];//����Ա����
	char name[20];//����Ա����
	char no[10];//����Ա����
	administrator *next;
};

	void registered_boss()//�ܹ���Աע��
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
	printf("�������û����˺ţ�����ĸ���»��߿�ͷ��15���ַ����ڣ���");
	gets(p->account);
	fflush(stdin);
	printf("���������루6���ַ����ϣ�20���ַ����ڣ���");
	for(i=0;i<20;i++)
		{
			p->password[i]=getch();
			if(p->password[i]=='\r')
				break;
			printf("*");
		}
	p->password[i]=0;
	fflush(stdin);
	printf("\n���������Ա������");
	gets(p->name);
	fflush(stdin);
	printf("���������Ա���ţ�");
	gets(p->no);
	fwrite(p,sizeof(administrator),1,fp);
	fclose(fp);
	free(p);	
}
void registered(administrator *head)//����Աע��
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
		printf("�������û����˺ţ�����ĸ���»��߿�ͷ��15���ַ����ڣ���");
		gets(p->account);
		fflush(stdin);
		printf("���������루6���ַ����ϣ�20���ַ����ڣ���");
		for(i=0;i<20;i++)
		{
			p->password[i]=getch();
			if(p->password[i]=='\r')
				break;
			printf("*");
		}
		p->password[i]=0;
		fflush(stdin);
		printf("\n���������Ա������");
		gets(p->name);
		fflush(stdin);
		printf("���������Ա���ţ�");
		gets(p->no);
		tail=head->next;
		while(tail!=NULL)
		{
			if(strcmp(p->account,tail->account)==0)	
			{
				flag=0;
				printf("���û����Ա�ע��\n");
				break;
			}
			tail=tail->next;
		}
		if(flag)
			break;
	}
	printf("ע��ɹ������μ������˺ź�����\n");
	fwrite(p,sizeof(administrator),1,fp);
	fclose(fp);
	free(p);
}

void Modify_password(administrator *head)//����Ա�����޸�
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
		printf("������Ҫ�޸�������˺ţ�");
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
			printf("�޴��˺ţ����������˺��Ƿ���ȷ��\n");
			continue;
		}

	}while(1);
	if(tail!=NULL)
	{
		do
		{
			memset(password,0,20);
			printf("�������ʼ���룺");
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
				printf("��ʼ���벻��ȷ�����������롣\n");
				continue;
			}

		}while(1);
		printf("\n");
		do
		{
			memset(password,0,20);
			printf("�����������룺");
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
			printf("���ٴ����������룺");
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
				printf("������������벻��ͬ�����������������롣");
				continue;
			}
		}while(1);
		memset(tail->password,0,20);
		strcpy(tail->password,password_second);
		printf("\n�޸ĳɹ���\n");
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

void magazine_input()//��־��Ϣ����
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
		printf("ע���������������־���ʱ����out\n");
		p=(magazine_information *)malloc(sizeof(magazine_information));
		memset(p,0,sizeof(magazine_information));
		printf("��������־��ţ�");
		scanf("%s",p->no);
		if(strcmp(p->no,"out")==0)
		{
			free(p);
			break;
		}
		fflush(stdin);
		printf("��������־���ƣ�");
		scanf("%s",p->name);
		fflush(stdin);
		printf("��������־���ͣ�");
		scanf("%s",p->type);
		printf("��������־�۸�");
		scanf("%lf",&p->price);
		fwrite(p,sizeof(magazine_information),1,fp);
	}while(1);
	fclose(fp);
}

void customer_input()//�ͻ���Ϣ����
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
		printf("ע������������ڿͻ����ʱ����out\n");
		p=(customer_information *)malloc(sizeof(customer_information));
		memset(p,0,sizeof(customer_information));
		printf("������ͻ���ţ�");
		scanf("%s",p->no);
		if(strcmp(p->no,"out")==0)
		{
			free(p);
			break;
		}
		fflush(stdin);
		printf("������ͻ�������");
		scanf("%s",p->name);
		fflush(stdin);
		printf("������ͻ����ĵ���־���ƣ����ͻ������˶౾��־����־����ֱ���á������� ����������");
		scanf("%s",p->magazine);
		fwrite(p,sizeof(customer_information),1,fp);
		fprintf(fp,"%c",ch);
	}while(1);
	fclose(fp);
}

void magazine_modify(magazine_information *head)//��־��Ϣ�޸�
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
		printf("������Ҫ�޸ĵ���־���ƣ�");
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
			printf("�����޴���־��������־�����Ƿ���ȷ��\n");
			continue;
		}
	}while(1);
	do
	{
		printf("1.�޸���־���\n2.�޸���־����\n3.�޸���־�۸�\nEsc.�����޸�\n");
		Q=getch();
		fflush(stdin);
		if(Q==27)
			break;
		switch(Q)
		{
			case '1':
				printf("�������µı�ţ�");
				memset(no,0,10);
				gets(no);
				strcpy(tail->no,no);
				printf("�޸ĳɹ���\n");
				break;
			case '2':
				printf("�������µ����ͣ�");
				memset(type,0,10);
				gets(type);
				strcpy(tail->type,type);
				printf("�޸ĳɹ���\n");
				break;
			case '3':
				printf("�������µļ۸�");
				scanf("%lf",&tail->price);
				printf("�޸ĳɹ���\n");
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

void customer_refer1(magazine_information *head)//�ͻ������ܵ���־��Ϣ
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
	printf("��־���\t��־����\t��־����\t��־�۸�\n");
	while(tail!=NULL)
	{
		printf("%s\t\t%s\t\t%s\t\t%.2lf\n",tail->no,tail->name,tail->type,tail->price);
		tail=tail->next;
	}
	fclose(fp);
	system("pause");
}

void customer_refer2(magazine_information *head)//�ͻ��ùؼ��ʲ�����־��Ϣ
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
		printf("1.����־��Ų���\n2.����־���Ʋ���\n3.����־���Ͳ���\nEsc.�˳�����\n");
		Q=getch();
		if(Q==27)
			break;
		fflush(stdin);
		switch(Q)
		{
			case '1':
				memset(no,0,10);
				printf("��������־��ţ�");
				gets(no);
				printf("��־���\t��־����\t��־����\t��־�۸�\n");
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
				printf("��������־���ƣ�");
				gets(name);
				printf("��־���\t��־����\t��־����\t��־�۸�\n");
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
				printf("��������־���ͣ�");
				gets(type);
				printf("��־���\t��־����\t��־����\t��־�۸�\n");
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

void customer_modify(customer_information *head)//�ͻ���Ϣ�޸�
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
		printf("������Ҫ�޸ĵĿͻ��ı�ţ�");
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
			printf("�ͻ���Ϣ�����޴���,��������ı���Ƿ���ȷ��\n");
			continue;
		}
	}while(1);
	printf("������ͻ��µ���־������Ϣ��");
	memset(magazine,0,200);
	gets(magazine);
	strcpy(tail->magazine,magazine);
	printf("�޸ĳɹ���\n");
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
	printf("������Ҫ���ҵĿͻ���ţ�");
	memset(no,0,10);
	gets(no);
	printf("�ͻ����\t\t�ͻ�����\t\t�ͻ����ĵ���־����\n");
	while(tail!=NULL)
	{
		if(strcmp(tail->no,no)==0)
			printf("%s\t%s\t%s\n",tail->no,tail->name,tail->magazine);
		tail=tail->next;
	}
}

void subscribe_input()//��־������Ϣ����
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
		printf("���������������ͻ����ʱ����out\n");
		p=(magazine_subscribe *)malloc(sizeof(magazine_subscribe));
		memset(p,0,sizeof(magazine_subscribe));
		printf("������ͻ���ţ�");
		fflush(stdin);
		gets(p->no);
		if(strcmp(p->no,"out")==0)
		{
			free(p);
			break;
		}
		fflush(stdin);
		printf("������ͻ����ĵ���־���ƣ�");
		gets(p->name);
		printf("������ͻ����ĵ��ܽ�");
		scanf("%lf",&p->total_amount);
		fwrite(p,sizeof(magazine_subscribe),1,fp);
		fprintf(fp,"%c",ch);
	}while(1);
	fclose(fp);
}

void subscribe_modify(magazine_subscribe *head)//��־������Ϣ�޸�
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
		printf("1.�޸Ŀͻ����\n2.�޸Ŀͻ����ĵ���־����\nEsc.�˳��޸�\n��ѡ��ִ�����");
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
					printf("������Ҫ�޸ĵĿͻ���ţ�");
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
						printf("��־������Ϣ�����޴˿ͻ���ţ������Ƿ�������ȷ���������롣\n");
						continue;
					}
				}while(1);
				memset(no,0,10);
				printf("�������µĿͻ���ţ�");
				gets(no);
				strcpy(tail->no,no);
				break;
			case '2':
				do
				{
					tail=head->next;
					memset(name,0,20);
					printf("������Ҫ�޸ĵĿͻ����ĵ���־���ƣ�");
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
						printf("��־������Ϣ�����޴˿ͻ���ţ������Ƿ�������ȷ���������롣\n");
						continue;
					}
				}while(1);
				memset(name,0,20);
				printf("�������µĿͻ����ĵ���־���ƣ�");
				gets(name);
				strcpy(tail->name,name);
				printf("�������µĶ����ܽ�");
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

void subscribe_infor_refer(magazine_subscribe *head)//������Ϣ��ѯ
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
	printf("������Ҫ��ѯ�Ŀͻ���ţ�");
	memset(no,0,10);
	gets(no);
	tail=head->next;
	printf("�ͻ����\t�ͻ����ĵ���־����\t�����ܽ��\n");
	while(tail!=NULL)
	{
		if(strcmp(tail->no,no)==0)
			printf("%s\t%s\t%.2lf\n",tail->no,tail->name,tail->total_amount);
		tail=tail->next;
	}
}

void login_boss(administrator *head)//�ܹ���Ա��¼
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
		printf("�������˺ţ�");
		gets(account);
		fflush(stdin);
		printf("���������룺");
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
			printf("�˺��������\n");
			continue;
		}
		else if(strcmp(password,tail->password)==0)
			break;
		else
			printf("\n�����������\n");
	}while(1);
	printf("\n��ӭ�����ܹ���Ա\n");
}

void login(administrator *head)//����Ա��¼
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
		printf("�������˺ţ�");
		gets(account);
		fflush(stdin);
		printf("���������룺");
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
			printf("\n�˺��������\n");
			continue;
		}
		if(strcmp(tail->password,password)==0)
		{
			printf("��ӭ���뱾����ϵͳ��\n");
			break;
		}
		else
			printf("\n�����������\n");
	}while(1);
}

void menu()//�˵�����
{
	printf("**********************************************************\n");
	printf("*               ��ӭʹ����־���Ĺ���ϵͳ                 *\n");
	printf("*                     1.�ܹ���Աͨ��                     *\n");
	printf("*                     2.����Աͨ��                       *\n");
	printf("*                     3.�ͻ�ͨ��                         *\n");
	printf("*                   Esc.�˳�ϵͳ                         *\n");
	printf("**********************************************************\n");
	printf("��ܰ��ʾ������ǵ�һ��ʹ�ñ�ϵͳ�����Ƚ����ܹ���Աͨ����ע��һ���ܹ���Ա�˺ţ����ں���ʹ��\n");
}

void magazine_management()//��־����
{
	char a;
	magazine_information *headmi=NULL;
	headmi=(magazine_information *)malloc(sizeof(magazine_information));
	memset(headmi,0,sizeof(magazine_information));
	do
	{
		printf("1.��־��Ϣ����\n2.��־��Ϣ�޸�\n3.��־��Ϣ��ѯ\nEsc.�˳�\n");
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

void customer_management()//�ͻ�����
{
	char a;
	customer_information *headc=NULL;
	headc=(customer_information *)malloc(sizeof(customer_information));
	memset(headc,0,sizeof(customer_information));
	do
	{
		printf("1.�ͻ���Ϣ����\n2.�ͻ���Ϣ�޸�\n3.�ͻ���Ϣ��ѯ\nEsc.�˳�\n");
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

void subscribe_management()//���Ĺ���
{
	char a;
	magazine_subscribe *headms=NULL;
	headms=(magazine_subscribe *)malloc(sizeof(magazine_subscribe));
	memset(headms,0,sizeof(magazine_subscribe));
	do
	{
		printf("1.������Ϣ����\n2.������Ϣ�޸�\n3.������Ϣ��ѯ\nEsc.�˳�\n");
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

void administrator_delete(administrator *head)//����Աɾ��
{
	FILE *fp;
	administrator *p=NULL,*q=NULL;
	char no[10],ch='\n';
	printf("������Ҫɾ���Ĺ���Ա���ţ�");
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
	printf("ɾ���ɹ�\n");
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

void administrator_management()//����Ա����
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
		printf("1.�鿴����Ա��Ϣ\n2.ɾ������Ա\nEsc.�˳�\n");
		a=getch();
		if(a==27)
			break;
		switch(a)
		{
			case '1':
				tail=heada->next;
				printf("����\t����\t�˺�\t\t����\n");
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

void administrator_function()//����Ա����
{
	administrator *heada=NULL;
	char a,b;
	heada=(administrator *)malloc(sizeof(administrator));
	memset(heada,0,sizeof(administrator));
	do
	{
		system("cls");
		printf("��ӭ�������Աͨ��\n1.��¼\n2.ע��\nEsc.�˳�\n");
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
					printf("1.��־��Ϣ����\n2.�ͻ���Ϣ����\n3.������Ϣ����\n4.�����޸�\nEsc.ע��\n");
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

void administrator_boss()//�ܹ���Ա����
{
	administrator *heada=NULL;
	char a,b;
	heada=(administrator *)malloc(sizeof(administrator));
	memset(heada,0,sizeof(administrator));
	do
	{
		printf("��ӭ�����ܹ���Աͨ��\n1.��¼\n2.ע��\nEsc.�˳�\n");
		a=getch();
		if(a==27)
			break;
		switch(a)
		{
			case '1':
				login_boss(heada);
				do
				{
					printf("1.��־��Ϣ����\n2.�ͻ���Ϣ����\n3.������Ϣ����\n4.�����޸�\n5.����Ա����\nEsc.ע��\n");
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

void perform()//ִ�к���
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
					printf("1.��־��Ϣ�ܲ�ѯ\n2.��־��Ϣ�ؼ��ʲ�ѯ\nEsc.�˳�\n");
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