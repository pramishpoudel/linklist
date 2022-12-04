#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node* pre;
	int data;
	struct node * next;
};

struct node * empty(struct node * head,int data)//creating first element in the link list
{
	
	struct node * temp=(struct node*)malloc(sizeof(struct node));
	temp->pre=NULL;
	temp->data=data;
	temp->next=NULL;
	head=temp;
	return head;
}

struct node * add_at_beg(struct node * head,int data)//insertion at the begining of the link_list
{
	
	struct node * temp=(struct node*)malloc(sizeof(struct node));
	temp->pre=NULL;
	temp->data=data;
	temp->next=NULL;
	temp->next=head;
	head->pre=temp;	
	head=temp;
	return head;
}

struct node * add_at_end(struct node * head,int data)//insertion at the end of the link_list
{
	struct node *tp;
	struct node * temp=(struct node*)malloc(sizeof(struct node));
	temp->pre=NULL;
	temp->data=data;
	temp->next=NULL;
	head=tp;
	while(tp->next!=NULL)
	    tp=tp->next;
	     
	tp->next=temp;
	temp->pre=tp;
	
	return head;
}

struct node * del_at_beg(struct node *head)
{
	struct node * temp =head;
	head=head->next;
	free(temp);
	temp=NULL;
	head->pre=NULL;
	return head;
}

struct node *del_at_end(struct node *head)
{
	struct node *temp=head;
	struct node *temp2;
	
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp2=temp->pre;
	temp2->next=NULL;
	free(temp);
	return head;
}

struct node *del_at_certain_pos(struct node * head,int pos)
{
	struct node * temp = head;
	struct node *temp2 = NULL;
	
	if(pos == 1)
	{
		head=del_at_beg(head);
	 return head;		
	}
	while(pos > 1)
	{
		temp = temp -> next;
		pos --;
	}
	
	if(temp->next==NULL)
	{
		head=del_at_end(head);
	}
	else
	{
		temp2=temp->pre;
		temp2->next = temp->next;
		temp->next ->pre=temp2;
		free(temp);
		temp = NULL;
	}
	return head;
}

int main()
{
	 
	struct node * head= NULL;
	head=empty(head,45);
	head=add_at_beg(head,85);
	head=add_at_end(head,23);
	struct node *ptr=head;
	 while(ptr!=NULL)
	 {
	 	printf("%d\t",ptr->data);
	 	ptr=ptr->next;
	 }
	 printf("\n");
	 
    //head=del_at_beg(head);  //this delete the first node of the link list
    //head=del_at_end(head);  //this delete the last node of the link list
    head =del_at_certain_pos(head,2); // this delete the sepecific node you wants to delete 
     
    ptr=head;
	//After sucessfull deltion of the link
	printf("After deletion\n");
    while(ptr!=NULL)
	 {
	 	printf("%d\t",ptr->data);
	 	ptr=ptr->next;
	 }
	return 0;
	 
}
