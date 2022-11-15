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
#include <stdio.h>

void binaryInsertSort(int arr[], int len)
{
	int i, j, k, low, high, mid;
	for (i = 1; i < len; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			k = arr[i];
			low = 0;
			high = i - 1;

			while (low <= high)
			{
				mid = (low + high) / 2;
				if (k <= arr[mid])
				{
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
			}
			
			for ( j = i - 1; j >= high + 1; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[high + 1] = k;
		}
	}
}

int main()
{
	int i, a[8] ={30,13,70,85,39,42,6,20} ;
	binaryInsertSort(a, 8);
	for (i = 0; i < 8; i++)
	{
		printf("%d ", a[i]);
	}
}

//bubble sort
