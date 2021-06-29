#include<iostream>
#include<string>
using namespace std;
#define INFTY 2000000000
#define MAX 100000

struct C{
    char s;
    int n;
};

void merge(struct C A[], int left, int mid, int right){
	int n1 = mid - left;
    int n2 = right - mid;
	struct C L[n1+1], R[n2+1];
	for(int i = 0; i < n1; i++){
		L[i] = A[left + i];
	}
	for(int i = 0; i < n2; i++){
		R[i] = A[mid + i];
	}
	L[n1].n = INFTY;
	R[n2].n = INFTY;
	for(int k = left, i = 0, j = 0; k < right; k++){
		if(L[i].n <= R[j].n){
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
}

void mergeSort(struct C A[], int left, int right){
	if(left+1 < right){
		int mid = (left + right)/2;
		mergeSort(A,left, mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}


int partition(struct C A[], int p, int r){
	int x = A[r].n;
	struct C t{};
	int i = p-1;
	for(int j = p; j < r; j++){
		if(A[j].n <= x){
			i++;
			//swap(A[i], A[j]);
			t=A[i];
			A[i]=A[j];
			A[j]=t;
		}
	}
	//swap(A[i+1],A[r]);
	t=A[i+1];
	A[i+1]=A[r];
	A[r]=t;
	return i+1;
}
int n;
void quickSort(struct C A[], int p, int r){
	if(p < r){
		int q = partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
	}
}
struct C A[MAX];
struct C B[MAX];
int main(){
	int  stable = 1;
	cin>> n;
	for(int i = 0; i < n; i++){
		cin>>A[i].s>>A[i].n;
		B[i].s = A[i].s;
		B[i].n = A[i].n;
	}
	
	quickSort(A,0,n-1);
	mergeSort(B,0,n);
	
	for(int i = 0; i < n; i++){
		if(A[i].s != B[i].s || A[i].n != B[i].n){
			stable = 0;
			break;
		}
	}
	
	//cout<<(stable?"Stable":"Not stable")<<endl;
	if(stable==0){
	    cout << "Not stable"<<endl;
	}else{
	    cout<<"Stable"<<endl;
	}
	for(int i = 0; i < n; i++){
		cout<<A[i].s<<" "<<A[i].n<<endl;
	}
	return 0;
}



