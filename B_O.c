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
		printf("��ѡ����Ҫ��ѯ�Ķ���״̬��\n\t1:\tδȷ�ϣ�\n\t2:\t��ȷ�ϣ�\n\t3:\t����ɣ�\n\t0:\t�˳���\n--------------------\n"); 
		scanf("%d", &a);
		if(a == 1||a == 2||a == 3||a == 0) {
			if(a == 0){
				break;
			}
			int pan;
			pan = B_print_o(a, B_id, &o[0], i);
			if(pan == 0){
				system("cls");
				printf("δ��ѯ����״̬�µĶ���\n"); 
				printf("--------------------\n����������Լ���"); 
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
			printf("������������������\n--------------------\n");
		}
		printf("--------------------\n����������Լ���");
		getche();
	}
	char cc;
	int len = i-1;
	do {
		system("cls");
		printf("�Ƿ񱣴�ȫ���޸ģ�����δ�޸���ѡ��\n\t1:��\n\t���������:��\n");
		cc = getch();
		if(cc = 1){
			fp = fopen("Order.dat", "wb");
			for( i = 0 ; i <= len; i++){
				fwrite(&o[i], sizeof(Order), 1, fp);
			}
			fclose(fp);
			break;
		}else if (cc =='2'){
			printf("����ʧ����δ��������ݣ��Ƿ�ȷ�ϣ�\n\t1���ǵģ��Ҳ�Ҫ��\n\t2�������ոհ�����\n");
		}
	}while(1);
	return 0;
}

int B_print_o(int a, long id, Order *o, int i){
	system("cls");
	int num = 0; 
	printf("���ڲ�ѯ");
	if(a == '1'){
		printf(" δȷ�� ");
	}else if( a == '2'){
		printf(" ��ȷ�� ");
	}else if(a == '3'){
		printf(" ����� ");
	}
	printf("״̬�µĶ���----------\n");
	printf("�������\t�µ��û�\tԤ����Ʒ\t�µ�ʱ��\n"); 
	while(i>0){
    	if(o[i].state == a && o[i].id_B == id){
			printf("%ld\t%ld\t%ld\t", o[i].id, o[i].id_U, o[i].id_C);
			//��� 
			printf("%c%c%c%c��", o[i].tm[20], o[i].tm[21], o[i].tm[22], o[i].tm[23]); 
			//�·�
			switch(o[i].tm[4]){
				case 'J':
					o[i].tm[5] == 'a' ? printf("1��") : (o[i].tm[7] == 'n' ? printf("6��") : printf("7��"));
					break; 
				case 'F':
					printf("2��");
					break; 
				case 'M':
					o[i].tm[5] == 'a' ? printf("3��") : printf("5��");
					break; 
				case 'A':
					o[i].tm[5] == 'p' ? printf("4��") : printf("8��");
					break; 
				case 'S':printf("9��");break; 
				case 'O':printf("10��");break; 
				case 'N':printf("11��");break; 
				case 'D':printf("12��");break;
			} 
			//����
			printf("%c%c��", o[i].tm[8], o[i].tm[9]);
			//ʱ��
			printf("%c%cʱ%c%c��%c%c�� ", o[i].tm[11], o[i].tm[12], o[i].tm[14], o[i].tm[15], o[i].tm[17], o[i].tm[18]);
			//���ڼ� 
			switch(o[i].tm[0]){
				case 'M':
					printf("����һ ");break; 
				case 'T':
					o[i].tm[1] == 'u' ? printf("���ڶ� "):printf("������ ");
					break;
				case 'W':
					printf("������ ");break;
				case 'F':
					printf("������ ");break; 
				case 'S':
					o[i].tm[1] == 'u' ? printf("������ "):printf("������ "); 
			} 
			printf("\n");
			num++; 
		}
		i--;
	}
	printf("����%d������\n", num);
	getch();
	
	return num;
} 

void B_O_1(long id, Order *o, int i){
	printf("�Ƿ�Ҫ����ȫ��������ֻ���ܵ�һ����\n\t1:ֻ���ܵ�һ��\n\t�������������ȫ������\n");
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
	printf("�Ƿ����ȫ��������ֻ��ɵ�һ����\n\t1:ֻ��ɵ�һ��\n\t�������������ȫ�����\n");

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

