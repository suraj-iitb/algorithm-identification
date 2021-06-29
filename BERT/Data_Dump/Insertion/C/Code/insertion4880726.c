#include<stdio.h>

int main(void){
    
    int n,i,j,s,v;
    int a[1000];
    
    scanf("%d",&n);
    
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        
    }
    
    for(i=1;i<=n;i++){
    	v=a[i];
        j=i-1;
    	
    	while((j>=0)&&(a[j]>v)){
    		a[j+1]=a[j];
    		j--;
    	}
    	a[j+1]=v;
    	
    	for(s=1;s<=n;s++){
    		if(s==n){printf("%d\n",a[s]);
    		}
    		else {
    			printf("%d ",a[s]);
    		}
    	}
    }
    
    return 0;
}
