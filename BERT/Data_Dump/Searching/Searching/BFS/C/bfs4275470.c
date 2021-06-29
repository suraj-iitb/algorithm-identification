#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 400

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

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

static int start = 0;
static int end = 0;
int queue[VERTEX_MAX+1];

void enqueue(int v) {
    queue[end++] = v;
}

int dequeue(void) {
    return queue[start++];
}

int is_empty(void) {
    return start == end;
}

int main(void) {
    int vs = get_int();
    int i, j;
    int buf[VERTEX_MAX];
    static int map[VERTEX_MAX+1][VERTEX_MAX+1];
    for(i = 0; i < vs; i++) {
        int size, id;
        fget_array(buf, &size, &id);
        for(j = 0; j < size; j++) {
            // directed graph
            map[id][buf[j]] = 1;
        }
    }

    int dist[VERTEX_MAX+1];
    for(i = 1; i <= vs; i++) {
        dist[i] = -1;
    }

    int start = 1; int steps = 0;
    int nv;
    // we can merge dist variable, but simple is best choice.
    int checked[VERTEX_MAX+1] = {0};
    enqueue(start);
    checked[start] = 1; dist[start] = steps;
    while(!is_empty()) {
        int v = dequeue();
        steps++;
        for(nv = 1; nv <= vs; nv++) {
            if(map[v][nv] && !checked[nv]) {
                dist[nv] = dist[v] + 1;
                checked[nv] = 1;
                enqueue(nv);
            }
        }
    }

    for(i = 1; i <= vs; i++) {
        printf("%d %d\n", i, dist[i]);
    }
    return 0;
}
