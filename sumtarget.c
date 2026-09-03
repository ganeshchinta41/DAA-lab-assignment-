#include <stdio.h>
int main(){
int a[10],hash[100]={0};
int n,t,required,i;
printf("enter the number of elements:");
scanf("%d",&n);
printf("enter the elements:\n");
for(i=0;i<n;i++){
	scanf("%d",&a[i]);
}
printf("enter the target value:");
scanf("%d",&t);
for(i=0;i<n;i++){
	required=t-a[i];
	if(required>=0&&required<100&&hash[required]==1){
		printf("pair found\n");
		printf("%d+%d=%d\n",a[i],required,t);
		return 0;
	}
	if(a[i]>=0&&a[i]<100){
		hash[a[i]]=1;
	}
}
	printf("pair not found!!\n");
	return 0;
}
