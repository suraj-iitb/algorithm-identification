#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n ; cin >> n ; int a[n + 5] ;
    for(int i = 0 ; i < n ; i++) cin >> a[i] ;
    for(int k = 0 ; k < n - 1 ; k++) cout << a[k] << " " ; cout << a[n - 1] << endl ;
    for(int i = 1 ; i < n ; i++)
    {
        int key = a[i] ;
        int j ;
        for(j = i - 1 ; j >= 0  && a[j] > key ; j--) a[j + 1] = a[j] ;
        a[j + 1] = key ;
        for(int k = 0 ; k < n - 1 ; k++) cout << a[k] << " " ; cout <<  a[n - 1] << endl ;
     }

}
