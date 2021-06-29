#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dump(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != (v.size() - 1))
        {
            cout << ' ';
        }
    }
    cout << endl;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> v;
    while (n-- > 0)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    dump(v);
    for (int i = 1; i < v.size(); i++)
    {
        int x = v[i];
        int j = i - 1;
        for (; j >= 0 && v[j] > x; j--) {
            swap(v[j+1], v[j]);
        }
        dump(v);
    }

    return 0;
}
