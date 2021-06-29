#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int count=0;

//二分探索。xが探すもの。Nは整列済みの配列。a,bは範囲
void v_search(int x,int *N,int a,int b){
  if(a<=b){
    int c;
    c=(a+b)/2;
    if(N[c]==x) count+=1;
    else if(N[c] <x) v_search(x,N,c+1,b);
    else v_search(x,N,a,c-1);
  }
}




int main(){
  int n,q;
  int i,j;
  int *N;
  int x;
   

  scanf("%d",&n);
  N=malloc(n*sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&N[i]);
  

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&x);
    v_search(x,N,0,n-1);
  }
  
  printf("%d\n",count);
  return 0;
}
    
