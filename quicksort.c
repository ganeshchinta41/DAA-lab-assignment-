#include <stdio.h>
int partition(int a[],int low,int high){
	int pivot=a[low];
	int i=low+1;
	int j=high;
	while(i<=j){
		while(a[i]<pivot){
			i++;
		}
		while(a[j]>pivot){
			j--;
		}
		if(i<j){
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	int temp=a[low];
	a[low]=a[j];
	a[j]=temp;
	return j;
}
void quicksort(int a[],int low,int high){
	if(low<high){
		int p=partition(a,low,high);
		quicksort(a,low,p-1);
		quicksort(a,p+1,high);
	}
}
int main(){
	int a[10]={3,35,45,67,8,7,56};
	int i,n=7;
	printf("before quick sort :\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	quicksort(a,0,6);
	printf("\nafter quick sort :\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
