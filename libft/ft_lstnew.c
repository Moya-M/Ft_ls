/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:16:15 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:16:17 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp)
	{
		if (content == NULL)
		{
			tmp->content = NULL;
			tmp->content_size = 0;
		}
		else
		{
			if (!(tmp->content = malloc(content_size)))
				return (NULL);
			tmp->content = ft_memcpy(tmp->content, content, content_size);
			tmp->content_size = content_size;
		}
		tmp->next = NULL;
	}
	return (tmp);
}
