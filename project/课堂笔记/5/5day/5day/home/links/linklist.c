#include "linklist.h"

//1，初始化,输出H
void init_linklist(list_pnode *H)
{
	*H = (list_pnode)malloc(sizeof(list_node));
	if (NULL==(*H)) {
		perror("malloc");
		exit(1);
	}
	(*H)->next = NULL;
}

//2，插入---pnode:插入位置前一个节点的指针，new_pnode:要插入的节点指针
void insert_linklist(list_pnode pnode,list_pnode new_pnode)
{
	
	new_pnode->next = pnode->next;
	pnode->next = new_pnode;
}

//3，删除----删除p指向的节点后面的节点
void del_linklist(list_pnode pnode)
{
	list_pnode tmp;
	if (isempty_linklist(pnode)) {
		printf("链表为空,不能删除!\n");
		return;
	}
	tmp=pnode->next; 		
	pnode->next=tmp->next;			
	free(tmp);			
	
}

//4，判断是否为空
bool isempty_linklist(list_pnode head)
{
	if (head->next == NULL)
		return true;
	else
		return false;
}

//5，遍历
void show_linklist(list_pnode head)
{
	list_pnode p;
	printf("head");
	for (p = head->next; p != NULL; p = p->next)
		printf("->%d", p->data);

	printf("->null\n");
}
