#include<bits/stdc++.h>
using namespace std;
struct card{
	char c;
 	int i;
 };
 card l[100000];
card r[100000];
void merge(int n,card H[],int left,int mid,int right){
	int n1 = mid-left;
	int n2 = right -mid;
	for(int i = 0;i<n1;i++) l[i] = H[left+i];
	for(int i = 0;i<n2;i++) r[i] = H[mid+i];
	l[n1].i = r[n2].i = 99;
	int i = 0,j = 0;
	for(int k = left;k<right;k++){
		if(l[i].i <=r[j].i){
			H[k] = l[i];
			i++;
		}else{
			H[k] = r[j];
			j++;
		}
	}
}
void mergesort(card H[],int n,int left,int right){
	if(left +1<right){
	int mid = (left + right)/2;
	mergesort(H,n,left,mid);
	mergesort(H,n,mid,right);
	merge(n,H,left,mid,right);
	}
}
int partition(card A[],int p,int r){
		int i = p;
	for(int j = p;j<r;j++){
		if(A[r].i >= A[j].i){
			swap(A[j],A[i]);
			i++;
		}
	}
	swap(A[i],A[r]);

	return i;
}
int quicksort(card A[],int p,int r){
	
	if(p<r){
	int q = partition(A,p,r);
	quicksort(A,p,q-1);
	quicksort(A,q+1,r);
	}
}
int main(){
	int n;
	cin>>n;
	card A[n];
	card H[n];
	for(int i = 0;i<n;i++)cin>>A[i].c>>A[i].i ,H[i] = A[i];
	quicksort(A,0,n-1);
	mergesort(H,n,0,n);
	for(int i = 0;i<n;i++){
		if(H[i].c != A[i].c){
			cout<<"Not stable"<<endl;
			break;
		}
		if(i == n-1){
			cout<<"Stable"<<endl;
		}

	}
	for(int i = 0;i<n;i++){
		cout<<A[i].c<<" "<<A[i].i<<endl;
	}
}
