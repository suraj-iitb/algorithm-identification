#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr.at(i);

    for (int i = 0; i < n; i++) {
        int j = i - 1;
        int v = arr.at(i);
        while (true){
            if (j < 0) break;
            if (v >= arr.at(j)) break;
            arr.at(j + 1) = arr.at(j);
            j--;
        }
        arr.at(j + 1) = v;

        for (int k = 0; k < n; k++) {
            std::cout << arr.at(k);
            if (k < n - 1) std::cout << " ";
            else std::cout << std::endl;
        }
    }

    return 0;
}
