
#include <stdio.h>
#include <pthread.h>

void *thread(void *arg)
{
	int *a = (int*)arg;
	printf("thread hello [%d]\n", *a);
}

int main(int argc, char *argv[])
{
	pthread_t t;
	int a = 1;
	pthread_create(&t, NULL, thread, (void*)&a);
	pthread_join(t, NULL);
	return 0;
}

