#include <bits/stdc++.h>
using namespace std;

void print(vector<int> const & a, int n )
{
    for(int i = 0 ; i < n ; i++)
    {
        cout << a.at(i) ;
        if(i != n - 1)
        {
            cout << " " ;
        }
    }
    cout << endl ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> data(n) ;
    for(int i = 0; i < n ; i++)
    {
        cin >> data.at(i) ;
    }

    int count = 0 ;
    for(int i = 0 ; i < n - 1 ; i++)
    {
        //cout << i << endl ;
        if(data.at(i) > data.at(i + 1))
        {
            //cout << data.at(i) << " " << data.at(i + 1) << endl ;
            swap(data.at(i), data.at(i + 1)) ;
            count++ ;
            i = -1 ;
        }
    }

    print(data, n) ;
    cout << count << endl ;
}

