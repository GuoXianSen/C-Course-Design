# include  "type.h"
int B(long B_id)
{
	int flag=1;
	char sele;
	while (1)
	{
	system("cls");
	printf("********* �̼ҹ���ϵͳ ********\n");
	printf("1.��������\n");
	printf("2.��Ʒ����\n");
	printf("3.��Ϣ�޸�\n");	
	printf("0.�˳�\n");
	printf("��ѡ��"); 
	sele=getch();
	
	switch(sele)
	{
		case '1': B_order(B_id);break;
		case '2': B_Commodity(B_id);break;
		case '3': xiugai2(B_id);break; 
		case '0': flag=0;
				  printf("\n\n");break;
		default: system("cls");
				 printf("\n����������������룡\n");
				 getche();
	} 
	if(flag == 0)
		break;
	}
	printf("********ллʹ�ñ�ϵͳ���ټ���********"); 
	
	return 0;
}
