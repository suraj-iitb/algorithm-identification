#include<stdio.h>
int search(int a[],int n,int key){
  int i;
  for(i=0;i<n;i++){
    if(a[i]==key)
      return 1;
  }
  return 0;
}
int main(){
  int i,n,m,a[10000],key;
  int sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&key);
    if(search(a,n,key)==1){
      sum++;
    }
  }
    printf("%d\n",sum);
    return 0;
}

