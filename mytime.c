# include  "type.h"
/*
�ú�����a��ֵΪ��ǰʱ����ַ�����ʽ �������ǰʱ��
��ʽΪ��"2018��7��5��15ʱ04��37�� ������" 
		����ǰ��һ�ո� 
aΪһָ������26��char�ռ���ַ���ָ�� 
��ʽΪ��"Thu Jul 05 15:16:05 2018\n\0"
		���� �·� ���� ʱ�� ���
		ÿ�������Կո�ֿ�����"\n\0"���� 
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
	//��� 
	printf("%c%c%c%c��", a[20], a[21], a[22], a[23]); 
	//�·�
	switch(a[4]){
		case 'J':
			a[5] == 'a' ? printf("1��") : (a[7] == 'n' ? printf("6��") : printf("7��"));
			break; 
		case 'F':
			printf("2��");
			break; 
		case 'M':
			a[5] == 'a' ? printf("3��") : printf("5��");
			break; 
		case 'A':
			a[5] == 'p' ? printf("4��") : printf("8��");
			break; 
		case 'S':printf("9��");break; 
		case 'O':printf("10��");break; 
		case 'N':printf("11��");break; 
		case 'D':printf("12��");break;
	} 
	//����
	printf("%c%c��", a[8], a[9]);
	//ʱ��
	printf("%c%cʱ%c%c��%c%c�� ", a[11], a[12], a[14], a[15], a[17], a[18]);
	//���ڼ� 
	switch(a[0]){
		case 'M':
			printf("����һ ");break; 
		case 'T':
			a[1] == 'u' ? printf("���ڶ� "):printf("������ ");
			break;
		case 'W':
			printf("������ ");break;
		case 'F':
			printf("������ ");break; 
		case 'S':
			a[1] == 'u' ? printf("������ "):printf("������ "); 
	} 
	
	return ;
}
