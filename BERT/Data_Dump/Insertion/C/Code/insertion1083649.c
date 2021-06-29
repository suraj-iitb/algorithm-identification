#include <stdio.h>

void print(int *array, int slong);

int main(void){
    /*宣言部*/
    int slong, key, sindex, x;    /*slong:数列の長さ key:検索キー sindex:検索用添字 x:ループ変数*/
    int sequence[100]={0};    /*sequence:数列*/
    
    /*入力部*/
    scanf("%d", &slong);    /*数列の長さを受け取る*/
    for(x=0; slong>x; x++){
        scanf("%d", &sequence[x]);    /*数列を受け取る*/
    }
    
    print(sequence, slong);    /*ソート前の状態を表示*/
    
    /*ソート・出力部*/
    for(x=1; slong>x; x++){    /*ソート対象は数列の前から2番目以降のため、数列の長さ-1回ループする*/
        key = sequence[x];    /*数列の前から2番目より後ろが検索キーになる*/
        sindex = x-1;    /*検索キーの一つ前の添字をを検索用添字とする*/
        
            /*検索用添字が前に行ききる（-1）か、検索キー以下である数列の要素に当たるまでループ*/
        while(sindex >= 0 && sequence[sindex] > key){
            sequence[sindex+1] = sequence[sindex];    /*検索対象は検索キーを超える大きさの要素なので数列の一つ後ろにどいてもらう*/
            sindex--;    /*検索用添字を前にずらす*/
        }
        
        sequence[sindex+1] = key;    /*検索用添字は、数列の最初よりひとつ前（-1）or検索キー以下である数列の要素が持つ添字
                                        となってるはずなのでその箇所の後ろに検索キーを挿入する*/
        
        print(sequence, slong);    /*ソート状況表示*/

    }
    
    return 0;
}

void print(int *array, int arraylong){
    int y;    /*y:ループ変数*/
    
    /*数列のソート状況を表示する*/
    for(y=0; arraylong>y; y++){
        printf("%d", array[y]);
        if(arraylong-1 == y){    /*表示形式調整*/
            printf("\n");
        }else{
            printf(" ");
        }
    }
}
