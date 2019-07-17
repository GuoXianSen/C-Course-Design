# include <stdio.h>
# define M 1000
# define E 5

typedef struct{
	long id;//������� 
	long id_U;//Ԥ���û���� 
	long id_C;//Ԥ����Ʒ��� 
	long id_B;//Ԥ���̼ұ�� 
	int state;
	//0-3���̼���ȡ��δȷ�ϡ���ȷ�ϡ�����ɣ�4-6�û�δ���ۡ������ۡ���ȡ�� 
	time_t tm;//����״̬����ʱ�� 
	int pj;//�������� 
}Order;

typedef struct{
	long id;//��Ʒ��� 
	char name[20];//��Ʒ���� 
	float cost;
	float price;//��Ʒ�۸� 
	int number;//��Ʒ���� 
	int sold;//�������� 
	long id_B;//�����̼ұ�� 
	float pj;//��Ʒ�ۺ����� 
	int state;//��Ʒ״̬��7������Ա�¼ܣ�8������ 
	char tm[26];//��Ʒ״̬����ʱ�� 
}Commodity;
void pingjia()
{
/*
���ۺ�������Ҫ��ȡ�û�������  ���������ܵ����۽�� �溯�����ص��õĵط�
��Ȩƽ����

��ȡ�ļ�֮�󣬶������۷���֮����д��� 
*/
	int len,len1,count;
	FILE *fp,*fp1;
	Commodity com[M];
	Order order[M];
	int sum1,sum2;
	float mark[M];
	fp=fopen("Order.dat","rb");

	fp1=fopen("Commodity.dat","rb+");
	
	printf("�𾴵Ĺ���Ա���ã�\n");
	printf("******�������۹����̨*******\n");
	int pj;//�������� 
	if (fp==NULL)
		printf("Open Error!");
	if (fp1==NULL)
		printf("Open Error!");
	int i,j;
	for (i=0 ; !feof(fp1) ; i++)
		fread( &com[i],sizeof(Commodity),1,fp1) ;
	len = i-1;
	for ( i=0 ; !feof(fp) ; i++)
		fread(&order[i],sizeof(Order),1,fp);
	len1= i-1;
	
	for (i=0; i<len ; i++)
	{
		sum1=sum2=0;
		for (j=0 ; j<len1 ; j++)
			if ( order[j].id_C == com[i].id && order[j].state == 5)
			{
				count++;
				switch(order[j].pj)
				{
					case 0:
					case 1:
					case 2:sum1++;break;
					case 3:
					case 4:
					case 5:sum2++;break;
						
				 } 
			 }
			if ( count > E )
				mark[i]=(sum1*0.6+sum2*0.4)/count;
			else 
				mark[i]=(sum1*0.7+sum2*0.3)/count;
			com[i].pj=mark[i];
			
	}
/*
sum1 ռ��60%
sum2 ռ��40%
������������ ĳһ���ض�ֵ��ʱ��define E 5
�����嵥��ʱ�򣬱ȷ�ռ��70 30
 
*/
		
	for ( i=0; i<len ; i++)
		fwrite(&com[i],sizeof(Commodity),1,fp);
	
	
	
	
	
		
	
	fclose(fp);
	return ;
 } 
