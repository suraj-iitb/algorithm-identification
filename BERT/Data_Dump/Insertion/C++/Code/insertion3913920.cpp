#include<iostream>
using namespace std;
const int MAXN=105;
int Array[MAXN];

int Print(int n){
	for(int i=0;i<n;i++){
		cout<<Array[i];
		if(i!=n-1)cout<<" ";
	}
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>Array[i];
	}
	for(int i=0;i<n;i++){
		int key=Array[i];
		int j=i-1;
		while(j>=0&&Array[j]>key){
			Array[j+1]=Array[j];
			j--;
		}
		Array[j+1]=key;
		Print(n);
	}
	return 0;
}
