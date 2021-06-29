#include <bits/stdc++.h>


int main()
{

    int N, mini, cnt = 0;
    std::scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) std::scanf("%d", &arr[i]);

    for (int i = 0; i < N; i++) {
        mini = i;
        for (int j = i; j < N; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }

        }
        if (arr[i] != arr[mini]) {
            cnt++;
            std::swap(arr[i], arr[mini]);
        }
    }

    for (int i = 0; i < N; i++) {
        if (i) std::printf(" ");
        std::printf("%d", arr[i]);
    }
    std::printf("\n");
    std::printf("%d\n", cnt);

    return 0;
}

