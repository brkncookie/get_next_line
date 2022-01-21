#include "includes/get_next_line_bonus.h"
int main(int argc, char *argv[])
{
	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDONLY);
	int fd3 = open(argv[3], O_RDONLY);
	char	*p_ret;
	int inx = 1;
	argc--;


	for(int i = atoi(argv[4]); inx <= i ; inx++)
	{
	/* printf("fd for 1st file is; %d\n", fd1); */
	p_ret = get_next_line(fd1);
	printf("%d line is --> \n%s\n", inx, p_ret);
	/* printf("%s",  p_ret); */
	free(p_ret);
	/* printf("fd for 2nd file is; %d\n", fd2); */
	p_ret = get_next_line(fd2);
	printf("%d line is --> \n%s\n", inx, p_ret);
	/* /1* printf("%s",  p_ret); *1/ */
	free(p_ret);
	/* /1* /2* printf("fd for 3rd file is; %d\n", fd3); *2/ *1/ */
	p_ret = get_next_line(fd3);
	printf("%d line is --> \n%s\n", inx, p_ret);
	/* /1* /2* printf("%s",  p_ret); *2/ *1/ */
	free(p_ret);
	printf("\t----------------------------\n");
	}
	return (0);
}

