#include<iostream>
#include<string>
#include<utility>
#include<algorithm>
#include<vector>
#include<math.h>

#define bp __builtin_popcount
#define pii pair<long long,long long>

using namespace std;

long long arr[200005],brr[200005];

void swap(long long *a, long long *b){
	long long temp = *a;
	*a = *b;
	*b = temp;
}

long long Partition(long long *A, long long p, long long r){
	long long x = A[r]-A[r]%10;
	long long i = p-1;
	for (long long j = p; j<=r-1;j++){
		if (A[j]-A[j]%10 <= x){
			i = i+1;
			swap(A[i], A[j]) ;
		}
		
		
	}
	swap(A[i+1],A[r]);
	return i+1;
}

void Quicksort(long long *A, long long p, long long r){
	if (p < r){
		long long q = Partition(A, p, r);
		Quicksort(A, p, q-1);
		Quicksort(A, q+1, r);
	}
}

long long L[500005],R[500005];

void Merge(long long *A, long long left, long long mid, long long right){
	long long n1 = mid - left;
	long long n2 = right - mid;
	long long i;
	for (i = 0; i<=n1-1; i++)
    L[i] = A[left + i];
    for (i = 0; i<=n2-1; i++)
    R[i] = A[mid + i];
    L[n1] = 200000000000000000;
    R[n2] = 200000000000000000;
	i = 0;
	long long j = 0;
	for (long long k = left; k<=right-1;k++){
		
		if (L[i]-L[i]%100 <= R[j]-R[j]%100){
			A[k] = L[i];
			i = i + 1;
		}
		else {
			A[k] = R[j];
        	j = j + 1;
		}
	}
}

void MergeSort(long long *A,long long left,long long right){
	if (left+1 < right){
		long long mid = (left + right)/2;
		MergeSort(A, left, mid);
		MergeSort(A, mid, right);
		Merge(A, left, mid, right);
	}
    
}
     


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long a,n;
	char c;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>c>>a;
		if(c == 'S')
		a = a*100+4;
		if(c == 'H')
		a = a*100+3;
		if(c == 'C')
		a = a*100+2;
		if(c == 'D')
		a = a*100+1;
		arr[i] = a;
		brr[i] = a;
	}
	bool ans = 1;
	Quicksort(arr,0,n-1);
	MergeSort(brr,0,n);
	for(int i=0;i<n;i++){
		if(brr[i] != arr[i]){
			ans = 0;
		}
	}
	if(ans == 1)cout<<"Stable\n";
	else cout<<"Not stable\n";
	for(int i=0;i<n;i++){
		if(arr[i]%100 == 4){
			cout<<"S ";
		}
		if(arr[i]%100 == 3){
			cout<<"H ";
		}
		if(arr[i]%100 == 2){
			cout<<"C ";
		}
		if(arr[i]%100 == 1){
			cout<<"D ";
		}
		cout<<arr[i]/100<<endl;
	}
	return 0;
}
