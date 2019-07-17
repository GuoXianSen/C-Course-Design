# include  "type.h"
# define N 1000
//long int startid=40000;//��ʱ��ȫ�ֱ�����Ϊ��֪��
////////////////////////////////////�����ṹ��

/*void mainmenu(long int startid);
void search2(Commodity *s,int len,long int startid);*/
///////////////////////////////////��ȡ��Ʒ��Ϣ
int fileread(Commodity *s) {
	int i;
	int len=0;
	FILE *fp;
	fp=fopen("Commodity.dat","rb");
	if(fp==NULL) {
		printf("file open error!\n");
		exit(0);
	}
	while(!feof(fp)) {
		fread(&s[len++],sizeof(Commodity),1,fp);
	}

	fclose(fp);
	return len-1;
}
//////////////////////////////////////////�����Ʒ��Ϣ
void output(Commodity *s,int len) {
	int i;
	for(i=0; i<len; i++) {
		printf("��ţ�%ld\n",s[i].id);
		printf("���ƣ�%s\n",s[i].name);
		printf("�۸�%5.2f\n",s[i].price);
		printf("������%d\n",s[i].number);
		printf("����������%d\n",s[i].sold);
		printf("�����̼ұ�ţ�%ld\n",s[i].id_B);
		printf("�ۺ�����:%3.2f\n",s[i].pj);
		printf("����ƷĿǰ��״̬:");
		switch(s[i].state) {
			case 1:
				printf("����\n");
				break;
			case 0:
				printf("�ۿ�\n");
		}
		printf("\n*************\n");
	}

}
//////////////////////////////////����������
void range1(Commodity *s,int len) {
	int i,j,k;
	Commodity t;
	for(i=0; i<len-1; i++) {
		k=i;
		for(j=i+1; j<len; j++) {
			if(s[k].sold<s[j].sold)
				k=j;
		}
		t=s[k];
		s[k]=s[i];
		s[i]=t;

	}
}
////////////////////////////////////////���۸�����
void range2(Commodity *s,int len) {
	int i,j,k;
	Commodity t;
	for(i=0; i<len-1; i++) {
		k=i;
		for(j=i+1; j<len; j++) {
			if(s[k].price>s[j].price)
				k=j;
		}
		t=s[k];
		s[k]=s[i];
		s[i]=t;

	}
}
//////////////////////////////////////�����ֽ���
void range3(Commodity *s,int len) {
	int i,j,k;
	Commodity t;
	for(i=0; i<len-1; i++) {
		k=i;
		for(j=i+1; j<len; j++) {
			if(s[k].pj<s[j].pj)
				k=j;
		}
		t=s[k];
		s[k]=s[i];
		s[i]=t;

	}
}
////////////////////////////�µ�����
void gobuy(Commodity si,long int startid) {
	Order p[N];
	Order s3;
	FILE *fp;
	int len=0;
	fp=fopen("Order.dat","ab+");
	if(fp==NULL) {
		printf("file open error!");
		exit(0);
	}
	while(!feof(fp)) {
		fread(&p[len++],sizeof(Order),1,fp);
	}
	s3.id=p[len-2].id+1;
	s3.id_U=startid;
	s3.id_C=si.id;
	s3.id_B=si.id_B;
	s3.state=1;
	mytime(&s3.tm[0]);////////////
	s3.pj=0;
	rewind(fp);
	fwrite(&s3,sizeof(Order),1,fp) ;
	fclose(fp);
	printf("\n�µ��ɹ�����ȴ��̼����ͣ�\n");
}
/////////////////////////////////////���̼�����
void search1(Commodity *s,int len,long int startid) {
	int i;
	int count=0;
	int count1=0;
	long int num,num1;
	char judge;
	printf("\n�������̼ұ�ţ�\n");
	do {
		scanf("%ld",&num);
		count1++;
		system("cls");
		for(i=0; i<len; i++) {
			if(s[i].id_B==num) {
				printf("��ţ�%ld\n",s[i].id);
				printf("���ƣ�%s\n",s[i].name);
				printf("�۸�%5.2f\n",s[i].price);
				printf("������%d\n",s[i].number);
				printf("����������%d\n",s[i].sold);
				printf("�����̼ұ�ţ�%ld\n",s[i].id_B);
				printf("�ۺ�����:%3.2f\n",s[i].pj);
				printf("����ƷĿǰ��״̬:");
				switch(s[i].state) {
					case 1:
						printf("����\n");
						break;
					case 0:
						printf("�ۿ�\n");
				}
				printf("\n*************\n");
				count++;
			}
		}
		if(count==0) {
			printf("\nδ�ҵ����̼ң������������̼ұ��(��3�λ���,3�κ��Զ��˳�)��\n");
		}
		if(count1>3)
			return;
	} while(count==0);
	printf("\n���ҵ��˸��̼ҵ�%d������������!\n",count);
	printf("\n�Ƿ��빺����̼���Ʒ��Y/N?(��Сд����)��\n");
	do {
		getchar();////////
		judge=getchar();
		if(judge=='Y'||judge=='y')
			search2(s,len,startid);////////////
		else if(judge=='N'||judge=='n')
			return;//������һ���˵�
		else
			printf("\n��������������ѡ��\n");
	} while(judge!='Y'&&judge!='y'&&judge!='N'&&judge!='n');
}

