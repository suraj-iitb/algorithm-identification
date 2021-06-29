#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void show_vector(vector<int> &v);

int main(int argc, char *argv[])
{
    int n, tmp;
    vector<int> a;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }

    int v, j;
    for (int i = 0; i < n; i++)
    {
        v = a[i];
        j = i - 1;
        while (j > -1 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;

        show_vector(a);
    }

    return 0;
}

void show_vector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
}
