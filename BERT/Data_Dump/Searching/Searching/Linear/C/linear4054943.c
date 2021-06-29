#include<stdio.h>

int LinearSearch(int*,int,int);

int main()
{
  int n,q,T,i,num=0;
  int S[10000];

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T);
    if(LinearSearch(S,T,n) == 1){
      num++;
    }
  }

  printf("%d\n",num);

}

int LinearSearch(int *A,int T,int n)
{
  int i;
  for(i=0;i<n;i++) {
    if(A[i] == T)
      return 1;
  }

  return 0;
}
    

