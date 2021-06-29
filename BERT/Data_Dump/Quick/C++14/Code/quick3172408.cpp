#include<iostream>
#include<string>
using namespace std;
#define INFTY (int)(1e9+100)

void merge(pair<int,string> A[], int left, int mid, int right){
	int n1 = mid - left, n2 = right - mid;
	pair<int, string> L[n1+1], R[n2+1];
	for(int i = 0; i < n1; i++){
		L[i] = A[left + i];
	}
	for(int i = 0; i < n2; i++){
		R[i] = A[mid + i];
	}
	L[n1].first = INFTY;
	R[n2].first = INFTY;
	for(int k = left, i = 0, j = 0; k < right; k++){
		if(L[i].first <= R[j].first){
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
}

void mergeSort(pair<int, string> A[], int left, int right){
	if(left+1 < right){
		int mid = (left + right)/2;
		mergeSort(A,left, mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}


int partition(pair<int, string> A[], int p, int r){
	int x = A[r].first;
	int i = p-1;
	for(int j = p; j < r; j++){
		if(A[j].first <= x){
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}
int n;
void quickSort(pair<int, string> A[], int p, int r){
	// for(int i = 0; i < n; i++){
		// cout<<A[i].second<<" "<<A[i].first<<endl;
	// }cout<<endl<<endl;;
	if(p < r){
		int q = partition(A, p, r);
		// cout<<p<<" "<<q-1<<" "<<q+1<<" "<<r<<endl;
		// cout<<A[q].first<<endl;
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
		// cout<<p<<" "<<q-1<<" "<<q+1<<" "<<r<<endl;
	}
}
pair<int, string> A[100100];
pair<int, string> B[100100];
int main(){

	int  flag = true;;
	
	cin>> n;
	
	for(int i = 0; i < n; i++){
		cin>>A[i].second>>A[i].first;
		B[i] = A[i];
	}
	
	quickSort(A,0,n-1);
	mergeSort(B,0,n);
	
	for(int i = 0; i < n; i++){
		if(A[i] != B[i]){
			flag = false;
			break;
		}
	}
	
	cout<<(flag?"Stable":"Not stable")<<endl;
	// cout<<(flag?"Stable":"Not stable")<<endl;
	for(int i = 0; i < n; i++){
		cout<<A[i].second<<" "<<A[i].first<<endl;
	}
	return 0;
}
