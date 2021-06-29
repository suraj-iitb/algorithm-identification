
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void print(int *buff, int num) {
    for (int i = 0; i < num; ++i) {
        printf("%d", buff[i]);
        if (i < num - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}

int main(void) {
    int num;
    
    fscanf(stdin, "%d", &num);
    
    int *buff = malloc(sizeof(int) * num);
    
    for (int i = 0; i < num; ++i) {
        fscanf(stdin, "%d", &buff[i]);
    }
    
    for (int i = 0; i < num; ++i) {
        int t = buff[i];
        for (int j = i - 1; j >= 0; --j) {
            if (buff[j] > t) {
                buff[j + 1] = buff[j];
                buff[j] = t;
            } else {
                break;
            }
        }

        print(buff, num);
    }
    
    free(buff);
    
    return 0;
}

