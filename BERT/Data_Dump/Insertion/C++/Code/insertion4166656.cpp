#include<iostream>
#include<vector>
using namespace std;
int main(){
	
	int N;
	cin >>N;
	
	vector<int> A(N);
	for(int i=0;i<N;i++){
		
		cin >>A.at(i);
		
	}
	
	cout <<A.at(0);
		for(int i=1;i<N;i++){
			
			cout <<" " <<A.at(i);
			
		}
		cout <<endl;
	
	for(int i=1;i<N;i++){
		
		int v=A.at(i);
		int j=i-1;
		while(j>=0&&A.at(j)>v){
			
			A.at(j+1)=A.at(j);
			j--;
			
		}
		A.at(j+1)=v;
		
		cout <<A.at(0);
		for(int i=1;i<N;i++){
			
			cout <<" " <<A.at(i);
			
		}
		cout <<endl;
		
	}
	
}
