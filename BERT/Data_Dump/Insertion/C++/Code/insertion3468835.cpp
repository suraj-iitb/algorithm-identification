#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

int main() {

    int size = 0;
    scanf("%d", &size);

    std::vector<int> numList;
    numList.resize(size);
    std::string buf;
    for (size_t i=0; i < numList.size(); ++i) {
        int num = 0;
        scanf("%d", &num);
        numList[i] = num;
    }


    for (int k=0; k<numList.size()-1; ++k) {
        printf("%d ", numList[k]);
    }
    printf("%d", numList.back());

    for (int i=1; i < numList.size(); ++i) {
        printf("\n");

        int v = numList[i];
        int j = i - 1;
        while (j >= 0 && numList[j] > v) {
            numList[j+1] = numList[j];
            --j;
        }
        numList[j+1] = v;

        for (int k=0; k<numList.size()-1; ++k) {
            printf("%d ", numList[k]);
        }

        printf("%d", numList.back());

    }

    printf("\n");

    return 0;
}


