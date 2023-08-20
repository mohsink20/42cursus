#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*buffer;
	t_list	*tmp;

	new = NULL;
	buffer = NULL;
	tmp = NULL;
	if (!f || !del || !lst || !(new = ft_lstnew(f(lst->content))))
		return (NULL);
	buffer = new;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		buffer->next = tmp;
		buffer = tmp;
		lst = lst->next;
	}
	return (new);
}
