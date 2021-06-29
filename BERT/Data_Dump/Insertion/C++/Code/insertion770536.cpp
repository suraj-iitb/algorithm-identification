#include <iostream>
using namespace std;



void showArray(int* datas,int n){
	int i;
	 for(i = 0;i<n-1;i++){
		 cout<<datas[i]<<" ";
		 
     }
	 cout << datas[n-1] << endl;
}
int main(){
	int n,i,j,k,key;
	cin >> n;
	int datas[1000];
	for(i=0;i<n;i++){
		cin >> datas[i];
	}

	for(j=1;j<n;j++){
	 showArray(datas,n);
	 key=datas[j];
	 for(k=j-1;k>=0;k--){
	  if(datas[k]<key) {break;}
	  datas[k+1] = datas[k];
	  datas[k] = key;
	 }

	}
	showArray(datas,n);
}
