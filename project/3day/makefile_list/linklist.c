#include "linklist.h"

//1，初始化
void init_linklist(list_pnode *H)
{
	*H=malloc(sizeof(list_pnode));
	(*H)->next=NULL;
}

//2，插入---pnode:插入位置前一个节点的指针，new_pnode:要插入的节点指针
void insert_linklist(list_pnode pnode,list_pnode new_pnode)
{
	// h->a->b->c->null
	new_pnode->next=pnode->next;
	pnode->next=new_pnode;
	// insert_linklist(a,new)  h->a->new->b->c->null
}

//3，删除----删除p指向的节点后面的节点
void del_linklist(list_pnode pnode)
{
//	list_pnode temp;
//	temp=pnode->next;
//	pnode->next=temp->next;
		pnode->next=pnode->next->next;
	//h->a->new->b->c->null
	//del_linklist(a)
	// h->a->b->c->null
}

//4，判断是否为空
bool isempty_linklist(list_pnode head)
{
	return head->next==NULL;
	//p==head	
}

//5，遍历
void show_linklist(list_pnode head)
{
	list_pnode temp;
	temp=head->next;
	while(temp !=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("show finish\n");
	//p=p->next p==NULL结束
}

