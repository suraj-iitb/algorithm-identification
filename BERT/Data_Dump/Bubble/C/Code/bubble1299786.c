#include<stdio.h>

int bubbleSort(int *, int);

main(){

  int n,i,num[100],c;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++)
    scanf("%d",&num[i]);

  c = bubbleSort(num, n);

  for(i = 0 ; i < n ; i++){
    printf("%d",num[i]);
    if(i!=n-1) printf(" ");
  }

  printf("\n%d\n",c);

  return 0;
}

int bubbleSort(int *num, int n){

  int flag = 1,tmp,count=0,j;

  while(flag){

    flag = 0;

    for(j = n-1 ; j >= 1 ; j--){
      if(num[j] < num[j-1]){
	tmp = num[j];
	num[j] = num[j-1];
	num[j-1] = tmp;
	flag = 1;
	count++;
      }
    }
  }

  return count;
}
