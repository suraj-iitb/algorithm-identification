#include <stdio.h>
#include <stdlib.h>

void put_int(int n) {
    if(!n) {
        putchar_unlocked('0');
        return;
    }
    if(n < 0) n = -n, putchar_unlocked('-');
    char buf[11];
    int i = 0;
    while(n) buf[i++] = (char)(n % 10 + '0'), n /= 10;
    while(i--)putchar_unlocked(buf[i]);
}
int get_uint() {
    int n = 0;
    int c = getchar_unlocked();
    if(c < 48 || 57 < c) return c;
    while(47 < c && c < 58) n = 10 * n + (c & 0xf), c = getchar_unlocked();
    return n;
}

typedef struct QueueKey {
    int num;
} QueueKey;
typedef struct QueueDat {
    QueueKey key;
    struct QueueDat *next;
} QueueDat;
typedef struct Queue {
    size_t len;
    QueueDat *head;
    QueueDat *tail;
} Queue;
#define queue_init(q) ((q) ? ((q)->len = 0, (q)->head = (q)->tail = NULL) : 0)
#define queue_len(q) ((q) ? (q)->len : 0)
void queue_push(Queue *q, QueueKey x) {
    QueueDat *new_dat = malloc(sizeof(QueueDat));
    *new_dat = (QueueDat){x, NULL};
    if(q->len) {
        q->tail->next = new_dat;
        q->tail = new_dat;
    } else {
        q->head = q->tail = new_dat;
    }
    q->len++;
}
QueueKey queue_pop(Queue *q) {
    //assert(q->len);
    QueueDat *old_head = q->head;
    q->head = old_head->next;
    QueueKey key = old_head->key;
    free(old_head);
    q->len--;
    return key;
}
void bfs(int G[100][100], const int N, int d[100]) {
    Queue Q;
    queue_init(&Q);
    queue_push(&Q, (QueueKey){0});
    int u;
    while(queue_len(&Q)) {
        u = queue_pop(&Q).num;
        for(int i = 0; i < N; ++i) {
            if(!G[u][i] || d[i] != 1 << 28) continue;
            d[i] = d[u] + 1;
            queue_push(&Q, (QueueKey){i});
        }
    }
}
int main(int argc, char **argv) {
    int n = get_uint();
    int G[100][100] = {};
    for(int i = 0; i < n; ++i) {
        int u = get_uint() - 1;
        int k = get_uint();
        for(int j = 0; j < k; ++j) G[u][get_uint() - 1] = 1;
    }
    int d[100] = {0};
    for(int i = 1; i < 100; ++i) d[i] = 1 << 28;
    bfs(G, n, d);
    for(int i = 0; i < n; ++i) {
        put_int(i + 1);
        putchar_unlocked(' ');
        put_int(d[i] == 1 << 28 ? -1 : d[i]);
        putchar_unlocked('\n');
    }
    return 0;
}

