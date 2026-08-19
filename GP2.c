#include <stdio.h>
#include <math.h>
int main(){
	int N,X,i;
	int sum;
	printf("enter the values of N and X:\n");
	scanf("%d %d",&N,&X);
	if(X==1){
		sum=N+1;
	}
	else{
		sum=(pow(X,N+1)-1)/(X-1);
	}
	printf("the of the GP series is %d",sum);
	return 0;
}
