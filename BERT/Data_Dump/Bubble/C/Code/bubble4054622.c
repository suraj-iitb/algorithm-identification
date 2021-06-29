#include <stdio.h>
int main(void){
  int n,i,tmp,arr[100],cnt=0,flag=1;;
    
    scanf("%d",&n);
    if(n>100) exit(1);
    for(i=0;i<n;i++){
      scanf("%d",&arr[i]);
    }
    
    while(flag){
      flag=0;
        for(i=n-1;i>0;i--){
	  if(arr[i]<arr[i-1]){
	      tmp=arr[i];
                arr[i]=arr[i-1];
                arr[i-1]=tmp;
                cnt++;
                flag=1;
	    }
	}     
    }
    
    for(i=0;i<n;i++){
      if(i!=0) printf(" ");
        printf("%d",arr[i]);
    }
    printf("\n%d\n",cnt);
    
    return 0;
}

