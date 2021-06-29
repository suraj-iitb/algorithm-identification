#include <bits/stdc++.h>
#include <math.h>  /* M_PI */

using namespace std;
 
void insertionSort(int a[], int n) {
    for(int i=1; i<n;i++) {
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = v;
        
        cout << a[0];
        for(int i = 1; i < n; i++) {
            cout << " " << a[i];
        }
        cout << endl;
    }

}
int main() {
    int n;
    cin >> n;
    
    int x[n];
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    
    cout << x[0];
    for(int i = 1; i < n; i++) {
        cout << " " << x[i];
    }
    cout << endl;
    
    insertionSort(x, n);
   
}
    

