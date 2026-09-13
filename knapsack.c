#include <stdio.h>
int main(){
	int i,j,n;
	float capacity,totalprofit=0;
	printf("enter the number of items:");
	scanf("%d",&n);
	float weight[n],profit[n],ratio[n];
	printf("enter the weight and profit of items:\n");
	for(i=0;i<n;i++){
		scanf("%f %f",&weight[i],&profit[i]);
		ratio[i]=profit[i]/weight[i];
	}
	printf("enter the capacity of bag:");
	scanf("%f",&capacity);
	for(i=0;i<n-1;i++){
		for(j=0;j<n;j++){
			if(ratio[i]<ratio[j]){
			   float temp;
			   temp=ratio[i];
			   ratio[i]=ratio[j];
			   ratio[j]=temp;
			
			   temp=weight[i];
			   weight[i]=weight[j];
			   weight[j]=temp;
			   
			   temp=profit[i];
			   profit[i]=profit[j];
			   profit[j]=temp;
		   }
		}
	}
	for(i=0;i<n;i++){
		if(weight[i]<capacity){
			capacity=capacity-weight[i];
			totalprofit=totalprofit+profit[i];
		}
		else{
			totalprofit=totalprofit+(ratio[i]*capacity);
			break;
		}
	}
	printf("the maximum profit is:%.2f",totalprofit);
	return 0;
}
