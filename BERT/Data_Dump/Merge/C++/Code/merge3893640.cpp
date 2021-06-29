#include <iostream>
using namespace std;

#define MAX 500001
#define SEN 1000000000
typedef long long llong;


llong A[MAX];
llong Left[MAX/2+1], Right[MAX/2+1];
int cnt = 0;
void merge(llong A[], int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	for(int i=0; i<n1; i++) Left[i] = A[left+i];
	for(int i=0; i<n2; i++) Right[i] = A[mid+i];
	Left[n1] = SEN; Right[n2] = SEN;

	int i,j;
	i=j=0;
	for(int k=left; k<right; k++){
		cnt++;
		if(Left[i]<=Right[j]){
			A[k] = Left[i++];
		}else{
			A[k] = Right[j++];
		}
	}
}

void mergesort(llong A[], int left, int right){
	if(left+1<right){
		int mid = (left+right) / 2;
		mergesort(A, left, mid);
		mergesort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++) cin>>A[i];

	mergesort(A, 0, n);

	for(int i=0; i<n; i++){
		if(i) cout<<" ";
		cout<<A[i];
	}
	cout<<endl;
	cout<<cnt<<endl;
	return 0;
}
