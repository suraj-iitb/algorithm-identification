#include <iostream>
using namespace std;
int n,a[100];

void print(){
	int i=0;
	while(true){
		cout<<a[i];
		i++;
		if(i<n){
			cout<<" ";
		}else{
			break;
		}
	}
	cout<<endl;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cont=0;
	for(int i=0;i<n;i++){
		int minj=i;
		for(int j=i;j<n;j++){
			if(a[j]<a[minj]){
				minj=j;
			}
		}
		if(i!=minj){
			const int tmp=a[i];
			a[i]=a[minj];
			a[minj]=tmp;
			cont++;
		}
	}
	print();
	cout<<cont<<endl;
	return 0;
}
