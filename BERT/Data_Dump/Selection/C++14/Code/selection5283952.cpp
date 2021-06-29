#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int n, mini = 0, ans = 0 ;
    cin >> n ;
    int arr[n+1] ;
    for(int i=0 ; i<n ; i++) cin >> arr[i] ;
    for(int i=0 ; i<=n-1 ; i++)
    {
        mini = i ;
        for(int j= i ; j<=n-1 ; j++)
        {
            if(arr[j]<arr[mini])
            {
                mini = j ;
            }
        }
        if(i!=mini)
        {
            swap(arr[i], arr[mini]) ;
            ans++;
        }
    }
    for(int i=0 ; i<n-1; i++) cout << arr[i] << " ";
    cout << arr[n-1] << endl << ans << endl ;
    return 0 ;
}

