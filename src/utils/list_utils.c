
#include "../../include/minishell.h"

int	free_list(t_node **list)
{
	t_node	*tmp;
	t_node	*current;

	if (!(*list))
		return (0);
	current = *list;
	while (current->next != *list)
	{
		tmp = current;
		current = current->next;
		free(tmp->str);
		free(tmp);
	}
	free(current->str);
	free(current);
	*list = NULL;
	return (0);
}

static int	list_new_elem_str(t_node **new, char *elem)
{
	(*new) = malloc(sizeof(t_node));
	if (*new == NULL)
		return (0);
	(*new)->str = elem;
	(*new)->next = NULL;
	(*new)->prev = NULL;
	return (1);
}

static void	add_first(t_node **list, t_node *new)
{
	(*list) = new;
	(*list)->prev = *list;
	(*list)->next = *list;
}

size_t	len_list(t_node *list)
{
	t_node	*tmp;
	size_t	i;

	if ((list))
	{
		tmp = list;
		i = 1;
		while (tmp->next != list)
		{
			++i;
			tmp = tmp->next;
		}
		return (i);
	}
	return (0);
}

int	append(t_node **list, char *elem)
{
	t_node	*new;

	if (!list_new_elem_str(&new, elem))
		return (0);
	if (!(*list))
		add_first(list, new);
	else
	{
		new->prev = (*list)->prev;
		new->next = (*list);
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	return (1);
}
