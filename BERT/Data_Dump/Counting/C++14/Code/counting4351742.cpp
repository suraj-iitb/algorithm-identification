#include <iostream>
#include <vector>
#include <map>
#include <limits>
using namespace std;

void CountingSort(int* a, int* b, int n, int k)
{
    int c[k+1];
    for(int i=0; i<=k; i++) c[i] = 0;
    for(int j=0; j<n; j++) c[a[j]]++;
/*
    for(int i=1; i<=k; i++){
        //cout << i << ":" << c[i] << endl;
        c[i] = c[i] + c[i-1];
    }
*/  
    int index = 0;
    for(int i=0; i<=k; i++){
        //cout << "c[i] is " << c[i] << endl; 
        for(int j=0; j<c[i]; j++){
            //cout << "b[" << index << "] = " << i << endl;
            b[index] = i;
            index++;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    int max = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(max < a[i]) max = a[i];
    }
    int b[n];
    CountingSort(a, b, n, max);

    for(int i=0; i<n; i++){
        cout << b[i];
        if(i != n-1) cout << " ";
        else cout << endl;
    }
}
