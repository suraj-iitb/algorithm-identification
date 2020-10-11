#include<stdio.h>
#define N 100

int main(){
  int f=1,c=0,i=0,n,a[N],swap,y=0;

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&a[i]);
  
  while(f!=0){
    f=0;
    
    for(i=n-1;i>=c+1;i--){      
      if(a[i]<a[i-1]){	
	swap=a[i-1];
	a[i-1]=a[i];
	a[i]=swap;
	f=1;
	y++;
      }
    }
    
    c++;
  }
  
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",y);
  return 0;
}
      

