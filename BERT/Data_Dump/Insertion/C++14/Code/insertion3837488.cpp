// insertion sort

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

void insertionSort(vector<int> &v, int & N)
{
    display(v);
    rep2(i, 1, N)
    {
        int temp = v.at(i);
        int j = i - 1;
        while(j >= 0 && v.at(j) > temp)
        {
            v.at(j+1) = v.at(j);
            --j;
        }
        v.at(j+1) = temp;
        display(v);
    } 
}

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i, N) cin >> v.at(i);
    // int N = 6;
    // vector<int> v{5,2,4,6,1,3};
    insertionSort(v, N);

    return 0;
}
