# include <stdio.h>
# define M 1000
# define E 5

typedef struct{
	long id;//订单编号 
	long id_U;//预定用户编号 
	long id_C;//预定商品编号 
	long id_B;//预定商家编号 
	int state;
	//0-3：商家已取消未确认、已确认、已完成；4-6用户未评价、已评价、被取消 
	time_t tm;//订单状态更改时间 
	int pj;//订单评价 
}Order;

typedef struct{
	long id;//商品编号 
	char name[20];//商品名称 
	float cost;
	float price;//商品价格 
	int number;//商品总量 
	int sold;//已售总量 
	long id_B;//所属商家编号 
	float pj;//商品综合评价 
	int state;//商品状态：7：管理员下架；8：正常 
	char tm[26];//商品状态更改时间 
}Commodity;
void pingjia()
{
/*
评价函数：主要读取用户的评价  做出最终总的评价结果 随函数返回调用的地方
加权平均分

读取文件之后，读出评价分数之后进行处理 
*/
	int len,len1,count;
	FILE *fp,*fp1;
	Commodity com[M];
	Order order[M];
	int sum1,sum2;
	float mark[M];
	fp=fopen("Order.dat","rb");

	fp1=fopen("Commodity.dat","rb+");
	
	printf("尊敬的管理员您好！\n");
	printf("******这是评价管理后台*******\n");
	int pj;//订单评价 
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
sum1 占据60%
sum2 占据40%
订单数量大于 某一个特定值的时候，define E 5
低于五单的时候，比分占据70 30
 
*/
		
	for ( i=0; i<len ; i++)
		fwrite(&com[i],sizeof(Commodity),1,fp);
	
	
	
	
	
		
	
	fclose(fp);
	return ;
 } 
