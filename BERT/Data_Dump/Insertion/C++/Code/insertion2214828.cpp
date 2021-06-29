#include "bits/stdc++.h"
using namespace std;

void intersection(int dd[],int n){
	int v,j;
	for (int k = 0; k < n; ++k) {
		if(k){cout<<" "<<dd[k];}
		else{cout<<dd[k];}
	}cout<<endl;
	for (int i = 1; i < n; ++i) {
		v=dd[i];
		j=i-1;
		while(j>=0&&dd[j]>v){
			dd[j+1]=dd[j];
			j--;
		}
		dd[j+1]=v;
		for (int k = 0; k < n; ++k) {
			if(k){cout<<" "<<dd[k];}
			else{cout<<dd[k];}
		}cout<<endl;
	}
}

int main() {
int n;
cin>>n;
int d[n];
for (int i = 0; i < n; ++i) {
	cin>>d[i];
}
	intersection(d,n);

}
