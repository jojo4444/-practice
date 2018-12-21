#include <stdio.h>

int main() {
	int flag = 0;
	int i, n, b, a, last;

	FILE* in = fopen("out.txt", "r");
	if (in == NULL) {
		printf("no files");
		return 0;
	}
	fscanf(in, "%d%d%d", &n, &a, &last);

	for (i = 1; i < n; ++i) {
		fscanf(in, "%d%d", &a, &b);
		if (b > last) {
			flag = 1;
			break;
		}
		last = b;
	}

	printf((flag)?"bad":"good");
	return 0;
}
