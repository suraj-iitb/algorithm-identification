#include<iostream>
void Insertionsort(int A[],int N)
{
	int v;
	int j;
	for(int i=0;i<=N-1;i++){
		v = A[i];
		j = i-1;
		while(j >= 0 && A[j] > v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		for(int k=0;k<=N-2;k++){
			std::cout << A[k] << " " ;
		}
		std::cout << A[N-1] << "\n";
	}
}
int main()
{
	int N;
	std::cin >> N;
	int A[N];
	for(int i=0;i<=N-1;i++){
		std::cin >> A[i];
	}
	Insertionsort(A,N);
	return 0;
}
