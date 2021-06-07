#include <stdio.h>

int main () {
    int ns,nt;
    scanf("%d ",&ns);
    int s[ns];
    int pre;
    for (pre=0;pre<ns;pre++) {
        scanf (" %d",&s[pre]);
    }
    scanf("%d ",&nt);
    int t[nt];
    for (pre=0;pre<nt;pre++) {
        scanf (" %d",&t[pre]);
    }

    int result=0;
    for (pre=0;pre<nt;pre++) {
        int pre2;
        for (pre2=0;pre2<ns;pre2++) {
            if (t[pre] == s[pre2]) {
                result ++;
                break;
            }
        }
    }
    printf("%d\n",result);

    return 0;
}
