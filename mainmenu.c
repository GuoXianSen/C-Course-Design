# include  "type.h"
# define N 1000
//long int startid=40000;//暂时用全局变量作为已知量
////////////////////////////////////订单结构体

/*void mainmenu(long int startid);
void search2(Commodity *s,int len,long int startid);*/
///////////////////////////////////读取商品信息
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
//////////////////////////////////////////输出商品信息
void output(Commodity *s,int len) {
	int i;
	for(i=0; i<len; i++) {
		printf("编号：%ld\n",s[i].id);
		printf("名称：%s\n",s[i].name);
		printf("价格：%5.2f\n",s[i].price);
		printf("总量：%d\n",s[i].number);
		printf("已售数量：%d\n",s[i].sold);
		printf("所属商家编号：%ld\n",s[i].id_B);
		printf("综合评价:%3.2f\n",s[i].pj);
		printf("该商品目前的状态:");
		switch(s[i].state) {
			case 1:
				printf("可售\n");
				break;
			case 0:
				printf("售空\n");
		}
		printf("\n*************\n");
	}

}
//////////////////////////////////按销量降序
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
////////////////////////////////////////按价格升序
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
//////////////////////////////////////按评分降序
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
////////////////////////////下单函数
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
	printf("\n下单成功！请等待商家配送！\n");
}
/////////////////////////////////////按商家搜索
void search1(Commodity *s,int len,long int startid) {
	int i;
	int count=0;
	int count1=0;
	long int num,num1;
	char judge;
	printf("\n请输入商家编号：\n");
	do {
		scanf("%ld",&num);
		count1++;
		system("cls");
		for(i=0; i<len; i++) {
			if(s[i].id_B==num) {
				printf("编号：%ld\n",s[i].id);
				printf("名称：%s\n",s[i].name);
				printf("价格：%5.2f\n",s[i].price);
				printf("总量：%d\n",s[i].number);
				printf("已售数量：%d\n",s[i].sold);
				printf("所属商家编号：%ld\n",s[i].id_B);
				printf("综合评价:%3.2f\n",s[i].pj);
				printf("该商品目前的状态:");
				switch(s[i].state) {
					case 1:
						printf("可售\n");
						break;
					case 0:
						printf("售空\n");
				}
				printf("\n*************\n");
				count++;
			}
		}
		if(count==0) {
			printf("\n未找到该商家，请重新输入商家编号(仅3次机会,3次后将自动退出)：\n");
		}
		if(count1>3)
			return;
	} while(count==0);
	printf("\n共找到了该商家的%d条结果，请浏览!\n",count);
	printf("\n是否想购买该商家商品？Y/N?(大小写不限)：\n");
	do {
		getchar();////////
		judge=getchar();
		if(judge=='Y'||judge=='y')
			search2(s,len,startid);////////////
		else if(judge=='N'||judge=='n')
			return;//返回上一级菜单
		else
			printf("\n输入有误，请重新选择！\n");
	} while(judge!='Y'&&judge!='y'&&judge!='N'&&judge!='n');
}

