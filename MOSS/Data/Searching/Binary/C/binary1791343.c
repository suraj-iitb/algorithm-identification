#include<stdio.h>

int main(){
  int n,m,sum=0,key,T[100005];
  int i,j,f;
  int left,right,mid;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&T[i]);
  }

  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&key);

    //BinarySearch                                                                                                                                          
    left = 0;
    right = n;
    f = 0;
    while(left<right){
      mid = (left + right)/2;
      if(T[mid]==key){
        f = 1;
        break;
      }
      if(T[mid]<key){
        left = mid+1;
      }else if(T[mid]>key){
        right = mid;
      }
    }
    if(f)sum++;
  }

  printf("%d\n",sum);

  return 0;
}
