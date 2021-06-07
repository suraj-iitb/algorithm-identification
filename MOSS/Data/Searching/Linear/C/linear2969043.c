#include<stdio.h>

int main()
{
  int i,n;
  scanf("%d",&n);
  int S[10001];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  int n2;
  int sum;
  int key;
  sum=0;
  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&key);
    if(search(S,n,key))
      sum++;
  }
  printf("%d\n",sum);
	
  return 0;
}

int search(int S[],int n,int key){
  int j=0;
  S[n]=key;
  while(S[j]!=key)
    j++;
  return j!=n;
} 

