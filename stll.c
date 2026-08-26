#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *top=NULL;
struct node *newnode,*temp;
void push(){
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter the data:");
		scanf("%d",&newnode->data);
		newnode->next=top;
		top=newnode;
}
void pop(){
    if(top==NULL){
		printf("the stack is empty!!");
    }
    else{
    	temp=top;
        printf("the deleted element is %d\n",top->data);
        top=top->next;
        free(temp);
	}
}
void peek(){
	if(top==NULL){
		printf("the stack is empty!!");
	}
	else{
		printf("the peek of the stack is %d\n",top->data);
	}
}
void display(){
	if(top==NULL){
		printf("the stack is empty!!");
	}
	else{
		temp=top;
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
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.peek\n");
		printf("4.display\n");
		printf("enter the choice:");
	    scanf("%d",&ch);
	switch(ch){
		case 1:push();
		       break;
		case 2:pop();
		       break;
		case 3:peek();
		       break;
		case 4:display();
		       break;
		default:printf("invalid choice!!\n");
	}
 }
	return 0;
}
