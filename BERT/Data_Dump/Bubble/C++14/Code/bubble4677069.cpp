#include <iostream>

int bubbleSort(int* a, int n) {
    int count = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = n - 1; j > 0; j--) {
            // 配列の最後の要素から値をチェックする。
            // もし、配列の要素の値がソートできたら、flagはfalseのまま。
            if (a[j] < a[j - 1]) {
                // ひとつ前の要素の値のほうが大きいので、
                // 値を入れ替える。
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
                flag = true;
                count++;
            }
        }
    }
    return (count);
}

int main() {
    int count;
    int n;      // 数列の長さ (0 < n < 101)
    std::cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    count = bubbleSort(a, n);

    for (int i = 0; i < n; i++) {
        std::cout << a[i];
        if (i == n - 1)
            std::cout << std::endl;
        else
            std::cout << ' ';
    }
    std::cout << count << std::endl;

    return (0);
}