//////////////////////////////////////����Ʒ����
void search2(Commodity *s,int len,long int startid) {
	int i;
	long int num;
	char judge;
	int count2=0;
	printf("\n��������Ʒ��ţ�\n");
	do {
		scanf("%ld",&num);
		count2++;
		system("cls");
		for(i=0; i<len; i++) {
			if(s[i].id==num) {
				printf("��ţ�%ld\n",s[i].id);
				printf("���ƣ�%s\n",s[i].name);
				printf("�۸�%5.2f\n",s[i].price);
				printf("������%d\n",s[i].number);
				printf("����������%d\n",s[i].sold);
				printf("�����̼ұ�ţ�%ld\n",s[i].id_B);
				printf("�ۺ�����:%3.2f\n",s[i].pj);
				printf("��ƷĿǰ��״̬��");
				switch(s[i].state) {
					case 1:
						printf("����\n");
						break;
					case 0:
						printf("�ۿ�\n");
				}///////////////////////////

				printf("\n*************\n");
				break;
			}
		}
		if(i>=len)
			printf("\nδ�ҵ�����Ʒ��������������Ʒ���(��3�λ���,3�κ��Զ��˳�)��\n");
		if(count2>3)
			return;
	}	while(i>=len);
	if(s[i].state ==0)
		printf("\n����Ʒ���ۿգ�\n");
	else {
		printf("\n�Ƿ���Ҫ�µ���Y/N(��Сд����)��\n");
		do {
			getchar();/////////////
			judge=getchar();
			if(judge=='Y'||judge=='y')
				gobuy(s[i],startid);
			else	if(judge=='N'||judge=='n')
				return;
			else
				printf("\n��������������ѡ��\n");
		} while(judge!='Y'&&judge!='y'&&judge!='N'&&judge!='n');
	}
}
////////////////////////////////////////////////////

