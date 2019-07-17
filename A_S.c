# include  "type.h"
void ad_search(){
	char a;
	do{
		printf("\n\n想要根据什么查询？：\n");
		printf("\t1.商品编号\n\t2.商家编号\n\t3.订单号\n\t4.用户编号\n"); 
		a = getch();
		if(a == '1'){
			A_S_C();
		}else if(a == '2'){
			A_S_B();
		}else if(a == '3'){
			A_S_O(); 
		}else if(a == '4'){
			A_S_U();
		}else if(a == '0'){
			break;
		}else {
			system("cls");
			printf("输入有误，请按下任意键后重新输入\n");
			getch(); 
		} 
	}while(a != '0');
	
	return ;
}

void A_S_C(){
	long id, i, a;
	Commodity c[10000];
	FILE *fp = fopen("Commodity_t.dat", "rb");
	if(fp == NULL){
		printf("ERROR:A_S_C:Commodity_t.dat:rb");
		exit(0);
	}
	for(i = 0; !feof(fp); i++){
		fread(&c[i], sizeof( Commodity), 1, fp);
	}
	fclose(fp);
	long tem = i-2;
	do{
		id = -1;
		int pan = 0;
		system("cls");
		printf("商品查询系统：\n----------\n将根据商品编号查询，请输入正确的商品编号，或输入0以退出:\n");
		scanf("%ld", &id);
		if(id == 0) break;
		for( i = 0 ; i <= tem; i++){
			if(id == c[i].id ){
				A_print_C(&c[i]);
				printf("是否需要将其下架或重新恢复？\n\t1:是\n\t2:不，继续查询其他商品"); 
				scanf("%d", &a);
				if(a == 1){
					c[i].state == 7 ? 8:7;
				}
				pan = 1;
				break;
			}
		}
		if (pan == 0){
			system("cls");
			printf("输入有误或无此编号的商品，请查证后重输\n按下任意键以继续");
			getch();
		}
	}while(1);
	fp = fopen("Commodity.dat", "wb");
	do{
		char b = 0;
		system("cls");
		printf("是否保存所有已做的更改？\n\t1.是的\n2.不，全部舍弃\n");
		b = getche();
		if(b == '1'){
			
			for(i = 0; i <= tem; i++){
				fwrite(&c[i], sizeof(Commodity), 1, fp);
			}
			break;
		}else if(b =='2'){
			printf("将丢弃所有已做的更改，是否确认？\n\t1.是的！我就是这个意思\n\t2.不，刚刚我按错了\n");
			b = getche();
			if(b == '1'){
				break;
			}else if( b =='2'){
				continue;
			}
		}
	}while(1);
	fclose(fp);
	return ;
}

void A_print_C(Commodity *c){
	
	printf("商品编号：\t%ld\n商品名称：", c->id);
	puts(c->name );
	printf("所属商家：\t%ld\n", c->id_B );
	printf("商品价格：\t%f\n", c->cost );
	printf("商品数量：\t%d\n", c->number );
	printf("已售总量：\t%d\n", c->sold );
	printf("商品综合评价：\t%f\n", c->pj );
	printf("商品状态：\t%d", c->state );
	printf("最后一次商品信息更改时间：\t%s\n", c->tm );
	
	return ;
}

void A_S_B(){
	long id, i, a;
	Business b[10000];
	FILE *fp = fopen("business.dat", "rb");
	if(fp == NULL){
		printf("ERROR:A_S_B:business.dat:rb");
		exit(0);
	}
	for(i = 0; !feof(fp); i++){
		fread(&b[i], sizeof( Business), 1, fp);
	}
	fclose(fp);
	long tem = i-2;
	do{
		id = -1;
		int pan = 0;
		system("cls");
		printf("商家查询系统：\n----------\n将根据商家编号查询，请输入正确的商品编号，或输入0以退出:\n");
		scanf("%ld", &id);
		if(id == 0) break;
		for( i = 0 ; i <= tem; i++){
			if(id == b[i].id_B ){
				A_print_B(&b[i]);
				pan = 1;
				break;
			}
		}
		if (pan == 0
		){
			system("cls");
			printf("输入有误或无此编号的商家，请查证后重输\n按下任意键以继续");
			getch();
		}
	}while(1);
	return ;
}

void A_print_B(Business *b){
	printf("商家编号：\t%ld\n", b->id_B);
	printf("商家名称：\t%s", b->name);
	printf("商家手机号：%s\n", b->phone);
	printf("商家邮箱：  %s\n", b->e); 
	return; 
} 

void A_S_O(){
	long id, i, a;
	Order o[10000];
	FILE *fp = fopen("order_t.dat", "rb");
	if(fp == NULL){
		printf("ERROR:A_S_O:order_t.dat:rb");
		exit(0);
	}
	for(i = 0; !feof(fp); i++){
		fread(&o[i], sizeof( Order), 1, fp);
	}
	fclose(fp);
	long tem = i-2;
	do{
		id = -1;
		int pan = 0;
		system("cls");
		printf("订单查询系统：\n----------\n将根据订单编号查询，请输入正确的订单编号，或输入0以退出:\n");
		scanf("%ld", &id);
		if(id == 0) break;
		for( i = 0 ; i <= tem; i++){
			if(id == o[i].id  ){
				A_print_O(&o[i]);
				pan = 1;
				break;
			}
		}
		if (pan == 0){
			system("cls");
			printf("输入有误或无此编号的订单，请查证后重输\n按下任意键以继续");
			getch();
		}
	}while(1);
	return ;
}

void A_print_O( Order *o){
	system("cls");
	printf("订单编号：\t%ld\n", o->id );
	printf("预定用户：\t%ld\n", o->id_U );
	printf("所属商家：\t%ld\n", o->id_B );
	printf("预定商品：\t%ld\n", o->id_C );
	printf("订单状态：\t%d\n", o->state );
	printf("订单时间：");
	puts(o->tm );
	
	return ;
}

void A_S_U(){
	long id, i, a;
	User u[10000];
	FILE *fp = fopen("user.dat", "rb");
	if(fp == NULL){
		printf("ERROR:A_S_U:user.dat:rb");
		exit(0);
	}
	for(i = 0; !feof(fp); i++){
		fread(&u[i], sizeof( User), 1, fp);
	}
	fclose(fp);
	long tem = i-2;
	do{
		id = -1;
		int pan = 0;
		system("cls");
		printf("用户查询系统：\n----------\n将根据用户编号查询，请输入正确的用户编号，或输入0以退出:\n");
		scanf("%ld", &id);
		if(id == 0) break;
		for( i = 0 ; i <= tem; i++){
			if(id == u[i].id_U ){
				A_print_U(&u[i]);
				pan = 1;
				break;
			}
		}
		if (pan == 0){
			system("cls");
			printf("输入有误或无此编号的用户，请查证后重输\n按下任意键以继续");
			getch();
		}
	}while(1);
	return ;
}

void A_print_U(User *u){
	printf("用户编号：\t%ld\n",u->id_U  );
	printf("用户名  ：\t%s\n",u->name );
	printf("用户手机：\t%s\n",u->phone );
	printf("用户邮箱：\t%s\n",u->e );
	return ;
}
