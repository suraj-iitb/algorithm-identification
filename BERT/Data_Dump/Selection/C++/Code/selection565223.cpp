#include<iostream>
using namespace std;
#define MAX 100
void SelectionSort(int x[],int n);

int main(){
	int i,N;
	int x[MAX] = {0} ;
	
	cin >> N ;

	for(i=0;i<N;i++){
		cin >> x[i] ;
	}

	SelectionSort(x,N);
	return 0;

}

void SelectionSort(int x[],int n){
	int i,j,tmp,count=0,mini;

	for(i=0;i<n;i++){
		mini = i ;
		for(j=i;j<n;j++){
			if(x[j] < x[mini]){
				if(mini == i) count++;
				mini = j ;
			}

		}

		tmp = x[i] ;
		x[i] = x[mini] ;
		x[mini] = tmp ;
	}

	for(i=0;i<n;i++){

	if(i<(n-1))cout << x[i] << ' ' ;
	if(i == (n-1))cout << x[i] << endl ;

	}
	
	cout << count << endl ;
}
