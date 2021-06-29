#include <iostream>
using namespace std;

struct card{
	char suit;int value;
};

card A[100010],B[100010],L[100010/2+2],R[100010/2+2];
int n;

int partition(int p ,int r){
	int i=p-1;
	for(int j=p;j<r;j++){
		if(B[j].value<=B[r].value){
			i++;
			swap(B[j],B[i]);
		}
	}
	swap(B[i+1],B[r]);
	return i+1;
}

void quicksort(int p,int r){
	if(p<r){
		int q=partition(p,r);
		quicksort(p,q-1);
		quicksort(q+1,r);
	}
}

void merge(int l,int r,int mid){
	int n1=mid-l;
	int n2=r-mid;
	for(int i=0;i<n1;i++){L[i]=A[l+i];}
	for(int i=0;i<n2;i++){R[i]=A[mid+i];}
	int i=0,j=0;
	L[n1].value=R[n2].value=2000000000;
	for(int k=l;k<r;k++){
		if(L[i].value<=R[j].value){
			A[k]=L[i++];
		}
		else{
			A[k]=R[j++];
		}
	}
}

void mergesort(int l,int r){
	if(l+1<r){
		int mid=(l+r)/2;
		mergesort(l,mid);
		mergesort(mid,r);
		merge(l,r,mid);
	}
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>B[i].suit>>B[i].value;
		A[i].suit=B[i].suit;
		A[i].value=B[i].value;
	}
	mergesort(0,n);
	quicksort(0,n-1);
	bool check=1;
	for(int i=0;i<n;i++){
		if(A[i].suit!=B[i].suit){
			check=0;
			break;
		}
	}
	cout << (check?"Stable":"Not stable")<<endl;
	for(int i=0;i<n;i++){
		printf("%c %d\n",B[i].suit,B[i].value);
	}
}
