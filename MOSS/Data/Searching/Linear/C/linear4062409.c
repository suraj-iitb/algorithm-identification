#include <stdio.h>
#define M 10001

int compare(int S1[],int n,int z){
  int j;
  S1[n]=z;
  for(j=0;S1[j]!=z;j++){
  }
    return j!=n;
}

int main(){
  int i,n,q,z,S1[M];
  int match=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S1[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&z);
    if(compare(S1,n,z)){
      match++;
    }
  }

  printf("%d\n",match);

  return 0;
}


