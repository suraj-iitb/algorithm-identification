#include <cstdio>
#include <vector>

void readInput(std::vector<int>& numList) {
    int size = 0;
    scanf("%d", &size);

    numList.resize(size);

    for (size_t i = 0; i < numList.size(); ++i) {
        int num = 0;
        scanf("%d", &num);
        numList[i] = num;
    }
}

int bubbleSort(std::vector<int>& numList) {
    int swapCount = 0;
    bool next = true;

    while (next) {
        next = false;
        for (size_t i = numList.size() - 1; i >= 1; --i) {
            if (numList[i] < numList[i - 1]) {
                int tmp = numList[i];
                numList[i] = numList[i - 1];
                numList[i - 1] = tmp;
                next = true;
                ++swapCount;
            }
        }
    }

    return swapCount;
}

int main() {
    
    std::vector<int> numList;

    readInput(numList);
    int swapCount = bubbleSort(numList);

    for (size_t i = 0; i < numList.size() - 1; ++i) {
        printf("%d ", numList[i]);
    }
    printf("%d\n%d\n", numList.back(), swapCount);

}
