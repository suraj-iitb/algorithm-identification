#include <stdio.h>
int main(){
	int n,a[100],key;
	scanf("%d",&n);
	for(int y=1;y<=n;y++){
		scanf("%d",&a[y]);
		printf("%d",a[y]);if(y<n)printf(" ");
	}
	printf("\n") ;
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1]){
			key=a[i];
			int j=i-1;
			while(j>0&&a[j]>key){
				a[j+1]=a[j];
				j--;
			}
			a[j+1]=key;

		}	
		for(int x=1;x<=n;x++){
		printf("%d",a[x]);	if(x<n)printf(" ");
	}

printf("\n") ;
	}

}
