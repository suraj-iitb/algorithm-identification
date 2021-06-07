#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 500

int get_int(void) {
  int num;
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return 0;
  sscanf(line, "%d", &num);
#else
#error
#endif
  return num;
}

// u k v_1 v_2
int fget_array(int *arr, int* size, int *id) {
#ifdef BUF_SIZE
    char line[BUF_SIZE];
    int i;
    char *tmp;
    if(!fgets(line, BUF_SIZE, stdin)) return -1;
    tmp = strtok(line, " ");
    int u = strtol(tmp, NULL, 10);
    tmp = strtok(NULL, " ");
    int k = strtol(tmp, NULL, 10);
    for(i = 0; i < k; i++) {
        tmp = strtok(NULL, " ");
        arr[i] = strtol(tmp, NULL, 10);
    }
    *id = u; *size = k;
#else
#error
#endif
    return 0;
}

#define VERTEX_MAX 100

int passed[VERTEX_MAX+1];
int finished[VERTEX_MAX+1];
int idx = 1;
int dfs(char table[][VERTEX_MAX+1], int vs, int start) {
#ifdef DEBUG
    printf("start: %d\n", start);
#endif
    int dst;
    passed[start] = idx++;
    for(dst = 1; dst <= vs; dst++) {
        if(!table[start][dst]) continue;
        if(passed[dst]) continue;
        dfs(table, vs, dst);
    }
    finished[start] = idx++;
    return 0;
}

int main(void) {
    int vs = get_int();
    static char table[VERTEX_MAX+1][VERTEX_MAX+1];
    int i, j;
    for(i = 0; i < vs; i++) {
        int arr[VERTEX_MAX];
        int size, id;
        fget_array(arr, &size, &id);
        for(j = 0; j < size; j++) {
            table[id][arr[j]] = 1;
        }
    }
    for(i = 1; i <= vs; i++) {
        if(!passed[i]) {
#ifdef DEBUG
            printf("%d DFS\n", i);
#endif
            dfs(table, vs, i);
        }
    }
    for(i = 1; i <= vs; i++) {
        printf("%d %d %d\n", i, passed[i], finished[i]);
    }
    return 0;
}
