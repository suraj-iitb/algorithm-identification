/* 
 * File:   main.c
 * Author: s1252007
 *
 * Created on June 26, 2018, 11:17 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int linearSearch(int *S, int n, int *T, int q);

int main(int argc, char** argv) {
    int n, q;
    int *S, *T;
    scanf("%d", &n);
    S = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    T = (int *)malloc(sizeof(int) * q);
    for (int j = 0; j < q; j++)
    {
        scanf("%d", &T[j]);
    }
    
    printf("%d\n", linearSearch(S, n, T, q));
    return (EXIT_SUCCESS);
}

int linearSearch(int *S, int n, int *T, int q)
{
    int counter = 0;
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (S[j] == T[i]) 
            {
                counter++;
                break;
            }
        }
    }
    return counter;
}


