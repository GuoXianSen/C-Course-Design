# include "type.h"

void xiugai2(long id)
{
	printf("=========================\n");
	printf("�˴������޸����ĸ�����Ϣ��\n\n");
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
		printf("�������µ��û���:"); 
		gets(business[j].name);

		printf("�������µ��ֻ����룺");
		gets(business[j].phone);
		printf("�������µĵ������䣺");
		gets(business[j].e); 
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
			printf("��������"); 
	}
	rewind(fp);
	for (j=0 ; j<len ; j++)
		fwrite(&business[j],sizeof(Business),1,fp);
	
	
	fclose(fp); 
	return ;
}
