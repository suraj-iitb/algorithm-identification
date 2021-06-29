#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

void display(vector<int> const &v)
{
    rep(i, v.size())
    {
        if(i > 0) cout << " ";
        cout << v.at(i);
    }
    cout << endl;
}

int bubbleSort(vector<int> &v, int const & N)
{
    int sw = 0;
    for ( int i = 0; i < N-1; ++i)
    {
        for ( int j = N-1; j > i; --j)
        {
            if ( v.at(j) < v.at(j-1))
            {
                swap(v.at(j), v.at(j-1));
                ++sw;
                // display(v);
            }
        }
    }
    display(v);
    return sw;
}

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i, N) cin >> v.at(i);
    int sw;

    sw = bubbleSort(v, N);
    cout << sw << endl;

    return 0;
}
