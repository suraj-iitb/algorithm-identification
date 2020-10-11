#include<stdio.h>
int v(int *,int);

int main(){
  int t,i,j,n,a[100],cn=0,flag=1;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  while(flag){
    flag=0;
    for(j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
	t=a[j];
	a[j]=a[j-1];
	a[j-1]=t;
	cn++;
	flag =1;
      }
    }
  }
  v(a,n);
  printf("%d\n",cn);
return 0;
}
int v(int *a,int n){
  int i;
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i==n-1)printf("\n");
    else printf(" ");
  }

}

