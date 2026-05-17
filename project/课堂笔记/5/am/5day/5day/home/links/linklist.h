#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int datatype; //节点数据类型

typedef struct listnode{
	datatype data; 			//保存节点的数据
	struct listnode *next;	//后继,指向下一节点
}list_node,*list_pnode;
// list_node是 struct listnode 外号
// list_pnode是 struct listnode * 别名


extern void init_linklist(list_pnode *H);
extern void insert_linklist(list_pnode pnode,list_pnode new_pnode);
extern void del_linklist(list_pnode pnode);
extern bool isempty_linklist(list_pnode head);
extern void show_linklist(list_pnode head);
#endif
