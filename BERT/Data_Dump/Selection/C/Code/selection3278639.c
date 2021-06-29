#include<stdio.h>

void selec(int *,int);
int main(){
  int n,a[100],i;
  scanf("%d",&n);
  if(n<1||n>100)fprintf(stderr,"ERRRRRRRRRRRRRRRR\n");
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  selec(a,n);
  return 0;
}

void selec(int *a,int n){
  int i,minj,j,x,count=0;
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
      	x=a[i];
	a[i]=a[minj];
	a[minj]=x;
	if(i!=minj){
	  count++;
  }
	}
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",count);
}

