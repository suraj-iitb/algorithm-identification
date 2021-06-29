#include <iostream>

using namespace std;

void print_data(int data[], int N) {
    cout << data[0];
    for (int i = 1; i < N; i++) cout << " " << data[i];
    cout << endl;
}

void insertion_sort(int data[], int N) {
    for (int i = 1; i < N; i++) {
        int v = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > v) {
            data[j+1] = data[j];
            j--; 
        }
        data[j+1] = v;
        print_data(data, N);
    }
}

int main(void) {
    int N;
    cin >> N;

    int data[N];
    for (int i = 0; i < N; i++) cin >> data[i];
    print_data(data, N);
    insertion_sort(data, N);
    
    return 0;
}

