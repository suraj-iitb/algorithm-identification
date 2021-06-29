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

// returns swap count
int selectionSort(std::vector<int>& a) {
    int swapCount = 0;
    for (int i=0; i<a.size(); ++i)
    {
        int minj = i;
        for (int j=i; j<a.size(); ++j)
        {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        if (i != minj)
        {
            std::swap(a[i], a[minj]);
            swapCount++;
        }
    }
    return swapCount;
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

    int count = selectionSort(a);
    print(a);
    std::cout << count << std::endl;

    return 0;
}

