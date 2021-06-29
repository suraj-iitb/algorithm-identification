#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 100

int main()
{
    int a[MAX]={0};
    long long int n = 0;
    cin >> n;
    int v, j;

    for(long long int i = 0; i < n; i++) cin >> a[i];

    for(long long int t = 0; t < n; t++){
        cout << a[t];
        if(t < n - 1) cout << " ";
    }
    cout << endl;

    for(long long int i = 1; i < n; i++){
        v = a[i];
        j = i -1;
        while(j >= 0&& a[j] >v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        for(long long int t = 0; t < n; t++){
            cout << a[t];
            if(t < n - 1) cout << " ";
        }
        cout << endl;
    }

	return 0;
}

