#include<iostream>
using namespace std;
#define INF 1000000001
int cnt;

void mergeSort(int *,int,int);
void merge(int *,int,int,int);
int main(){
	int N;
	cin>>N;
	int *line=new int[N];
	for(int i=0;i<N;++i){
		cin>>line[i];
	}
	cnt=0;
	mergeSort(line,0,N);
	for(int i=0;i<N;++i){
		cout<<line[i]<<(i<N-1?" ":"\n");
	}
	cout<<cnt<<endl;
	return 0;
}

void mergeSort(int *A,int left,int right){
	if(left + 1 < right){
		int mid = (left + right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}

void merge(int *A,int left,int mid,int right){
	int n1 = mid - left;
	int n2 = right - mid;
	int *L=new int[n1+1],*R=new int[n2+1];
	for(int i=0;i<n1;++i){
		L[i]=A[left + i];
	}
	for(int i=0;i<n2;++i){
		R[i]=A[mid + i];
	}
	L[n1]=INF;
	R[n2]=INF;
	int i=0;
	int j=0;
	for(int k=left;k<right;++k){
		++cnt;
		if(L[i] <= R[j]){
			A[k]=L[i];
			++i;
		}else{
			A[k]=R[j];
			++j;
		}
	}
}
