#include<stdio.h>
int main(){
  int i,j,k,minj,swap;
  int a[100];
  int con=0;
  scanf("%d",&i);
  for(j=0;j<i;j++){
    scanf("%d",&a[j]);
  }


  
  for(j=0;j<i-1;j++){
    minj=j;
    for(k=j;k<i;k++){
      if(a[k]<a[minj]){
	minj=k;
      }}
	swap=a[j];
	a[j]=a[minj];
	a[minj]=swap;
  
	if(j!=minj){
	  con++;
    }
  }
  for(j=0;j<i;j++){
    if(j==0) printf("%d",a[j]);
    else printf(" %d",a[j]);
  }
  printf("\n");
  printf("%d\n",con);
  return 0;
 
}

