#ifndef _TYPE_H_
#define _TYPE_H_
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
#include <time.h>
# include  "type.h"
# include  "conio.h"
# include  <windows.h>
//商家结构体
//business.dat
 typedef struct{
	long id_B;//商家编号
	char name[19];//商家名称 
	char mi[19];//商家密码
	char phone[12];//商家手机号 
	char e[30];//商家邮箱 
 }Business;


// 用户结构体
// Userdate.dat
 typedef struct{
 	long id_U;//用户编号 
 	char name[20];//用户名 
	char mi[20];//用户密码 
 	char phone[12];//用户手机 
 	char e[30];//用户邮箱 
 }User;
 
 
typedef struct{
	long id;//订单编号 
	long id_U;//预定用户编号 
	long id_C;//预定商品编号 
	long id_B;//预定商家编号 
	int state;
	//0-3：商家已取消、未确认、已确认、已完成；5-6用户已评价、被取消 
	char tm[26];//订单状态更改时间 
	int pj;//订单评价 
}Order;

//结构体商品 
//Commodity_t.dat当前文件
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

void B_Commodity(long B_id) ;
void B_aid_c(long B_id, Commodity *c, int i);
void B_print_c(Commodity *c);
void B_s_c(long B_id, Commodity *c, int i);
void B_change_c(long B_id, Commodity *c, int i);
void B_mytime(char *a);
void B_print_time(char *a);
void B_save_c( Commodity *c, int *i);

int B_order(long B_id);
int B_print_o(int a, long id, Order *o, int i);
void B_O_1(long id, Order *o, int i);
void B_O_2(long id, Order *o, int i);


void ad_search();
void A_S_C();
void A_print_C(Commodity *c);
void A_S_B();
void A_print_B(Business *b);
void A_S_O();
void A_print_O( Order *o);
void A_S_U();
void A_print_U(User *u);
void mytime(char *a);
/////////////////////////////
void mainmenu(long int startid);
void search2(Commodity *s,int len,long int startid);
int fileread(Commodity *s);
///////////////////////
int B(long B_id);
void pingjia();
void change1(char* name);
void change(char* name);
void xiugai1(long id);
void xiugai2(long id);
void menu();
#endif

