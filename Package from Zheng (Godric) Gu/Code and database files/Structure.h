#ifndef __STRUCTURE_H
#define __STRUCTURE_H
//�������ʹ�õ����ݽṹ...

//������������Ϣ�ṹ
typedef struct bookstock
{
	int stocktime;
	int ISBN;
	CString bookname;
	CString author;
	CString bookconcern;
	CString label;
	float cost;
	int bookcount;
}bookstock;

//�˻���������Ϣ�ṹ...
typedef struct bookrefund
{
	int refundtime;
	int ISBN;
	CString bookname;
	CString author;
	CString bookconcern;
	CString label;
	float price;
	int refundcount;
}bookrefund;

//�����Ϣ�ṹ
typedef struct bookstorage
{
	int ISBN;
	CString bookname;
	CString author;
	CString bookconcern;
	CString label;
	float price; //�ۼ�
	float cost;  //�ɱ�
	int storecount;
}bookstorage;

// ������Ϣ�ṹ
typedef struct bookvend
{
	int vendtime;
	int ISBN;
	CString bookname;
	CString author;
	CString bookconcern;
	CString label;
	float price;
	int vendcount;
}bookvend;

// ��Ӧ����Ϣ...
typedef struct booksupply
{
	int ISBN;
	CString bookname;
	CString author;
	CString bookconcern;
	float cost;
	int supplycount;
}booksupply;

#endif