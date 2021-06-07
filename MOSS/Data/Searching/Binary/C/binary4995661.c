#include<stdio.h>

int main(){
  int n,m,sum=0,key,T[100005];
  int i,j,f;
  int l,h,mid;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&T[i]);
  }
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&key);
    l = 0;
    h = n;
    f = 0;
    while(l<h){
      mid = (l + h)/2;
      if(T[mid]==key){
        f = 1;
        break;
      }
      if(T[mid]<key){
        l = mid+1;
      }else if(T[mid]>key){
        h = mid;
      }
    }
    if(f)sum++;
  }

  printf("%d\n",sum);

  return 0;
}
