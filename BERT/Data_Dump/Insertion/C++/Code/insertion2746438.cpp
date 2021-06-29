#include<iostream>

using namespace std;
int main(){
	
	int A[100], i, j, size, pos, n=0;
	
	while( cin >> size){
		
	for(i=0;i<size;i++){
		
	cin >> A[i];
	
	}
	for(i=0;i<size-1;i++){
		
	cout << A[i]  << " ";
	
	}	
	
	cout << A[size-1] << "\n";
	for(i=1;i<=size-1;i++)
	{
		pos = A[i];
		j = i - 1;
		
	while( j >= 0 && A[j] > pos ){
        A[j+1] = A[j];
        j--;
 		}
 		        A[j+1] = pos;
 	for(int k=0;k<size-1;k++){
	cout << A[k] << " " ;

	}
	cout << A[size-1] << "\n";

	}
	
	}
	return 0;
	}
