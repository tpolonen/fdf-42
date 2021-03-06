/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:02:54 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/09 10:53:11 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "dintarr.h"

void	print_map(int **map, int *cols, int rows)
{
	int	x;
	int	y;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols[y])
		{
			ft_putnbr(map[y][x]);
			if (x < cols[y] - 1)
				ft_putstr(" ");
			x++;
		}
		ft_putendl("");
		y++;
	}
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

static int	**read_cols(char *nptr, int **col_arr, int rows, t_param *params)
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
		while ((ft_isdigit(*nptr) || *nptr == '+' || *nptr == '-') \
				&& *nptr != '\0' && *nptr != '\n')
		{
			cols = get_col(&darr, &nptr, cols);
			while (*nptr != '\n' && *nptr != '\0' && ft_isspace(*nptr))
				nptr++;
		}
		dintarr_close(&darr, &(params->map[i]));
		if (!cols)
			return (free_map(&(params->map), col_arr, rows));
		(*col_arr)[i++] = cols;
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
	len = ft_getline(fd, &buf);
	if (len <= 0)
		return (0);
	while (1)
	{
		ft_dstrbuild(data, buf, len);
		ft_dstrbuild(data, "\n", 1);
		rows++;
		free(buf);
		len = ft_getline(fd, &buf);
		if (len <= 0)
			return (rows);
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
	{
		ft_dstrclose(&data, NULL);
		handle_exit("Map error: Empty file", params);
	}
	params->cols = (int *)ft_memalloc(sizeof(int) * rows);
	params->map = read_cols(data->str, &(params->cols), rows, params);
	ft_dstrclose(&data, NULL);
	if (!params->map)
		handle_exit("Map error: Invalid row", params);
	params->map_height = rows;
}
