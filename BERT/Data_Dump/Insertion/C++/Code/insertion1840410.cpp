#include <iostream>
#include <vector> 
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> array;
	for (int i = 0; i<n; i++){
		int temp;
		cin>>temp;
		array.push_back(temp);
	}
	//---------array bulid---------
	for (int i = 0; i<n; i++){
		if(i!=0) cout<<" ";
		cout<<array[i];
		if(i == n-1) cout<<endl;
	}
	//----------original array----------
	for (int i = 1; i<n; i++){
		int insert = array[i];
		int j = i-1;
		while(j>=0 && array[j]>insert){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = insert;
	//-----------sort----------------	
		for(int k = 0; k<n; k++)
		{
		if(k!=0) cout<<" ";
		cout<<array[k];
		if(k == n-1) cout<<endl;
		}
	}
	return 0;
}
