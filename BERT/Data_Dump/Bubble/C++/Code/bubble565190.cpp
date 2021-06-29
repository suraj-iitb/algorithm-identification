#include<iostream>
using namespace std;
#define MAX 100
void BubbleSort(int x[],int n);

int main(){
	int i,N;
	int x[MAX] = {0} ;
	
	cin >> N ;

	for(i=0;i<N;i++){
		cin >> x[i] ;
	}

	BubbleSort(x,N);
	return 0;

}

void BubbleSort(int x[],int n){
	int i,j,tmp,count=0;

	for(i=1;i<n;i++){
		for(j=(n-1);j>(i-1);j--){
			if(x[j] < x[j-1]){
				tmp = x[j] ;
				x[j] = x[j-1] ;
				x[j-1] = tmp ;
				count++;
			}
		}
	}

	for(i=0;i<n;i++){

	if(i<(n-1))cout << x[i] << ' ' ;
	if(i == (n-1))cout << x[i] << endl ;

	}
	
	cout << count << endl ;
}
