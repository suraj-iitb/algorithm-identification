#include<iostream>
using namespace std;

int N;
const int MAX=101;
unsigned int A[MAX];


void  bubblesort(unsigned int A[]){
	int count=0;
	int k=N;
	while(k>=1){
		int j=N-1;
		while(j>=N-k+1)
		{
			if(A[j]<A[j-1])
			{
				swap(A[j],A[j-1]);
				count++;
			}
			j--;
		}
		k--;
	}
	
	for(int k=0;k<N;k++)
	{
		if(k==0)cout<<A[k];
		else
			cout<<" "<<A[k];
	}
	cout<<endl;
	cout<<count<<endl;
}

int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>A[i];
	bubblesort(A);
	return 0;

}
