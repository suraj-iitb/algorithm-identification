#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	
  	int A[100];
  	int count = 0, n, mini;
  
  	cin >> n;
  	for(int i=0;i<n;i++) 
  	cin >> A[i];
  
  	for(int i=0;i<n;i++) {
  	
    mini = i;
    for(int j=i;j<n;j++)
    if(A[j]<A[mini])
    mini = j;
    
    
    if(mini != i) {
    	
      count++;
      swap(A[i], A[mini]);
      
    }
}

  	for(int i=0;i<n-1;i++)
    cout << A[i] << " ";
    
    cout << A[n-1] << "\n"
    	 << count << "\n";
  
	return 0;
}
