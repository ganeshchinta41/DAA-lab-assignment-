#include <stdio.h>
int main(){
	int n,i,j,k,result;
	printf("enter the value os n:");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements of array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
    printf("enter the value of k:");
    scanf("%d",&k);
    for(i=0;i<k;i++){
    	int min=a[0];
    	for(j=1;j<n;j++){
    		if(a[j]<min){
    			min=a[j];
			}
		}
		 result=min;
		for(j=0;j<n;j++){
			if(a[j]==min){
				a[j]=99999;
				break;
			}
		}
	}
	printf("the kth smallest element is %d",result);
	return 0;
}
