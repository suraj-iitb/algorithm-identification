#include <iostream>
using namespace std;

int n, key, j;

void print(int a[]) {
  for(int i = 0; i < n; ++i)
    cout << (i!=0?" ":"") << a[i];
  cout << endl;
}

int main()
{   
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    print(a);

    for (int i=1; i<n; i++) {
        key = a[i];
        j = i - 1;
        while( j >= 0 and a[j] > key) {
            a[j+1] = a[j];
            j--;            
        }
        a[j+1] = key;
        print(a);
    }
    return 0;
}

