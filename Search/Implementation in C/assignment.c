/* 
    1.Finish a program in block searching, binary searching and sequence searching in random/not random list.
    2.Switch the order list to binary tree and implement a search by recursion.
    3.Implement the addition and deletion of binary tree and do not affect the search.
*/ 

//1.block
#include <stdio.h>
int i,j,k;
struct index
{
	int key;  
	int start;
	int end;    
}index_list[3];

int creat_list(int a[])
{
	i=0;
	j=0;
	while(i<=2){
		index_list[i].start=j;
		j=j+2;
		index_list[i].end=j;
		for(k=index_list[i].start;k<=j;k++){
			if(index_list[i].key < a[k]){
				index_list[i].key = a[k];
			}
		}
		j++;
		i++;
	}
}

int block_search(int key,int a[])  
{
	
	for(i=0;i<=2&&key>index_list[i].key;i++)
	{
		
	}
	
	for(j=index_list[i].start; j<=index_list[i].end; j++){
		if(a[j]==key){
			return j;
			//break;
			} 
		}
	
	
}


int main(){
	int rarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int key,n;
	scanf("%d",&key);
	creat_list(rarr);
	n=block_search(key,rarr);
	printf("%d", n);
	return 0;
}


//1.sequence
#include<stdio.h>
int rarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int k = 7;
int lenr = sizeof(rarr) / sizeof(rarr[0]);

int sequence(int *a, int len, int k)
{
	for(int i = 0 ;i <= len;i++){
		if(a[i] == k)
		{
			return i;	
		}
	}
	return -1;
}

int main()
{
	int result;
	result = sequence(rarr, lenr, k);
	printf("result by sequence search : %d", result);
}
