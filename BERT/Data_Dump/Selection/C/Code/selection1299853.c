#include<stdio.h>

int selectionSort(int *, int);

main(){

  int n,i,num[100],c;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++)
    scanf("%d",&num[i]);

  c = selectionSort(num, n);

  for(i = 0 ; i < n ; i++){
    printf("%d",num[i]);
    if(i!=n-1) printf(" ");
  }

  printf("\n%d\n",c);

  return 0;
}

int selectionSort(int *num, int n){

  int i,minj,j,tmp,count=0,flag;

  for(i = 0 ; i <= n-1 ; i++){
    flag = 0;
    minj = i;
    for(j = i ; j <= n-1 ; j++){
      if(num[j] < num[minj]){ 
	minj = j;
	flag = 1;
      }
    }
    tmp = num[i];
    num[i] = num[minj];
    num[minj] = tmp;
    
    if(flag==1) count++;
  }

  return count;

}
