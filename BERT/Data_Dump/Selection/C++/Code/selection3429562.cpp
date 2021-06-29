#include <iostream>

using namespace std;

void print_data(int data[], int N) {
    cout << data[0];
    for (int i = 1; i < N; i++) cout << " " << data[i];
    cout << endl;
}

int selection_sort(int data[], int N) {
    int swap_count = 0;

    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (data[j] < data[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(data[i], data[minj]);
            swap_count++;
        }
    }

    return swap_count;
}

int main(void) {
    int N;
    cin >> N;

    int data[N];
    for (int i = 0; i < N; i++) cin >> data[i];
    int swap_count = selection_sort(data, N);
    print_data(data, N);
    cout << swap_count << endl;
    
    return 0;
}

