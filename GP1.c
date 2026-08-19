#include <stdio.h>
int main(){
	int N,X,i;
	int sum=1,power=1;
	printf("enter the values of N and X:\n");
	scanf("%d %d",&N,&X);
	for(i=1;i<=N;i++){
		power=power*X;
		sum=sum+power;
	}
	printf("the sum of the series is %d",sum);
	return 0;
}
