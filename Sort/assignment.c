/*
    implement insertion sort，binary insertion sort and bubble sort.
*/

//insertion sort
#include<stdio.h>

void insertsort(int arr[], int len){
	int i,j,k;
	for (i=1;i<len;i++){
		k = arr[i];
		j=i-1;
		while((j>=0) && (arr[j]>k)) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = k;
	}
}

int main()
{
	int a[6] = {7,4,-2,19,13,6};
	insertsort(a,6);
	for(int i=0;i<=5;i++){
		printf("%d ", a[i]);
	}
}

//binary insertion sort


//bubble sort
