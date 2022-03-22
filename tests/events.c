#include "tests.h"

static t_list **keys_head;

t_list *seek_key(int keycode)
{
	t_list	*seek = *keys_head;

	while (seek != NULL)
	{
		t_keybind *kb = (t_keybind *) seek->content;
		if (kb->keycode == keycode)
			break;
		else
			seek = seek->next;
	}
	return (seek);
}

int set_key(int keycode, void (*func)(t_param *params))
{
	t_list *seek;
	int ret = 0;
	t_keybind *key = calloc(1, sizeof(t_keybind));
	if (key == NULL)
		return (1);
	key->keycode = keycode;
	key->func = func;
	seek = seek_key(keycode);
	if (seek == NULL) {
		//create new keybind (at the top of linked list?)
		t_list *new = lstnew((void *)key, sizeof(t_keybind));
		lstadd(keys_head, new);
	} else {
		//overwrite existing keybind
		free(seek->content);
		seek->content = (void *)key;
	} return (ret);
}

int read_key(int keycode, void *params)
{
	(void) params;
	printf("%d was pressed\n", keycode);
	// seek the keys linked list by keycode
	// currently we have only the hardcoded options
	if (keycode == 65307)
		exit(0);
	return (0);
}
