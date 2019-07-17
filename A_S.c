# include  "type.h"
void ad_search(){
	char a;
	do{
		printf("\n\n��Ҫ����ʲô��ѯ����\n");
		printf("\t1.��Ʒ���\n\t2.�̼ұ��\n\t3.������\n\t4.�û����\n"); 
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
			printf("���������밴�����������������\n");
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
		printf("��Ʒ��ѯϵͳ��\n----------\n��������Ʒ��Ų�ѯ����������ȷ����Ʒ��ţ�������0���˳�:\n");
		scanf("%ld", &id);
		if(id == 0) break;
		for( i = 0 ; i <= tem; i++){
			if(id == c[i].id ){
				A_print_C(&c[i]);
				printf("�Ƿ���Ҫ�����¼ܻ����»ָ���\n\t1:��\n\t2:����������ѯ������Ʒ"); 
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
			printf("����������޴˱�ŵ���Ʒ�����֤������\n����������Լ���");
			getch();
		}
	}while(1);
	fp = fopen("Commodity.dat", "wb");
	do{
		char b = 0;
		system("cls");
		printf("�Ƿ񱣴����������ĸ��ģ�\n\t1.�ǵ�\n2.����ȫ������\n");
		b = getche();
		if(b == '1'){
			
			for(i = 0; i <= tem; i++){
				fwrite(&c[i], sizeof(Commodity), 1, fp);
			}
			break;
		}else if(b =='2'){
			printf("���������������ĸ��ģ��Ƿ�ȷ�ϣ�\n\t1.�ǵģ��Ҿ��������˼\n\t2.�����ո��Ұ�����\n");
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
	
	printf("��Ʒ��ţ�\t%ld\n��Ʒ���ƣ�", c->id);
	puts(c->name );
	printf("�����̼ң�\t%ld\n", c->id_B );
	printf("��Ʒ�۸�\t%f\n", c->cost );
	printf("��Ʒ������\t%d\n", c->number );
	printf("����������\t%d\n", c->sold );
	printf("��Ʒ�ۺ����ۣ�\t%f\n", c->pj );
	printf("��Ʒ״̬��\t%d", c->state );
	printf("���һ����Ʒ��Ϣ����ʱ�䣺\t%s\n", c->tm );
	
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
		printf("�̼Ҳ�ѯϵͳ��\n----------\n�������̼ұ�Ų�ѯ����������ȷ����Ʒ��ţ�������0���˳�:\n");
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
			printf("����������޴˱�ŵ��̼ң����֤������\n����������Լ���");
			getch();
		}
	}while(1);
	return ;
}

void A_print_B(Business *b){
	printf("�̼ұ�ţ�\t%ld\n", b->id_B);
	printf("�̼����ƣ�\t%s", b->name);
	printf("�̼��ֻ��ţ�%s\n", b->phone);
	printf("�̼����䣺  %s\n", b->e); 
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
		printf("������ѯϵͳ��\n----------\n�����ݶ�����Ų�ѯ����������ȷ�Ķ�����ţ�������0���˳�:\n");
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
			printf("����������޴˱�ŵĶ��������֤������\n����������Լ���");
			getch();
		}
	}while(1);
	return ;
}

void A_print_O( Order *o){
	system("cls");
	printf("������ţ�\t%ld\n", o->id );
	printf("Ԥ���û���\t%ld\n", o->id_U );
	printf("�����̼ң�\t%ld\n", o->id_B );
	printf("Ԥ����Ʒ��\t%ld\n", o->id_C );
	printf("����״̬��\t%d\n", o->state );
	printf("����ʱ�䣺");
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
		printf("�û���ѯϵͳ��\n----------\n�������û���Ų�ѯ����������ȷ���û���ţ�������0���˳�:\n");
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
			printf("����������޴˱�ŵ��û������֤������\n����������Լ���");
			getch();
		}
	}while(1);
	return ;
}

void A_print_U(User *u){
	printf("�û���ţ�\t%ld\n",u->id_U  );
	printf("�û���  ��\t%s\n",u->name );
	printf("�û��ֻ���\t%s\n",u->phone );
	printf("�û����䣺\t%s\n",u->e );
	return ;
}
