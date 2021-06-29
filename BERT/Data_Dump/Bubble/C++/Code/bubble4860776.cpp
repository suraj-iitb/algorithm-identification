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
int bubbleSort(std::vector<int>& a) {
    bool flag = true;
    int swapCount = 0;
    while (flag)
    {
        flag = false;
        for (int j=a.size()-1; j>=1; j--)
        {
            if (a[j] < a[j-1])
            {
                std::swap(a[j], a[j-1]);
                swapCount++;
                flag = true;
            }
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

    int count = bubbleSort(a);
    print(a);
    std::cout << count << std::endl;

    return 0;
}

