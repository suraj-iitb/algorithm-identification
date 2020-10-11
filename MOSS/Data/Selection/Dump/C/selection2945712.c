#include<stdio.h>
int main(){
  int i;
  int n;
  int l[100];
  int value;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&l[i]);
  }
  value=selection(l,n);
  for(i=0;i<n;i++){
    printf("%d",l[i]);
    if(i<n-1)printf(" ");
    else printf("\n");
  }
  printf("%d\n",value);
  return 0;
}
int selection(int l[],int n){
  int i;
  int j;
  int cnt=0;
  int mini;
  int temp;
  for(i=0;i<n;i++){
    mini=i;
    for(j=i;j<n;j++){
      if(l[j]<l[mini])mini=j;
    }
    if(mini!=i){
      temp=l[mini];
      l[mini]=l[i];
      l[i]=temp;
      cnt++;
    }
  }
  return cnt;
}

