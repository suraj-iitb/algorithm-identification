#include<stdio.h>

//#define NOT_FOUND -1;
int binarySearch(int *,int,int);

int main(){
  int i,j,k,s,numA,numB,num=0,key;
  scanf("%d",&numA);

  int retuA[numA];

  for(i = 0; i < numA; i++){
    scanf("%d",&retuA[i]);
  }

  scanf("%d",&numB);

  for(i = 0; i < numB; i++){
    scanf("%d",&key);
    //   printf("%d",binarySearch(retuA,retuB[i]));
    if(binarySearch(retuA,key,numA) == 1) num++;
  }

  printf("%d\n",num);

return 0;
}

int binarySearch(int* A,int B,int C){
  int left = 0;
  int right = C;
  int mid;
  //  int flag=0;

  while(left < right){
    mid = (left + right) / 2;
    
    if(A[mid] == B)return 1;
    else if(B < A[mid]) right = mid;
    else left = mid + 1;
  }

  return 0;
}
