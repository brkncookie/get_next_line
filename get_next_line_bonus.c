#include "includes/get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static filer8d	file;
	char		*buf;
	char		*nln;
	char		*rpt;
	long int	cnt;

	/* this variable is used to indicate if we returned the rest of the file that is not nulled */
	if(file.done[fd] == 1)
		return(NULL);
	/* restore what ever we saved */
	buf = file.kpb[fd];
	if(!buf)
		buf = malloc(BUFFER_SIZE + sizeof(char));
	ERROR(buf);
	/*read to buf and expand it, and at the same time find a line*/
	while((cnt = read(fd, buf + file.b8rd[fd], BUFFER_SIZE)) > 0 )
	{
		file.b8rd[fd] += cnt;
		file.sze[fd]  += BUFFER_SIZE;
		buf = ft_realloc(buf, (BUFFER_SIZE + file.sze[fd] + 1) * sizeof(char), NULL);
		ERROR(buf);
		cnt = file.b8rd[fd];
		while(cnt < (BUFFER_SIZE + file.sze[fd]))
			buf[cnt++] = 0;
		file.kpb[fd] = buf;
		/* if we find a line we then get a copy of it, null it and then return it and manage the rest of the buffer */
		nln = ft_strchr(buf, 10);
		if(nln)
		{
			rpt = ft_strndup(buf, (nln - buf + 2));
			ERROR(rpt);
			rpt[nln - buf + 1] = 0;
			file.b8rd[fd] -= nln - buf + 1;
			file.sze[fd] -= nln - buf + 1;
			buf = ft_realloc(nln + 1, (BUFFER_SIZE + file.sze[fd]  + 1) * sizeof(char), buf);
			ERROR(buf);
			cnt = file.b8rd[fd];
			while(cnt < (BUFFER_SIZE + file.sze[fd]))
				buf[cnt++] = 0;
			file.kpb[fd] = buf;
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
		file.b8rd[fd] -= nln - buf + 1;
		file.sze[fd] -= nln - buf + 1;
		buf = ft_realloc(nln + 1, (BUFFER_SIZE + file.sze[fd] + 1) * sizeof(char), buf);
		ERROR(buf);
		cnt = file.b8rd[fd];
		while(cnt < (BUFFER_SIZE + file.sze[fd]))
			buf[cnt++] = 0;
		file.kpb[fd] = buf;
		return(rpt);
	}
	/* if we reached here it means that it's eof and there is no new line character either ways we return the rest of the file or NULL if there is not */
	if(*buf && file.done[fd] != 1)
	{
		file.done[fd] = 1;
		return(buf);
	}
	return(NULL);
}

