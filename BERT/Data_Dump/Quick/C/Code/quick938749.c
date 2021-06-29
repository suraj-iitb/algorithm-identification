#include <stdio.h>
#include <memory.h>

typedef struct _element {
	int index;
	int val;
	char c;
} element;

int is_stable(element lst[], int n) {
	int i;
	element last;

	memcpy((char*)&last, (char*)&lst[0], sizeof(element));
	for(i=1;i<n;i++) {
		if(last.val == lst[i].val) {
			if(last.index > lst[i].index) {
				return 0;
			}
		}
		memcpy((char*)&last, (char*)&lst[i], sizeof(element));
	}
	
	return 1;
}

 
void swap(element A[], int i, int j) {
    element t;
    memcpy((char*)&t, (char*)&A[i], sizeof(t));
    memcpy((char*)&A[i], (char*)&A[j], sizeof(t));
    memcpy((char*)&A[j], (char*)&t, sizeof(t));
}
 
int partition(element A[], int p, int r) {
    int i,j,t;
    element x;
    memcpy((char*)&x, (char*)&A[r], sizeof(x));
    i=p;
    for(j=p;j<r;j++) {
        if(A[j].val <= x.val) {
            swap(A, i, j);
            i++;
        }
    }
     
    swap(A, i, r);
    return i;
}

int quick_sort(element A[], int p, int r, int n) {
	int q;
	if(p < r) {
		q = partition(A, p, r);
        quick_sort(A, p, q-1, n);
        quick_sort(A, q+1, r, n);
	}
	
	return is_stable(A, n);
}

int main(void) {
	int i, val, n;
	int stable;
	element lst[100001];
	element q_lst[100001];

	scanf("%d\n", &n);
	for(i=0;i<n;i++) {
		lst[i].index = i;
		scanf("%c%d ", &(lst[i].c), &(lst[i].val));
	}
	memcpy((char*)q_lst, (char*)lst, sizeof(lst));

	stable = quick_sort(q_lst, 0, n-1, n);
	if(stable == 1) {
		printf("Stable\n");
	} else {
		printf("Not stable\n");
	}
	for(i=0;i<n;i++) {
		printf("%c %d\n", q_lst[i].c, q_lst[i].val);
	}
	
	return 0;
}
