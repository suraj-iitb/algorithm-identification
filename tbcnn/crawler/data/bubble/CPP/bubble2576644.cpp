#include<iostream>
using namespace std;
int main(){
	int N,a[100],count=0,flag,val;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	flag = 1;
	while(flag==1){
		flag = 0;
		for(int j=N-1;j>=1;j--){
			if(a[j]<a[j-1]){
				val = a[j];
				a[j]=a[j-1];
				a[j-1]=val;
				flag = 1;
				count++;
			}
		}
	}
	for(int i=0;i<N;i++){
if(i>0)cout << " ";
		cout << a[i] ;
	}
	cout << "\n" << count << endl;
	return 0;
}
