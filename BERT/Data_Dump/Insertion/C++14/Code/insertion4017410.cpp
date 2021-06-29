#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;

void insetrtionsort(int a[], int n){
    int j, v;
    for (int i = 0; i < n - 1; i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    for (int i = 1; i < n; i++){
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        for (int i = 0; i < n - 1; i++){
            cout << a[i] << " ";
        }
        cout << a[n-1] << endl;
    }
}

int main()
{   
    int n;
    cin >> n; 
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
  	insetrtionsort(a,n);
    return 0;
}

