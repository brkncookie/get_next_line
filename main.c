#include "includes/get_next_line.h"
int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	char	*p_ret;
	int inx = 1;
	argc--;
	argc++;


	for(int i = atoi(argv[2]); inx <= i ; inx++)
	{
	p_ret = get_next_line(fd);
	printf("%d line is --> \n%s\n", inx, p_ret);
	/* printf("%s",  p_ret); */
	free(p_ret);
	printf("\t\t--------------------\n");
	}
	return (0);
}

