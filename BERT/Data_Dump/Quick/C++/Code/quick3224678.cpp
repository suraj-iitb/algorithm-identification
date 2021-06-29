#include<iostream>
using namespace std;

struct C{char s;int n,o;};

int partition(C c[],int l, int r){
	int x=c[r].n;
	int i=l-1;
	for(int j=l;j<r;j++){
		if(c[j].n<=x){
			i++;
			swap(c[i],c[j]);
		}
	}
	swap(c[i+1],c[r]);
	return i+1;
}

void quickSort(C c[],int l,int r){
	if(l<r){
		int p=partition(c,l,r);
		quickSort(c,l,p-1);
		quickSort(c,p+1,r);
	}
}

bool isStable(int n, C c[]){
	for(int i=1;i<n;i++){
		if(c[i-1].n==c[i].n){
			if(c[i-1].o>c[i].o){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	C c[n];
	for(int i=0;i<n;i++){
		cin >> c[i].s >> c[i].n;
		c[i].o=i;
	}
	quickSort(c,0,n-1);
	if(isStable(n,c)){
		cout << "Stable" << endl;
	}else{
		cout << "Not stable" << endl;
	}
	for(int i=0;i<n;i++){
		cout << c[i].s << " " << c[i].n << endl;
	}
	return 0;
}

