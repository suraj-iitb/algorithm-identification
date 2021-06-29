#include <stdio.h>
 
int get_uint() {
    int m = 0;
    int a = getchar_unlocked();
    if(a < 48 || 57 < a) return a;
    while(47 < a && a < 58) {
        m = 10 * m + (a & 0xf);
        a = getchar_unlocked();
    }
    return m;
}
void put_uint(int m) {
    if(!m) {
        putchar_unlocked('0');
        return;
    }
    char buf[11];
    int i = 0;
    while(m) buf[i++] = (char)(m % 10 + '0'), m /= 10;
    while(i--)putchar_unlocked(buf[i]);
}
typedef struct Card {
    int i;
    int m;
    char a;
} Card;
 
// retard desu LMAO
void *partition(Card *fir, Card *last) {
    Card pivot = *(last - 1);
    Card *p = fir - 1;
    for(Card *is = fir; is != last - 1; ++is) {
        if(is->m <= pivot.m) {
            p++;
            Card tmp = *p;
            *p = *is;
            *is = tmp;
        }
    }
    Card tmp = *++p;
    *p = pivot;
    *(last - 1) = tmp;
    return p;
}
void quicksort(void *fir, void *last, size_t M) {
    if(last - fir <= M) return;
    void *mid = partition(fir, last);
    quicksort(fir, mid, M);
    quicksort(mid, last, M);
}
 
int main(int argc, char **argv) {
    int m = get_uint();
    Card A[m];
    for(int i = 0; i < m; ++i) {
        A[i].a = getchar_unlocked();
        getchar_unlocked();
        A[i].m = get_uint();
        A[i].i = i;
    }
    quicksort(A, A + m, sizeof(Card));
 
    int flag = 0;
    for(int i = 1; i < m; ++i) {
        if(A[i].m==A[i-1].m && A[i].i < A[i-1].i){
            flag = 1;
            break;
        }
    }
    puts(flag ? "Not stable" : "Stable");
    for(int i = 0; i < m; ++i) {
        putchar_unlocked(A[i].a), putchar_unlocked(' ');
        put_uint(A[i].m), putchar_unlocked('\n');
    }
    return 0;
}
/*クイックソート

n

枚のカードの列を整列します。１枚のカードは絵柄(S, H, C, またはD)と数字のペアで構成されています。これらを以下の疑似コードに基づくクイックソートで数字に関して昇順に整列するプログラムを作成してください。partition は ALDS1_6_B の疑似コードに基づくものとします。

1 quicksort(A, p, r)
2   if p < r
3     q = partition(A, p, r)
4     quickSort(A, p, q-1)
5     quickSort(A, q+1, r)

ここで、A

はカードが格納された配列であり、partition における比較演算はカードに書かれた「数」を基準に行われるものとします。

また、与えられた入力に対して安定な出力を行っているかを報告してください。ここでは、同じ数字を持つカードが複数ある場合、それらが入力で与えられた順序であらわれる出力を「安定な出力」とします。
入力

1行目にカードの枚数 n

が与えられます。

2行目以降で n

枚のカードが与えられます。各カードは絵柄を表す１つの文字と数（整数）のペアで１行に与えられます。絵柄と数は１つの空白で区切られています。
出力

1行目に、この出力が安定か否か（StableまたはNot stable）を出力してください。

2行目以降で、入力と同様の形式で整列されたカードを順番に出力してください（n

を出力する必要はありません）。
制約

    1≤n≤100,000

1≤カードに書かれている数≤109

    入力に絵柄と数の組が同じカードは２枚以上含まれない

入力例 1

6
D 3
H 2
D 1
S 3
D 2
C 1

出力例 1

Not stable
D 1
C 1
D 2
H 2
D 3
S 3

入力例 2

2
S 1
H 1

出力例 2

Stable
S 1
H 1
*/

