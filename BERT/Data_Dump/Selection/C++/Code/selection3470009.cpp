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

int selectionSort(std::vector<int>& numList) {
    using std::swap;

    int swapCount = 0;

    for (size_t i=0; i < numList.size(); ++i) {
        size_t minj = i;

        for (size_t j = i; j < numList.size(); ++j) {
            if (numList[j] < numList[minj]) {
                minj = j;
            }
        }

        if (i != minj) {
            swap(numList[i], numList[minj]);
            ++swapCount;
        }
    }

    return swapCount;
}

int main() {
    std::vector<int> numList;
    readInput(numList);

    int swapCount = selectionSort(numList);

    for (size_t i = 0; i < numList.size()-1; ++i) {
        printf("%d ", numList[i]);
    }
    printf("%d\n%d\n", numList.back(), swapCount);

    return 0;
}

