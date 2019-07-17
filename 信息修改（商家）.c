# include "type.h"

void xiugai2(long id)
{
	printf("=========================\n");
	printf("此处可以修改您的个人信息！\n\n");
	FILE *fp;
	int len,j;
	int f=0;
	char c;
	Business business[1000];
	char name[20];
	fp=fopen("Business.dat","rb+");
	if(fp==NULL)
	{
		printf("file open error!");
		exit(0);
	}
	for ( j=0 ; !feof(fp) ; j++ )
		fread(&business[j],sizeof(User),1,fp);
	len=j-1;

S2:	printf(" ");
//	gets(name);
	for ( j=0 ; j<=len ; j++ )
		if (business[j].id_B==id)
		{
		printf("请输入新的用户名:"); 
		gets(business[j].name);

		printf("请输入新的手机号码：");
		gets(business[j].phone);
		printf("请输入新的电子邮箱：");
		gets(business[j].e); 
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
			printf("输入有误！"); 
	}
	rewind(fp);
	for (j=0 ; j<len ; j++)
		fwrite(&business[j],sizeof(Business),1,fp);
	
	
	fclose(fp); 
	return ;
}
