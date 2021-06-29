#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &vec);
void print_vector(vector<int> vec);

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];

    print_vector(vec);
    insertion_sort(vec);
}

void insertion_sort(vector<int> &vec)
{
    for (int i = 1; i < vec.size(); ++i) {
        int tmp = vec[i];

        int j = i - 1;
        while (j >= 0 && vec[j] > tmp) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = tmp;

        print_vector(vec);
    }
}

void print_vector(vector<int> vec)
{
    cout << vec[0];
    for (int i = 1; i < vec.size(); ++i)
        cout << ' ' << vec[i];
    cout << '\n';
}