//////////////////////////
void outputorder(Order *p,int len,long int startid) {
	int i;
	for(i=0; i<len; i++) {
		if(p[i].id_U==startid) {
			printf("\n������ţ�%ld\n",p[i].id);
			printf("Ԥ���û���ţ�%ld\n",p[i].id_U);
			printf("Ԥ����Ʒ��ţ�%ld\n",p[i].id_C);
			printf("Ԥ���̼ұ�ţ�%ld\n",p[i].id_B);
			printf("����Ŀǰ��״̬��");
				switch(p[i].state) {
				case 0:
					printf("�̼���ȡ��\n");
					break;
				case 1:
					printf("�̼�δȷ��\n");
					break;
				case 2:
					printf("�̼���ȷ��\n");
					break;
				case 3:
					printf("�̼������\n");
					break;
				case 5:
					printf("�û�������\n");
					break;
				case 6:
					printf("�û���ȡ��\n");/////////////////////////////////
			}
			printf("����״̬����ʱ�䣺");///////////////////
			//���
			printf("%c%c%c%c��", p[i].tm [20], p[i].tm[21], p[i].tm[22], p[i].tm[23]);
			//�·�
			switch(p[i].tm[4]) {
				case 'J':
					p[i].tm[5] == 'a' ? printf("1��") : (p[i].tm[7] == 'n' ? printf("6��") : printf("7��"));
					break;
				case 'F':
					printf("2��");
					break;
				case 'M':
					p[i].tm[5] == 'a' ? printf("3��") : printf("5��");
					break;
				case 'A':
					p[i].tm[5] == 'p' ? printf("4��") : printf("8��");
					break;
				case 'S':
					printf("9��");
					break;
				case 'O':
					printf("10��");
					break;
				case 'N':
					printf("11��");
					break;
				case 'D':
					printf("12��");
					break;
			}
			//����
			printf("%c%c��", p[i].tm[8], p[i].tm[9]);
			//ʱ��
			printf("%c%cʱ%c%c��%c%c�� ", p[i].tm[11], p[i].tm[12], p[i].tm[14], p[i].tm[15], p[i].tm[17], p[i].tm[18]);
			//���ڼ�
			switch(p[i].tm[0]) {
				case 'M':
					printf("����һ ");
					break;
				case 'T':
					p[i].tm[1] == 'u' ? printf("���ڶ� "):printf("������ ");
					break;
				case 'W':
					printf("������ ");
					break;
				case 'F':
					printf("������ ");
					break;
				case 'S':
					p[i].tm[1] == 'u' ? printf("������ "):printf("������ ");
			}

			printf("\n�������ۣ�%d\n",p[i].pj);
			printf("\n**************\n");
		}
	}

}
///////////////////////////////////////////////////////////////////////

void sub11() {
	system("cls");
	int len;
	Commodity goods[N];
	len=fileread(goods);
	range1(goods,len);
	output(goods,len);
	printf("\n���ǰ����������������������......\n");
	getche();
}
//////////////////////
void sub12() {
	system("cls");
	int len;
	Commodity goods[N];
	len=fileread(goods);
	range2(goods,len);
	output(goods,len);
	printf("\n���ǰ�����Ʒ�۸��������������......\n");
	getche();
}
//////////////////////
void sub13() {
	system("cls");
	int len;
	Commodity goods[N];
	len=fileread(goods);
	range3(goods,len);
	output(goods,len);
	printf("\n���ǰ��������������������......\n");
	getche();
}
//////////////////////
void sub21(long int startid) {
	system("cls");
	FILE *fp;
	int len;
	Commodity goods[N];
	len=fileread(goods);
	output(goods,len);
	search1(goods,len,startid);
	printf("\n���������̼ҡ����������......\n");
	getche();
}
/////////////////////
void sub22(long int startid) {
	system("cls");
	int len;
	Commodity goods[N];
	len=fileread(goods);
	output(goods,len);
	search2(goods,len,startid);
	printf("\n����������Ʒ�����������......\n");
	getche();
}
///////////////////////////

///////////////////

