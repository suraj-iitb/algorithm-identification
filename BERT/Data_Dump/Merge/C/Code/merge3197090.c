#include <stdio.h>
#define Num 500050

int S[Num];
int Left[Num / 2] , Right[Num / 2];
int count = 0;

/*統合*/
void Merge(int S[] , int left , int mid ,int right){
    int i , j , k;
    
    int n1 = mid - left;
    int n2 = right - mid;
    
    
    for(i = 0 ; i < n1 ; i++)
        Left[i]  = S[left + i];
    for(j = 0 ; j < n2 ; j++)
        Right[j] = S[mid + j];
    
    /*番兵*/
    Left[n1]  = 2000000000;
    Right[n2] = 2000000000;

    i = 0;
    j = 0;
    k = 0;
    for(k = left ; k < right ; k++) {
        count++;
        if(Left[i] <= Right[j]) {
            S[k] = Left[i];
            i++;
        }
        else {
            S[k] = Right[j];
            j++;
        }
    }
}


void Merge_Sort(int S[] , int left , int right) {
    
    if(left + 1 < right) {
        int mid = (left + right) / 2;
        Merge_Sort(S , left , mid);
        Merge_Sort(S , mid , right);
        Merge(S , left , mid , right);
    }
}

int main(void)
{
    int n;
    int i , j;
    
    scanf("%d" , &n);
    
    for(i = 0 ; i < n ; i++)
        scanf("%d" , &S[i]);
    
    Merge_Sort(S , 0 , n);
    
    for(j = 0 ; j < n - 1; j++)
        printf("%d " , S[j]);
    printf("%d" , S[j]);
    printf("\n%d\n" , count);
    
    return 0;
}

