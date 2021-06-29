#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n,0);
    for(auto&& x: v){
        cin >> x;
    }
    for(int i=0; i<n; ++i){
        int x = v[i];
        int j=i-1;
        while( j>=0 and v[j]>x ){
            v[j+1]=v[j];
            --j;
        }
        v[j+1] = x;

        for(int i=0; i<n; ++i){
            if ( i>0 )
                cout << ' ';
            cout << v[i];
        }
        cout << endl;
    }

    return 0;
}
