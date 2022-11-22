#include<stdio.h>
void insertSort(int arr[], int len){
	int i,j,k,n;
	for (i=1;i<len;i++){
		k = arr[i];
		j=i-1;
		while((j>=0) && (arr[j]>k)) {
			arr[j+1] = arr[j];
			j--;
			/*
			  for(n=0;n<=5;n++){
				printf("%d ", arr[n]);
			}
			printf("k = %d", k);
			printf("\n"); 
		    */
		}
		arr[j+1] = k;
	}
}

int main()
{
	int a[6] = {7,4,-2,19,13,6};
	insertSort(a,6);
	for(int i=0;i<=5;i++){
		printf("%d ", a[i]);
	}
}
