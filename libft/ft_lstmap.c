/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:16:10 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:16:11 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*base;

	tmp2 = NULL;
	while (lst)
	{
		if ((tmp = ft_lstnew(f(lst)->content, f(lst)->content_size)) == NULL)
			return (NULL);
		if (tmp2 != NULL)
			tmp2->next = tmp;
		else
			base = tmp;
		lst = lst->next;
		tmp2 = tmp;
	}
	return (base);
}
