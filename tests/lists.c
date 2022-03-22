#include "tests.h"

t_list	*lstnew(void *content, size_t content_size)
{
	t_list	*l1;

	l1 = (t_list *) calloc(1, sizeof(t_list));
	if (!l1)
		return (NULL);
	l1->content = content;
	if (content == NULL)
		l1->size = 0;
	else
	{
		l1->content = malloc(content_size);
		if (!l1->content)
		{
			free(l1);
			return (NULL);
		}
		memcpy(l1->content, content, content_size);
		l1->size = content_size;
	}
	l1->next = NULL;
	return (l1);
}

void	lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
