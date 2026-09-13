#include <stdio.h>
int bucket[10][10];
int count[10]={0};
void bucketsort(int a[],int n){
	int i,j,k;
	for(i=0;i<n;i++){
	  int index=a[i]/10;
	  bucket[index][count[index]]=a[i];
	  count[index]++;
	}
	for(i=0;i<10;i++){
		for(j=0;j<count[i]-1;j++){
			for(k=j+1;k<count[i];k++){
				if(bucket[i][j]>bucket[i][k]){
					int temp=bucket[i][j];
					bucket[i][j]=bucket[i][k];
					bucket[i][k]=temp;
				}
			}
		}
	}
	int pos=0;
	for(i=0;i<10;i++){
		for(j=0;j<count[i];j++){
			a[pos]=bucket[i][j];
			pos++;
		}
	}
}
int main(){
	int a[10]={3,35,45,67,8,7,56};
	int i,n=7;
	printf("before bucket sort :\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	bucketsort(a,7);
	printf("\nafter bucket sort :\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
