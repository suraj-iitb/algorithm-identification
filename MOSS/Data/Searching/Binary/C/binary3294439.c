#include<stdio.h>
int binarySearch(int *, int, int);
int main(){
  int i,count,n,S[100000],q,T[50000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
}
  scanf("%d",&q);
  for(i=0;i<n;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
  count+=binarySearch(S,n,T[i]);
  //printf("test1\n");
  }

  printf("%d\n",count);
  return 0;
}

int binarySearch(int *S,int n,int key){
  int left=0,right=n,mid;
  while(left < right){
    mid=(left + right) / 2;
    if(S[mid]==key){
      //printf("test2\n");
      return 1;
}
    else if(key < S[mid]){
      //printf("test3\n");
      right = mid;
}
    else{
      //printf("test4\n");
      left = mid +1;
}
}
  return 0;
}

