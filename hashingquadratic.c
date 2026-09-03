#include <stdio.h>
#define size 10
#define empty -1
#define deleted -2
int hashtable[size];
int hashfunction(int key){
	return key%size;
}
void initialize(){
	int i;
	for(i=0;i<size;i++){
		hashtable[i]=empty;
	}
}
void insert(int key){
	int index=hashfunction(key);
	int i=0;
	while(hashtable[index]!=empty&&hashtable[index]!=deleted){
		i++;
		index=(key+i*i)%size;
		if(i==size){
			printf("the hash table is full!!\n");
			return;
		}
	}
	hashtable[index]=key;
	printf("%d inserted at index %d\n",key,index);
}
int search(int key){
	int index=hashfunction(key);
	int i=0;
	while(hashtable[index]!=empty){
		i++;
		if(hashtable[index]==key){
			return index;
		}
		index=(key+i*i)%size;
		if(i==size){
			break;
		}
	}
	return -1;
}
void delete(int key){
	int index=search(key);
	if(index==-1){
		printf("element not found\n");
	}
	else{
		hashtable[index]=deleted;
		printf("%d deleted from index %d\n",key,index);
	}
}
void display(){
	int i;
	printf("index\tvalue\n");
	for(i=0;i<size;i++){
		printf("%d\t",i);
		if(hashtable[i]==empty){
			printf("empty");
		}
		else if(hashtable[i]==deleted){
			printf("deleted");
		}
		else{
			printf("%d",hashtable[i]);
		}
		printf("\n");
	}
}
int main(){
	int choice,key,index;
	initialize();
	while(1){
		printf("1.insert\n");
		printf("2.search\n");
		printf("3.delete\n");
		printf("4.display\n");
		printf("5.exit\n");
		printf("enter the choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("enter key:");
			       scanf("%d",&key);
			       insert(key);
			       break;
			case 2:printf("enter key to search:");
			       scanf("%d",&key);
			       index=search(key);
			       if(index==-1){
			       	printf("element not found!!\n");
				   }
				   else{
				   	printf("%d found at index %d\n",key,index);
				   }
				   break;
			case 3:printf("enter key to delete:");
			       scanf("%d",&key);
			       delete(key);
			       break;
			case 4:display();
			       break;
			case 5:return 0;
			       break;
			default:printf("invalid choice!!\n");
		}
	}
	return 0;
}
