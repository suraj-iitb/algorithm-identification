//
//  選択ソート
//  (昇順に並び替え)
//
#include <iostream>

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
int selectionSort(int* a, int n) {
    int count = 0;
    // 配列の中から最小値を探し、
    // 前から順に格納する。
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        if (i < min) {
            swap(a[i], a[min]);
            count++;
        } // i == minであれば入れ替える必要がない
    }
    return (count);
}

int main() {
    int count = 0;

    int n;
    std::cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    count = selectionSort(a, n);

    for (int i = 0; i < n; i++) {
        std::cout << a[i];
        if (i == n - 1)
            std::cout << std::endl;
        else
            std::cout << " ";
    }
    std::cout << count << std::endl;

    delete a;
    return (0);
}
