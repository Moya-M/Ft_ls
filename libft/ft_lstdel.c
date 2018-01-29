/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:15:59 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:16:00 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *cur;
	t_list *tmp;

	cur = *alst;
	while (cur != NULL)
	{
		tmp = cur->next;
		del(cur->content, cur->content_size);
		free(cur);
		cur = tmp;
	}
	*alst = NULL;
}
