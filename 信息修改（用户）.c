
# include "type.h"

void xiugai1(long id)
{
	printf("=========================\n");
	printf("�˴������޸����ĸ�����Ϣ��\n\n");
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

S3:	printf("��������Ҫ�޸ĵ��û�����");
S2:	gets(name);
	for ( j=0 ; j<=len ; j++ )
		if (id==user[j].id_U)
		{
		printf("�������µ��û���:"); 
		gets(user[j].name);

		printf("�������µ��ֻ����룺");
		gets(user[j].phone);
		printf("�������µĵ������䣺");
		gets(user[j].e); 
		f=1;
		printf("\n\n��Ϣ�޸ĳɹ���");
		break;
		}
	
	if ( f==0 )
	{
		printf("û�д��û���");
		printf("\n�Ƿ�ѡ������������Ҫ���ĵ��û�����(Y/N)");
		scanf("%c",&c);
		getchar();
		if (c=='Y')
			goto S2;
		else if ( c=='N')
			printf("���̽�����");
		else 
		{
			printf("������������������"); 
			goto S3;
		}
	}
	rewind(fp);
	for (j=0 ; j<len ; j++)
		fwrite(&user[j],sizeof(User),1,fp);
	
	
	fclose(fp); 
	return ;
}
