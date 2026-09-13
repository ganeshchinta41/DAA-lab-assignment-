#include <stdio.h>
void merge(int a[],int low,int mid,int high){
	int b[100];
	int i=low;
	int j=mid+1;
	int k=low;
	while(i<=mid&&j<=high){
		if(a[i]<a[j]){
			b[k]=a[i];
			i++;
		}
		else{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=mid){
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=high){
		b[k]=a[j];
		j++;
		k++;
	}
	k=low;
	while(k<=high){
		a[k]=b[k];
		k++;
	}
}
void mergesort(int a[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
int main(){
	int a[10]={1,5,4,8,9,7,6};
	int i,n=7;
	printf("before merge sort :\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	mergesort(a,0,6);
	printf("\nafter merge sort :\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
