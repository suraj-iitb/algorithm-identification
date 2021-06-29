#include<stdio.h>

int main(){
	int n,i,j,k;
	int c=0,x=0;
	int a[1001]={0};
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(i=1;i<=n;i++){
	    
		for(k=1;k<=n;k++){
			printf("%d",a[k]);
			if(k!=n)printf(" ");
		}
		
		printf("\n");
		
		j=i+1;
		
		if(a[i]>a[j]){
		    
			while(a[i]>a[j] && i!=0){
				x=0;
				x=a[i];
				a[i]=a[j];
				a[j]=x;
				i--;
				j--;
				c++;
			}
		}
		i=i+c;
		c=0;
	}
	return 0;
}

