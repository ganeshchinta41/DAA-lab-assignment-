#include <stdio.h>
int binarysearch(int a[],int n,int key){
	int low=0;
	int high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid]==key){
			return mid;
		}
		else if(key<a[mid]){
			high=mid-1;
		}
		else if(key>a[mid]){
			low=mid+1;
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
	result=binarysearch(a,n,key);
	if(result==-1){
		printf("element not found!!\n");
	}
	else{
		printf("element is found at position %d",result);
	}
	return 0;
}
