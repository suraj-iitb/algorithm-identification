#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int selection_sort(vector<int> &vec, int size);

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];

    int swap_count = selection_sort(vec, n);
    cout << vec[0];
    for (int i = 1; i < n; ++i)
        cout << ' ' << vec[i];
    cout << '\n' << swap_count << '\n';
}

int selection_sort(vector<int> &vec, int size)
{
    int swap_count = 0;

    for (int i = 0; i < size; ++i) {
        int min_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (vec[j] < vec[min_index])
                min_index = j;
        }

        if (i != min_index) {
            swap(vec[i], vec[min_index]);
            ++swap_count;
        }
    }

    return swap_count;
}

