#include<stdio.h>

void selectionsort(int s[],int n){
  int min=0,a;
  for(int i=0;i<n;i++){
    min=i;
    for(int j=i;j<n;j++){
      if(s[j]<s[min])min=j;
    }
    a=s[i];
    s[i]=s[min];
    s[min]=a;
  }
}

int main(void){
  int n,q,cnt=0,mid,key;
  scanf("%d",&n);
  int s[n];
  for(int i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  int t[q];
  for(int i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  selectionsort(s,n);
  mid=n/2;
  for(int i=0;i<q;i++){
    key=t[i];
    if(s[mid]<=key){
      for(int j=mid;j<n;j++){
        if(key==s[j]){
          cnt++;
          break;
        }
      }
    }
    else if(s[mid]>key){
      for(int j=0;j<mid;j++){
        if(key==s[j]){
          cnt++;
          break;
        }
      }
    }
  }
    
  printf("%d\n",cnt);

  return 0;
}

