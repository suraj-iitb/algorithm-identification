#include<stdio.h>
int main(){
  
  int N,arr[100],i,V,j=0,m;
  
  scanf("%d",&N);
  
  for(i=0;i<N;i++)  
    scanf("%d",&arr[i]);
  
   for(i=0;i<N;i++){  
    printf("%d",arr[i]);
    if(i!=N-1) printf(" ");
    if(i==N-1) printf("\n");
  }
  
  
  for(i=1;i<N;i++){
    
    V=arr[i];
    j=i-1;
    while(j>=0 && arr[j]> V){
      arr[j+1]=arr[j];
      j--;
      arr[j+1]=V;
      
    }
   for(m=0;m<N;m++){  
	printf("%d",arr[m]);
	if(m!=N-1) printf(" ");
	if(m==N-1) printf("\n");
      } 
  }
   
  return 0;
}
