#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define infinity 2000000000
struct node{
	char pat;
	int num;
};

node A[100010],B[100010];
node L[50010],R[50010];
int n;

void merge(int left,int mid,int right){
	int n1=mid-left,n2=right-mid;
	for(int i=0;i<n1;i++) L[i]=B[left+i];
	for(int i=0;i<n2;i++) R[i]=B[mid+i];
	L[n1].num=infinity;R[n2].num=infinity;
	int i=0,j=0;
	for(int x=left;x<right;x++){
		if(L[i].num<=R[j].num) {B[x]=L[i++];}
		else B[x]=R[j++];
	}
	return ;
}

void merge_sort(int left,int right){

	if(left+1<right){
		int mid=(left+right)/2;
		merge_sort(left,mid);
		merge_sort(mid,right);
		merge(left,mid,right);
	}

	return ;
}

int partition(int left,int right){
	int i =left-1;
	for(int j=left;j<right;j++){
		if(A[j].num<=A[right].num) {
			swap(A[i+1],A[j]);
			i++;
		}
	}
	swap(A[i+1],A[right]);
	return i+1;
}

void quicksort(int left,int right){
	if(left<right){
		int p=partition(left,right);
		quicksort(left,p-1);
		quicksort(p+1,right);
	}
	return ;
}

int main (){
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
			scanf("%c %d", &A[i].pat, &A[i].num);
			getchar();
			B[i] = A[i];
		}
	quicksort(0,n-1);
	merge_sort(0,n);
	bool stable=true;
	for(int i=0;i<n;i++) if(A[i].pat!=B[i].pat) stable=false;
	if(stable==false) cout<<"Not stable"<<endl; else cout<<"Stable"<<endl;
	for(int i=0;i<n;i++) cout<<A[i].pat<<" "<<A[i].num<<endl;

	return 0;
}
