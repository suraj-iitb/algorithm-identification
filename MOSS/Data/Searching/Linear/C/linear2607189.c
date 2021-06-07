#include <stdio.h>
int linearSearch(int a[],int n,int key){
  int i;
  i=0;
  a[n]=key;
  while(a[i]!=key){
    i++;
  }
  return i!=n;
}


int main(void)
{
  int i,n,q,ans,a[10001],key;
  ans=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(linearSearch(a,n,key)){
      ans++;
    }
  }
  printf("%d\n",ans);
  
  return 0;
}
