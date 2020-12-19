#include<iostream>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
const long SENTINEL = 1000000007;
int gCount;

void merge( long a[], int l, int m, int r ){
	int n1 = m - l;
	int n2 = r - m;
	long *arrL = new long[n1+1];
	long *arrR = new long[n2+1];
	for( int i=0; i<n1; i++ ){
		arrL[i] = a[l+i];
	}
	for( int i=0; i<n2; i++ ){
		arrR[i] = a[m+i];
	}
	arrL[n1] = SENTINEL;
	arrR[n2] = SENTINEL;
	int i=0, j=0;
	for( int k=l; k<r; k++ ){
		gCount++;
		if( arrL[i] <= arrR[j] ){
			a[k] = arrL[i++];
		}else{
			a[k] = arrR[j++];
		}
	}
	delete[] arrL;
	delete[] arrR;
}

void mergeSort( long a[], int l, int r ){
	if( l+1 < r ){
		int m = (l+r)/2;
		mergeSort(a, l, m);
		mergeSort(a, m, r);
		merge(a, l, m, r);
	}
}

int main(){
	int n;
	long s[500000];
	gCount = 0;
	cin >> n;
	rep(i,n) cin >> s[i];
	mergeSort(s,0,n);
	cout << s[0];
	for(int i=1; i<n; i++ )
		cout << " " << s[i];
	cout << endl;
	cout << gCount << endl;
	return 0;
}
