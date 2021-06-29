/*Insertion sort*/
#include<stdio.h>


int main(){
	int n,i,j;
	scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		printf("%d",a[0]);
		for(i=1;i<n;i++){
			printf(" %d",a[i]);
		}
		printf("\n");
		for(i=0;i<n-1;i++){
		    j=i+1;
			while(j>0 && a[j]<a[j-1]){
				a[j-1]^=a[j];
				a[j]^=a[j-1];
				a[j-1]^=a[j];
				j--;
			}
			printf("%d",a[0]);
            for(int k=1;k<n;k++){
                printf(" %d",a[k]);
            }
            printf("\n");
        }
	return 0;
}
