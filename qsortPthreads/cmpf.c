#include <stdio.h>
#include "cmp.h"
#include <math.h>

int sumDig(int a) {
        int res = 0;
        while (a) {
                res += (a % 10);
                a /= 10;
        }
        return res;
}

int cmp(int a, int b) {
        int sa = sumDig(a);
        int sb = sumDig(b);

	//FOR SLOW
	/*int i, j;
	for (i = 0; i < 1e6; ++i) {
		j += sin(i);
	}*/

        if (sa != sb) {
                return (sa < sb)?-1:1;
        }
	return 0;
}

