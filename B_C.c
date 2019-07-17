# include  "type.h"

void B_Commodity(long B_id) {
	char a;
	int i;
	Commodity c[1000];
	FILE *fp = fopen ("Commodity.dat", "rb");
	if(fp == NULL){
		printf("ERROR:B_Com:Commodity.dat:rb");
		exit(0);
	}
	for(i = 0; !feof(fp); i++){
		fread(&c[i], sizeof(Commodity), 1, fp);
	}
	i-=1;
	printf("%d\n", i);
	getch();
	fclose(fp);
	
	do{
		do {
			system("cls");
			printf("\n\n\t\t\t1：增加商品\n\t\t\t2：查询商品\n\t\t\t3：修改商品\n4：保存已有的更改\n\t\t\t0: 退出\n");
			fflush(stdin);
			a = getche();
			if(a == '1'||a == '2'||a == '3'||a == '4'||a == '0') {
				break;
			} else {
				system("cls");
				printf("\n\n\t\t\t输入错误，请重新输入\n键入任意以继续");
				getche();
			}
		} while(1);
		if(a == '1') {
			system("cls");
			printf("\n\n\t\t\t增加商品操作\n");
			B_aid_c( B_id, &c[0], i);
			i++;
		}else if(a == '2'){
			B_s_c(B_id, &c[0], i);
		}else if(a == '3'){
			B_change_c(B_id, &c[0], i);
		}else if(a == '4'){
			B_save_c(&c[0], &i);
		}
	}while(a!='0');
	
	B_save_c(&c[0], &i);
	
	return ;
}
//输入商品信息 
void B_aid_c(long B_id, Commodity *c, int i){
	char r;
	printf("\n\t\t\t请输入商品名称：");
	fflush(stdin);
	gets(c[i].name);
	printf("\t\t\t请输入商品成本：");
	scanf("%f", &c[i].cost);
	printf("\t\t\t请输入商品单价：");
	scanf("%f", &c[i].price );
	fflush(stdin);
	printf("\t\t\t请输入商品总量：");
	scanf("%d", &c[i].number);
	system("cls");
	c[i].id = c[i-1].id +1;
	c[i].sold = 0;
	c[i].id_B = B_id;
	c[i].pj = 0;
	c[i].state = 8;
	mytime(&c[i].tm[0]);
	system("cls");
	printf("\n\t\t\t请确认输入的数据：\n");
	B_print_c(&c[i]);
	printf("\n----------\n");
	printf("\t\t按下任意键返回");
	getch();
	system("cls"); 
	return ;
}
//输出商品信息
void B_print_c(Commodity *c){
	printf("\t\t\t商品名称：");
	puts(c->name);
	printf("\t\t\t商品编号：%ld\n", c->id );
	printf("\t\t\t商品成本：%.2f\t元\n\t\t\t商品单价：%.2f\t元\n\t\t\t商品总量：%d\n\t\t\t预期收益：%.2f\n\t\t\t修改时间：",c->cost , c->price ,c->number ,(c->price -c->cost )*c->number);
	mytime(&c->tm[0] );
	return ;
}
//查询商品 
void B_s_c(long B_id, Commodity *c, int i){
	int j = i, sum = 0;
	char a; 
	system("cls");
	printf("经查询，您现有商品列表如下：\n");
	for( i = 0 ; i < j ; i ++){
		if(B_id == c[i].id_B ){
			printf("\t\t\t----------\n\n"); 
			B_print_c(&c[i]);
			printf("\t\t\t----------\n\n"); 
			sum ++;
		}
	}
	if(sum == 0){
		system("cls");
		printf("\n\n\t\t\t抱歉，您还没有商品入库,去增加商品试试吧\n");
		printf("\t\t\t1：现在就去增加商品\n\t\t\t其他任意键：\t算了，以后再说\n");
		a = getch();
		if(a == '1') {
			system("cls");
			printf("\n\n\t\t\t这里是增加商品系统\n");
			B_aid_c( B_id, &c[0], i);
		}
	}else{
		printf("\n\t\t\t经统计，您共有商品 %d 件", sum);
		printf("\n----------\n\t\t\t是否需要修改某些商品信息？\n");
		printf("\t\t\t1:是的，我想修改这件商品......\n\t\t\t其他任意键：\t不！让我回去！\n");
		a = getch();
		if(a == '1'){
			B_change_c(B_id, &c[0], i);
		}
	}
	return ;
}

void B_change_c(long B_id, Commodity *c, int i){
	long id;
	int j = i, pan= 1;
	do{
		printf("\n\t\t\t这里是商品修改系统，请输入想要修改的商品编号，或输入0以退出：");
		scanf("%ld", &id);
		if(id == 0){
			break;
		}
		for( i = 0 ; i < j ; i++){
			if(B_id == c[i].id_B && id == c[i].id ){
				system("cls");
				printf("\n\t\t\t该商品现在状态为：\n");
				B_print_c(&c[i]); 
				printf("\n----------\n");
				printf("\t\t\t修改为：\n");
				B_aid_c(B_id, &c[0], i);
				pan = 0;
			}
		}
		if(pan ){
			system("cls");
			printf("\n\n\t\t\t查询不到或无权查询该商品，请重新输入\n");
			printf("\t\t键入任意键以继续\n");
			getch();
		}
	}while(1);
	return ;
}

void B_save_c( Commodity *c, int *i){
	
	do{
		int tem = *i, j;
		char b = 0;
		system("cls");
		printf("\n\n\t\t\t是否保存所有已做的更改？\n\t1.是的\n\t2.不，全部舍弃\n");
		b = getch();
		if(b == '1'){
			FILE *fp = fopen("Commodity.dat", "wb");
			if(fp == NULL){
				printf("ERROR:B_C:B_save_c:Commodity.dat:wb");
				exit(0);
			}
			for(tem = 0; tem < *i; tem++){
				fwrite(c+tem, sizeof(Commodity), 1, fp);
			}
			fclose(fp);
			system("cls");
			printf("\n\n\t\t\t已成功写入更改，键入任意键以继续"); 
			getch();
			break;
		}else if(b =='2'){
			system("cls");
			printf("\n\n\t\t\t将丢弃所有已做的更改，是否确认？\n\t\t\t\1.是的！我就是这个意思\n\t\t\t2.不，刚刚我按错了\n");
			b = getch();
			if(b == '1'){
				FILE *fp = fopen("Commodity.dat", "rb");
				if(fp == NULL){
					printf("ERROR:B_C:B_save_c:Commodity.dat:rb");
					exit(0);
				}
				for(j = 0; !feof(fp); j++){
					fread(c+j, sizeof(Commodity), 1, fp);
				}
				*i-=1;
				fclose(fp);
				system("cls");
				printf("\n\n\t\t\t已成功删除更改，键入任意键以继续"); 
				getch();
				break;
			}else if( b =='2'){
				continue;
			}
		}
	}while(1);
	
	return ;
}
