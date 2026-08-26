#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
struct node *newnode,*temp;
void enqueue(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter the data:");
	scanf("%d",&newnode->data);
	if(front==NULL&&rear==NULL){
		front=rear=newnode;
	}
	else{
		rear->next=newnode;
		rear=newnode;	
	}
	rear->next=NULL;
}
void dequeue(){
	if(front==NULL&&rear==NULL){
		printf("the queue is empty!!");
	}
	else{
		temp=front;
		printf("the deleted element is %d\n",front->data);
		front=front->next;
		free(temp);
	}
}
void display(){
	if(front==NULL&&rear==NULL){
		printf("the queue is empty!!");
	}
	else{
		temp=front;
		while(temp->next!=NULL){
			printf("the data is %d\n",temp->data);
			temp=temp->next;
		}
		printf("the data is %d\n",temp->data);
	}
}
int main(){
	int ch=1;
	while(ch!=0){
		printf("1.enqueue\n");
		printf("2.dequeue\n");
		printf("3.display\n");
		printf("enter the choice:");
	    scanf("%d",&ch);
	switch(ch){
		case 1:enqueue();
		       break;
		case 2:dequeue();
		       break;
		case 3:display();
		       break;
		default:printf("invalid choice!!\n");
	}
 }
	return 0;
}
