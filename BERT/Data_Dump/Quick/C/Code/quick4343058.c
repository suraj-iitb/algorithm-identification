#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SWAP(type, a, b) do { type t = a; a = b; b = t; } while(0)

typedef struct {
    char suit;
    int number;
} Card;

int insertIdx(Card *array, int rear, int x);
void stableSort(Card *array, int n);
void copyCardArray(Card *des, Card *src, int n);
bool isEqualCardArray(Card *des, Card *src, int n);
bool isStable(Card *des, Card *src, int n);
int partition(Card *array, int left, int right);
void _quickSort(Card *array, int left, int right);
void quickSort(Card *array, int n);

int insertIdx(Card *array, int rear, int x) {
    int pl = 0;
    int pr = rear;

    while(pl <= pr) {
        int pc = (pl + pr) / 2;
        if(array[pc].number == x) {
            do {
                pc++;
            } while(pc <= rear && array[pc].number == x);
            
            return pc;
        } else if(array[pc].number < x) {
            pl = pc + 1;
        } else if(array[pc].number > x) {
            pr = pc - 1;
        } 
    }

    return pl;
}

void stableSort(Card *array, int n) {
    for(int i = 1; i < n; i++) {
        Card temp = array[i];
        int idx = insertIdx(array, i - 1, array[i].number);
        memmove(&array[idx + 1], &array[idx], (i - idx) * sizeof(Card));
        array[idx] = temp;
    }
}

void copyCardArray(Card *des, Card *src, int n) {
    for(int i = 0; i < n; i++) {
        des[i] = src[i];
    }
}

bool isEqualCardArray(Card *des, Card *src, int n) {
    for(int i = 0; i < n; i++) {
        if(des[i].suit != src[i].suit) {
            return false;
        } if(des[i].number != src[i].number) {
            return false;
        }
    }

    return true;
}

bool isStable(Card *des, Card *src, int n) {
    Card *copySrc = malloc(n * sizeof(Card));

    if(copySrc == NULL) {
        return false;
    }

    copyCardArray(copySrc, src, n);

    stableSort(copySrc, n);

    bool ret = isEqualCardArray(copySrc, des, n);

    free(copySrc);
    return ret;
}

int partition(Card *array, int left, int right) {
    int x = array[right].number;

    int bnd = left;
    for(int i = left; i < right; i++) {
        if(array[i].number <= x) {
            SWAP(Card, array[i], array[bnd]);
            bnd++;
        }
    }

    SWAP(Card, array[right], array[bnd]);
    return bnd;
}

void _quickSort(Card *array, int left, int right) {
    if(left < right) {
        int bnd = partition(array, left, right);
        _quickSort(array, left, bnd - 1);
        _quickSort(array, bnd + 1, right);
    }
}

void quickSort(Card *array, int n) {
    _quickSort(array, 0, n - 1);
}

int main(void) {
    int n;
    Card *array;
    char buf[32];

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);
    if((array = malloc(n * sizeof(Card))) == NULL) {
        return 1;
    }

    for(int i = 0; i < n; i++) {
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%c %d", &array[i].suit, &array[i].number);
    }

    Card *copy = malloc(n * sizeof(Card));
    if(copy == NULL) {
        return 1;
    }

    copyCardArray(copy, array, n);

    quickSort(copy, n);

    puts(isStable(copy, array, n) ? "Stable" : "Not stable");
    
    for(int i = 0; i < n; i++) {
        printf("%c %d\n", copy[i].suit, copy[i].number);
    }

    return 0;
}
