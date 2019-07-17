# include  "type.h"
# include  "type.h"
int B_order(long B_id){
	Order o[1000];
	int i, a=11;
	char b;
	FILE *fp = fopen("Order.dat", "rb");
	if(fp ==NULL){
		printf("ERROR:B_order:order.dat:rb");
		exit(0);
	}
	for(i = 0; !feof(fp); i++){
		fread(&o[i], sizeof(Order), 1, fp);
	}
	fclose(fp);
	i-=1;
	while( a != 0){
		system("cls");
		printf("请选择想要查询的订单状态：\n\t1:\t未确认；\n\t2:\t已确认；\n\t3:\t已完成；\n\t0:\t退出。\n--------------------\n"); 
		scanf("%d", &a);
		if(a == 1||a == 2||a == 3||a == 0) {
			if(a == 0){
				break;
			}
			int pan;
			pan = B_print_o(a, B_id, &o[0], i);
			if(pan == 0){
				system("cls");
				printf("未查询到该状态下的订单\n"); 
				printf("--------------------\n键入任意键以继续"); 
				getche();
				continue;
			}
			if(a == 1){
				B_O_1(B_id, &o[0], i);
			}else if(a == 2){
				B_O_2(B_id, &o[0], i);
			}
		}else {
			system("cls");
			printf("输入有误，请重新输入\n--------------------\n");
		}
		printf("--------------------\n输入任意键以继续");
		getche();
	}
	char cc;
	int len = i-1;
	do {
		system("cls");
		printf("是否保存全部修改？（如未修改请选否）\n\t1:是\n\t其它任意键:否\n");
		cc = getch();
		if(cc = 1){
			fp = fopen("Order.dat", "wb");
			for( i = 0 ; i <= len; i++){
				fwrite(&o[i], sizeof(Order), 1, fp);
			}
			fclose(fp);
			break;
		}else if (cc =='2'){
			printf("将丢失所有未保存的数据，是否确认？\n\t1：是的，我不要了\n\t2：不，刚刚按错了\n");
		}
	}while(1);
	return 0;
}

int B_print_o(int a, long id, Order *o, int i){
	system("cls");
	int num = 0; 
	printf("正在查询");
	if(a == '1'){
		printf(" 未确认 ");
	}else if( a == '2'){
		printf(" 已确认 ");
	}else if(a == '3'){
		printf(" 已完成 ");
	}
	printf("状态下的订单----------\n");
	printf("订单编号\t下单用户\t预定商品\t下单时间\n"); 
	while(i>0){
    	if(o[i].state == a && o[i].id_B == id){
			printf("%ld\t%ld\t%ld\t", o[i].id, o[i].id_U, o[i].id_C);
			//年份 
			printf("%c%c%c%c年", o[i].tm[20], o[i].tm[21], o[i].tm[22], o[i].tm[23]); 
			//月份
			switch(o[i].tm[4]){
				case 'J':
					o[i].tm[5] == 'a' ? printf("1月") : (o[i].tm[7] == 'n' ? printf("6月") : printf("7月"));
					break; 
				case 'F':
					printf("2月");
					break; 
				case 'M':
					o[i].tm[5] == 'a' ? printf("3月") : printf("5月");
					break; 
				case 'A':
					o[i].tm[5] == 'p' ? printf("4月") : printf("8月");
					break; 
				case 'S':printf("9月");break; 
				case 'O':printf("10月");break; 
				case 'N':printf("11月");break; 
				case 'D':printf("12月");break;
			} 
			//日期
			printf("%c%c日", o[i].tm[8], o[i].tm[9]);
			//时间
			printf("%c%c时%c%c分%c%c秒 ", o[i].tm[11], o[i].tm[12], o[i].tm[14], o[i].tm[15], o[i].tm[17], o[i].tm[18]);
			//星期几 
			switch(o[i].tm[0]){
				case 'M':
					printf("星期一 ");break; 
				case 'T':
					o[i].tm[1] == 'u' ? printf("星期二 "):printf("星期四 ");
					break;
				case 'W':
					printf("星期三 ");break;
				case 'F':
					printf("星期五 ");break; 
				case 'S':
					o[i].tm[1] == 'u' ? printf("星期日 "):printf("星期六 "); 
			} 
			printf("\n");
			num++; 
		}
		i--;
	}
	printf("共计%d条数据\n", num);
	getch();
	
	return num;
} 

void B_O_1(long id, Order *o, int i){
	printf("是否要接受全部订单或只接受第一条？\n\t1:只接受第一条\n\t或按下其它任意键全部接受\n");
	char a;
	Commodity c[1000];
	int j, x;
	FILE *fp = fopen("Commodity.dat", "rb");
	for(x = 0; !feof(fp); x++){
		fread(&c[x], sizeof(Commodity), 1, fp); 
	}
	fclose(fp);
	fp = fopen("Commodity.dat", "wb");
	a = getche();
	if(a =='1'){
		for( i ; i > 0 ; i--){
			if(id == o[i].id_B && o[i].state == 1){
				o[i].state = 2;
				for(j = 0 ;j < x; j++)
					if(o[i].id_C == c[j].id )
						c[j].number --;
				for(j = 0; j < x; j++){
					fwrite(&c[j], sizeof(Commodity), 1, fp);
				}
				fclose(fp);
				break;
			}
		} 
		
	}else {
		for( i ; i > 0 ; i--){
			if(id == o[i].id_B && o[i].state == 1){
				o[i].state = 2;
				for(j = 0 ;j < x; j++){
					if(o[i].id_C == c[j].id )
						c[j].number --;
				}
			}
		} 
	}
	for(j = 0; j < x; j++){
		fwrite(&c[j], sizeof(Commodity), 1, fp);
	}
	fclose(fp);
	return ;
}

void B_O_2(long id, Order *o, int i){
	printf("是否完成全部订单或只完成第一条？\n\t1:只完成第一条\n\t或按下其它任意键全部完成\n");

	char a;
	a = getche();
	if(a =='1'){
		for( i ; i > 0 ; i--){
			if(id == o[i].id_B && o[i].state == 2){
				o[i].state = 3;
				
				break;
			}
		} 
	}else {
		for( i ; i > 0 ; i--){
			if(id == o[i].id_B && o[i].state == 2){
				o[i].state = 3;
			}
		} 
	}
	return ;
}

