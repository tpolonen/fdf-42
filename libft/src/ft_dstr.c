#include "libft.h"

ssize_t	ft_dstrbuild(t_dstr **ds, const char *str, size_t len)
{
	char	*new_str;
	size_t	new_size;

	if (*ds == NULL)
	{
		*ds = (t_dstr *) ft_memalloc(sizeof(t_dstr));
		(*ds)->str = ft_strnew(len);
		(*ds)->alloced = len + 1;
	}
	else if ((*ds)->alloced < (*ds)->len + len + 1)
	{
		new_size = ((*ds)->len + len + 1) * 2;
		new_str = (char *) malloc(new_size * sizeof(char));
		if (!new_str)
			return (-1);
		ft_memcpy((void *)new_str, (void *)(*ds)->str, (*ds)->len + 1);
		free((*ds)->str);
		(*ds)->str = new_str;
		(*ds)->alloced = new_size;
	}
	ft_memcpy((void *)((*ds)->str + (*ds)->len), (void *)str, len);
	(*ds)->str[(*ds)->len + len] = '\0';
	(*ds)->len += len;
	return ((ssize_t)(*ds)->len);
}

int	ft_dstrclose(t_dstr **ds, char **target)
{
	int	ret;

	ret = 0;
	if (*ds == NULL)
		return (ret);
	if (target != NULL)
	{
		ret = 1;
		if ((*ds)->alloced == (*ds)->len + 1)
			*target = (*ds)->str;
		else
		{
			*target = ft_strnew((*ds)->len);
			if (target)
				ft_memcpy(*target, (*ds)->str, (*ds)->len);
			else
				ret = -1;
			free((*ds)->str);
		}
	}
	else
		free((*ds)->str);
	ft_memdel((void **) ds);
	return (ret);
}
