#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

char    *get_next_line(int fd);
int	    ft_strlen(const char *str);
char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_strchr( char *s, int c);
char	*ft_strldup(const char *s1, int len);
char	*ft_substr(char	 *s,int start, int len);
#endif