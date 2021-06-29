#include<stdio.h>

int linearSearch(int S[], int T[],int n,int q){
   int i,j;
   int sum = 0;
  for(i = 0;i < q;i++){
    for(j = 0;j<n;j++){
      if(T[i] == S[j]){
	sum++;
	break;
      }
      
    }
  }
  return sum;
}



int main(){
  int i,n;
  int S[10001];
  int q,T[10001];
  int sum = 0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0;i<q;i++){
    scanf("%d",&T[i]);
  } 
   sum = linearSearch(S,T,n,q);
    
  printf("%d\n",sum);
    return 0;
  
}

