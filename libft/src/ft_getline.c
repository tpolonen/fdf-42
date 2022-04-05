/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:22:03 by tpolonen          #+#    #+#             */
/*   Updated: 2022/03/31 10:01:23 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_buff	*get_buff(const int fd, t_buff **buffs)
{
	t_buff	*target;
	t_buff	**new;

	if (fd < 0)
		return (NULL);
	if (*buffs != NULL)
	{
		target = *buffs;
		while (target->fd != fd && target->next != NULL)
			target = target->next;
		if (target->fd == fd)
			return (target);
		new = &(target->next);
	}
	else
		new = buffs;
	*new = (t_buff *) malloc(sizeof(t_buff));
	if (*new)
	{
		(*new)->fd = fd;
		(*new)->offset = 0;
		(*new)->bytes = 0;
		(*new)->next = NULL;
	}
	return (*new);
}

static int	read_fd(t_buff *buff, t_dstr **new_line)
{
	char	*stop;

	if (buff->bytes <= 0)
		return (buff->bytes);
	stop = ft_memchr(buff->content + buff->offset, '\n',
			(size_t)(buff->bytes - buff->offset));
	if (stop == NULL)
		stop = buff->content + buff->bytes;
	if (ft_dstrbuild(new_line, buff->content + buff->offset,
			(size_t)((stop - buff->offset) - buff->content)) < 0)
	{
		ft_dstrclose(new_line, NULL);
		return (-1);
	}
	buff->offset = stop - buff->content + 1;
	if (buff->offset <= buff->bytes)
		return (0);
	return (1);
}

int	ft_getline(const int fd, char **line)
{
	static t_buff	*buffs;
	t_buff			*buff;
	t_dstr			*new_line;
	int				ret;

	buff = get_buff(fd, &buffs);
	if (buff == NULL || line == NULL)
		ret = -1;
	else
		ret = 1;
	new_line = NULL;
	while (ret > 0)
	{
		if (buff->bytes <= 0 || buff->offset >= buff->bytes)
		{
			buff->offset = 0;
			buff->bytes = read(buff->fd, buff->content, BUFF_SIZE);
		}
		ret = read_fd(buff, &new_line);
	}
	if (new_line != NULL)
		return (ft_dstrclose(&new_line, line));
	return (ret);
}
