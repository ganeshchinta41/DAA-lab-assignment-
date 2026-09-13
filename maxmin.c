#include <stdio.h>
void maxmin(int a[],int low,int high,int *min,int *max){
	int max1,min1,max2,min2,mid;
	if(low==high){
		*max=a[low];
		*min=a[low];
	}
	else if(high==low+1){
		if(a[low]>a[high]){
			*max=a[low];
			*min=a[high];
		}
		else{
			*max=a[high];
			*min=a[low];
		}
	}
	else{
		mid=(low+high)/2;
		maxmin(a,low,mid,&min1,&max1);
		maxmin(a,mid+1,high,&min2,&max2);
	    if(min1<min2)
		   *min=min1;
	    else
	       *min=min2;
	    if(max1>max2)
	       *max=max1;
	    else
	       *max=max2;
    }
}
int main(){
	int n,i,min,max;
	int a[100];
	printf("enter the number of elements:");
	scanf("%d",&n);
	printf("enter the elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	maxmin(a,0,n-1,&min,&max);
	printf("max=%d\n",max);
	printf("min=%d\n",min);
	return 0;
}
