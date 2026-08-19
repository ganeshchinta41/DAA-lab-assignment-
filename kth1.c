#include <stdio.h>
int main(){
	int n,i,j,k;
	printf("enter the value os n:");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements of array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
    printf("enter the value of k:");
    scanf("%d",&k);
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("the kth smallest element is %d",a[k-1]);
	return 0;
}
