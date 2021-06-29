#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

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

int main(void)
{
    int n = next_int();
    int *s = (int *)malloc(sizeof(int) * (n + 1));

    for (int i = 0; i < n; i++)
    {
        s[i] = next_int();
    }

    // print_int_array(s, n);

    int q = next_int();
    int *t = (int *)malloc(sizeof(int) * q);

    for (int i = 0; i < q; i++)
    {
        t[i] = next_int();
    }

    // print_int_array(t, q);

    int cnt = 0;

    for (int i = 0; i < q; i++)
    {
        if (linearSearch(s, n, t[i]) != -1)
        {
            cnt += 1;
        }
    }
    printf("%d\n", cnt);

    // tがsにある数
    free(s);
    free(t);
    return 0;
}

