
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
		printf("\t\t\t\t*******  选择  ********\n");
		printf("\t\t\t\t**                   **\n");
		printf("\t\t\t\t**1.重新输入         **\n");
		printf("\t\t\t\t**                   **\n");
		printf("\t\t\t\t**2.重新注册         **\n");
		printf("\t\t\t\t**1.                 **\n");
		printf("\t\t\t\t**0.退出             **\n");
		printf("\t\t\t\t**                   **\n");
		printf("\t\t\t\t***********************\n");
		printf("\t\t\t\t请选择：");
		
		sele = getche();
		
		switch(sele)
		{
			case '1': system("cls");loginUser();getche();mainmenu(40000);break;
			case '2': system("cls");register1();getche();loginUser();mainmenu(40000);break;
			case '0': flag=0;
					  printf("\n\n");exit(0);
			default:  system("cls");printf("\n\n输入错误，请重新选择！\n\n");
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
		printf("\t\t\t\t*******  选择  ********\n");
		printf("\t\t\t\t**                   **\n");
		printf("\t\t\t\t**1.重新输入         **\n");
		printf("\t\t\t\t**                   **\n");
		printf("\t\t\t\t**2.重新注册         **\n");
		printf("\t\t\t\t**                   **\n");
		printf("\t\t\t\t**0.退出             **\n");
		printf("\t\t\t\t**                   **\n");
		printf("\t\t\t\t***********************\n");
		printf("\t\t\t\t请选择：");
		
		sele = getche();
		
		switch(sele)
		{
			case '1': system("cls");loginBus();getche();B(num);break;
			case '2': system("cls");register2();getche();loginBus();B(num);break;
			case '0': flag=0;
					  printf("\n\n");exit(0);
			default:  system("cls");printf("\n\n输入错误，请重新选择！\n\n");
					  getche();

		}
	}	
//S1:	
}

long  loginUser()	//用户登陆的模块   fp
{
	int i,k=0;   //用k来记录密码登录次数 
	User user[1000];
	printf("\t\t\t\t-----------------\n"); 
	printf("\t\t\t\t欢迎来到本系统！\n");
s2:	printf("\t\t\t\t请输入您的用户名：");
	
	char name[20];
	char ch; 
	int j=0,len;
	char password[20];
	FILE *fp;
s1:	fflush(stdin);
	gets(name);
	fflush(stdin);
	if ((fp=fopen("User.dat","rb"))==NULL)
		printf("文件打开错误！");
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
		printf("\n\t\t\t\t用户名不存在，是否开始注册或者重新输入\n\t\t\t\t");
		getche();
		system("cls");
		sub111();
	}
	
/*
先进行用户名的验证不对的话先验证用户名 
*/	
	if (f==1)
		{
		printf("\t\t\t\t请输入您的密码：");
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
	/* 先进行用户名输入	
	   输入之后需要进行用户名验证 
	   再输入密码
	   进行密码验证
	   密码限制输入次数  如果密码遗忘，则需要进行密码重置 
	*/	 

	if ((strcmp(user[j].mi,password)==0))
		{
			printf("\n\t\t\t\t正在登陆，请稍后……\n");
			printf("\t\t\t\t");
			for ( i=0 ; i<15; i++ )
			{
				printf("#");
				Sleep(100);
			}
			printf("\n\t\t\t\t登录成功！欢迎来到本订单管理系统！\n\t\t\t\t"); 
		}
	else 
		{
			system("cls");
			printf("\t\t\t\t您的用户名或者是密码输入错误！请重新输入！\n");
			
			if (k<=2)
				{
					printf("\t\t\t\t请重新输入您的密码：");
					goto S;
				}
			else 
			{
				system("cls");
				printf("\t\t\t\t您已经输错三次机会啦！，是否进行密码重置？");
				change(&user[j].name[0]);
				goto s2;
			} 
		 }
	fclose(fp);
	return user[j].id_U;
} 	

long loginBus()	   //商家登陆的模块    fp2
{
	int i,k=0,j,len;   //用k来记录密码登录次数 
	char name[20];
	char ch; 
	int f=0;
	printf("\t\t\t\t-------------------\n"); 
	printf("\t\t\t\t欢迎来到本系统！\n");
S1:	printf("\t\t\t\t请输入您的用户名：");
	Business business[1000]; 
	FILE *fp2;
	char password[20];
	fflush(stdin);
S0:	gets(name);
fflush(stdin);
	if ((fp2=fopen("Business.dat","rb"))==NULL)
	{
		printf("文件打开错误！");
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
		printf("\t\t\t\t用户名不存在!");
		system("cls");
		printf("\t\t\t\t请重新输入您的用户名：");
		sub222(business[j].id_B);
	}

//这边可以 进行注册函数的调用
 
/*
先进行用户名的验证不对的话先验证用户名 
*/	
	if ( f==1 )
	{
	printf("\t\t\t\t请输入您的密码:");
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
/* 先进行用户名输入	
   输入之后需要进行用户名验证 
   再输入密码
   进行密码验证
   密码限制输入次数  如果密码遗忘，则需要进行密码重置 
*/	 


	if ((strcmp(business[j].mi,password)==0))
		{
			printf("\n\t\t\t\t密码输入正确\n\t\t\t\t正在登陆，请稍后：\n\t\t\t\t");
			for ( i=0 ; i<15 ; i++ )
			{
				printf("#");
				Sleep(100); 
			}
			printf("\n\t\t\t\t登录成功！\n\t\t\t\t欢迎来到本订单管理系统！\n\t\t\t\t"); 
			getch();

		}
		
	else 
	{
		system("cls");
		printf("\t\t\t\t您的用户名或者是密码输入错误！请重新输入！\n\t\t\t\t");
//		getche();
		
		if (k<=2)
			{
				printf("请重新输入您的密码：");
				goto S;
			}
		else 
			system("cls");
			printf("\t\t\t\t您已经输错三次机会啦！，是否进行密码重置？");
   			change1(business[j].name);
   			goto S1;
	 } 	
	}
	fclose(fp2);
	return business[j].id_B;
}

