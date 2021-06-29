#include <stdio.h>


#define N 100

int selectionSort(int *,int);

int main(){
  int s,t[N],i;
  scanf("%d",&s);

  for(i=0;i<s;i++)
    scanf("%d",&t[i]);

  printf("%d\n",selectionSort(t,s));

  return 0;
}
int selectionSort(int *t,int s){
  int swap,count=0,i,minj,j;
  for(i=0;i<s-1;i++){
    minj = i;
    for(j=i;j<s;j++){
      if(t[j]<t[minj]){
	minj = j;
     }
    }
    if(minj!=i){
      swap = t[minj];
      t[minj] = t[i];
      t[i] = swap;
      count++;  
    }
  }
  for(i=0;i<s-1;i++)
    printf("%d ",t[i]);
  printf("%d\n",t[s-1]);

  return count;
}


