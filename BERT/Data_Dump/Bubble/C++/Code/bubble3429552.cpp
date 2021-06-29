#include <iostream>

using namespace std;

void print_data(int data[], int N) {
    cout << data[0];
    for (int i = 1; i < N; i++) cout << " " << data[i];
    cout << endl;
}

int bubble_sort(int data[], int N) {
    int swap_count = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = N - 1; i > 0; i--) {
            if (data[i] < data[i-1]) {
                swap(data[i], data[i-1]);
                swap_count++;
                flag = true;
            }
        }
    }
    return swap_count;
}

int main(void) {
    int N;
    cin >> N;

    int data[N];
    for (int i = 0; i < N; i++) cin >> data[i];
    int swap_count = bubble_sort(data, N);
    print_data(data, N);
    cout << swap_count << endl;
    
    return 0;
}

