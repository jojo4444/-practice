#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define NMAX 44

typedef struct {
	int be, en;
	FILE* in;
	char** arr;
	char file[NMAX];
} ptdata;

void* readth(void* dt) {
	ptdata* data = (ptdata*)dt;
	
	data->in = fopen(data->file, "r");
	for (; data->be <= data->en; ++(data->be)) {
		//fprintf(stderr, "%s %d\n", data->file, data->be);
		fscanf(data->in, "%c", &((*(data->arr))[data->be]));
	}
	fclose(data->in);

	return NULL;
}

long long mtime() {
  	struct timespec t;

  	clock_gettime(CLOCK_REALTIME, &t);
  	long long mt = (long long)t.tv_sec * 1000 + t.tv_nsec / 1000000;
  	return mt;
}

int main() {
	struct dirent* fl;
	DIR* dir;

	dir = opendir("./files/");
	if (dir == NULL) {
		printf("no files");
		return -1;
	}

	struct stat st;

	char* arr;
	pthread_t* th;
	ptdata* thdata = (ptdata*)calloc(0, sizeof(ptdata));

	int allSize = 0, num = 0;

	long long start_p = mtime();

	while ((fl = readdir(dir)) != NULL) {
		if (fl->d_type != DT_REG) {
			continue;
		}
		
		char way[NMAX];
		memset(way, 0, NMAX);
		strcat(way, "./files/");

		stat(strcat(way, fl->d_name), &st);
		int size = st.st_size;

		thdata = realloc(thdata, sizeof(ptdata) * (num + 1));
		
		thdata[num].arr = &arr;
		thdata[num].be = allSize;
		thdata[num].en = allSize + size - 1;
		
		memset(thdata[num].file, 0, NMAX);
		strcat(thdata[num].file, way);
		
		allSize += size;
		++num;
	}

	th = (pthread_t*)calloc(num, sizeof(pthread_t));
	arr = (char*)calloc(allSize, sizeof(char));

	int i;
	for (i = 0; i < num; ++i) {
		pthread_create(&(th[i]), NULL, readth, &(thdata[i]));
	}

	for (i = 0; i < num; ++i) {
		pthread_join(th[i], NULL);
	}

	printf("time parallel on sec: %lf\n", (double)(mtime() - start_p)/1e3);

	long long start_l = mtime();

	int j = 0;
	rewinddir(dir);
	while ((fl = readdir(dir)) != NULL) {
                if (fl->d_type != DT_REG) {
                        continue;
                }

                char way[NMAX];
                memset(way, 0, NMAX);
                strcat(way, "./files/");
		strcat(way, fl->d_name);
        	
		FILE* in = fopen(way, "r");

		while (fscanf(in, "%c", &arr[j]) > 0) {
			++j;
		}

		fclose(in);
	}


	printf("time linear on sec: %lf\n", (double)(mtime() - start_l)/1e3);

	/*FILE* out = fopen("out.txt", "w");

	for (i = 0; i < allSize; ++i) {
		fprintf(out, "%c", arr[i]);
	}*/
	
	return 0;
}
