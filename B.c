# include  "type.h"
int B(long B_id)
{
	int flag=1;
	char sele;
	while (1)
	{
	system("cls");
	printf("********* 商家管理系统 ********\n");
	printf("1.订单管理\n");
	printf("2.商品管理\n");
	printf("3.信息修改\n");	
	printf("0.退出\n");
	printf("请选择："); 
	sele=getch();
	
	switch(sele)
	{
		case '1': B_order(B_id);break;
		case '2': B_Commodity(B_id);break;
		case '3': xiugai2(B_id);break; 
		case '0': flag=0;
				  printf("\n\n");break;
		default: system("cls");
				 printf("\n输入错误，请重新输入！\n");
				 getche();
	} 
	if(flag == 0)
		break;
	}
	printf("********谢谢使用本系统！再见！********"); 
	
	return 0;
}
