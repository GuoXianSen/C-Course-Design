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
			printf("\n\n\t\t\t1��������Ʒ\n\t\t\t2����ѯ��Ʒ\n\t\t\t3���޸���Ʒ\n4���������еĸ���\n\t\t\t0: �˳�\n");
			fflush(stdin);
			a = getche();
			if(a == '1'||a == '2'||a == '3'||a == '4'||a == '0') {
				break;
			} else {
				system("cls");
				printf("\n\n\t\t\t�����������������\n���������Լ���");
				getche();
			}
		} while(1);
		if(a == '1') {
			system("cls");
			printf("\n\n\t\t\t������Ʒ����\n");
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
//������Ʒ��Ϣ 
void B_aid_c(long B_id, Commodity *c, int i){
	char r;
	printf("\n\t\t\t��������Ʒ���ƣ�");
	fflush(stdin);
	gets(c[i].name);
	printf("\t\t\t��������Ʒ�ɱ���");
	scanf("%f", &c[i].cost);
	printf("\t\t\t��������Ʒ���ۣ�");
	scanf("%f", &c[i].price );
	fflush(stdin);
	printf("\t\t\t��������Ʒ������");
	scanf("%d", &c[i].number);
	system("cls");
	c[i].id = c[i-1].id +1;
	c[i].sold = 0;
	c[i].id_B = B_id;
	c[i].pj = 0;
	c[i].state = 8;
	mytime(&c[i].tm[0]);
	system("cls");
	printf("\n\t\t\t��ȷ����������ݣ�\n");
	B_print_c(&c[i]);
	printf("\n----------\n");
	printf("\t\t�������������");
	getch();
	system("cls"); 
	return ;
}
//�����Ʒ��Ϣ
void B_print_c(Commodity *c){
	printf("\t\t\t��Ʒ���ƣ�");
	puts(c->name);
	printf("\t\t\t��Ʒ��ţ�%ld\n", c->id );
	printf("\t\t\t��Ʒ�ɱ���%.2f\tԪ\n\t\t\t��Ʒ���ۣ�%.2f\tԪ\n\t\t\t��Ʒ������%d\n\t\t\tԤ�����棺%.2f\n\t\t\t�޸�ʱ�䣺",c->cost , c->price ,c->number ,(c->price -c->cost )*c->number);
	mytime(&c->tm[0] );
	return ;
}
//��ѯ��Ʒ 
void B_s_c(long B_id, Commodity *c, int i){
	int j = i, sum = 0;
	char a; 
	system("cls");
	printf("����ѯ����������Ʒ�б����£�\n");
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
		printf("\n\n\t\t\t��Ǹ������û����Ʒ���,ȥ������Ʒ���԰�\n");
		printf("\t\t\t1�����ھ�ȥ������Ʒ\n\t\t\t�����������\t���ˣ��Ժ���˵\n");
		a = getch();
		if(a == '1') {
			system("cls");
			printf("\n\n\t\t\t������������Ʒϵͳ\n");
			B_aid_c( B_id, &c[0], i);
		}
	}else{
		printf("\n\t\t\t��ͳ�ƣ���������Ʒ %d ��", sum);
		printf("\n----------\n\t\t\t�Ƿ���Ҫ�޸�ĳЩ��Ʒ��Ϣ��\n");
		printf("\t\t\t1:�ǵģ������޸������Ʒ......\n\t\t\t�����������\t�������һ�ȥ��\n");
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
		printf("\n\t\t\t��������Ʒ�޸�ϵͳ����������Ҫ�޸ĵ���Ʒ��ţ�������0���˳���");
		scanf("%ld", &id);
		if(id == 0){
			break;
		}
		for( i = 0 ; i < j ; i++){
			if(B_id == c[i].id_B && id == c[i].id ){
				system("cls");
				printf("\n\t\t\t����Ʒ����״̬Ϊ��\n");
				B_print_c(&c[i]); 
				printf("\n----------\n");
				printf("\t\t\t�޸�Ϊ��\n");
				B_aid_c(B_id, &c[0], i);
				pan = 0;
			}
		}
		if(pan ){
			system("cls");
			printf("\n\n\t\t\t��ѯ��������Ȩ��ѯ����Ʒ������������\n");
			printf("\t\t����������Լ���\n");
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
		printf("\n\n\t\t\t�Ƿ񱣴����������ĸ��ģ�\n\t1.�ǵ�\n\t2.����ȫ������\n");
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
			printf("\n\n\t\t\t�ѳɹ�д����ģ�����������Լ���"); 
			getch();
			break;
		}else if(b =='2'){
			system("cls");
			printf("\n\n\t\t\t���������������ĸ��ģ��Ƿ�ȷ�ϣ�\n\t\t\t\1.�ǵģ��Ҿ��������˼\n\t\t\t2.�����ո��Ұ�����\n");
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
				printf("\n\n\t\t\t�ѳɹ�ɾ�����ģ�����������Լ���"); 
				getch();
				break;
			}else if( b =='2'){
				continue;
			}
		}
	}while(1);
	
	return ;
}
