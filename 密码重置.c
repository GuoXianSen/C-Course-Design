
# include "type.h"

void change(char name[])
{
	int k=0,f=0;
	FILE *fp;
	fp=fopen("User.dat","rb+");
	if (fp==NULL)
		printf("�ļ��򿪴���"); 
	int j,len;
	Business business;
	User user[1000];
	printf("\n\t\t\t\t**********************\n");
	printf("\t\t\t\t��ӭ�����������ò˵���\n");
S:	printf("\t\t\t\t�����������ֻ��Ž�����֤��");
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
		printf("\n\t\t\t\t���������������룺\n\t\t\t\t");
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
		printf("\n\t\t\t\t�����޸ĳɹ���,���μ�������룡\n"); 
		strcpy(user[j].mi,password);
		}
	else 
	{
		k++;
		printf("\n\t\t\t\t�����ֻ������������,���������룡\n\t\t\t\t");
		if (k<=2)
			goto S;
		else 
			printf("��������ʧ�ܣ�"); 
			return ;
	}
	

	rewind(fp);
	for ( i=0 ; i<len ; i++ )
		fwrite(&user[i],sizeof(User),1,fp);
	
	fclose(fp);
	
}

