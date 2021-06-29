#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <random>

void quickSort(int* inputArr, int* orderArr, int startPos, int endPos, int mode);
int randomPartition(int* inputArr, int* orderArr, int startPos, int endPos);
int medianPartition(int* inputArr, int* orderArr, int startPos, int endPos);
int lastPartition(int* inputArr, int* orderArr, int startPos, int endPos);
int partition(int* inputArr, int* orderArr, int startPos, int endPos, int refValPos);

struct Card {
    char letter;
    int value;
};

int main(int argc, char** argv) {
    int len;
    Card* cards;
    int *inputArr, *orderArr;
    std::string output;

    scanf("%d", &len);
    cards = (Card *) calloc(sizeof(Card), len + 1);
    inputArr = (int *) calloc(sizeof(int), len + 1);
    orderArr = (int *) calloc(sizeof(int), len + 1);

    for (int i = 0; i < len; i++) {
        char tmp[10];

        scanf("%s %d", tmp, &cards[i].value);

        cards[i].letter = tmp[0];
        *(inputArr + i) = cards[i].value;
        *(orderArr + i) = i;
    }

    quickSort(inputArr, orderArr, 0, len - 1, 0);

    bool stableSort = true;
    for (int i = 0; i < len; i++) {
        output += cards[orderArr[i]].letter;
        output += " ";
        output += std::to_string(cards[orderArr[i]].value);
        output += "\n";

        if (i > 0) {
            if (inputArr[i] == inputArr[i - 1]) {
                if (orderArr[i] < orderArr[i - 1]) {
                    stableSort = false;
                }
            }
        }
    }

    std::cout << (stableSort ? "Stable" : "Not stable") << "\n" << output;

    free(cards);
    free(inputArr);
    free(orderArr);
    return 0;
}

/* enter point of quick sort */
void quickSort(int* inputArr, int* orderArr, int startPos, int endPos, int mode) {
    if (startPos < endPos) {
        int refPos;

        switch (mode) {
            case 1:
                // randomly choose a reference value
                refPos = randomPartition(inputArr, orderArr, startPos, endPos);
                break;
            case 2:
                // choose the median of some randomly chosen elements as the reference value
                refPos = medianPartition(inputArr, orderArr, startPos, endPos);
                break;
            default:
                // use the last element as the reference value
                refPos = lastPartition(inputArr, orderArr, startPos, endPos);
                break;
        }

        quickSort(inputArr, orderArr, startPos, refPos - 1, mode);
        quickSort(inputArr, orderArr, refPos + 1, endPos, mode);
    }
}

/* 
 * Should only be called internally by quickSort 
 * randomly choose a reference value
 */
int randomPartition(int* inputArr, int* orderArr, int startPos, int endPos) {
    time_t t;

    t += 183723354;
    srand((unsigned) time(&t));

    return partition(inputArr, orderArr, startPos, endPos, startPos + ((int) rand()) % (endPos - startPos + 1));
}

/* 
 * Should only be called internally by quickSort 
 * choose the median of some randomly chosen elements as the reference value
 */
int medianPartition(int* inputArr, int* orderArr, int startPos, int endPos) {
    int refValPos;
    int num;
    int* candidatePos;
    int* candidates;
    time_t t;

    t += 183723354;
    srand((unsigned) time(&t));

    if ((endPos - startPos + 1) * 0.02 > 5) {
        num = 5;
    } else if ((endPos - startPos + 1) * 0.02 < 1) {
        num = 1;
    } else {
        num = (endPos - startPos + 1) * 0.02;
    }

    candidatePos = (int *) calloc(sizeof(int), num + 1);
    candidates = (int *) calloc(sizeof(int), num + 1);

    while (true) {
        int cnt = 0;
        int pos = startPos + rand() % (endPos - startPos + 1);
        bool isNew = true;

        for (int i = 0; i < cnt && i < num; i++) {
            if (pos == candidatePos[i]) {
                isNew = false;
            }
        }

        if (isNew) {
            candidatePos[cnt] = pos;
            candidates[cnt++] = inputArr[pos];
        } else {
            continue;
        }

        if (cnt == num) {
            break;
        }
    }

    quickSort(candidates, candidatePos, 0, num - 1, 0);

    refValPos = candidatePos[num / 2];

    free(candidatePos);
    free(candidates);
    return partition(inputArr, orderArr, startPos, endPos, refValPos);
}

/* 
 * Should only be called internally by quickSort 
 * use the last element as the reference value
 */
int lastPartition(int* inputArr, int* orderArr, int startPos, int endPos) {
    return partition(inputArr, orderArr, startPos, endPos, endPos);
}

/* Should only be called internally by quickSort */
int partition(int* inputArr, int* orderArr, int startPos, int endPos, int refValPos) {
    int partEnd1 = startPos - 1, partEnd2 = startPos;
    int refVal = *(inputArr + refValPos);

    if (endPos != refValPos) {
        int tmp = *(inputArr + endPos);
        *(inputArr + endPos) = *(inputArr + refValPos);
        *(inputArr + refValPos) = tmp;

        if (orderArr != nullptr) {
            tmp = *(orderArr + endPos);
            *(orderArr + endPos) = *(orderArr + refValPos);
            *(orderArr + refValPos) = tmp;
        }
    }

    while (partEnd2 < endPos) {
        if (*(inputArr + partEnd2) <= refVal) {
            if ((++partEnd1) != partEnd2) {
                int tmp = *(inputArr + partEnd2);
                *(inputArr + partEnd2) = *(inputArr + partEnd1);
                *(inputArr + partEnd1) = tmp;

                if (orderArr != nullptr) {
                    tmp = *(orderArr + partEnd2);
                    *(orderArr + partEnd2) = *(orderArr + partEnd1);
                    *(orderArr + partEnd1) = tmp;
                }
            }
        }

        partEnd2++;
    }

    if ((++partEnd1) != partEnd2) {
        int tmp = *(inputArr + endPos);
        *(inputArr + endPos) = *(inputArr + partEnd1);
        *(inputArr + partEnd1) = tmp;

        if (orderArr != nullptr) {
            tmp = *(orderArr + endPos);
            *(orderArr + endPos) = *(orderArr + partEnd1);
            *(orderArr + partEnd1) = tmp;
        }
    }

    return partEnd1;
}
