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
			} 
		}
	
	
}

int main(){
	int rarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int larr[] = {3, 2, 1, 5, 6, 4, 9, 8, 7};
	int key,a;
	scanf("%d",&key);
	creat_list(rarr);
	a=block_search(key,rarr);
	printf("result by block search : %d is founded at index %d in array \n", key, a);
	creat_list(larr);
	a=block_search(key,larr);
	printf("result by block search : %d is founded in random list at index %d in array \n", key, a);
	return 0;
}

//1.sequence
#include<stdio.h>
int i;
int sequence_search(int *a, int len, int key)
{
	for(i = 0 ;i <= len;i++){
		if(a[i] == key)
		{
			return i;	
		}
	}
	return -1;
}

int main()
{
	int rarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int key = 7;
	int lenr = sizeof(rarr) / sizeof(rarr[0]);
	int b = sequence_search(rarr, lenr, key);
	printf("result by sequence search : %d is founded at index %d in array \n", key, b);
}

//1.binary
#include<stdio.h>
int binary_search(int key) 
{
 int left = 1,right = 9;
 int mid = 0;
 while (left <= right)
 {
  mid = (left + right) / 2;
  if (key < mid)
  {
   right = mid;
  }
  else if (key > mid)
  {
   left = mid+1;   //notice:left = mid+1 instead of mid
  }
  else 
  {
   return key;
   break;
  }	
 }
}

int main()
{
 int rarr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9 };
 int key;
 scanf("%d",&key);
 int c = binary_search(key);
 printf("result by binary search : %d is founded \n", c);
}

//1.general
#include <stdio.h>
int rarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int larr[] = {3, 2, 1, 5, 6, 4, 9, 8, 7};
int i,j,k;

struct index   //block
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
			} 
		}
	
	
}


int lenr = sizeof(rarr) / sizeof(rarr[0]);//sequence
int sequence_search(int *a, int len, int key)
{

	for(i = 0 ;i <= len;i++){
		if(a[i] == key)
		{
			return i;	
		}
	}
	return -1;
}


int binary_search(int key) //binary
{
 int left = 1,right = 9;
 int mid = 0;
 while (left <= right)
 {
  mid = (left + right) / 2;
  if (key < mid)
  {
   right = mid;
  }
  else if (key > mid)
  {
   left = mid+1;
  }
  else 
  {
   return key;
   break;
  }	
 }
}

int main(){
	int key,a;
	scanf("%d",&key);
	creat_list(rarr);
	a=block_search(key,rarr);
	printf("result by block search : %d is founded in not random list at index %d in array \n", key, a);
	
	creat_list(larr);
	a=block_search(key,larr);
	printf("result by block search : %d is founded in random list at index %d in array \n", key, a);
	
	int b;
	b = sequence_search(rarr, lenr, key);
	printf("result by sequence search : %d is founded in not random list at index %d in array \n", key, b);
	
 	int c = binary_search(key);
 	printf("result by binary search : %d is founded in not random list \n", c);
 
	return 0;
}

//2-3
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct TNode
{
	int data;
	struct TNode *lchild, *rchild;
} TNode, *BTree;

int BST_Search(BTree T, int key, BTree f, BTree *p) {
	if (!T) {
		*p = f;
		return FALSE;
	}
	else if (key == T->data) {
		*p = T;
		return TRUE;
	}
	else if (key < T->data) {
		return BST_Search(T->lchild, key, T, p);
	}
	else {
		return BST_Search(T->rchild, key, T, p);
	}
}

int creatInsert(BTree *T, int e) {
	BTree p = NULL;
	if (!BST_Search((*T), e, NULL, &p)) {

		BTree s = (BTree)malloc(sizeof(TNode));
		s->data = e;
		s->lchild = s->rchild = NULL;
	
		if (p==NULL) {
			*T = s;
		}
		else if (e < p->data) {
			p->lchild = s;
		}
		else {
			p->rchild = s;
		}
		return TRUE;
	}
	return FALSE;
}

int Delete(BTree *p)
{
	BTree q, s;
	if (!(*p)->lchild && !(*p)->rchild) {
		*p = NULL;
	}
	else if (!(*p)->lchild) { 
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else if (!(*p)->rchild) {
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else {
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != *p) {
			q->rchild = s->lchild;
		}
		else {
			q->lchild = s->lchild;
		}
		free(s);
	}
	return TRUE;
}

int BST_Delete(BTree *T, int key)
{
	if (!(*T)) {
		return FALSE;
	}
	else
	{
		if (key == (*T)->data) {
			Delete(T);
			return TRUE;
		}
		else if (key < (*T)->data) {
			return BST_Delete(&(*T)->lchild, key);
		}
		else {
			return BST_Delete(&(*T)->rchild, key);
		}
	}
}

void inOrder(BTree T)
{
	if (T == NULL) {
		return;
	}
	inOrder(T->lchild);
	printf("%d ", T->data);
	inOrder(T->rchild);
}

int main()
{
	int i;
	int a[9] = { 1,2,3,4,5,6,7,8,9 };
	BTree T = NULL;
	for (i = 0; i < 9; i++) {
		creatInsert(&T, a[i]);
	}
	printf("traverse binary search tree by inorder ：\n");
	inOrder(T);
	printf("\n");
	printf("add 10：\n");
	creatInsert(&T,10);
	inOrder(T);
	printf("\n");
	printf("delete 6：\n");
	BST_Delete(&T, 6);
	inOrder(T);
} 
