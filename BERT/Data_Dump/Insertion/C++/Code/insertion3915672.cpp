//https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_A
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <map> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

int insertionSort(vector<int>& A,int n)
{
    for(int i = 1; i < n; ++i)
    {
        for(int k = 0; k < n; ++k)
        {
            cout << A.at(k);
            if(k != n-1)
            {
                cout << " ";
            }
        }

        cout << endl;
        int v = A.at(i);
        int j = i - 1;
        while(j >= 0 && A.at(j) > v)
        {
            A.at(j+1) = A.at(j);
            --j;
        }
        A.at(j+1) = v;
    }
    for(int k = 0; k < n; ++k)
    {
        cout << A.at(k);
        if(k != n-1)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}


int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    REP(i,n)
    {
        cin >> a.at(i);
    }

    insertionSort(a,n);

    return 0;    
}

