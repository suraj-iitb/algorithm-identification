#include <stdio.h>
#include <stdlib.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int n;
int ans[202];
int que[202], qf = 0, qb = 0;

#define E_MAX 10101
#define V_MAX 202
typedef struct edlst{
    int fr, to;
}E;
typedef struct graph{
    E e[E_MAX];
    int st[V_MAX], siz[V_MAX];
}G;
G g;
int upe(const void *a, const void *b){
    if(((E*)a)->fr != ((E*)b)->fr) 
        return (((E*)a)->fr > ((E*)b)->fr ? 1 : -1);
    else
        return (((E*)a)->to == ((E*)b)->to ? 0 : (((E*)a)->to > ((E*)b)->to ? 1 : -1));
}
void g_init(int vn, int en){
    int a, b, u;
    rep(i, vn) g.siz[i] = 0;
    rep(i, vn) {
        scanf("%d%d", &a, &u);
        a--;
        g.siz[a] = u;
        rep(j, u) {
            scanf("%d", &b);
            b--;
            g.e[en].fr = a; g.e[en].to = b;
            en++;
        }
    }
    qsort(g.e, en, sizeof(E), upe);
    g.st[0] = 0;
    rep(i, vn-1){
        g.st[i+1] = g.st[i] + g.siz[i];
    }
}

void solve() {
    rep(i, n)
        ans[i] = -1;
    que[qb++] = 0;
    ans[0] = 0;
    while(qb - qf > 0) {
        int v = que[qf++];
        rep(i, g.siz[v]) {
            int nv = g.e[g.st[v] + i].to;
            if(ans[nv] == -1) {
                ans[nv] = ans[v] + 1;
                que[qb++] = nv;
            } 
        }
    }
}

int main(){
    scanf("%d", &n);
    g_init(n, 0);

    solve();

    rep(i, n)
        printf("%d %d\n", i+1, ans[i]);
}
