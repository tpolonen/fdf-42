/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:02:54 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/06 09:01:38 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "dintarr.h"

static int	isvalidchar(char c)
{
	return (ft_isdigit(c) || ft_isspace(c) || c == '+' || c == '-');
}

static int	get_col(t_dintarr **darr, char **nptr, int cols)
{
	char	*start;

	start = *nptr;
	dintarr_add(darr, (int)ft_strtol(*nptr, nptr));
	if (start == *nptr)
		return (cols);
	return (++cols);
}

static int	**read_cols(char *nptr, int *col_arr, int rows, t_param *params)
{
	t_dintarr	*darr;
	int			i;
	int			cols;

	params->map = (int **)ft_memalloc(sizeof(int *) * rows);
	i = 0;
	darr = NULL;
	while (i < rows)
	{
		cols = 0;
		while (*nptr != '\n' && *nptr != '\0')
		{
			cols = get_col(&darr, &nptr, cols);
			if (!isvalidchar(*nptr) || !cols
		if ((*nptr != '\n' && *nptr != '\0') || !cols)
			return (free_map(&(params->map), &col_arr, rows));
		col_arr[i++] = cols;
		nptr++;
	}
	return (params->map);
}

static int	read_rows(int fd, t_dstr **data)
{
	int		rows;
	int		len;
	char	*buf;

	rows = 0;
	while (1)
	{
		len = ft_getline(fd, &buf);
		if (len <= 0)
			return (rows);
		ft_dstrbuild(data, buf, len);
		ft_dstrbuild(data, "\n", 1);
		rows++;
		free(buf);
	}
}

void	read_file(char *filename, t_param *params)
{
	int		fd;
	int		rows;
	t_dstr	*data;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("File reading failed");
		exit(1);
	}
	rows = 0;
	data = NULL;
	rows = read_rows(fd, &data);
	if (!rows)
		handle_exit("Map error: Empty file", params);
	params->cols = (int *)ft_memalloc(sizeof(int) * rows);
	params->map = read_cols(data->str, params->cols, rows, params);
	ft_dstrclose(&data, NULL);
	if (!params->map)
		handle_exit("Map error: Invalid characters", params);
	params->map_height = rows;
}
