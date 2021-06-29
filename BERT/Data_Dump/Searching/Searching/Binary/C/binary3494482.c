#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* array, int array_size, int target) {
    int left = 0;
    int right = array_size - 1;
    int middle = (array_size - 1) / 2;

    while (left < right) {
        //printf("BEF %d %d %d\n", left, middle, right);
        if (array[middle] == target) {
            //printf("Found\n");
            return 1;
        } else if (array[middle] > target) {
            right = middle;
        } else {
            left = middle + 1;
        }
        middle = (left + right) / 2;
        //printf("AFT %d %d %d\n", left, middle, right);
    }
    if (left == right) {
        if (array[middle] == target) {
            //printf("Found\n");
            return 1;
        }
    }
    //printf("Not Found\n");
    return 0;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int* s = (int*) malloc(sizeof(int) * n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    int m;
    scanf("%d", &m);
    int* t = (int*) malloc(sizeof(int) * m);
    int count = 0;
    for (i = 0; i < m; i++) {
        scanf("%d", &t[i]);
        count += binarySearch(s, n, t[i]);
    }
    printf("%d\n", count);

}

