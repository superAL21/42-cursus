#include "ft_list_size.h"

int	ft_list_size(t_list *begin_list)
{
	int		size;
	t_list	*current;

	size = 0;
	current = begin_list;
	while(current != NULL)
	{
		current = current -> next;
		size++;
	}
	return(size);
}