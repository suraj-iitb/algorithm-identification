#include<stdio.h>
int main(){
  int con,minj,n,i,j,k,l,c=0,a[100];
  scanf("%d",&n);
  for(k = 0;k < n;k++){
    scanf("%d",&a[k]);
  }
  for(i = 0;i < n;i++){
    minj = i;
    for(j = i;j < n;j++){
      if(a[j] < a[minj]){
	minj = j;
      }
    }
    con=a[i];
    a[i]=a[minj];
    a[minj]=con;
    if(a[minj]>a[i])c++;

  }
  for (l = 0; l < n; l++) {
    if(l < n-1){
      printf("%d ",a[l]);
    }
    else if(l==n-1){
      printf("%d\n",a[l]);
    }
  }
  printf("%d\n",c);
  return 0;
}
