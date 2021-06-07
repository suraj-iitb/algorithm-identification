#include <stdio.h>
int binarysearch(int ,int ,int *);
int main(){
  int i,ans=0,j,k,stuff1[100000],kazu1,kazu2,stuff2;
  scanf("%d",&kazu1);
  for(i=0;i<kazu1;i++){
    scanf("%d",&stuff1[i]);
  }
  scanf("%d",&kazu2);
  for(j=0;j<kazu2;j++){
    scanf("%d",&stuff2);
    ans+=binarysearch(stuff2,kazu1,stuff1);
  }
  printf("%d\n",ans);
  return 0;
}


int binarysearch(int key,int kazu1,int *stuff1){
  int left=0,right=kazu1,mid;
  while(left<right){
    mid=(left+right)/2;
    if(stuff1[mid]==key){
      return 1;
    }
    else if(key<stuff1[mid]){
      right=mid;
    }
    else {
      left=mid+1;
    }
  }
  return 0;
}

  

