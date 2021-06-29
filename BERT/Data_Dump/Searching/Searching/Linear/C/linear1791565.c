#include <stdio.h>
#define N 10000
#define Q 500
#define notFound 0

int linearSearch(int[], int, int);

int main()
{
  int i,n,q,key,cnt=0;
  int S[N];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);

    if(linearSearch(S,key,n)){
      cnt++;
    }
  }
  printf("%d\n",cnt);


  return 0;
}


int linearSearch(int A[],int key,int n)
{
  int i=0;
  for(i=0;i<n;i++){
    if(A[i]==key){
      return 1;
    }
  }
    return notFound;
}
