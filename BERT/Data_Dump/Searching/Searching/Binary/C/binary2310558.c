#include<stdio.h>

#define N 100000
#define CLEAR 1
#define NOT 0

int num1[N],num2[N];

int search(int , int);

int main(){
  int n1,n2,i,j,count=0;

  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&num1[i]);
  }

  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&num2[i]);
  }

  for(i=0;i<n2;i++){
    if(search(n1,num2[i])==1) count++;
  }
  printf("%d\n",count);
      return 0;
}

int search(int right,int n){
  int left=0,mid;
  
  while (left<right){
    mid=(left+right)/2;

    if (num1[mid]==n) return CLEAR;
    else if(n<num1[mid]) right = mid;
    else left = mid +1;
  }
  
  return NOT;
}
