#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define N_MIN       (1)
#define N_MAX       (100)
#define A_MIN       (0)
#define A_MAX       (1000)

typedef enum
{
    ERROR  =-1,
    SUCCESS= 0
} ResultType;

static ResultType checkRangeOfNum(int, int, int);
static void insertionSort(int *, int);
static void printArray(int *, int);

int main(void)
{
    int A[N_MAX], N, i;
    ResultType eResult;

    /* input line 1 */
    scanf("%d",&N);
    eResult = checkRangeOfNum(N, N_MIN, N_MAX);
    if(eResult < SUCCESS)
    {
        printf("Err: %d is out of range.", N);
        return eResult;
    }

    /* input line 2 */
    for(i=0; i<N; i++)
    {
        scanf("%d",&A[i]);
        eResult = checkRangeOfNum(A[i], A_MIN, A_MAX);
        if(eResult < SUCCESS)
        {
            printf("Err: %d is out of range.", A[i]);
            return eResult;
        }
    }

    /* exec insertionSort */
    insertionSort(A, N);

    return SUCCESS;
}

static ResultType checkRangeOfNum(int n, int nMin, int nMax)
{
    if((n < nMin) || (nMax < n))
    {
        return ERROR;
    }
    return SUCCESS;
}

static void insertionSort(int A[], int N)
{
    int  i, j, v;

    printArray(A, N);

    for(i=1; i<N; i++)
    {
        v = A[i];
        j = i - 1;
        while((j>=0) && (A[j] > v))
        {
            A[j+1] = A[j];
            j--;

        }
        A[j+1] = v;
        printArray(A, N);
    }
}

static void printArray(int A[], int N)
{
    int i;

    for(i=0; i<N-1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[N-1]);
}
