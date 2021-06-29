#include<iostream>
#include<vector>
using namespace std;

struct card{
	char suit;
	int num;
	int jun;
};

int out_card(vector<card> &A,int n){
	int i;
	for (i=0;i<=n-1;i++){
		cout << A[i].suit << " "<< A[i].num <<endl;
	}
}

int judgeStability(vector<card> &A,int n){
	int i;
	int flag=0;
	for(i=1;i<n;i++){
		if((A[i].num==A[i-1].num)&&(A[i].jun<A[i-1].jun)){
			flag=1;
		}
	}
	return flag;
}

int partition(vector<card> &A, int p, int r){
	int x=A[r].num;
	int i=p-1;
	int j;
	for (j=p;j<r;j++){
		if (A[j].num<=x){
			i++;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}

void QuickSort(vector<card> &A, int p, int r){
	if (p<r){
		int q=partition(A,p,r);
		QuickSort(A,p,q-1);
		QuickSort(A,q+1,r);
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,i;
	cin >> n;
	
	vector<card> C(n);
	for (i=0;i<n;i++){
		cin >> C[i].suit >> C[i].num;
		C[i].jun=i;
	}	
	
	QuickSort(C,0,n-1);
	
	int flag=judgeStability(C,n);
	if (!flag){
		cout <<"Stable" <<endl;
	}else{
		cout <<"Not stable" <<endl;
	}
	out_card(C,n);
	
	return 0;
}
