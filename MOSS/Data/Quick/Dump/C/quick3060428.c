/* 
 * File:   main.c
 * Author: s1252007
 *
 * Created on July 27, 2018, 11:53 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100000
#define INFTY 1000000001

typedef struct{
    char suit;
    int num;
}Poker;
/*
 * 
 */

Poker Left[MAX_SIZE/2 + 2], Right[MAX_SIZE/2 + 2];
int count = 0;

void merge(Poker A[], int left, int mid, int right);
void mergeSort(Poker A[], int left, int right);
void quickSort(Poker A[], int left, int right);
int partition(Poker A[], int left, int right);

int main(int argc, char** argv) {
    Poker A[MAX_SIZE], B[MAX_SIZE];
    int  n, temp, stability = 1;
    char C[11];
    
    scanf("%d", &n);
    for (int ix = 0; ix < n; ++ix) 
    {
        scanf("%s %d", C, &temp);
        A[ix].suit = C[0];
        B[ix].suit = C[0];
        A[ix].num = temp;
        B[ix].num = temp;
    }
    
    mergeSort(A, 0, n);
    quickSort(B, 0, n-1);
    
    for (int k = 0; k < n; ++k) if (A[k].suit != B[k].suit) stability = 0;
    
    if (stability == 1) printf("Stable\n");
    else { printf("Not stable\n"); }
    
    for (int kx = 0; kx < n; ++kx) printf("%c %d\n", B[kx].suit, B[kx].num);
    
    return (EXIT_SUCCESS);
}

void quickSort(Poker A[], int left, int right)
{
    if (left < right)
    {
        int mid = partition(A, left, right);
        quickSort(A, left, mid-1);
        quickSort(A, mid+1, right);
    }
}
int partition(Poker A[], int left, int right)
{
    Poker temp;
    int x = A[right].num;
    int i = left-1;
    for (int j = left; j < right; ++j)
    {
        if (A[j].num <= x)
        {
            i = i + 1;
//            strcmp(temp.suit , A[i].suit);
//            temp.num = A[i].num;
//            strcmp(A[i].suit, A[j].suit);
//            A[i].num = A[j].num;
//            strcmp(A[j].suit, temp.suit);
//            A[j].num = temp.num;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
//    strcmp(temp.suit , A[i+1].suit);
//    temp.num = A[i+1].num;
//    strcmp(A[i+1].suit, A[right].suit);
//    A[i+1].num = A[right].num;
//    strcmp(A[right].suit, temp.suit);
//    A[right].num = temp.num;
    temp = A[i+1];
    A[i+1] = A[right];
    A[right] = temp;
    
    return i+1;        
}

void merge(Poker A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; ++i) Left[i] = A[left + i];
    for (int j = 0; j < n2; ++j) Right[j] = A[mid + j];
    Left[n1].num = INFTY;
    Right[n2].num = INFTY;
    int i = 0, j = 0;
    for (int k = left; k < right; ++k)
    {
        if (Left[i].num <= Right[j].num)
        {
            A[k] = Left[i];
            i = i + 1;
        }
        else 
        { 
            A[k] = Right[j]; 
            j = j + 1;
        }
        count++;
    }
}

void mergeSort(Poker A[], int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}




