#include<iostream>
using namespace std;
int main(){
	int N,v,j;
	cin >> N;
	int a[N];
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	for(int i=0;i<N;i++){
		v = a[i];
		j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1] = a[j];
			j--;
			a[j+1] = v;
		}
		for(int x=0;x<N;x++){
if(x!=N-1){
			cout <<a[x] <<" ";
}
else{
cout <<a[x];
}
		}
		cout << "\n";
	}
	return 0;
}
