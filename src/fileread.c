/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:02:54 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/25 15:09:18 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "dintarr.h"

static int	isskippable(char c)
{
	return (c != '\0' && c != '\n' && c != '-' && c != '+' && !ft_isdigit(c));
}

static void	print_intarr(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putnbr(arr[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putendl("");
}

static void	**read_cols(char *nptr, int *col_arr, int rows, t_param *params)
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
			if (!ft_isspace(*nptr) && !ft_isdigit(*nptr) && \
				!(*nptr == '-' || *nptr == '+'))
			{
				dintarr_close(&darr, NULL);
				return ;
			}
			dintarr_add(&darr, (int)ft_strtol(nptr, &nptr));
			cols++;
			while (isskippable(*nptr))
				nptr++;
		}
		dintarr_close(&darr, &(params->map[i]));
		col_arr[i++] = cols;
		nptr++;
	}
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
	read_cols(data->str, params->cols, rows, params);
	ft_dstrclose(&data, NULL);
	if (!map)
		handle_exit("Map error: Invalid characters", params);
	params->map_height = rows;
	params->map_width = -1;
	ft_putendl("contents of col array:");
	print_intarr(params->cols, rows);
	ft_putendl("contents of map arr:");
	for (int i=0; i<rows; i++) {
		if (params->cols[i] > params->map_width) params->map_width = params->cols[i];
		print_intarr(params->map[i], params->cols[i]);
	}
}
