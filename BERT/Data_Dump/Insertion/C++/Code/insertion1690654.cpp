#include<iostream>

using namespace std;

void show(int arr[], int n){
	for(int i=0; i<n; i++)
		if(i<n-1)
			cout<<arr[i]<<' '<<flush;
		else
			cout<<arr[i]<<flush;
	cout<<endl;
}


void swap(int& a, int& b){
	int t=a;
	a=b;
	b=t;
}


int insertsort(int[], int);

int main()
{
	int n;
	cin>>n;
	int arr[100];

	for(int i=0; i<n; i++)
		cin>>arr[i];
	show(arr, n);

	insertsort(arr, n);

	


}

int insertsort(int arr[], int n)
{

	int counter=0;
	int compindex;
	int comp;
	int j;
	for( int i=1; i < n; i++ ){
		
		compindex=i;
		comp=arr[compindex];
		j=1;
		for( ; compindex-j > -1; j++ ) {

			if(comp < arr[compindex-j])
				arr[compindex - j + 1] = arr[compindex - j];
			else
				break;
			
			counter++;
		}
		arr[compindex - j + 1] = comp;
	
		show(arr, n);


	}

	return counter;


	
}
