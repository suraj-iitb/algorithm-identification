#include <stdio.h>
int main(void){
  int n,i,j,tmp,arr[100],cnt=0,minj;
    
    scanf("%d",&n);
    if(n>100) exit(1);
    for(i=0;i<n;i++){
      scanf("%d",&arr[i]);
    }
    
    for(i=0;i<n;i++){
      minj=i;
        for(j=i;j<n;j++){
	  if(arr[minj]>arr[j]) minj=j;
        }
        if(minj!=i){
	  tmp=arr[i];
            arr[i]=arr[minj];
            arr[minj]=tmp;
            cnt++;
        }
    }
    
    for(i=0;i<n;i++){
      if(i!=0) printf(" ");
        printf("%d",arr[i]);
    }
    printf("\n%d\n",cnt);
    
    return 0;
}

