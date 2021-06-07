#include <stdio.h>

int S[100000],a;
int binarySearch(int);

int main(){
  int T[50000];
  int b,i,c=0;

  scanf("%d",&a);
  for(i=0 ;i<a ;i++ )
    scanf("%d",&S[i]);
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&T[i]);
    c+=binarySearch(T[i]);
  }

  printf("%d\n",c);

  return 0;
}


int binarySearch(int k){

  int l=0,r,m;

  r=a ;

  while(l<r){
    m=(l+r)/2;
    if(S[m]==k)
      return 1;
    else if(S[m]<k)
      l=m+1;
    else if(S[m]>k)
      r=m;
  }
  return 0;
}
 

