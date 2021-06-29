#include<bits/stdc++.h>

using namespace std;

int a[500005], L[500005], R[500005];
long long int comparisons=0;

void merge(int a[], int left, int mid, int right){
	int n1, n2;
	n1=mid-left;
	n2=right-mid;
	
	for(int i=0; i<n1; i++){
		L[i]=a[left+i];
//		comparisons++;
	}
	for(int i=0; i<n2; i++){
		R[i]=a[mid+i];
//		comparisons++;
	}
	
	L[n1]=INT_MAX;
	R[n2]=INT_MAX;
	int i=0, j=0;
	
	for(int k=left; k<right; k++){
		if(L[i]<=R[j]){
			a[k]=L[i];
			i+=1;
		}
		else{
			a[k]=R[j];
			j+=1;
		}
		comparisons++;
	}
	
}


void merge_sort(int a[], int left, int right){
	if((left+1)<right){
		int mid=(left+right)/2;
		merge_sort(a, left, mid);
		merge_sort(a, mid, right);
		merge(a, left, mid, right);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	merge_sort(a, 0, n);
	for(int i=0; i<n; i++){
		printf("%d", a[i]);
		if(i<n-1){
			printf(" ");
		}
	}
	printf("\n%lld\n", comparisons);
	

	
	return 0;
}

