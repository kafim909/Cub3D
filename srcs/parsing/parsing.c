/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:38:02 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/16 19:56:27 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/cub3d.h"

// void	print_file(char **file)
// {
// 	int i;

// 	i = -1;
// 	while(file[++i])
// 		printf("%s", file[i]);
// }

int count_lines(char *path)
{
    int		i;
	int		ret;
    int		fd;
    char	*line;

	ret = 1;
	i = 0;
    fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(1);
    while (ret)
    {
		ret = get_next_line(fd, &line);
		if (ret == -1)
			exit(1);
        i++;
        free(line);
    }
	close(fd);
    return (i);
}

void read_file(char *path, t_dfile *dfile)
{
    char    *line;
    int ret;
    int i;
    int j;
	int	fd;

    ret = 1;
    i = -1;
    j = -1;
    dfile->size_file = count_lines(path);
    dfile->file = malloc(sizeof(char *) * (dfile->size_file + 1));
    if (!dfile->file)
        exit(1);
	fd = open(path, O_RDONLY);
    while (ret)
    {
        ret = get_next_line(fd, &line);
		if (ret == -1 || (!line && ret))
			exit(1);
        dfile->file[++i] = line;
    }
    dfile->file[++i] = NULL;
}

int	parsing(int argc, char *path, t_var *v)
{
    v->dfile.error = 0;
    (void)argc;
	read_file(path, &v->dfile);
    error_file(v);
	parse_data(v);
    // parse_map(v);
    return (1);
}