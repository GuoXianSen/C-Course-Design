
# include  "type.h"

long loginUser();
long loginBus()	;
void register1() ;
void register2();
void sub111()
{

	char sele;
	int flag = 1;
	while(flag)
	{
		system("cls");
		printf("\t\t\t\t*******  ѡ��  ********\n");
		printf("\t\t\t\t**                   **\n");
		printf("\t\t\t\t**1.��������         **\n");
		printf("\t\t\t\t**                   **\n");
		printf("\t\t\t\t**2.����ע��         **\n");
		printf("\t\t\t\t**1.                 **\n");
		printf("\t\t\t\t**0.�˳�             **\n");
		printf("\t\t\t\t**                   **\n");
		printf("\t\t\t\t***********************\n");
		printf("\t\t\t\t��ѡ��");
		
		sele = getche();
		
		switch(sele)
		{
			case '1': system("cls");loginUser();getche();mainmenu(40000);break;
			case '2': system("cls");register1();getche();loginUser();mainmenu(40000);break;
			case '0': flag=0;
					  printf("\n\n");exit(0);
			default:  system("cls");printf("\n\n�������������ѡ��\n\n");
					  getche();

		}
	}	
}

void sub222(long num)
{

	char sele;
	int flag = 1;
	while(flag)
	{
		system("cls");
		printf("\t\t\t\t*******  ѡ��  ********\n");
		printf("\t\t\t\t**                   **\n");
		printf("\t\t\t\t**1.��������         **\n");
		printf("\t\t\t\t**                   **\n");
		printf("\t\t\t\t**2.����ע��         **\n");
		printf("\t\t\t\t**                   **\n");
		printf("\t\t\t\t**0.�˳�             **\n");
		printf("\t\t\t\t**                   **\n");
		printf("\t\t\t\t***********************\n");
		printf("\t\t\t\t��ѡ��");
		
		sele = getche();
		
		switch(sele)
		{
			case '1': system("cls");loginBus();getche();B(num);break;
			case '2': system("cls");register2();getche();loginBus();B(num);break;
			case '0': flag=0;
					  printf("\n\n");exit(0);
			default:  system("cls");printf("\n\n�������������ѡ��\n\n");
					  getche();

		}
	}	
//S1:	
}

long  loginUser()	//�û���½��ģ��   fp
{
	int i,k=0;   //��k����¼�����¼���� 
	User user[1000];
	printf("\t\t\t\t-----------------\n"); 
	printf("\t\t\t\t��ӭ������ϵͳ��\n");
s2:	printf("\t\t\t\t�����������û�����");
	
	char name[20];
	char ch; 
	int j=0,len;
	char password[20];
	FILE *fp;
s1:	fflush(stdin);
	gets(name);
	fflush(stdin);
	if ((fp=fopen("User.dat","rb"))==NULL)
		printf("�ļ��򿪴���");
	for (j=0; !feof(fp); j++)
		fread(&user[j],sizeof(User),1,fp);
	len = j-1;
	int f=0;
	for (j=0 ; j<len ; j++)
		if (strcmp(user[j].name,name)==0)
	{	
		f=1;
		break;
	}
	if (j==len && f==0)
	{
		printf("\n\t\t\t\t�û��������ڣ��Ƿ�ʼע�������������\n\t\t\t\t");
		getche();
		system("cls");
		sub111();
	}
	
/*
�Ƚ����û�������֤���ԵĻ�����֤�û��� 
*/	
	if (f==1)
		{
		printf("\t\t\t\t�������������룺");
	S:	for (i=0 ; i<19 && (ch=getch())!='\r' ; i++)
			{
	
				if (ch=='\b')
				{
					if (i>0)
						i--; 
					printf("\b \b");
					password[i]='\0';
					i--;
					continue;
				}
				else 
				{
					password[i]=ch;
					printf("*");
				}
			}
		k++;
		password[i]='\0';
		} 
	/* �Ƚ����û�������	
	   ����֮����Ҫ�����û�����֤ 
	   ����������
	   ����������֤
	   ���������������  �����������������Ҫ������������ 
	*/	 

	if ((strcmp(user[j].mi,password)==0))
		{
			printf("\n\t\t\t\t���ڵ�½�����Ժ󡭡�\n");
			printf("\t\t\t\t");
			for ( i=0 ; i<15; i++ )
			{
				printf("#");
				Sleep(100);
			}
			printf("\n\t\t\t\t��¼�ɹ�����ӭ��������������ϵͳ��\n\t\t\t\t"); 
		}
	else 
		{
			system("cls");
			printf("\t\t\t\t�����û�����������������������������룡\n");
			
			if (k<=2)
				{
					printf("\t\t\t\t�����������������룺");
					goto S;
				}
			else 
			{
				system("cls");
				printf("\t\t\t\t���Ѿ�������λ����������Ƿ�����������ã�");
				change(&user[j].name[0]);
				goto s2;
			} 
		 }
	fclose(fp);
	return user[j].id_U;
} 	

