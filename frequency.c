#include <stdio.h>
#define size 20
int main(){
	int a[100];
	int hash[size];
	int n,pos,i,index;
	for(i=0;i<size;i++){
		hash[i]=-1;
	}
	printf("enter the number of elements:");
	scanf("%d",&n);
	printf("enter the elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		index=a[i]%size;
		while(hash[index]!=-1&&hash[index]!=a[i]){
			index=(index+1)%size;
		}
		hash[index]=a[i];
	}
	printf("element\tfrequency\n");
	for(i=0;i<size;i++){
		if(hash[i]!=-1){
			int count=0;
			for(pos=0;pos<n;pos++){
				if(a[pos]==hash[i]){
					count++;
				}
			}
			printf("%d\t%d\n",hash[i],count);
		}
	}
	return 0;
}
 


