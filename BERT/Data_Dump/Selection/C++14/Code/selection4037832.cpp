#include<stdio.h>

int SelectionSort(int* a, int n){
	int i,j,cnt=0,tmp,min,pos;
	for(i=0;i+1<n;i++){
		min=a[i];	pos=i;
		for(int j=i+1;j<n;j++){
			if(min>a[j]){
				min=a[j];
				pos=j;
			}
		}

		if(pos!=i){
			cnt++;
			tmp=a[i];
			a[i]=a[pos];
			a[pos]=tmp;
		}
	}

	return cnt;
}

int main(){
	int i,n,cnt, a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	cnt=SelectionSort(a,n);

	for(i=0;i<n;i++){
		if(i)printf(" ");
		printf("%d",a[i]);
	}printf("\n%d\n",cnt);
	
	return 0;
}

