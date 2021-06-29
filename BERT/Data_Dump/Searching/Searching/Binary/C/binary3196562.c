#include <stdio.h>

/*keyがn個の配列A内にあるかを調べる*/
/*半分より大きいか調べて、もし大きければ半分より大きい中で半分より大きいか調べ...を繰り返してmidを検索値とするもの*/
int Binary_Search(int key , int A[] , int n) {
    /*leftはA[0] rightはA[n]のこと。すなわち配列番地のこと*/
    int left = 0;
    int right = n;
    int mid;
    
    while(left < right) {
        /*midの設定(配列の真ん中の番地)*/
        mid = (left + right) / 2;
        /*keyをmidに追いやるのが目標*/
        if(A[mid] == key)
            return 1;
        /*keyが中央値よりも小さかったら＝keyが左半分にあるなら*/
        /*leftそのまま rightをmidに　midを左半分の中間値(whileの一番上でやります)に(繰り返してkeyを追いやる)*/
        else if(key < A[mid])
            right = mid;
        /*keyが中央値よりも大きかったら＝keyが右半分にあるなら*/
        /*rightそのまま (keyはmid以上であることが他のifよりわかるので)leftをmid+1に　midを右半分の中間値(whileの一番上でやります)に(繰り返してkeyを追いやる)*/
        else
            left = mid + 1;
    }
    /*見つからない*/
    return -1;
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
        if(Binary_Search(T[k] , S , n) == 1)
            count++;
    }
    
    printf("%d\n" , count);
    
    return 0;
}

