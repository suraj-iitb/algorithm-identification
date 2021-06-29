#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void out(int* a, int n)
{
    for(int i=0; i<n; i++){
        cout << a[i];
        if(i != n-1) cout << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        //cout << "---" << endl;
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                //cout << "Swap " << a[j] << ":" << a[j+1] << endl;
                int tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
                cnt++;
                //out(a, n);
            }
        }
    }
    
    out(a, n);
    cout << cnt << endl;
}
