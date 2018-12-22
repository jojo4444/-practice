#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define NMAX  44
#define MAXOUT 444444

int main(int argc, char* argv[]) {
	srand(time(NULL));
	int i, j;

	if (argc != 2) {
		printf("format: ./{name} {cnt txt files < 1000 }");
		return -1;
	}

	int n = atoi(argv[1]);

	for (i = 0; i < n; ++i) {
		char fileAndWay[NMAX] = "./files/";
		static char file[NMAX];
		sprintf(file, "%0*d", 4, i);
		strcat(file, ".txt");
		strcat(fileAndWay, file);
		
		FILE* out = fopen(fileAndWay, "w");
		int delta = abs(rand() * rand())%MAXOUT;
		for (j = 0; j < MAXOUT + delta; ++j) {
			fprintf(out, "%c", rand()%('z' - 'a') + 'a');
		}
		fclose(out);
	}
	return 0;
}
