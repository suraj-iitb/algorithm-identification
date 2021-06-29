#include <stdio.h>
int binarySearch(int*,int*);
  int n,q;
int main(){
  int i,j;
  int key;
  int c = 0;
  int S[1000000];
  int T[50000];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }




  printf("%d\n",binarySearch(S,T));


  
  return 0;
}

int binarySearch(int *S ,int *T){
  int j,l,r,mid;
  int cnt=0;
  l=0;
  r=n;
  for(j=0;j<q;j++){  
  while(l<r){
    mid=(l+r)/2;
    if(S[mid]==T[j]){cnt++;
 
      break;}
    else if(T[j]<S[mid]){r=mid;}
    else l=mid+1;
 
  } l=0;
  r=n;

  }
  return cnt;
}



