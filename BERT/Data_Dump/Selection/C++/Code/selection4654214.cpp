#include <iostream>
#include <vector>

int selectionSort(std::vector<int> &data, int dataLength);
int main(void)
{
    int dataLength = 0;         // データ数
    // データ数を入力
    std::cin >> dataLength;

    std::vector<int> data(dataLength);   // ソートデータ

    for (int i = 0; i < dataLength; i++) {
        std::cin >> data[i];
    }

    int swapCnt = selectionSort(data, dataLength);

    std::cout << data[0];
    for (int k = 1; k < dataLength; k++) {
        std::cout << " " << data[k];
    }
    std::cout << "\n";
    std::cout << swapCnt << "\n";

    return 0;
}

int selectionSort(std::vector<int> &data, int dataLength)
{
    int swapCnt = 0;
    
    for (int i = 0; i < dataLength - 1; i++) {
        int minj = i;
        for (int j = i + 1; j < dataLength; j++) {
            if (data[j] < data[minj]) {
                minj = j;
            }
        }

        if(minj != i){
            int temp = data[i];
            data[i] = data[minj];
            data[minj] = temp;
            swapCnt++;
        }
    }

    return swapCnt;
}