void sub10() {
	char sele;
	int flag=1;
	while(flag) {
		system("cls");
		printf("********��Ʒ����˵�********\n");
		printf("1.������������\n");
		printf("2.���۸�����\n");
		printf("3.�����۽���\n");
		printf("0.�˳����\n");
		printf("\n��ѡ��");
		sele=getche();
		switch(sele) {
			case '1':
				sub11();
				break;
			case '2':
				sub12();
				break;
			case '3':
				sub13();
				break;
			case '0':
				flag=0;
				printf("\n\n");
				break;
			default:
				printf("\n\n�������������ѡ��\n\n");
				getche();
		}
	}
	system("cls");
	printf("\n�����ϣ����������......\n");
	getche();
//	mainmenu();
}
///////////////////
void sub20(long int startid) {
	char sele;
	int flag=1;
	while(flag) {
		system("cls");
		printf("********��Ʒ����˵�********\n");
		printf("1.���̼���������\n");
		printf("2.����Ʒ��������\n");
		printf("0.�˳���������\n");
		printf("\n��ѡ��");
		sele=getche();
		switch(sele) {
			case '1':
				sub21(startid);
				break;
			case '2':
				sub22(startid);
				break;
			case '0':
				flag=0;
				printf("\n\n");
				break;
			default:
				printf("\n\n�������������ѡ��\n\n");
				getche();
		}
	}
	system("cls");
	printf("\n����������ϣ����������......\n");
	getche();
//	mainmenu();
}
//////////////////////////////////��������
void sub30(long int startid) {
	system("cls");////////////////
	int flag;
	Order p[N];
	int i;
	char judge;
	int pingfen;
	long int num;
	FILE *fp;
	int len=0;
	int count3=0;

	fp=fopen("Order.dat","rb+");
	if(fp==NULL) {
		printf("orderfile open error!");
		exit(0);
	}
	while(!feof(fp)) {
		fread(&p[len++],sizeof(Order),1,fp);
	}
	len--;
	outputorder(p,len,startid); 

	printf("\n�����붩����ţ�\n")	;
	do {
		scanf("%ld",&num);
		count3++;
		fflush(stdin);
		for(i=0; i<len; i++) {
			if(p[i].id==num)
				break;
		}
		if(i>=len)
			printf("\n�ö��������ڣ�����������(��3�Σ�3�κ��Զ��˳�)��\n");
		if(count3>3)
			return;
	} while(i>=len);

	if(p[i].state==3) {
		printf("\n�����ѱ��̼Ҵ����Ƿ���Ҫ���ۣ�Y/N����Сд���ޣ�\n");
		do { 
			judge=getchar();
			if(judge=='y'||judge=='Y') {
				printf("\n������(����0-5)��\n");
				do {
					scanf("%d",&pingfen);
					if(pingfen<0||pingfen>5)
						printf("\n�����������������֣�\n");
				} while(pingfen<0||pingfen>5);
				p[i].pj =pingfen;
				p[i].state=5;
			}
			if(judge!='Y'&&judge!='y'&&judge!='N'&&judge!='n')
				printf("\n�����������������룺\n");
		} while(judge!='Y'&&judge!='y'&&judge!='N'&&judge!='n');

	} else if(p[i].state==1) {
		printf("\n������δ���̼Ҵ����Ƿ�ȡ��������Y/N����Сд���ޣ�\n");
		do {

			judge=getchar();
			if((judge == 'y')||(judge == 'Y')) {
				p[i].state=6;
			}
			if(judge!='Y'&&judge!='y'&&judge!='N'&&judge!='n')
				printf("\n�����������������룺\n");
		} while(judge!='Y'&&judge!='y'&&judge!='N'&&judge!='n');
	} else {
		printf("\n����δ��Ȩ���޸ĸ���Ʒ��\n");
		getche();
		return ;
	}
	if(p[i].state==6||p[i].state==5) {
		rewind(fp);
		for(i=0; i<len; i++)
			fwrite(&p[i],sizeof(Order),1,fp);
		printf("\n�����޸ĳɹ���");
		getche();
	}
	fclose(fp);
	system("cls");
	printf("\n���Ƕ����������������......\n");
	getche();
//	mainmenu();

}
///////////////////////////////////

void sub40(long int startid)
{
	system("cls");
	xiugai1(startid);
	
	printf("����������أ�");
	getche();
	
	
}

void mainmenu(long int startid) {
	char sele;
	int flag=1;
	while(flag) {
		system("cls");
		printf("********�û��˵�********\n");
		printf("1.�����Ʒ��Ϣ\n");
		printf("2.�����µ�\n");
		printf("3.������\n");
		printf("4.��Ϣ�޸�\n");
		printf("0.�˳�\n");
		printf("\n��ѡ��");
		sele=getche();
		switch(sele) {
			case '1':
				sub10();
				break;
			case '2':
				sub20(startid);
				break;
			case '3':
				sub30(startid);
				break;
			case '4':
				sub40(startid);
				break; 
			case '0':
				flag=0;
				printf("\n\n");
				break;
			default:
				printf("\n\n�������������ѡ��\n\n");
				getche();
		}
	}
	printf("\n\nллʹ�ã��ټ�!\n\n");
}
