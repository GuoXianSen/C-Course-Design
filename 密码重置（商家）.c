
# include "type.h"

void change1(char* name)
{
	int k=0,f=0;
	FILE *fp;
	fp=fopen("Business.dat","rb+");
	if (fp==NULL)
		printf("文件打开错误！"); 
	int j,len;
	Business business[1000];
	printf("\n\t\t\t\t**********************\n");
	printf("\t\t\t\t欢迎进入密码重置系统：\n");
	printf("\t\t\t\t请输入您的手机号码：");
	char ch;
	char phone[12];
	char password[20]={0};
	int i;
S:	gets(phone);
	for ( j=0 ; !feof(fp) ; j++ )
		fread(&business[j],sizeof(Business),1,fp);
	len=j-1;
	rewind(fp);
	for ( j=0 ; j<len ; j++ )
		if(strcmp(business[j].phone,phone)==0)
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
		printf("\n\t\t\t\t密码修改成功！\n"); 
		strcpy(business[j].mi,password);
		}
	
	else 
	{
		k++;
		printf("\n\t\t\t\t您的原密码输入错误！,请重新输入！\n\t\t\t\t");
		if (k<=2)
			goto S;
		else 
			printf("密码重置失败！"); 
			return ;
	}
	

	rewind(fp);
	for ( i=0 ; i<len ; i++ )
		fwrite(&business[i],sizeof(Business),1,fp);
	
	fclose(fp);
}

