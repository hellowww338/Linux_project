/*
 用单向链表实现数据逆转，
 首先建立一个包含若干整数的单向链表，
 然后实现数据的逆转。
 比如说把1，2，3，4，5逆转成5，4，3，2，1
 
 head->1->2->3->4->5->null
 
 head->5->4->3->2->1->null
 
 */

#include "linklist.h"

void create_linklist(list_pnode head);
void list_sort(list_pnode head);
void list_reverse(list_pnode head);

int main(void)
{
	list_pnode head;

	//1,初始化单向链表
	init_linklist(&head);

	//2，向链表中插入一些数据---创建链表
	create_linklist(head);
	//list_reverse(head);
	list_reverse(head);
	show_linklist(head);
	return 0;
}

void list_reverse(list_pnode head)
{
	if (head == NULL || head->next == NULL)
        return;
	list_pnode data = head->next;	//保存链表数据，空出链表头
	head->next=NULL;							//链表头指向链表尾部（空）
	list_pnode temp;
	while(data != NULL)						//保存的数据指向空说明链表没有数据了
	{
		temp=data->next;						//下一个链表之后的数据，相当于取出第一个链表数据放在data
		data->next=head->next;			//把data写入链表头
		head->next=data;
		data=temp;									//把第二个数据放会data进入下一个循环
	}
	printf("reverse finish\n");
}

void create_linklist(list_pnode head)
{
	list_pnode new_pnode,pnode;
	int i,n;
	printf("请输入数据的个数:");
	scanf("%d",&n);
	for(i = 0,pnode=head; i < n; i++){
		new_pnode = (list_pnode)malloc(sizeof(list_node));
		if(new_pnode == NULL){
			perror("malloc");
			exit(1);
		}
		printf("请输入数据:");
		scanf("%d",&new_pnode->data);

		insert_linklist(pnode,new_pnode);
		
		//pnode = pnode->next;
		show_linklist(head);
	}
}

