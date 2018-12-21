#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <math.h>
#include "cmp.h"

int N;

#define LOGN 100

typedef struct{
	int num, ls, rs;
       	int l, r;
	int it_l, it_r;
	int key;
	int swap;
} pthrData;

pthrData* thdata;
pthread_t* th;

int arr[1000004];

void createData() {
	thdata = (pthrData*)calloc(N*LOGN, sizeof(pthrData));
	th = (pthread_t*)calloc(N*LOGN, sizeof(pthread_t));
	srand(time(NULL));
	int i;
	for (i = 0; i < N; ++i) {
		arr[i] = rand();
	}
}

void* prlsort(void* thdataTmp) {
	pthrData* data = (pthrData*)thdataTmp;
	
	//fprintf(stderr, "%d %d\n", data->l, data->r);

	if (data->l >= data->r) {
		return NULL;
	}

	data->it_l = data->l;
	data->it_r = data->r;
	data->ls = 2 * data->num + 1;
	data->rs = 2 * data->num + 2;
	data->key = arr[data->l + rand() % (data->r - data->l + 1)];

	do {
		while (data->it_l < N && cmp(arr[data->it_l], data->key) == 1) ++(data->it_l);
		while (data->it_l > -1 && cmp(arr[data->it_r], data->key) == -1) --(data->it_r);

		if (data->it_l <= data->it_r) {
			data->swap = arr[data->it_l];
			arr[data->it_l] = arr[data->it_r];
			arr[data->it_r] = data->swap;
			++(data->it_l);
			--(data->it_r);
		}
	} while(data->it_l <= data->it_r);
	
	thdata[data->ls].num = data->ls;
	thdata[data->ls].l = thdata[data->num].l;
	thdata[data->ls].r = thdata[data->num].it_r;
	
	thdata[data->rs].num = data->rs;
        thdata[data->rs].r = thdata[data->num].r;
        thdata[data->rs].l = thdata[data->num].it_l;

	//data->r = data->it_r;

	pthread_create(&(th[data->ls]), NULL, prlsort, &(thdata[data->ls]));
	pthread_create(&(th[data->rs]), NULL, prlsort, &(thdata[data->rs]));
	
	return NULL;//prlsort((void*)data);
}

int main(int argc, char* argv[]) {
	N = atoi(argv[1]);
	createData();
	
	thdata[1].num = 1;
	thdata[1].l = 0;
	thdata[1].r = N - 1;

	pthread_create(&(th[1]), NULL, prlsort, &(thdata[1]));

	int i;
	for (i = 1; i < N*LOGN; ++i) {
		if (thdata[i].num > 0) {
			pthread_join(th[i], NULL);
		}
	}

	FILE* out = fopen("out.txt", "w");
	fprintf(out, "%d\n", N);
	for (i = 0; i < N; ++i) {
		fprintf(out, "%d %d\n", arr[i], sumDig(arr[i]));
	}
	fclose(out);

	return 0;
}
