
#include "get_next_line.h"
#include <stdio.h>
char *get_next_line(int fd)
{
    char *buff;
    static char *saver;
    char *tmp;
    char *line;
    int i,rd;

    if (fd < 0 || BUFFER_SIZE <= 0)
	    return (0);
    i = 0;
    rd = 1;
    buff = (char *) malloc(BUFFER_SIZE + 1);
    if(!buff)
        return (NULL);
    buff[0] = 0;
    while(rd > 0 && !ft_strchr(buff,'\n'))
    {
        rd = read(fd,buff,BUFFER_SIZE);
        if(rd < 0)
        {
            free(buff);
            return (0);
        }
        buff[rd] = 0;
        saver = ft_strjoin(saver,buff);
    }
    free(buff);
    while(saver[i] != '\0' && saver[i] != '\n')
        i++;
    if(rd == 0 && saver[0] == '\0')
    {
        free(saver);
        saver = NULL;
        return 0;
    }
    line =  ft_substr(saver,0,i + 1);
    tmp = saver;
    saver = ft_substr(saver,i + 1, ft_strlen(saver));
    free(tmp);
    return (line);
}
