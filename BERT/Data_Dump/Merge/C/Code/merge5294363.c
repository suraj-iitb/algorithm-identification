#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <stdbool.h>

int next_int()
{
    int n;
    scanf("%d", &n);
    return n;
}

uint64_t next_uint64()
{
    uint64_t n;
    scanf("%lu", &n);
    return n;
}

int64_t next_int64()
{
    int64_t n;
    scanf("%ld", &n);
    return n;
}

uint64_t max_uint64(uint64_t *ary, size_t length)
{
    uint64_t max = 0;

    for (size_t i = 0; i < length; i++)
    {
        if (ary[i] > max)
        {
            max = ary[i];
        }
    }
    return max;
}

int64_t max_int64(int64_t *ary, size_t length)
{
    int64_t max = INT64_MIN;

    for (size_t i = 0; i < length; i++)
    {
        if (ary[i] > max)
        {
            max = ary[i];
        }
    }
    return max;
}

uint64_t min_uint64(uint64_t *ary, size_t length)
{
    uint64_t min = UINT64_MAX;

    for (size_t i = 0; i < length; i++)
    {
        if (ary[i] < min)
        {
            min = ary[i];
        }
    }
    return min;
}

int64_t min_int64(int64_t *ary, size_t length)
{
    int64_t min = INT64_MAX;

    for (size_t i = 0; i < length; i++)
    {
        if (ary[i] < min)
        {
            min = ary[i];
        }
    }
    return min;
}

uint64_t sum_uint64(uint64_t *ary, size_t length)
{
    uint64_t sum = 0;
    for (size_t i = 0; i < length; i++)
    {
        sum += ary[i];
    }
    return sum;
}

int64_t sum_int64(int64_t *ary, size_t length)
{
    int64_t sum = 0;
    for (size_t i = 0; i < length; i++)
    {
        sum += ary[i];
    }
    return sum;
}

void print_int_array(int *ary, size_t length)
{
    if (length == 0)
    {
        puts("[]");
        return;
    }
    else
    {
        printf("%d", ary[0]);

        for (size_t i = 1; i < length; i++)
        {
            printf(" %d", ary[i]);
        }
        printf("\n");
    }
}

void print_uint64_array(uint64_t *ary, size_t length)
{
    if (length == 0)
    {
        puts("[]");
        return;
    }
    else
    {
        printf("%ld", ary[0]);

        for (size_t i = 1; i < length; i++)
        {
            printf(" %ld", ary[i]);
        }
        printf("\n");
    }
}

void print_int64_array(int64_t *ary, size_t length)
{
    if (length == 0)
    {
        puts("[]");
        return;
    }
    else
    {
        printf("%ld", ary[0]);

        for (size_t i = 1; i < length; i++)
        {
            printf(" %ld", ary[i]);
        }
        printf("\n");
    }
}

int include3(int n)
{
    if (n == 3)
    {
        return 1;
    }
    while (1)
    {
        if (n == 0)
        {
            break;
        }
        if (n % 10 == 3)
        {
            return 1;
        }
        n /= 10;
    }
    return 0;
}

void reverse_uint64(uint64_t *ary, size_t length)
{
    for (size_t i = 0; i < (length / 2); i++)
    {
        uint64_t tmp = ary[i];
        ary[i] = ary[length - 1 - i];
        ary[length - 1 - i] = tmp;
    }
}

struct Stack
{
    int *ary;
    int top; // 最後の要素が格納されている場所
    int length;
};

void stack_initialize(struct Stack *stack, int *buf_stack, int buf_stack_length)
{
    stack->top = 0;
    stack->ary = buf_stack;
    stack->length = buf_stack_length;
}

int stack_isEmpty(struct Stack *stack)
{
    return stack->top == 0;
}

int stack_isFull(struct Stack *stack)
{
    return stack->top == stack->length;
}

int stack_push(struct Stack *stack, int x)
{
    if (stack_isFull(stack))
    {
        return -1;
    }
    stack->ary[stack->top + 1] = x;
    stack->top += 1;
    return 0;
}

int stack_pop(struct Stack *stack, int *pop_value)
{
    if (stack_isEmpty(stack))
    {
        return -1;
    }
    *pop_value = stack->ary[stack->top];
    stack->top -= 1;
    return *pop_value;
}

void stack_print(struct Stack *stack)
{
    for (int i = 0; i < stack->top + 1; i++)
    {
        if (i == 0)
        {
            printf("%d", stack->ary[i]);
        }
        else
        {
            printf(" %d", stack->ary[i]);
        }
    }
    printf("\n");
}
struct RoundRobinScheduling
{
    char *name;
    int time;
};
struct Queue
{
    struct RoundRobinScheduling *ary;
    int head;
    int tail; // tail は新しい要素が追加される場所
    int length;
};

