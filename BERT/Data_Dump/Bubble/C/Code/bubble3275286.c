#include<stdio.h>

int main(){
  int n,a[100],flag,i,j,r,cnt=0;

  scanf("%d",&n);
  for(i=0; i<n; i++)scanf("%d",&a[i]);

    flag=1;
    i=0;
    while(flag){
      flag=0;
      for(j=n-1; j>=i+1; j--){
	if(a[j]<a[j-1]){
	  r=a[j];
	  a[j]=a[j-1];
	  a[j-1]=r;
	  cnt++;
	  flag=1;
	}
      }
      i++;
    }
  
  for(i=0; i<n; i++){
    if(i)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",cnt);
  
  return 0;
}

