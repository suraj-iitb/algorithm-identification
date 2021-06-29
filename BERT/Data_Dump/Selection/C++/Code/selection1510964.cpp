#include <iostream>
using namespace std;

void print_elements(int length, int elements[]) {
    cout << elements[0];
    for (int i = 1; i < length; i++)
        cout << " " << elements[i];
    cout << endl;
}

int selection_sort(int N, int elements[]) {
    int n_swapped = 0;
    for (int i = 0; i < N; i++) {
        int min_i = i;
        for (int i_unsorted = i; i_unsorted < N; i_unsorted++) {
            if (elements[i_unsorted] < elements[min_i]) {
                min_i = i_unsorted;
            }
        }
        if (i < min_i) {
            std::swap(elements[i], elements[min_i]);
            n_swapped++;
        }
    }
    return n_swapped;
}

/* ALDS1_2_B: Selection Sort */
int main() {
    int N;
    cin >> N;

    int elements[N];
    for (int i = 0; i < N; i++)
        cin >> elements[i];

    int n_swapped = selection_sort(N, elements);

    print_elements(N, elements);
    cout << n_swapped << endl;
    return 0;
}
