#include <iostream>
using namespace std;

void trace(int a[],int N){            
	int i=0;
	for(i=0;i<N-1;i++)
	   cout<<a[i]<<" ";	
	   cout<<a[i]<<endl;
}

void insertionsort(int a[],int N){
	trace(a,N);
	int i,j,v;
	for(i=1;i<N;i++){
		v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
		}
	    a[j+1]=v;
		trace(a,N);
	}
	
}

int main()
{
	int N;
	cin>>N;
    int a[110];
    for(int i=0;i<N;i++)
    cin>>a[i];
    insertionsort(a,N);  
	return 0;
}
