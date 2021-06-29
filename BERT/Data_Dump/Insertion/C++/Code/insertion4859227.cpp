#include <iostream>
#include <vector>

void print(std::vector<int>& a) {
    for (int i=0; i<a.size(); ++i) {
        if (i>0) {
            std::cout << " ";
        }
        std::cout << a[i];
    }
    std::cout << std::endl;
}

void insertionSort(std::vector<int>& a) {
    for (int i=1; i<a.size(); ++i) {
        int v = a[i];
        int j = i-1;
        while (j>=0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        print(a);
    }
}

int main() {
    int n=0;
    std::cin >> n;
    std::vector<int> a;
    for (int i=0; i<n; ++i) {
        int v=0;
        std::cin >> v;
        a.push_back(v);
    }

    print(a);
    insertionSort(a);

    return 0;
}

