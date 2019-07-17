
# include "type.h"

void xiugai1(long id)
{
	printf("=========================\n");
	printf("此处可以修改您的个人信息！\n\n");
	FILE *fp;
	int len,j;
	int f=0;
	char c;
	User user[1000];
	char name[20];
	fp=fopen("user.dat","rb+");
	if(fp==NULL)
	{
		printf("file open error!");
		exit(0);
	}
	for ( j=0 ; !feof(fp) ; j++ )
		fread(&user[j],sizeof(User),1,fp);
	len=j-1;

S3:	printf("请输入您要修改的用户名：");
S2:	gets(name);
	for ( j=0 ; j<=len ; j++ )
		if (id==user[j].id_U)
		{
		printf("请输入新的用户名:"); 
		gets(user[j].name);

		printf("请输入新的手机号码：");
		gets(user[j].phone);
		printf("请输入新的电子邮箱：");
		gets(user[j].e); 
		f=1;
		printf("\n\n信息修改成功！");
		break;
		}
	
	if ( f==0 )
	{
		printf("没有此用户！");
		printf("\n是否选择重新输入需要更改的用户名？(Y/N)");
		scanf("%c",&c);
		getchar();
		if (c=='Y')
			goto S2;
		else if ( c=='N')
			printf("进程结束！");
		else 
		{
			printf("输入有误！请重新输入"); 
			goto S3;
		}
	}
	rewind(fp);
	for (j=0 ; j<len ; j++)
		fwrite(&user[j],sizeof(User),1,fp);
	
	
	fclose(fp); 
	return ;
}