void register1()   //用户在注册的模块  fp1
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
		printf("文件打开错误！");
	User user;
	 
	char password[20]; 
	printf("\t\t\t\t请输入您的用户名：");
	gets(user.name);
	printf("\t\t\t\t请输入您的密码：");

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
	printf("\t\t\t\t请确认您的密码：");
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
		printf("\t\t\t\t两次输入的密码不相同，请重新输入！\n");
		goto S;
	}
	
	printf("\t\t\t\t请输入您的手机号码：");
	gets(user.phone);
	printf("\t\t\t\t请输入您的电子邮箱：");
	gets(user.e); 
	user.id_U = b.id_U +1;
	fwrite(&user,sizeof(User),1,fp1);
	fclose(fp1);	 

} 

void register2()   //商家在注册的模块  fp3
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
		printf("文件打开错误！");
	Business business; 
	char password[20]; 
	printf("\t\t\t\t请输入您的用户名：");
	gets(business.name);
	printf("\t\t\t\t请输入您的密码：");
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
	printf("\t\t\t\t请确认您的密码：");
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
		printf("\t\t\t\t两次输入的密码不相同，请重新输入！\n");
		goto S;
	}
	
	printf("\t\t\t\t请输入您的手机号码：");
	gets(business.phone);
	printf("\t\t\t\t请输入您的电子邮箱：");
	gets(business.e); 
	business.id_B = b.id_B +1;
	fwrite(&business,sizeof(Business),1,fp3);
	fclose(fp3);	 

}

void sub1()       //这是二级菜单 用于登陆模块 
{
long id;
	char sele;
	int flag = 1;
	while(flag)
	{
		system("cls");
		printf("\t\t\t\t********** 登录 **********\n");
		printf("\t\t\t\t**                      **\n");
		printf("\t\t\t\t**1.商家                **\n");
		printf("\t\t\t\t**                      **\n");
		printf("\t\t\t\t**2.用户                **\n");
		printf("\t\t\t\t**                      **\n");
		printf("\t\t\t\t**0.返回                **\n");
		printf("\t\t\t\t**                      **\n");
		printf("\t\t\t\t**************************\n");
		printf("\t\t\t\t请选择：");
		
		sele = getche();
		
		switch(sele)
		{
			case '1': system("cls");id = loginBus();getche();B(id);break;
			case '2': system("cls");id = loginUser();system("cls");getche();mainmenu(id);break;
			case '0': flag=0;
					  printf("\n\n");break;
			default:  system("cls");printf("\n\n输入错误，请重新选择！\n\n");
					  getche();

		}
	}
}

void sub2()       //这是二级菜单 用于注册模块 
{

	char sele;
	int flag = 1;
	while(flag)
	{
		system("cls");
		printf("\t\t\t\t*********** 注册 ***********\n");
		printf("\t\t\t\t**                        **\n");		
		printf("\t\t\t\t*1.商家                   **\n");
		printf("\t\t\t\t**                        **\n");
		printf("\t\t\t\t*2.用户                   **\n");
		printf("\t\t\t\t**                        **\n");
		printf("\t\t\t\t*0.返回                   **\n");
		printf("\t\t\t\t**                        **\n");
		printf("\t\t\t\t****************************\n");
		printf("\t\t\t\t*请选择：");
		
		sele = getche();
		
		switch(sele)
		{
			case '1': system("cls");register2();printf("\t\t\t\t欢迎成为本订单系统中的一名商家\n");getche();break;
			case '2': system("cls");register1();printf("\n\n\t\t\t\t欢迎加入本订单系统用户的大家庭中\n\t\t\t\t");getche();break;
			case '0': flag=0;
					  printf("\n\n");break;
			default:  system("cls");printf("\n\n输入错误，请重新选择！\n\n");
					  getche();

		}
	}
}

void sub3()       //这是管理员 后台操作界面 
{
	system("cls");
	printf("****************************\n");
	printf("尊敬的管理员你好！\n"); 
	printf("欢迎来到本系统后台管理界面！\n");
	pingjia();
	ad_search();
	return ;
}

void menu()        //主菜单模块 
{
int flag=1;
	char sele;
	while (flag)
	{
	system("cls");
	printf("\t\t\t\t*******欢迎使用本系统*********\n");
	printf("\t\t\t\t**                          **\n");
	printf("\t\t\t\t**1.登录                    **\n");
	printf("\t\t\t\t**                          **\n");
	printf("\t\t\t\t**2.注册                    **\n");
	printf("\t\t\t\t**                          **\n");
	printf("\t\t\t\t**0.退出                    **\n");
	printf("\t\t\t\t**                          **\n");
	printf("\t\t\t\t******************************\n");
	printf("\t\t\t\t请选择："); 
	sele=getche();
	
	switch(sele)
	{
		case '1': sub1();break;
		case '2': sub2();break;
		case 'a': sub3();break;
		case '0': flag=0;
				  printf("\n\n");break;
		default: system("cls");
				 printf("\n输入错误，请重新输入！\n");
				 getche();
	} 
	}	
	printf("\t\t\t\t********谢谢使用本系统！再见！*********\n"); 
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