void queue_initialize(struct Queue *queue, struct RoundRobinScheduling *rrs, int rrs_length)
{
    queue->ary = rrs;

    queue->head = 0;
    queue->tail = 0;

    queue->length = rrs_length;
}

int queue_isEmpty(struct Queue *queue)
{
    return queue->head == queue->tail;
}

int queue_isFull(struct Queue *queue)
{
    return queue->head == ((queue->tail) + 1) % queue->length;
}

int queue_enqueue(struct Queue *queue, char *name, int time)
{
    if (queue_isFull(queue))
    {
        return -1;
    }
    queue->ary[queue->tail].name = name;
    queue->ary[queue->tail].time = time;

    queue->tail += 1;
    queue->tail %= queue->length;

    return 0;
}

int queue_dequeue(struct Queue *queue, struct RoundRobinScheduling *v)
{
    if (queue_isEmpty(queue))
    {
        return -1;
    }
    *v = queue->ary[queue->head];
    queue->head += 1;
    queue->head %= queue->length;

    return 0;
}

struct Node
{
    int key;
    struct Node *prev;
    struct Node *next;
};

struct DoublyLinkedList
{
    struct Node *head;
    struct Node *last;
};

void doublyLinkedList_init(struct DoublyLinkedList *dll)
{
    dll->head = NULL;
    dll->last = NULL;
}

void doublyLinkedList_insert(struct DoublyLinkedList *dll, struct Node *node, int x)
{
    // x をセットする
    // 連結リストの先頭にキー x を持つ要素を継ぎ足す

    node->key = x;

    if (dll->head == NULL)
    {
        assert(dll->last == NULL);

        node->prev = NULL;
        node->next = NULL;

        dll->head = node;
        dll->last = node;
    }
    else
    {
        dll->head->prev = node;
        node->next = dll->head;
        dll->head = node;
        dll->head->prev = NULL;
    }
}

