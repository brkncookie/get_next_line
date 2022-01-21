#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define ERROR(n) \
	if(n == NULL)\
		return(0);

char	*get_next_line(int fd);
char	*ft_strndup(char *src, long int len);
char	*ft_strchr(char	*src,	char c);
char	*ft_realloc(char	*src, long int sze, char	*s_src);

#endif

