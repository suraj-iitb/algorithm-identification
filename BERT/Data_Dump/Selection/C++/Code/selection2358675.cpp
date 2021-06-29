#include<iostream>
using namespace std;

const int MAX=101;
int A[MAX];

int N;
int selection(int A[]){
	int minv,count=0;
	for(int i=0;i<N-1;i++){
		minv=i;
		for(int j=i+1;j<N;j++)
		{
			if(A[minv]>A[j])
                  minv=j;
		}
		if(i!=minv){
		swap(A[i],A[minv]);
		count++;
		}
	}
	cout<<A[0];
	for(int i=1;i<N;i++)
		  cout<<" "<<A[i]; 
    cout<<endl;			
	return count;
}

int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>A[i];
	cout<<selection(A)<<endl;
	return 0;
}
