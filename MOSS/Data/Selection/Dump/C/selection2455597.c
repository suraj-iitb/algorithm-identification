#include <stdio.h>

#define N 100

int main(){
	
  int a[N];
  int i,j,n,cout=0,tmp,minj;
	
  scanf("%d",&n);
	
  for(i=0;i<n;i++) scanf("%d",&a[i]);
	
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]) {
	minj=j;
      }
    }
    if(i!=minj){
    tmp=a[i];
      a[i]=a[minj];
      a[minj]=tmp;
      cout++;
    }
  }
			
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",cout);
				
  return 0;
}
