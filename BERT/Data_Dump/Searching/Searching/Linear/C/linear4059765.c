#include<stdio.h>

 int A[10000],n;



int linearSearch(int key){
  int j,flag;
  for(j=0;j<=n-1;j++){
    if(A[j]==key){
      return  1;
    }
  }
  return 0;
}


int main() {
  int i,q,key,sum=0;
 

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(linearSearch(key)){
      sum++;
    }
  }

  printf("%d\n",sum);

  return 0;
}