//////////////////////////////////////按商品搜索
void search2(Commodity *s,int len,long int startid) {
	int i;
	long int num;
	char judge;
	int count2=0;
	printf("\n请输入商品编号：\n");
	do {
		scanf("%ld",&num);
		count2++;
		system("cls");
		for(i=0; i<len; i++) {
			if(s[i].id==num) {
				printf("编号：%ld\n",s[i].id);
				printf("名称：%s\n",s[i].name);
				printf("价格：%5.2f\n",s[i].price);
				printf("总量：%d\n",s[i].number);
				printf("已售数量：%d\n",s[i].sold);
				printf("所属商家编号：%ld\n",s[i].id_B);
				printf("综合评价:%3.2f\n",s[i].pj);
				printf("商品目前的状态：");
				switch(s[i].state) {
					case 1:
						printf("可售\n");
						break;
					case 0:
						printf("售空\n");
				}///////////////////////////

				printf("\n*************\n");
				break;
			}
		}
		if(i>=len)
			printf("\n未找到该商品，请重新输入商品编号(仅3次机会,3次后将自动退出)：\n");
		if(count2>3)
			return;
	}	while(i>=len);
	if(s[i].state ==0)
		printf("\n该商品已售空！\n");
	else {
		printf("\n是否需要下单？Y/N(大小写不限)：\n");
		do {
			getchar();/////////////
			judge=getchar();
			if(judge=='Y'||judge=='y')
				gobuy(s[i],startid);
			else	if(judge=='N'||judge=='n')
				return;
			else
				printf("\n输入有误，请重新选择！\n");
		} while(judge!='Y'&&judge!='y'&&judge!='N'&&judge!='n');
	}
}
////////////////////////////////////////////////////

