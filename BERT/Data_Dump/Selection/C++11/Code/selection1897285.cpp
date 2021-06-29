#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n,temp,mini,count=0;
	cin>>n;
	int array[n]={};
	for(int i=0;i<n;i++){
		cin>>array[i];
	}	
	for(int i=0;i<n;i++){
		mini =i;
		for(int j=i;j<n;j++){
			if(array[j]<array[mini]){
				mini=j;
			}
		}
		if(i!=mini){
				temp = array[i];
				array[i]=array[mini];
				array[mini]=temp;
				count++;}
	}
	for(int i=0;i<n;i++){
		cout<<array[i];
		if(i==n-1){
			break;
		}
		cout<<" ";
	}	
	cout<<endl;
	cout<<count<<endl;
	return 0;
}
