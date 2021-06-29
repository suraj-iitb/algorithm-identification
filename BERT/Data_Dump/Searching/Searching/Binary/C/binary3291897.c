#include<stdio.h>

int main(){
  int n,i,A[100000],r,q,j,cnt=0,left,right,mid,key,minj;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  /*for(i=0; i<n-1; i++){
    minj=i;
    for(j=i; j<n; j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    r=A[i];
    A[i]=A[minj];
    A[minj]=r;
    }*/

  scanf("%d",&q);
  for(j=0; j<q; j++){
    //binarysearch
    scanf("%d",&key);
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(A[mid]==key){
	cnt++;
	break;
      }
      else if(key<A[mid])right=mid;
      else left=mid+1;
      //printf("cnt:%d key:%d A[mid]:%d j:%d left:%d mid:%d right:%d\n",cnt,key,A[mid],j,left,mid,right);
    }
  }

  printf("%d\n",cnt);

  return 0;
}