//////////////////////////
void outputorder(Order *p,int len,long int startid) {
	int i;
	for(i=0; i<len; i++) {
		if(p[i].id_U==startid) {
			printf("\n订单编号：%ld\n",p[i].id);
			printf("预定用户编号：%ld\n",p[i].id_U);
			printf("预定商品编号：%ld\n",p[i].id_C);
			printf("预定商家编号：%ld\n",p[i].id_B);
			printf("订单目前的状态：");
				switch(p[i].state) {
				case 0:
					printf("商家已取消\n");
					break;
				case 1:
					printf("商家未确认\n");
					break;
				case 2:
					printf("商家已确认\n");
					break;
				case 3:
					printf("商家已完成\n");
					break;
				case 5:
					printf("用户已评价\n");
					break;
				case 6:
					printf("用户已取消\n");/////////////////////////////////
			}
			printf("订单状态更改时间：");///////////////////
			//年份
			printf("%c%c%c%c年", p[i].tm [20], p[i].tm[21], p[i].tm[22], p[i].tm[23]);
			//月份
			switch(p[i].tm[4]) {
				case 'J':
					p[i].tm[5] == 'a' ? printf("1月") : (p[i].tm[7] == 'n' ? printf("6月") : printf("7月"));
					break;
				case 'F':
					printf("2月");
					break;
				case 'M':
					p[i].tm[5] == 'a' ? printf("3月") : printf("5月");
					break;
				case 'A':
					p[i].tm[5] == 'p' ? printf("4月") : printf("8月");
					break;
				case 'S':
					printf("9月");
					break;
				case 'O':
					printf("10月");
					break;
				case 'N':
					printf("11月");
					break;
				case 'D':
					printf("12月");
					break;
			}
			//日期
			printf("%c%c日", p[i].tm[8], p[i].tm[9]);
			//时间
			printf("%c%c时%c%c分%c%c秒 ", p[i].tm[11], p[i].tm[12], p[i].tm[14], p[i].tm[15], p[i].tm[17], p[i].tm[18]);
			//星期几
			switch(p[i].tm[0]) {
				case 'M':
					printf("星期一 ");
					break;
				case 'T':
					p[i].tm[1] == 'u' ? printf("星期二 "):printf("星期四 ");
					break;
				case 'W':
					printf("星期三 ");
					break;
				case 'F':
					printf("星期五 ");
					break;
				case 'S':
					p[i].tm[1] == 'u' ? printf("星期日 "):printf("星期六 ");
			}

			printf("\n订单评价：%d\n",p[i].pj);
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
	printf("\n这是按照销售量排序。任意键返回......\n");
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
	printf("\n这是按照商品价格排序。任意键返回......\n");
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
	printf("\n这是按照评价排序。任意键返回......\n");
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
	printf("\n这是搜索商家。任意键返回......\n");
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
	printf("\n这是搜索商品。任意键返回......\n");
	getche();
}
///////////////////////////

///////////////////

void sub10() {
	char sele;
	int flag=1;
	while(flag) {
		system("cls");
		printf("********商品浏览菜单********\n");
		printf("1.按销售量降序\n");
		printf("2.按价格升序\n");
		printf("3.按评价降序\n");
		printf("0.退出浏览\n");
		printf("\n请选择");
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
				printf("\n\n输入错误，请重新选择！\n\n");
				getche();
		}
	}
	system("cls");
	printf("\n浏览完毕！任意键返回......\n");
	getche();
//	mainmenu();
}
///////////////////
void sub20(long int startid) {
	char sele;
	int flag=1;
	while(flag) {
		system("cls");
		printf("********商品购买菜单********\n");
		printf("1.按商家搜索购买\n");
		printf("2.按商品搜索购买\n");
		printf("0.退出搜索购买\n");
		printf("\n请选择");
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
				printf("\n\n输入错误，请重新选择！\n\n");
				getche();
		}
	}
	system("cls");
	printf("\n搜索购买完毕！任意键返回......\n");
	getche();
//	mainmenu();
}
//////////////////////////////////订单管理
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

	printf("\n请输入订单编号：\n")	;
	do {
		scanf("%ld",&num);
		count3++;
		fflush(stdin);
		for(i=0; i<len; i++) {
			if(p[i].id==num)
				break;
		}
		if(i>=len)
			printf("\n该订单不存在，请重新输入(仅3次，3次后自动退出)：\n");
		if(count3>3)
			return;
	} while(i>=len);

	if(p[i].state==3) {
		printf("\n订单已被商家处理，是否需要评价？Y/N（大小写不限）\n");
		do { 
			judge=getchar();
			if(judge=='y'||judge=='Y') {
				printf("\n请评分(输入0-5)：\n");
				do {
					scanf("%d",&pingfen);
					if(pingfen<0||pingfen>5)
						printf("\n输入有误，请重新评分：\n");
				} while(pingfen<0||pingfen>5);
				p[i].pj =pingfen;
				p[i].state=5;
			}
			if(judge!='Y'&&judge!='y'&&judge!='N'&&judge!='n')
				printf("\n输入有误，请重新输入：\n");
		} while(judge!='Y'&&judge!='y'&&judge!='N'&&judge!='n');

	} else if(p[i].state==1) {
		printf("\n订单还未被商家处理，是否取消订单？Y/N（大小写不限）\n");
		do {

			judge=getchar();
			if((judge == 'y')||(judge == 'Y')) {
				p[i].state=6;
			}
			if(judge!='Y'&&judge!='y'&&judge!='N'&&judge!='n')
				printf("\n输入有误，请重新输入：\n");
		} while(judge!='Y'&&judge!='y'&&judge!='N'&&judge!='n');
	} else {
		printf("\n您尚未有权限修改该商品！\n");
		getche();
		return ;
	}
	if(p[i].state==6||p[i].state==5) {
		rewind(fp);
		for(i=0; i<len; i++)
			fwrite(&p[i],sizeof(Order),1,fp);
		printf("\n订单修改成功！");
		getche();
	}
	fclose(fp);
	system("cls");
	printf("\n这是订单管理。任意键返回......\n");
	getche();
//	mainmenu();

}
///////////////////////////////////

void sub40(long int startid)
{
	system("cls");
	xiugai1(startid);
	
	printf("按任意键返回！");
	getche();
	
	
}

void mainmenu(long int startid) {
	char sele;
	int flag=1;
	while(flag) {
		system("cls");
		printf("********用户菜单********\n");
		printf("1.浏览商品信息\n");
		printf("2.搜索下单\n");
		printf("3.管理订单\n");
		printf("4.信息修改\n");
		printf("0.退出\n");
		printf("\n请选择");
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
				printf("\n\n输入错误，请重新选择！\n\n");
				getche();
		}
	}
	printf("\n\n谢谢使用，再见!\n\n");
}
