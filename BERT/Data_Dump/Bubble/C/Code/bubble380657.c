
#include<stdio.h>

int main(){

  int i,j,n,s,count=0,a[101];


  //load N
  scanf("%d",&n);
  //load number
  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }

  //Algorithm
  for(i=1;i<=n;i++){
    for(j=n;j>=i+1;j--){
      //swap
      if(a[j]<a[j-1]){
	s=a[j];
	a[j]=a[j-1];
	a[j-1]=s;
	count++;
      }
    }
  }


  //primt number
    for(i=1;i<=n;i++){
      printf("%d",a[i]);
      if(i!=n){
	printf(" ");
      }
    }

    printf("\n");
    printf("%d\n",count);

  return 0;

}
