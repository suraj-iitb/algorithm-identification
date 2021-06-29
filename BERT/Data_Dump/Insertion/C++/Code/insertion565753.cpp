#include<iostream>
using namespace std ;
#define MAX 100

int main()
{
	int N,i,j,k,key;
	int A[MAX] ;

	cin >> N;
	for(i=0;i<N;i++){
		cin >> A[i] ;
	}

	for(j=1;j<N+1;j++){
		for(k=0;k<N+1;k++){
			if(k <(N-1)) cout << A[k] << ' ' ;
			if(k==(N-1)) cout << A[k] <<endl ;
		}
		key = A[j];
		i = j-1 ;

		while((i>(-1)) && (A[i]>key))
		{
			A[i+1] = A[i] ;
			i--;
		}

		A[i+1] = key ;
	}

	return 0;
}
