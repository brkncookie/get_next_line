#include "includes/get_next_line.h"
char	*get_next_line(int fd)
{
	if(fd < 0 || BUFFER_SIZE < 0)
		return(NULL);
	static char	*kpb;
	static long int	b8rd;
	static long int sze;
	static long int done;
	char		*buf;
	char		*nln;
	char		*rpt;
	long	int	cnt;

	/* this variable is used to indicate if we returned the rest of the file that is not nulled */
	if(done == 1)
		return(NULL);
	/* restore what ever we saved */
	buf = kpb;
	if(!buf)
		buf   = malloc(BUFFER_SIZE * sizeof(char));
	ERROR(buf);
	/*read to buf and expand it, and at the same time find a line*/
	while((cnt = read(fd, buf + b8rd, BUFFER_SIZE)) > 0)
	{
		b8rd += cnt;
		sze  += BUFFER_SIZE;
		buf   = ft_realloc(buf, (BUFFER_SIZE + sze + 1) * sizeof(char), NULL);
		ERROR(buf);
		buf[b8rd] = 0;
		kpb = buf;
		/* if we find a line we then get a copy of it, null it and then return it and manage the rest of the buffer */
		nln = ft_strchr(buf, 10);
		if(nln)
		{
			rpt = ft_strndup(buf, (nln - buf + 2));
			ERROR(rpt);
			rpt[nln - buf + 1] = 0;
			b8rd -= nln - buf + 1;
			sze  -= nln - buf + 1;
			buf = ft_realloc(nln + 1, (BUFFER_SIZE + sze + 1) * sizeof(char), buf);
			ERROR(buf);
			buf[b8rd] = 0;
			kpb = buf;
			return(rpt);
		}
	}
	/* if reached eof we then just parse the rest of the buffer for lines */
	nln = ft_strchr(buf, 10);
	if(nln)
	{
		rpt = ft_strndup(buf, (nln - buf + 2));
		ERROR(rpt);
		rpt[nln - buf + 1] = 0;
		b8rd -= nln - buf + 1;
		sze  -= nln - buf + 1;
		buf = ft_realloc(nln + 1, (BUFFER_SIZE + sze + 1) * sizeof(char), buf);
		ERROR(buf);
		buf[b8rd] = 0;
		kpb = buf;
		return(rpt);
	}
	/* if we reached here it means that it's eof and there is no new line character either ways we return the rest of the file or NULL if there is not */
	if(*buf && done != 1)
	{
		done  = 1;
		return(buf);
	}
	return(NULL);
}

