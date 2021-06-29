#include<iostream>
#include<vector>
using namespace std;

void print_array(vector<int> a) {
    size_t array_size = a.size();
    for (int i = 0; i < array_size; i++) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << endl;
}

void insertionSort(vector<int>& a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        print_array(a);
    }
}

int main() {
    int n,num;

    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);
    }
  
    print_array(a);
    insertionSort(a, n);

    return 0;
}
