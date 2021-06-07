#include<stdio.h>

int linearSearch(int A[],int key, int n ){

  int i=0;
  int count=0;

 A[n]=key;

  while(A[i] != key) i++;

  return i!=n;


}


int main(){
  int A[10000+1];
  int i,key,n,q;
  int count=0;


  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);

  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(linearSearch(A,key,n))
      count++;
  }
  printf("%d\n",count);

  return 0;
}


