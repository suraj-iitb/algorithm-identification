#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int bubble_sort(vector<int> &vec, int size);

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];

    int swap_count = bubble_sort(vec, n);
    cout << vec[0];
    for (int i = 1; i < n; ++i)
        cout << ' ' << vec[i];
    cout << '\n' << swap_count << '\n';
}

int bubble_sort(vector<int> &vec, int size)
{
    int swap_count = 0;

    for (int i = 0; i < size; ++i) {
        bool flag = false;
        for (int j = size - 1; j > i; --j) {
            if (vec[j] < vec[j - 1]) {
                swap(vec[j], vec[j - 1]);
                ++swap_count;
                flag = true;
            }
        }

        if (!flag)
            break;
    }

    return swap_count;
}

