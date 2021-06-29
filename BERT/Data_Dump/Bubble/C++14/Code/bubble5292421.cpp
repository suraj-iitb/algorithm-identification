#include <bits/stdc++.h>
using namespace std;
int main()
{
     int n ; cin >> n ; int a[n + 4] ;
     for(int i = 0 ; i < n ; i++) cin >> a[i] ;
     int cnt = 0 , flag = 1 ;
     for(int i = 0 ; flag ; i++)
     {
         flag = 0 ;
         for(int j = n - 1 ; j >= i + 1 ; j--)
         {
             if(a[j] < a[j - 1]){
                swap(a[j] , a[j - 1]) ;
                flag = 1 ;
                cnt++ ;
             }
         }
     }
     for(int i = 0 ; i < n - 1 ; i++) cout  << a[i] << " " ; cout << a[n - 1] << endl ;
     cout << cnt << endl ;

}





