#include <stdio.h>
int linearsearch(int a[],int n,int key){
	int i;
	for(i=0;i<n;i++){
		if(a[i]==key){
	       return i;
		}
	}
	return -1;
}
int main(){
	int a[100],n,result,key,i;
	printf("enter the number of elements:");
	scanf("%d",&n);
	printf("enter the elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("enter the element to search:");
	scanf("%d",&key);
	result=linearsearch(a,n,key);
	if(result==-1){
		printf("element not found!!\n");
	}
	else{
		printf("element is found at position %d",result);
	}
	return 0;
}

