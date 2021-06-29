#include <stdio.h>

void ins_sort(int *A); //insertion sort

int num;

int main () {
	int a[101],i;
	
	scanf ("%d",&num);
	for (i = 0;i < num;i ++) {
		scanf ("%d",&a[i]);
	}
	ins_sort(a);
	
	return 0;
}

void ins_sort(int *A) {
	int  i,j,k,v;
	
	for (k = 0;k < num;k ++) { //なんか最初に出力しないといけないから
		printf ("%d",A[k]);
    	if (k != num - 1) {
    		putchar (' ');
    	}
	}
	putchar('\n');
	
    for (i = 1;i < num;i ++){
    	v = A[i]; /*i番目の数が手前の数たちの中のどこに入るか
    	            vは、A[i]の値の保存*/
    	j = i - 1; //手前の数たち
    	while (j >= 0 && A[j] > v) { //vのとこA[i]だと下の代入で違うの入ってる
    		//手前の数がデカかったら
    		A[j + 1] = A[j]; //iじゃなくてj+1なのはj--がきくから
    		j --;
    	}
    	A[j + 1] = v; //やっとv落ち着きました
    	
    	for (k = 0;k < num;k ++) {
    		printf ("%d",A[k]);
    		if (k != num - 1) {
    			putchar (' ');
    		}
    	}
    	putchar ('\n');
    }
	
}
