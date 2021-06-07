#include<stdio.h>

int LinearSearch(int *, int);

int n;

int main(void){

  int q,s[10000],t,count=0,i;


  scanf("%d",&n);
  for(i = 0 ; i < n ; i++)
    scanf("%d",&s[i]);


  scanf("%d",&q);
  for(i = 0 ; i < q ; i++){
    scanf("%d",&t);

    if(LinearSearch(s,t)==1) count++;

  }

  printf("%d\n",count);

  return 0;

}


int LinearSearch(int *s, int key){

  int i = 0;

  s[n] = key;

  while(s[i]!=key){
    i++;
  }
  
  if(i == n) return 0;
  
  return 1;
  
}
