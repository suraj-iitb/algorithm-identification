#include <bits/stdc++.h>
using namespace std;

void myquicksort(vector<tuple<int, int, char>> &, int, int);

void myswap(tuple<int, int, char> &, tuple<int, int, char> &);

int mypartition(vector<tuple<int, int, char>> &, int, int);

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;

    int num_card = 0;
    char char_card = '0';

    vector<tuple<int, int, char>> a;
    for (int i = 0; i < n; i++)
    {
        cin >> char_card >> num_card;
        a.push_back(make_tuple(num_card, i, char_card));
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << get<2>(a[i]) << ", " << get<0>(a[i]) << ", " << get<1>(a[i]) << endl;
    // }

    myquicksort(a, 0, n - 1);

    bool unstable_flag = false;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            unstable_flag = true;
            break;
        }
    }

    cout << ((unstable_flag) ? "Not stable" : "Stable") << endl;
    for (int i = 0; i < n; i++)
    {
        cout << get<2>(a[i]) << " " << get<0>(a[i]) << endl;
    }

    return 0;
}

void myquicksort(vector<tuple<int, int, char>> &a, int p, int r)
{
    if (p < r)
    {
        int q = mypartition(a, p, r);
        myquicksort(a, p, q - 1);
        myquicksort(a, q + 1, r);
    }
}

void myswap(tuple<int, int, char> &a, tuple<int, int, char> &b)
{
    tuple<int, int, char> c = a;
    a = b;
    b = c;
}

int mypartition(vector<tuple<int, int, char>> &a, int p, int r)
{
    int i = p - 1;
    int j = p;

    while (j < r)
    {
        if (get<0>(a[j]) > get<0>(a[r]))
        {
            j++;
        }
        else
        {
            i++;
            myswap(a[i], a[j]);
            j++;
        }
    }

    myswap(a[i + 1], a[r]);

    return (i + 1);
}
