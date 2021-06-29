#include<stdio.h>
int main(){
  int i;
  int l[100];
  int n;
  int value;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&l[i]);
  }
  value=bubble(l,n);
  for(i=0;i<n;i++){
    printf("%d",l[i]);
    if(i<n-1)printf(" ");
    else printf("\n");
  }
  printf("%d\n",value);
  return 0;
}
int bubble(int l[],int n){
  int i;
  int j;
  int temp;
  int cnt=0;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(l[j]<l[j-1]){
	temp=l[j];
	l[j]=l[j-1];
	l[j-1]=temp;
	cnt++;
      }
    }
  }
  return cnt;
}

