#include <limits.h>
#include <iostream>
#include <vector>

int bubbleSort(std::vector<int> &data, int dataLength);
int main(void)
{
    int dataLength = 0;         // データ数
    // データ数を入力
    std::cin >> dataLength;

    std::vector<int> data(dataLength);   // ソートデータ

    for (int i = 0; i < dataLength; i++) {
        std::cin >> data[i];
    }

    int swapCnt = bubbleSort(data, dataLength);

    std::cout << data[0];
    for (int k = 1; k < dataLength; k++) {
        std::cout << " " << data[k];
    }
    std::cout << "\n";
    std::cout << swapCnt << "\n";

    return 0;
}

int bubbleSort(std::vector<int> &data, int dataLength)
{
    int swapCnt = 0;
    bool flag = true;

    
    for (int i = 0; i < dataLength - 1; i++) {
        for (int j = dataLength - 1; j > i; j--) {
            if (data[j] < data[j - 1]) {
                int temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
                swapCnt++;
            }
        }
    }

    return swapCnt;
}

