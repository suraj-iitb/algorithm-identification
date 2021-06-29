#include<stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    
	int n,a[200005];
	scanf("%d",&n);
	for(int i=0; i<n;i++) {
		scanf("%d",&a[i]);
	}
	for(int z=0; z<n-1;z++) {
		printf("%d ",a[z]);
	}
	printf("%d\n",a[n-1]);
	int key,j,x;
	for(x=1;x<n;x++) {
		key = a[x];
		j = x - 1;
		while(j>=0 && a[j] > key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
		
		for(int k=0;k<n-1;k++) printf("%d ",a[k]);
		printf("%d\n",a[n-1]);
	}
	
    return 0;
}

