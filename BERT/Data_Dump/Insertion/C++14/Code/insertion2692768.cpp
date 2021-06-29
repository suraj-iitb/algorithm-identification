#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(const vector<int>& array)
{
    for (int i = 0; i < array.size(); i++){
        if (i >= 1){
            cout << " ";
        }

        cout << array[i];
    }
    cout << endl;
}

vector<int> insertion_sort(const vector<int>& array)
{
    // 配列のコピー
    vector<int> a = vector<int>(array.size());
    copy(array.begin(), array.end(), a.begin());

    // 配列を表示
    print_vector(a);

    int n = a.size();
    for (int i = 1; i < n; i++){
        int buf = a[i];

        int j;
        for (j = i - 1; j >= 0 && a[j] > buf; j--) a[j + 1] = a[j];
        a[j + 1] = buf;

        // 配列を表示
        print_vector(a);
    }

    return a;
}

int main()
{
    int n;
    vector<int> a;

    cin >> n;
    a = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    insertion_sort(a);

    return 0;
}

