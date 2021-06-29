#include <stdio.h>

int table[105][105];
int breadth_list[105];

void breadth_search(int breadth, int id, int col) {
	int i;
	int j;
	int queue[1005];
	int wp = 0;
	int rp = 0;
	int now_id;
	
	table[id][0] = 0;
	breadth_list[id] = breadth;

	queue[wp] = id;
	wp++;

	while(wp > rp) {
		now_id = queue[rp%1000];
		rp++;
		for(i=1;i<=col;i++) {
			if(table[now_id][i] == 1 && table[i][0] == 1) {
				for(j=0;j<=col;j++) table[j][i] = 0;
				breadth_list[i] = breadth_list[now_id] + 1;
				queue[wp%1000] = i;
				wp++;
			}
		}
	}
}

int main(void) {
    int i, j, n, q;
    int id, t;
    char buff[1024];

    scanf("%d\n", &n);
    for(i=0;i<=n;i++) {
    	breadth_list[i] = -1;
    	table[i][0] = 1;
        for(j=1;j<=n;j++) {
            table[i][j] = 0;
        }
    }
   
    for(i=0;i<n;i++) {
        scanf("%d %d", &id, &q);
        for(j=0;j<q;j++) {
            scanf("%d", &t);
            table[id][t] = 1;
        }
        gets(buff);
    }
	
	breadth_search(0, 1, n);

	for(i=1;i<=n;i++) {
		printf("%d %d\n", i, breadth_list[i]);
	}

    return 0;
}
