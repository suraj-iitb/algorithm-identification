#include<stdio.h>
int main(){
  int i,j,key,n,x,y;
  int a[100];

  scanf("%d",&n);
  for(y=0; y<n; y++){
    scanf("%d",&a[y]);
  }
  for(y=0; y<n; y++){
    if(y==n-1){
      printf("%d",a[y]);
    }
    else{
    printf("%d ",a[y]);
    }
    }
  printf("\n");
  
  for(i=1; i<n; i++){
    key=i;
  
    while((key>0)&&(a[key-1]>a[key])){
      j=a[key-1];
      a[key-1]=a[key];
      a[key]=j;
      

      key--;
    }
      for(x=0; x<n; x++){
	if(x==n-1){
	  printf("%d",a[x]);
	}
	else{
	printf("%d ",a[x]);
	}
      }
      
	printf("\n");
      
  }
  return 0;
}

