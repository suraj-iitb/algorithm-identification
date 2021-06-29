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

int selectionSort(vector<int> &v, int const & N)
{
    int sw = 0;
    rep(i, N){
        int minj = i;
        rep2(j, i, N){
            if(v.at(j) < v.at(minj)) minj = j;
        }
        if(minj != i){
            swap(v.at(i), v.at(minj));
            ++sw;
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

    sw = selectionSort(v, N);
    cout << sw << endl;

    return 0;
}
