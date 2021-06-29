#include<stdio.h>

int search(int A[],int s,int key){
  int i=0;
  A[s] = key;
  while(A[i]!=key)i++;
  return i!=s;
}
int main(){
  int i,n,m[10000+1],q,key,sum=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&m[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&key);
      if(search(m,n,key))sum++;
    }
  printf("%d\n",sum);

  return 0;
}

