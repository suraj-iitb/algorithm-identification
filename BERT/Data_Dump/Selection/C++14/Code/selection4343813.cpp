#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

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
    //out(a, n);

    int cnt = 0;
    for(int i=0; i<n; i++){
        //cout << "---" << endl;
        int min = a[i];
        int min_index = i;
        for(int j=i+1; j<n; j++){
            if(a[min_index] > a[j]){
                min_index = j;
            }
        }
        if(min_index != i){
            int tmp = a[i];
            a[i] = a[min_index];
            a[min_index] = tmp;
            cnt++;
            //out(a, n);
        }
    }
    
    out(a, n);
    cout << cnt << endl;
}
