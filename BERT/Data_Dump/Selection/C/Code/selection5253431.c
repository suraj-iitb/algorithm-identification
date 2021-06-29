#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>

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

void shift(char *str, uint64_t length, uint64_t shift)
{
    char head[200];
    char tail[200];

    strncpy(head, str, shift); // ab

    strncpy(tail, str + shift, length - shift); // cde

    strncpy(str, tail, length - shift);
    strncpy(str + length - shift, head, shift);
}

void print(char *str, uint64_t a, uint64_t b)
{
    for (size_t i = a; i < b + 1; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void replace(char *str, uint64_t a, uint64_t b, char *p)
{
    strncpy(str + a, p, b - a + 1);
}

void reverse(char *str, uint64_t a, uint64_t b)
{
    for (size_t i = 0; i < (b - a) / 2 + 1; i++)
    {
        char ch = str[a + i];
        str[a + i] = str[b - i];
        str[b - i] = ch;
    }
}

void E(uint64_t *ary)
{
    uint64_t tmp = ary[1];
    ary[1] = ary[4];
    ary[4] = ary[6];
    ary[6] = ary[3];
    ary[3] = tmp;
}

void N(uint64_t *ary)
{
    uint64_t tmp = ary[1];
    ary[1] = ary[2];
    ary[2] = ary[6];
    ary[6] = ary[5];
    ary[5] = tmp;
}

void S(uint64_t *ary)
{
    uint64_t tmp = ary[1];
    ary[1] = ary[5];
    ary[5] = ary[6];
    ary[6] = ary[2];
    ary[2] = tmp;
}

void W(uint64_t *ary)
{
    uint64_t tmp = ary[1];
    ary[1] = ary[3];
    ary[3] = ary[6];
    ary[6] = ary[4];
    ary[4] = tmp;
}

uint64_t func(uint64_t *ary, uint64_t *entire, uint64_t n)
{
    uint64_t cnt = 0;
    for (size_t i = 1; i < n; i++)
    {
        // printf("cnt=%lu\n", cnt);
        // if (cnt == 6)
        // {
        //     // return 1;
        //     printf("%lu\n", cnt);
        // }
        cnt = 0;
        for (size_t j = 1; j < 7; j++)
        {
            // printf("ary[i]=%lu,entire[6 * i + j]=%lu\n", ary[j], entire[6 * i + j]);
            if (ary[j] != entire[6 * i + j])
            {
                // return 0;
                // printf("no\n");
            }
            else if (ary[j] == entire[6 * i + j])
            {
                cnt += 1;
                // printf("yes cnt=%lu\n", cnt);
                if (cnt == 6)
                {
                    return 1;
                }
            }
        }
        // printf("\n");
    }
    // printf("\n");
    return 0;
}

uint64_t find_insert_pos(uint64_t *ary, uint64_t j)
{
    // 挿入位置を返す関数

    uint64_t v = ary[j];

    uint64_t insert_pos = j;

    for (size_t i = 0; i < j; i++)
    {
        if (ary[i] > v)
        {
            insert_pos = i;
            return insert_pos;
        }
    }
    return insert_pos;
}

void shift_and_insert(uint64_t *ary, uint64_t insert_pos, uint64_t j)
{
    uint64_t v = ary[j];

    for (size_t i = j; i > insert_pos; i--)
    {
        // printf("j=%lu,j-1=%lu\n", i, i - 1);
        ary[i] = ary[i - 1];
    }
    // print_uint64_array(ary, 6);
    ary[insert_pos] = v;
}

uint64_t isPrime(uint64_t n)
{
    if (n == 1)
    {
        return 0;
    }
    for (size_t i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    uint64_t n = next_uint64();
    uint64_t ary[110] = {0};

    for (size_t i = 0; i < n; i++)
    {
        uint64_t nn = next_uint64();
        ary[i] = nn;
    }

    // print_uint64_array(ary, n);

    uint64_t cnt = 0;

    uint64_t m = 0; // 未ソートの先頭

    while (1)
    {
        if (m == n)
        {
            break;
        }
        uint64_t min = 2147483647;

        uint64_t min_pos = 0; // 最小値の位置

        for (size_t i = m; i < n; i++)
        {
            // printf("%lu\n", i);
            if (min > ary[i])
            {
                min = ary[i];
                min_pos = i;

                // cnt += 1;
            }
        }
        // printf("ary[m]=%lu\n", ary[m]);
        // printf("ary[m]=%lu,ary[min_pos]=%lu\n", ary[m], ary[min_pos]);
        if (m != min_pos)
        {

            uint64_t tmp = ary[min_pos];
            ary[min_pos] = ary[m];
            ary[m] = tmp;

            cnt += 1;
        }

        m += 1;
        // print_uint64_array(ary, n);
    }
    print_uint64_array(ary, n);
    printf("%lu\n", cnt);
    return 0;
}