long loginBus()	   //�̼ҵ�½��ģ��    fp2
{
	int i,k=0,j,len;   //��k����¼�����¼���� 
	char name[20];
	char ch; 
	int f=0;
	printf("\t\t\t\t-------------------\n"); 
	printf("\t\t\t\t��ӭ������ϵͳ��\n");
S1:	printf("\t\t\t\t�����������û�����");
	Business business[1000]; 
	FILE *fp2;
	char password[20];
	fflush(stdin);
S0:	gets(name);
fflush(stdin);
	if ((fp2=fopen("Business.dat","rb"))==NULL)
	{
		printf("�ļ��򿪴���");
		exit(0);
	}
	
	for ( j=0 ; !feof(fp2) ; j++ )
		fread(&business[j],sizeof(Business),1,fp2);
	len = j-1;	
	
	for ( j=0 ; j<len ; j++)
		if (strcmp(business[j].name,name)==0)
			{
				f=1;
				break;
			}
	if ( j==len && f==0 )
	{
		printf("\t\t\t\t�û���������!");
		system("cls");
		printf("\t\t\t\t���������������û�����");
		sub222(business[j].id_B);
	}

//��߿��� ����ע�ắ���ĵ���
 
/*
�Ƚ����û�������֤���ԵĻ�����֤�û��� 
*/	
	if ( f==1 )
	{
	printf("\t\t\t\t��������������:");
S:	for (i=0 ; i<19 && (ch=getch())!='\r' ; i++)
		{

				if (ch=='\b')
				{
					if (i>0)
						i--; 
					printf("\b \b");
					password[i]='\0';
					i--;
					continue;
				}
				else 
				{
					password[i]=ch;
					printf("*");
				}
		}
	k++;
	password[i]='\0';
	fflush(stdin);
/* �Ƚ����û�������	
   ����֮����Ҫ�����û�����֤ 
   ����������
   ����������֤
   ���������������  �����������������Ҫ������������ 
*/	 


	if ((strcmp(business[j].mi,password)==0))
		{
			printf("\n\t\t\t\t����������ȷ\n\t\t\t\t���ڵ�½�����Ժ�\n\t\t\t\t");
			for ( i=0 ; i<15 ; i++ )
			{
				printf("#");
				Sleep(100); 
			}
			printf("\n\t\t\t\t��¼�ɹ���\n\t\t\t\t��ӭ��������������ϵͳ��\n\t\t\t\t"); 
			getch();

		}
		
	else 
	{
		system("cls");
		printf("\t\t\t\t�����û�����������������������������룡\n\t\t\t\t");
//		getche();
		
		if (k<=2)
			{
				printf("�����������������룺");
				goto S;
			}
		else 
			system("cls");
			printf("\t\t\t\t���Ѿ�������λ����������Ƿ�����������ã�");
   			change1(business[j].name);
   			goto S1;
	 } 	
	}
	fclose(fp2);
	return business[j].id_B;
}

