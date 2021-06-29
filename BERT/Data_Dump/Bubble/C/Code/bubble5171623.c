#include <stdio.h>
void BubbleSort (int a[],int n){
	int t,m = 0;
	for (int j = 0;j < n;j ++){
		for (int k = (n - 1);k > j;k --){
			if (a[k] < a[k - 1]){
				m +=1;
				t = a[k];
				a[k] = a[k - 1];
				a[k - 1] = t; 	
			}
		}
	}
	for (int i = 0; i < n; i ++){
		if (i == (n - 1)) printf ("%d",a[i]);
		else printf("%d ",a[i]);
	} 
	printf("\n%d\n",m);
}
int main(){
	int n,m = 0;
	scanf("%d",&n);
	int a[n];
	for (int i = 0; i < n; i ++){
		scanf("%d",&a[i]);
	} 
	BubbleSort (a,n);
	return 0;
}
