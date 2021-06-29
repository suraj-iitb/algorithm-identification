#include <stdio.h>
#include <stdlib.h>
int binarysearch(int*,int,int);
int main(){

  int n,q,*data1,*data2,i,r,count=0;

  scanf("%d",&n);

  data1=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    scanf("%d",&data1[i]);
  }

  scanf("%d",&q);

  data2=(int *)malloc(sizeof(int)*q);
  for(i=0;i<q;i++){
    scanf("%d",&data2[i]);
  }
  
  for(i=0;i<q;i++){
    r=binarysearch(data1,data2[i],n);
      if(r==1) count++;
        }

  printf("%d\n",count);

  free(data1);
  free(data2);
  return 0;
}


int binarysearch(int *data1,int data2,int length){

  int left,right,mid;

  left=0;
  right=length;
  while(left<right){
    mid=(left+right)/2;
    if(data2==data1[mid]) return 1;
    if(data2>data1[mid]) left=mid+1;
    else if(data2<data1[mid]) right=mid;
      }
  return -1;

}
