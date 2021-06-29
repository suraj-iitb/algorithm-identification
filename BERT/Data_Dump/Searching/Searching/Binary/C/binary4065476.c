#include <stdio.h>
#include <stdlib.h>

int Search(int *a,int b,int c){
  int l,r,m;

  l=0;
  r=c;

  while(l<r){
    
    m=(l+r)/2;
    
    if(a[m]==b){
      
      return 1;
    }
    
    else if(a[m]<b){
      
      l=m+1;
      
    }else
      
      r=m;
    
  }
  return 0;
}


int main(){
  int *a,*b,c,d,i,e=0,f;

  scanf("%d",&c);

  a=(int *)malloc(c*sizeof(int));
  
  for(i=0;i<c;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&d);
  
 b=(int *)malloc(d*sizeof(int));
  
  for(i=0;i<d;i++){
    scanf("%d",&b[i]);
  }
  
  for(i=0;i<d;i++){
    
    f=Search(a,b[i], c);
    
  if(f==1)
    
    e++;
  }
  
  printf("%d\n",e);
  
  free(a);

  return 0;
}

