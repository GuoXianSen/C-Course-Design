# include  "type.h"
/*
该函数将a赋值为当前时间的字符串形式 并输出当前时间
形式为："2018年7月5日15时04分37秒 星期四" 
		星期前有一空格 
a为一指向至少26个char空间的字符型指针 
形式为："Thu Jul 05 15:16:05 2018\n\0"
		星期 月份 日期 时间 年份
		每两参数以空格分开，以"\n\0"结束 
*/ 
void mytime(char *a){
	char *b;
	int i = 0;
	struct tm *local;
	time_t t;
	
	t = time(NULL);
	b = ctime(&t);
	while(*b){
		*(a+i++) = *(b++);
	}
	//年份 
	printf("%c%c%c%c年", a[20], a[21], a[22], a[23]); 
	//月份
	switch(a[4]){
		case 'J':
			a[5] == 'a' ? printf("1月") : (a[7] == 'n' ? printf("6月") : printf("7月"));
			break; 
		case 'F':
			printf("2月");
			break; 
		case 'M':
			a[5] == 'a' ? printf("3月") : printf("5月");
			break; 
		case 'A':
			a[5] == 'p' ? printf("4月") : printf("8月");
			break; 
		case 'S':printf("9月");break; 
		case 'O':printf("10月");break; 
		case 'N':printf("11月");break; 
		case 'D':printf("12月");break;
	} 
	//日期
	printf("%c%c日", a[8], a[9]);
	//时间
	printf("%c%c时%c%c分%c%c秒 ", a[11], a[12], a[14], a[15], a[17], a[18]);
	//星期几 
	switch(a[0]){
		case 'M':
			printf("星期一 ");break; 
		case 'T':
			a[1] == 'u' ? printf("星期二 "):printf("星期四 ");
			break;
		case 'W':
			printf("星期三 ");break;
		case 'F':
			printf("星期五 ");break; 
		case 'S':
			a[1] == 'u' ? printf("星期日 "):printf("星期六 "); 
	} 
	
	return ;
}
