#include <stdio.h>

/*keyが配列S内にあるかを調べる*/
int Liner_Search(int key , int S[] , int n) {
    int i = 0;
    
    while(S[i] != key) {
        i++;
        /*Sの配列は0〜n-1まで*/
        /*最後まで行った＝一致する要素なし*/
        if(i == n - 1)
            return -1;
    }
    /*whileに入らなかった＝keyとSの要素がイコールだった*/
    return 1;
}

int main(void)
{
    int n , q;
    int i , j , k;
    int count = 0;
    
    scanf("%d" , &n);
    
    int S[n];
    for(i = 0 ; i < n ; i++)
        scanf("%d" , &S[i]);
    
    scanf("%d" , &q);
    
    int T[q];
    for(j = 0 ; j < q ; j++)
        scanf("%d" , &T[j]);
    
    for (k = 0 ; k < q ; k++) {
        if(Liner_Search(T[k] , S , n) == 1)
            count++;
    }
    
    printf("%d\n" , count);
    
    return 0;
}