void doublyLinkedList_delete_impl(struct DoublyLinkedList *dll, struct Node *node)
{
    if (node->prev == NULL && node->next == NULL)
    {
        dll->head = NULL;
        dll->last = NULL;
    }
    else if (node == dll->head)
    {
        node->next->prev = NULL;
        dll->head = node->next;
    }
    else if (node == dll->last)
    {
        node->prev->next = NULL;
        dll->last = node->prev;
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
}

struct Node *doublyLinkedList_delete(struct DoublyLinkedList *dll, int x)
{
    // キー x を持つ最初の要素を連結リストから削除する。
    // そのような要素が存在しない場合は何もしない。

    struct Node *node = dll->head;

    while (1)
    {
        if (node == NULL)
        {
            break;
        }
        if (node->key == x)
        {
            doublyLinkedList_delete_impl(dll, node);
            return node;
        }

        node = node->next;
    }
    return NULL;
}

struct Node *doublyLinkedList_deleteHead(struct DoublyLinkedList *dll)
{
    struct Node *node = dll->head;

    doublyLinkedList_delete_impl(dll, node);

    return node;
}

struct Node *doublyLinkedList_deleteLast(struct DoublyLinkedList *dll)
{
    struct Node *node = dll->last;

    doublyLinkedList_delete_impl(dll, node);

    return node;
}

void doublyLinkedList_print(struct DoublyLinkedList *dll)
{
    struct Node *node = dll->head;
    while (1)
    {
        if (node == NULL)
        {
            break;
        }
        if (node == dll->head)
        {
            printf("%d", node->key);
        }
        else
        {
            printf(" %d", node->key);
        }
        node = node->next;
    }
    printf("\n");
}

int linearSearch(int *ary, int ary_length, int key)
{
    int i = 0;
    ary[ary_length] = key;
    while (ary[i] != key)
    {
        i += 1;
    }
    if (i == ary_length)
    {
        return -1;
    }
    return i;
}

int binarySearch(int *ary, int ary_length, int key)
{
    int ok = ary_length;
    int ng = -1;
    while (abs(ok - ng) > 1)
    {
        int mid = (ok + ng) / 2;

        if (ary[mid] == key)
        {
            ok = mid;
            return ok;
        }
        else
        {
            if (ary[mid] <= key)
            {
                ng = mid;
            }
            else
            {
                ok = mid;
            }
        }
    }
    return -1;
}

struct List
{
    char *str;
    struct List *next;
};

uint64_t getChar(char ch)
{
    if (ch == 'A')
    {
        return 1;
    }
    else if (ch == 'C')
    {
        return 2;
    }
    else if (ch == 'G')
    {
        return 3;
    }
    else if (ch == 'T')
    {
        return 4;
    }
    else
    {
        return -1;
    }
}

uint64_t getKey(char str[])
{
    uint64_t sum = 0;
    uint64_t p = 1;
    uint64_t i;

    for (i = 0; i < strlen(str); i++)
    {
        sum += p * (getChar(str[i]));
        p *= 5;
    }

    return sum;
}

void insert(struct List **hashtable, uint64_t key, char *str)
{
    struct List *p = hashtable[key];

    if (p != NULL)
    {
        while (1)
        {
            if (strcmp(p->str, str) == 0)
            {
                return;
            }
            if (p->next == NULL)
            {
                struct List *list = (struct List *)malloc(sizeof(struct List));
                list->str = str;
                list->next = NULL;
                p->next = list;
                break;
            }
            p = p->next;
        }
    }
    else
    {
        struct List *list = (struct List *)malloc(sizeof(struct List));
        list->str = str;
        list->next = NULL;
        hashtable[key] = list;
    }
}

void list_free(struct List *list)
{
    struct List *p = list;

    if (p != NULL)
    {
        list_free(p->next);
        free(p);
    }

    if (p == NULL)
    {
        return;
    }
}

void hashtable_free(struct List **hashtable, uint64_t hashtable_size)
{
    for (size_t i = 0; i < hashtable_size; i++)
    {
        list_free(hashtable[i]);
    }

    free(hashtable);
}

int64_t my_max(int64_t x, int64_t y)
{
    if (x < y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

uint64_t cnt = 0;

void merge(uint64_t *ary, uint64_t left, uint64_t mid, uint64_t right)
{

    // printf("left=%lu,mid=%lu,right=%lu\n", left, mid, right);

    uint64_t l_length = (mid - left) + 1;
    uint64_t r_length = (right - mid) + 1;

    // printf("l_length=%lu,r_length=%lu\n", l_length, r_length);

    uint64_t *l = (uint64_t *)malloc(sizeof(uint64_t) * l_length);
    uint64_t *r = (uint64_t *)malloc(sizeof(uint64_t) * r_length);

    // uint64_t l[l_length];
    // uint64_t r[r_length];

    for (size_t i = 0; i < l_length - 1; i++)
    {
        // printf("ary[left]%lu\n", ary[left]);
        l[i] = ary[left + i];
    }
    for (size_t i = 0; i < r_length - 1; i++)
    {
        r[i] = ary[mid + i];
    }

    uint64_t max_value = 1000000000 + 10;

    l[l_length - 1] = max_value;
    r[r_length - 1] = max_value;

    // printf("l:");
    // print_uint64_array(l, l_length);

    // printf("r:");
    // print_uint64_array(r, r_length);

    uint64_t l_index = 0;
    uint64_t r_index = 0;

    for (size_t i = left; i < right; i++)
    {
        cnt += 1;

        if (l[l_index] == max_value)
        {
            ary[i] = r[r_index];
            r_index += 1;
            continue;
        }
        if (r[r_index] == max_value)
        {
            ary[i] = l[l_index];
            l_index += 1;
            continue;
        }
        if (l[l_index] < r[r_index])
        {
            ary[i] = l[l_index];
            l_index += 1;
        }
        else
        {
            ary[i] = r[r_index];
            r_index += 1;
        }
    }
    // printf("%lu\n", tmp);

    free(l);
    free(r);
}

void mergesort(uint64_t *ary, uint64_t ary_length, uint64_t left, uint64_t right)
{

    // rightは最大index+1

    // print_uint64_array(ary, ary_length);

    uint64_t mid = (left + right) / 2;

    // printf("left=%lu,mid=%lu,right=%lu\n", left, mid, right);

    if (left + 1 == right)
    {
        return;
    }

    mergesort(ary, ary_length, left, mid);
    mergesort(ary, ary_length, mid, right);
    merge(ary, left, mid, right);
    // printf("merge...");
    // print_uint64_array(ary, ary_length);
    // printf("%lu\n", tmp);
}

int main(void)
{
    uint64_t n = next_uint64();
    // uint64_t k = next_uint64();

    // printf("%lu %lu\n", n, k);

    uint64_t ary[1000000] = {0};
    // uint64_t buf_m[1000000] = {0};

    for (size_t i = 0; i < n; i++)
    {
        ary[i] = next_uint64();
    }
    // print_uint64_array(ary, n);

    // uint64_t cnt;
    mergesort(ary, n, 0, n);

    for (size_t i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printf("%lu", ary[i]);
        }
        else
        {
            printf(" %lu", ary[i]);
        }
    }
    printf("\n");

    printf("%lu\n", cnt);

    return 0;
}

