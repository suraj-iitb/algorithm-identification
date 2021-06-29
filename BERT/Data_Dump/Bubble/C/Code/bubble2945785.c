#include <stdio.h>
#define A 100
int main(){
  int i,j,n,flag=0,hozon;
  int sort[A];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&sort[i]);
  }
  
  for(i=0;i<=n-1;i++){
     for(j=n-1;j>=i+1;j--){
       if(sort[j]<sort[j-1]){
	 hozon = sort[j];
	 sort[j] = sort[j-1];
	 sort[j-1] = hozon;
	 flag++;
       }
     }
  }

  for(i=0;i<=n-1;i++){
    if(i==n-1){
      printf("%d",sort[i]);
    }
    else printf("%d ",sort[i]);
  }
  printf("\n%d\n",flag);

  return 0;
}
  
	 
	 

