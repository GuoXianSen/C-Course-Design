#ifndef _TYPE_H_
#define _TYPE_H_
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
#include <time.h>
# include  "type.h"
# include  "conio.h"
# include  <windows.h>
//�̼ҽṹ��
//business.dat
 typedef struct{
	long id_B;//�̼ұ��
	char name[19];//�̼����� 
	char mi[19];//�̼�����
	char phone[12];//�̼��ֻ��� 
	char e[30];//�̼����� 
 }Business;


// �û��ṹ��
// Userdate.dat
 typedef struct{
 	long id_U;//�û���� 
 	char name[20];//�û��� 
	char mi[20];//�û����� 
 	char phone[12];//�û��ֻ� 
 	char e[30];//�û����� 
 }User;
 
 
typedef struct{
	long id;//������� 
	long id_U;//Ԥ���û���� 
	long id_C;//Ԥ����Ʒ��� 
	long id_B;//Ԥ���̼ұ�� 
	int state;
	//0-3���̼���ȡ����δȷ�ϡ���ȷ�ϡ�����ɣ�5-6�û������ۡ���ȡ�� 
	char tm[26];//����״̬����ʱ�� 
	int pj;//�������� 
}Order;

//�ṹ����Ʒ 
//Commodity_t.dat��ǰ�ļ�
typedef struct{
	long id;//��Ʒ��� 
	char name[20];//��Ʒ���� 
	float cost;
	float price;//��Ʒ�۸� 
	int number;//��Ʒ���� 
	int sold;//�������� 
	long id_B;//�����̼ұ�� 
	float pj;//��Ʒ�ۺ����� 
	int state;//��Ʒ״̬��7������Ա�¼ܣ�8������ 
	char tm[26];//��Ʒ״̬����ʱ�� 
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

