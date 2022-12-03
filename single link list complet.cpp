#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *link;
};

struct node* add_at_end(struct node *ptr,int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	
	ptr -> link = temp;
	
	return temp;
	
}

struct node* add_at_beg(struct node * head ,int data)
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->link=NULL;
	
	ptr -> link = head;
	head=ptr;
	return head;
	
}

void add(struct node*head,int data,int pos)
{
     //struct node *temp2=NULL;
	struct node *ptr=head;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	
	while(pos!=2)
	{
		ptr=ptr->link;
		pos--;
	}
 temp->link=ptr->link;
 ptr->link=temp;
	
	
}

struct node * delbeg(struct node * head)
{
	if(head==NULL)
	{
		printf("link list is empty");
	}
	else
	{
		struct node *temp=head;
		head=head->link;
		free(temp);
		temp=NULL;
	}
	return head;
}

struct node *delend(struct node *head)
{
	if(head==NULL)
	{
		printf("link list is empty");
	}
	else if(head->link==head)
	{
		free(head);
		head=NULL;
	}
	else 
	{
		struct node *temp = head;
		while(temp->link->link!=NULL)
		{
			temp=temp->link;
		}
		free(temp->link);
		temp->link=NULL;
	}
	return head;
}

void del_pos(struct node **head,int pos)
{
	struct node * current =*head;
	struct node *previous = *head;
	
	if(*head==NULL)
	{
		printf("link list is already empty");
	}
	else if(pos==1)
	{
		*head=current->link;
		free(current);
		current =NULL;
	}
	else
	{
		while(pos !=1)
		{
			previous =current;
			current = current ->link;
			pos--;
		}
		previous ->link = current ->link;
		free(current);
		current=NULL;
	}
}

int main()
{
	struct node * head=(struct node*)malloc(sizeof(struct node));
	head->data=10;
	head->link= NULL;
	struct node *ptr=head;
	ptr=add_at_end(ptr,56);
	head=add_at_beg(head,96);
	add(head,20,2);
	//head=delbeg(head);
	//head=delend(head);
	//del_pos(&head,2);
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->link;
	}
	return 0;
}
