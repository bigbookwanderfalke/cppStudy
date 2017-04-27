
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	FILE *fw, *fr;
	int fd;
	struct stat st;
	char path[] = "./helloC.txt";
	char str[100] = "Hello, world\n";
	char buf[100] = "";

	fw = fopen(path, "w");
	fwrite(str, strlen(str), 1, fw);
	fflush(fw);
	fclose(fw);

	fr = fopen(path, "r");
	fd = fileno(fr);
	fstat(fd, &st);
	fread(buf, st.st_size, 1, fr);
	printf("read -- %s\n", buf);
	fclose(fr);

	return 0;
}
