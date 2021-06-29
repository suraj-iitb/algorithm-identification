#include <stdio.h>
int LinearSearch(int );
int S[1000000],n;
int main(){

  int j,i,q,T[1000000],count=0,flag;
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
    }
  scanf("%d",&q);
   for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  
    for(j=0;j<q;j++){
      flag=LinearSearch(T[j]);
      if(flag==1) count++;
    }
 
  printf("%d\n",count);
  return 0;


}

int LinearSearch(int key){
  int i;
  for(i=0;i<n;i++){
    if(S[i]==key) return 1;
  }
  return 0;
}
