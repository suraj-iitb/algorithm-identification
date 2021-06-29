#include <stdio.h>
int main(){
  int i,j,minj,n,work,count=0,a[100];

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }

  for(i=0; i<n; i++){
    minj=i;
    
    for(j=i; j<n; j++){
      if(a[j] < a[minj]) minj=j;
    }
      if(i != minj){
	work=a[i];
	a[i]=a[minj];
	a[minj]=work;
	count++;
    }
  }


  if(n==1) printf("%d",a[0]);
  else{
    for(i=0; i<n; i++){
      if(i==n-1) printf("%d", a[i]);
      else printf("%d ",a[i]);
    }
  }
  printf("\n%d\n",count);
  return 0;
}
