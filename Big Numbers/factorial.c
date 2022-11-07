#include<stdio.h>

#define MAX 100000

int main()
{

  int i,j,k,digit,temp;

  scanf("%d",&k);

  char arr[MAX+1] = {1};

  for(i=2; i<=k; i++){

    for(digit=0, j=0; j<=MAX; j++){

        temp = arr[j] * i + digit;

        digit = temp / 10;

        arr[j] = temp % 10;

    }

  }

  for(i = MAX;i>=0;i--){

    if(arr[i] != 0){

      for(i;i>=0;i--){

        printf("%d",arr[i]);

      }

    }

  }

  return 0;

}
