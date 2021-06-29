#include<stdio.h>
int bubbleSort(int A[],int N){
  int i,j,temp,count=0,minj;
  for(i=0;i<N;i++){
    minj=i;
  for(j =i;j<N;j++){
    if(A[j]<A[minj]){
      minj=j;
    }
  }if(i!=minj){
      temp=A[i];
      A[i]=A[minj];
      A[minj]=temp;
      count++;
    }
    // if(A[i]>A[minj]){
    // if(i!=minj){
    // temp=A[i];
    //  A[i]=A[minj];
    //  A[minj]=temp;
      // if(i!=minj){
    //  count++;
      }
    return count;
    }
int main(){
  int N,i,flag;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
 flag=bubbleSort(A,N);
 for(i=0;i<N;i++){
   if(i>0) printf(" ");
   printf("%d",A[i]);
 }
   printf("\n");
   // printf(" ");
 printf("%d\n",flag);
 return 0;
}
