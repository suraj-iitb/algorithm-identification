#include <iostream>
using namespace std;

void SelectionSort(int a[], int n) {	
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {		
	    int iMin = i, s = i;; 		
	    for (int j = i + 1; j < n; j++) {		
	        if (a[j] < a[iMin]) {
	            iMin = j;	
	        }
	    }		
	    if (iMin != s) ans++;
    	int temp = a[i];		
        a[i] = a[iMin];		
	    a[iMin] = temp;		
	    
    }
    
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i == n - 1) cout << endl;
        else cout << ' ';
    }
    cout << ans << endl;
}		

int main(void){
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SelectionSort(a, n);
}

