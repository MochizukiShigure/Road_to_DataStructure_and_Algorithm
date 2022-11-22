#include <stdio.h>
void mergeSort(int a[],int left,int right){
	if(left<right){
		int mid = (left + right) / 2;
		mergeSort(a,left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, right, mid);
	}
}
void merge(int a[],int left,int right,int mid) {
	int s[100];
	int k;
	int i = left, j = mid + 1;
	int sor = left;
	while (i <= mid && j <= right) {
		if (a[i] < a[j]) {
			s[sor++] = a[i++];
		
		}
		else {
			s[sor++] = a[j++];
			
		}
		for(k = 0; k < 10; k++)
		{
			printf("%d ", a[k]);
		}
		printf("\n");
	}
	while (i <= mid) s[sor++] = a[i++];
	while (j <= right)  s[sor++] = a[j++];
	sor = left;
	while (sor <= right) {
		a[sor] = s[sor];
		sor++;
	}
}
int main()
{
	int a[]={3,11,5,4,64,43,6,9,8,99};
	int i;
	mergeSort(a, 0, 9);
	for(i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0; 
} 
