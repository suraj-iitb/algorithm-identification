#include <stdio.h>
#define N 100000
#define NOT

int linearSearch(int [],int,int);


int main(){
  int count=0;
  int S[N],T[N],i,j,n,q;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }

  for(j=0;j<q;j++){
    
    if(linearSearch(S,n,T[j]) != 0){
	count++;
     
    }
  }
  
  printf("%d\n",count);

  return 0;
}
  
int linearSearch(int A[ ],int n,int key){
 int i=0;
  A[n] = key;

  while(A[i] != key){
    i++;
  }
  if(i==n) return 0;
  else return 1;

}
 


