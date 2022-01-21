#include "includes/get_next_line.h"
char	*ft_strndup(char *src, long int len)
{
	char		*dst;
	long	int 	inx;

	inx = 0;
	dst = malloc(len * sizeof(char));
	ERROR(dst);
	while(inx < len)
	{
		dst[inx] = src[inx];
		inx++;
	}
	return(dst);
}

char	*ft_strchr(char	*src,	char c)
{
	while(*src)
	{
		if( *src == c)
			return(src);
		src++;
	}
	return(NULL);
}
long int	ft_strlen(char *str)
{
	long int	len;

	len	= 0;

	while(str[len])
		len++;
	return(len);
}
char	*ft_realloc(char	*src, long int sze, char	*s_src)
{
	long	int	len;
	long	int	inx;
	char		*dst;

	dst = malloc(sze);
	ERROR(dst);
	if(!src)
		return(dst);
	len = ft_strlen(src);
	inx = 0;
	while(inx < len)
	{
		dst[inx] = src[inx];
		inx++;
	}
	if(s_src)
		free(s_src);
	else
		free(src);
	return(dst);
}

