#include <iostream>
#include <vector>

using namespace std;

void trace(vector<int> a, int n)
{
    for (int k=0; k<n; k++) {
        if (k>0)
            cout << " ";
        cout << a[k];
    }
    cout << endl;
}

vector<int> insertion_sort(vector<int> a, int n)
{
    for (int i=0; i<n; i++) {
        int v = a[i];
        int j = i - 1;
        while (j>=0 && a[j] > v) {
            a[j+1] = a[j];
                j--;
        }
        a[j+1] = v;
        trace(a, n);
    }

    return a;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a;
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    insertion_sort(a, n);

    return 0;
}
