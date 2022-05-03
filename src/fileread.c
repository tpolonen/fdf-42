/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:02:54 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/03 18:01:51 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "dintarr.h"

int	**free_map(int ***map, int **col_arr, int rows)
{
	int i;

	i = 0;
	while (i < rows)
		free((*map)[i++]);
	ft_memdel((void **)map);
	ft_memdel((void **)col_arr);
	return (NULL);
}	

static int	isvalidchar(char c)
{
	return (ft_isdigit(c) || ft_isspace(c) || c == '+' || c == '-');
}

static int	isskippable(char c)
{
	return (c != '\0' && c != '\n' && c != '-' && c != '+' && !ft_isdigit(c));
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
			if (!isvalidchar(*nptr))
			{
				dintarr_close(&darr, NULL);
				return (free_map(&(params->map), &col_arr, rows));
			}
			dintarr_add(&darr, (int)ft_strtol(nptr, &nptr));
			cols++;
			while (isskippable(*nptr))
				nptr++;
		}
		dintarr_close(&darr, &(params->map[i]));
		col_arr[i++] = cols;
		if (cols == 0)
			return (free_map(&(params->map), &col_arr, rows));
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

	(void) params;
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
	params->map_width = -1;
	for (int i=0; i<rows; i++)
		if (params->cols[i] > params->map_width) params->map_width = params->cols[i];
	if (params->map_width == 0)
		handle_exit("Map error: Empty rows", params);
}
