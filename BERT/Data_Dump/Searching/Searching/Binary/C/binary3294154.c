#include<stdio.h>
int binarySearch(int*,int,int);

int main(){
  int n,S[1000000];
  int q,T[1000000];
  int i,j,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
    if(binarySearch(S,n,T[j])!=0){
      count++;
    }
  }

  printf("%d\n",count);
  return 0;
}


int binarySearch(int *s,int n,int key){
  int left,middle,right;
  left=0;
  right=n;
 
  while(left<right){
    middle=(right+left)/2;
    if(s[middle]==key){
      return 1;
    }else if(s[middle]>key){
      right=middle;
    }else{
      left=middle+1;
    }
  }
  return 0;
}




