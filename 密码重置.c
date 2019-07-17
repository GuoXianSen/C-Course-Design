
# include "type.h"

void change(char name[])
{
	int k=0,f=0;
	FILE *fp;
	fp=fopen("User.dat","rb+");
	if (fp==NULL)
		printf("文件打开错误！"); 
	int j,len;
	Business business;
	User user[1000];
	printf("\n\t\t\t\t**********************\n");
	printf("\t\t\t\t欢迎进入密码重置菜单：\n");
S:	printf("\t\t\t\t请输入您的手机号进行验证：");
	char ch;
	char password[20]={0};
	int i;

	char phone[12];
	gets(phone);
	for ( j=0 ; !feof(fp) ; j++ )
		fread(&user[j],sizeof(User),1,fp);
	len=j-1;
	rewind(fp);
	for ( j=0 ; j<len ; j++ )
		if(strcmp(user[j].phone,phone)==0)
		{
			f=1;
			break;
		}
	
	if (f==1)
	{
		printf("\n\t\t\t\t请输入您的新密码：\n\t\t\t\t");
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
		printf("\n\t\t\t\t密码修改成功！,请牢记你的密码！\n"); 
		strcpy(user[j].mi,password);
		}
	else 
	{
		k++;
		printf("\n\t\t\t\t您的手机号码输入错误！,请重新输入！\n\t\t\t\t");
		if (k<=2)
			goto S;
		else 
			printf("密码重置失败！"); 
			return ;
	}
	

	rewind(fp);
	for ( i=0 ; i<len ; i++ )
		fwrite(&user[i],sizeof(User),1,fp);
	
	fclose(fp);
	
}

