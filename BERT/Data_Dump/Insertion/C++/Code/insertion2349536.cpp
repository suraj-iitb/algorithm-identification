#include<iostream>
using namespace std;

int N;
const int MAX=101;
int  A[MAX];



void print(){
	for(int i=0;i<N;i++){
		if(i==0)
			cout<<A[i];
		else{
			cout<<" "<<A[i];
		}

	}
	cout<<endl;
}
void insertionsort(int A[]){
	print();
	for(int i=1;i<N;i++){
		for(int j=i;j>=0;j--){
			if(A[j]<A[j-1]){
				swap(A[j-1],A[j]);
			}
		}
		print();
	}
}

int main()
{
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	insertionsort(A);
	return 0;
}
