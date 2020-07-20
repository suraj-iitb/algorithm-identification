#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int N,count=0;
	//読み込み
	cin >> N;
	int A[N];
	for(int i=0;i<N;i++)
		cin >> A[i];
	//整列
	for(int i=0;i<N;i++)
		for(int j=N-1;j>i;j--)
			if(A[j]<A[j-1]){
				swap(A[j],A[j-1]);
				count++;
			}
	//出力
	for(int i=0;i<N;i++){
		if(i>0)	cout<<" ";
		cout<< A[i];
	}
	cout<< endl << count << endl;
	return 0;
}
