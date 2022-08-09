/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:35:42 by aceralin          #+#    #+#             */
/*   Updated: 2022/08/09 21:24:46 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <limits.h>

char *keep_before_new_line(char *line_read)
{
	char *tmp;
	int i;
	
	tmp = malloc( sizeof (char) * (ft_strlen(line_read)));
	i = 0;
	while(line_read[i] != '\n' && line_read[i] != '\0')
	{
		tmp[i] = line_read[i];  
		i++;
	}
	return(tmp);
} 
char * copy_after_new_line(char *buffer)
{
	int	i ;
	int j ;
	char *word;
	
	word = malloc( sizeof(char) * (BUFFER_SIZE + 1));
	if (!word)
		return(0);
	i = 0;
	j = 0;
	while(buffer[i] && buffer [i] != '\n' )
		i++;
	if( buffer[i] && buffer[i] == '\n')
		i++;
	while (buffer[i] )
	{
		word[j] = buffer [i];
		i++; 
		j++;	
	}
	word[i] = '\0';
	return(word);
}

int	found_new_line(char *buffer)
{
	int	i;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i ++;
	}
	return (0);
}

char	*ft_copy_and_stick(char *buffer, char *line_read)
{	
	char	*tmp;
	
	
	if (line_read == NULL )
	{
		line_read = ft_strdup(buffer);	
		return(line_read);
	}
	tmp = ft_strdup(buffer);
	line_read = ft_strjoin(line_read, tmp);
	
	return (line_read);
}
	
char	*get_next_line(int fd)
{
    char	*line_read;
	static char	*buffer;
	size_t	count;
	
	if ((fd < 0) || BUFFER_SIZE <= 0  || read(fd, buffer, 0) < 0)
		return (NULL);
	if(buffer == NULL)
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line_read = NULL;
	if(found_new_line (buffer) == 1)
	{
		line_read = copy_after_new_line(buffer);
	
		buffer = ft_strdup(line_read);
	}	
    while (found_new_line(buffer) == 0)
	{
		
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == 0)
			return(line_read);
        buffer[count + 1 ] = '\0';
        line_read = ft_copy_and_stick(buffer, line_read); 
		if (line_read == NULL)
		{
			free(buffer);
			return(NULL);
		}
    }
	line_read = keep_before_new_line(line_read);
	return (line_read); 
}

int	main()
{
	int fd;
    char *result;
	fd = open("jojo", O_RDONLY);
	int i;	
	i = 0; 

	
	while (i != 10)
	{
		result = get_next_line(fd);
		printf("\nResultat final: %s\n",result);
		free(result);
		i++;
	}	
	return(0);
	//result = get_next_line(fd);
		
	//printf("Par la: %s",get_next_line(fd));
	//free(result);
	//}	
	//return(0);
}