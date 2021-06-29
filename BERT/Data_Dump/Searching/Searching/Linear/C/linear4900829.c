#include <stdio.h>

int main(void){
	int c,d,i,j,k,l,m,n,q,s,t,ans;
	int a[10000]={-1};
	
	t=0;
	ans=0;
	k=0;
	scanf("%d",&n);
/*	for(i=0;i<n;i++){
		scanf("%d",&s);
		d=0;
		++c;
		for(j=0;j<c;j++){
			if(s==a[j]){
				d=1;
				break;
			}
		}
		if(d==0){
			a[k]=s;
			++k;
		}
	}*/
	
	for(i=0;i<n;i++){
	    scanf("%d",&a[i]);
	}

	
	scanf("%d",&q);
	for(l=0;l<q;l++){
		scanf("%d",&t);
		//printf("t is %d \n",t);
		for(m=0;m<n;m++){
			if(t==a[m]){
				++ans;
				break;
			}
		}
	}
	
	printf("%d\n",ans);
	
	
	
	
	return 0;
}


