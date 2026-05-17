#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#include <stdio.h>
#include <stdbool.h>  //true=1  false=0
#include <stdlib.h>

typedef int datatype;

//typedef int * pint
//pint p;
//int *p


//定义链表节点的类型
typedef struct listnode{
	datatype data;//节点保存的数据的数据类型
	struct listnode *next; //节点后继
}list_node,*list_pnode;
//list_node是这个节点类型的别名
//list_pnode是这个节点的指针类型的别名

//list_pnode p; //等价的
//struct listnode *p  

//list_node node;
//struct listnode node;


extern void init_linklist(list_pnode *H); //创建头节点
//H是输出参数 
//list_pnode head;
//init_linklist(&head);


extern void insert_linklist(list_pnode pnode,list_pnode new_pnode);
extern void del_linklist(list_pnode pnode);
extern bool isempty_linklist(list_pnode head);
extern void show_linklist(list_pnode head);
#endif

