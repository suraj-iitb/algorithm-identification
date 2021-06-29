#include <stdio.h>
 
int Sort(int n,int *a);
 
int main(){
  int len,i,count,j,a[100];
   
  //input
  scanf("%d", &len);
  for(i=0; i<len; i++){
    scanf("%d", &a[i]);
  }
 
  //sort
  count = Sort(len, &a[0]);
 
  //output
  for(i=0; i<len; i++){
    printf("%d", a[i]);
    if(i != len-1)printf(" ");
    else printf("\n");
  }
  printf("%d\n", count);
   
  return 0;
}
 
int Sort(int len,int *a){
  int i,j;
  int mini,tmp,count=0;
   
  for(i=0; i<len; i++){
    mini = i;

    for(j=i+1; j<len; j++){
      if(a[j] < a[mini]){
	mini = j;
      }
    }

    if(mini != i){
      tmp = a[i];
      a[i] = a[mini];
      a[mini] = tmp;
      ++count;
    }

  }
  return count;
}