void register1()   //�û���ע���ģ��  fp1
{
	User b;
	FILE *fp1;
	int i=0;
	char ch;
	int j;
	fp1=fopen("User.dat","rb+");
	for(i= 0 ;!feof(fp1); i++){
		fread(&b, sizeof(User), 1, fp1);
	}
	fclose(fp1);
	fp1=fopen("User.dat","ab+");
	if (fp1==NULL)
		printf("�ļ��򿪴���");
	User user;
	 
	char password[20]; 
	printf("\t\t\t\t�����������û�����");
	gets(user.name);
	printf("\t\t\t\t�������������룺");

S:	for (i=0 ; i<19 && (ch=getch())!='\r' ; i++)
		{

				if (ch=='\b')
				{
					if (i>0)
						i--; 
					printf("\b \b");
					user.mi[i]='\0';
					i--;
					continue;
				}
				else 
				{
					user.mi[i]=ch;
					printf("*");
				}
		}
	user.mi[i]='\0';
	printf("\n");
	printf("\t\t\t\t��ȷ���������룺");
	for (i=0 ; i<19 && (ch=getch())!='\r' ; i++)
		{

			if (ch=='\b')
			{
				if (i>0)
					i--; 
				printf("\b \b");
				password[i]='\0';
				i--;
				continue;
			}
			else 
			{
				password[i]=ch;
				printf("*");
			}
		}
	password[i]='\0';	 
	printf("\n");
	if (strcmp(user.mi,password)!=0)
	{
		printf("\t\t\t\t������������벻��ͬ�����������룡\n");
		goto S;
	}
	
	printf("\t\t\t\t�����������ֻ����룺");
	gets(user.phone);
	printf("\t\t\t\t���������ĵ������䣺");
	gets(user.e); 
	user.id_U = b.id_U +1;
	fwrite(&user,sizeof(User),1,fp1);
	fclose(fp1);	 

} 

void register2()   //�̼���ע���ģ��  fp3
{
	Business b;
	int i;
	FILE *fp3;
	fp3=fopen("Business.dat","rb+");
	for(i= 0 ;!feof(fp3); i++){
		fread(&b, sizeof(Business), 1, fp3);
	}
	fclose(fp3);
	fp3=fopen("Business.dat","ab+");
	if (fp3==NULL)
		printf("�ļ��򿪴���");
	Business business; 
	char password[20]; 
	printf("\t\t\t\t�����������û�����");
	gets(business.name);
	printf("\t\t\t\t�������������룺");
	char ch;
S:	for (i=0 ; i<19 && (ch=getch())!='\r' ; i++)
		{

			if (ch=='\b')
			{
				if (i>0)
					i--; 
				printf("\b \b");
				business.mi[i]='\0';
				i--;
				continue;
			}
			else 
			{
				business.mi[i]=ch;
				printf("*");
			}
		}
	business.mi[i]='\0';
	printf("\n");
	printf("\t\t\t\t��ȷ���������룺");
	for (i=0 ; i<19 && (ch=getch())!='\r' ; i++)
		{

			if (ch=='\b')
			{
				if (i>0)
					i--; 
				printf("\b \b");
				password[i]='\0';
				i--;
				continue;
			}
			else 
			{
				password[i]=ch;
				printf("*");
			}
		}
	password[i]='\0';	 
	printf("\n");
	if (strcmp(business.mi,password)!=0)
	{
		printf("\t\t\t\t������������벻��ͬ�����������룡\n");
		goto S;
	}
	
	printf("\t\t\t\t�����������ֻ����룺");
	gets(business.phone);
	printf("\t\t\t\t���������ĵ������䣺");
	gets(business.e); 
	business.id_B = b.id_B +1;
	fwrite(&business,sizeof(Business),1,fp3);
	fclose(fp3);	 

}

