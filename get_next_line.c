/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:07:11 by aceralin          #+#    #+#             */
/*   Updated: 2022/08/02 19:46:30 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <limits.h>

// Fonction qui trouve s'il y a ou non un \n a fin la ligne
//qui va chercher dans le buffer si il y a un \n
//return 1 si il trouve et 0 si il ne trouve pas

int	found_new_line(char *buffer)
{
	int	i;
	//printf(" ici 4\n");
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
	static char	*tmp;
	int	new_line;
	char *tmp1;
	//printf(" buffer 1: %s\n", buffer);
	printf(" ici 3 \n");
	if (line_read == NULL )
		line_read = ft_strdup(buffer);
	tmp = ft_strdup(buffer); //duplique le buffer dqns la variable statique 
	printf("line_read : %s\n", line_read);
	if(ft_strchr(tmp,'\n') != NULL)
	{
		tmp1 = ft_strchr(tmp1, '\n');
		new_line = buffer - (ft_strchr(buffer , '\n'));
	}
	line_read = ft_strjoin(line_read, tmp1);
	return (line_read);
}


char	*get_next_line(int fd)
{
	char	*line_read;
	void	*buffer;
	size_t	count;

	printf(" ici\n");
	if ((fd < 0) || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0) //probleme dans la lecture du fichier (fichier illisible)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line_read = NULL;
	while (found_new_line(buffer) == 0) // tant que dans le buffer on netrouve pas de \n 
	{
		printf("\nici 2 \n");
		read (fd, buffer, BUFFER_SIZE);//lire puis stocker dans le buffer
		line_read = ft_copy_and_stick(buffer, line_read);//fonction qui va copier ce qu'il y a dans buffer strdup + strjoin
		printf("coucoula %s \n", (char * )buffer);
		printf("coucou %s \n", line_read);
		// sinon separer la ligne et retourner la string
		// apres \n  on recommence le processus
	}
	printf("%s", (char *)buffer);
	printf("\n derniere ligne :%s\n", line_read);
	//si le buffer contient \n alors on doit separer
	return (line_read);
}

int	main()
{
	char fd;
	fd = open("text.txt", O_RDONLY);
	//printf("%d\n", FOPEN_MAX);

	// /!\ appeler getnextline une ligne apres l'autre
	//while (1)
	//{
		get_next_line(fd);
		if(get_next_line(fd) == NULL)
			return(0);
		
		printf("Par la: %s",get_next_line(fd));
		free(get_next_line(fd));
	//}	
	return(0);
}
