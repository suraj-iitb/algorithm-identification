#include <stdio.h>
void output(int *,int);
int main(){
  int i,j,n,cnt=0;
  int min,hozon,han=0;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(a[j]<a[min]){
	min=j;
	han=1;
      }
    }
    if(han==1){
      hozon=a[i];
      a[i]=a[min];
      a[min]=hozon;
      cnt++;
      han=0;
    }
  }
  output(a,n);
  printf("%d\n",cnt);
  return 0;
}
void output(int *a,int n){
  int i,j;
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i==n-1) printf("\n");
    else printf(" ");
  }
}
