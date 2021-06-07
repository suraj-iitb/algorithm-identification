#include<stdio.h>
#define N 100000

int a,A[N];

int se(int rig,int A[],int k);
int main(){
 
  int b,bValue;
  int i,c=0;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&bValue);
    if(se(a,A,bValue)==1)c++;
  }

  printf("%d\n",c);
  return 0;
}
int se(int rig,int A[],int k){
  int lef=0;
  int mid=0;
  while(lef<rig){
    mid=(lef+rig)/2;
    if(A[mid]>k)rig=mid;
    else if(A[mid]<k)lef=mid+1; 
    else return 1;
  }
  return 0;
}

