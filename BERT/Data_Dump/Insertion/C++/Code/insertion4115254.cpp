#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++) cin >> A[i];
  	int c = 0;
    
    for (int k=0;k<n-1;k++){
    	cout << A[k] << " ";
    }
    cout << A[n-1] << endl;
  
  	for (int i=1;i<n;i++){
    	for (int j=0;j<i;j++){
        	if (A[j] > A[i]){
            	c = A[j];
              	A[j] = A[i];
                A[i] = c;
            }
        }
    	for (int k=0;k<n-1;k++){
    		cout << A[k] << " ";
    	}
      	cout << A[n-1] << endl;
    }
    
}
