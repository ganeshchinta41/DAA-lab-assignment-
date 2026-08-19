#include <stdlib.h>
#include <stdio.h>
struct node{
	int data;
	struct node *left,*right;
};
struct node *root=NULL;
struct node *createnode(int value){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->left=newnode->right=NULL;
	return newnode;
}
void insert(){
	int value;
	printf("enter value:");
	scanf("%d",&value);
	struct node *newnode=createnode(value);
	struct node *temp=root,*parent=NULL;
	if(root==NULL){
		root=newnode;
		return;
	}
	while(temp!=NULL){
		parent=temp;
		if(value<temp->data){
			temp=temp->left;
		}
		else{
			temp=temp->right;
		}
	}
	if(value<parent->data){
		parent->left=newnode;
	}
	else{
		parent->right=newnode;
	}
}
struct node *findmin(struct node *temp){
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}
struct node *deletenode(struct node *root,int value){
	if(root==NULL){
		return NULL;
	}
	else if(value<root->data){
		root->left=deletenode(root->left,value);
	}
	else if(value>root->data){
		root->right=deletenode(root->right,value);
	}
	else{
		if(root->left==NULL&&root->right==NULL){
			free(root);
			return NULL;
		}
		else if(root->left==NULL){
			struct node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			struct node *temp=root->left;
			free(root);
			return temp;
		}
		else{
			struct node *temp=findmin(root->right);
			root->data=temp->data;
			root->right=deletenode(root->right,temp->data);
		}
	}
	return root;
}
void delete(){
	int value;
	printf("enter value to delete:");
	scanf("%d",&value);
	root=deletenode(root,value);
}
void inorder(struct node *temp){
	if(temp!=NULL){
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
		}
	}
	void display(){
		printf("inorder traversal is:\n");
		inorder(root);
		printf("\n");
	}
int main(){
	int choice;
	while(1){
		printf("1.insert\n");
		printf("2.delete\n");
		printf("3.display\n");
		printf("enter the choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:insert();
			        break;
			case 2:delete();
			        break;
			case 3:display();
			        break;
			default:printf("invalid choice!!\n");
		}
	}
	return 0;
}