void sub1()       //���Ƕ����˵� ���ڵ�½ģ�� 
{
long id;
	char sele;
	int flag = 1;
	while(flag)
	{
		system("cls");
		printf("\t\t\t\t********** ��¼ **********\n");
		printf("\t\t\t\t**                      **\n");
		printf("\t\t\t\t**1.�̼�                **\n");
		printf("\t\t\t\t**                      **\n");
		printf("\t\t\t\t**2.�û�                **\n");
		printf("\t\t\t\t**                      **\n");
		printf("\t\t\t\t**0.����                **\n");
		printf("\t\t\t\t**                      **\n");
		printf("\t\t\t\t**************************\n");
		printf("\t\t\t\t��ѡ��");
		
		sele = getche();
		
		switch(sele)
		{
			case '1': system("cls");id = loginBus();getche();B(id);break;
			case '2': system("cls");id = loginUser();system("cls");getche();mainmenu(id);break;
			case '0': flag=0;
					  printf("\n\n");break;
			default:  system("cls");printf("\n\n�������������ѡ��\n\n");
					  getche();

		}
	}
}

void sub2()       //���Ƕ����˵� ����ע��ģ�� 
{

	char sele;
	int flag = 1;
	while(flag)
	{
		system("cls");
		printf("\t\t\t\t*********** ע�� ***********\n");
		printf("\t\t\t\t**                        **\n");		
		printf("\t\t\t\t*1.�̼�                   **\n");
		printf("\t\t\t\t**                        **\n");
		printf("\t\t\t\t*2.�û�                   **\n");
		printf("\t\t\t\t**                        **\n");
		printf("\t\t\t\t*0.����                   **\n");
		printf("\t\t\t\t**                        **\n");
		printf("\t\t\t\t****************************\n");
		printf("\t\t\t\t*��ѡ��");
		
		sele = getche();
		
		switch(sele)
		{
			case '1': system("cls");register2();printf("\t\t\t\t��ӭ��Ϊ������ϵͳ�е�һ���̼�\n");getche();break;
			case '2': system("cls");register1();printf("\n\n\t\t\t\t��ӭ���뱾����ϵͳ�û��Ĵ��ͥ��\n\t\t\t\t");getche();break;
			case '0': flag=0;
					  printf("\n\n");break;
			default:  system("cls");printf("\n\n�������������ѡ��\n\n");
					  getche();

		}
	}
}

void sub3()       //���ǹ���Ա ��̨�������� 
{
	system("cls");
	printf("****************************\n");
	printf("�𾴵Ĺ���Ա��ã�\n"); 
	printf("��ӭ������ϵͳ��̨������棡\n");
	pingjia();
	ad_search();
	return ;
}

void menu()        //���˵�ģ�� 
{
int flag=1;
	char sele;
	while (flag)
	{
	system("cls");
	printf("\t\t\t\t*******��ӭʹ�ñ�ϵͳ*********\n");
	printf("\t\t\t\t**                          **\n");
	printf("\t\t\t\t**1.��¼                    **\n");
	printf("\t\t\t\t**                          **\n");
	printf("\t\t\t\t**2.ע��                    **\n");
	printf("\t\t\t\t**                          **\n");
	printf("\t\t\t\t**0.�˳�                    **\n");
	printf("\t\t\t\t**                          **\n");
	printf("\t\t\t\t******************************\n");
	printf("\t\t\t\t��ѡ��"); 
	sele=getche();
	
	switch(sele)
	{
		case '1': sub1();break;
		case '2': sub2();break;
		case 'a': sub3();break;
		case '0': flag=0;
				  printf("\n\n");break;
		default: system("cls");
				 printf("\n����������������룡\n");
				 getche();
	} 
	}	
	printf("\t\t\t\t********ллʹ�ñ�ϵͳ���ټ���*********\n"); 
	int i,j,n=6;
	for (i=1-(n>>1);i<=n;i++) 
		if (i>=0) 
		{ 
		for (j=0;j<i;j++) printf("  "); 
		for (j=1;j<=2*(n-i)+1;j++) printf(" *"); 
		printf("\n"); 
		} 
		else 
		{ 
		for (j=i;j<0;j++) 
			printf("  "); 
		for (j=1;j<=n+2*i+1;j++) 
			printf(" *"); 
		for (j=1;j<=-1-2*i;j++) 
			printf("  "); 
		for (j=1;j<=n+2*i+1;j++) 
			printf(" *"); 
		printf("\n"); 
		}	
	
}

int main()
{
	menu();
	return 0;
}
