/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 14:35:21 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 19:30:16 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_addlink(t_list **begin, t_list *prv, t_list *new, t_list *cur)
{
	if (prv != NULL)
	{
		if (prv->next != NULL)
			new->next = cur;
		prv->next = new;
	}
	else
	{
		new->next = cur;
		(*begin) = new;
	}
}

static int	ft_sortnt(t_file *ifo, t_file *nfo, t_opt *opt)
{
	if (opt->t == 1 && ifo->stamp - nfo->stamp != 0)
	{
		if (ifo->stamp - nfo->stamp > 0 && opt->r == 0)
			return (1);
		if (ifo->stamp - nfo->stamp < 0 && opt->r == 1)
			return (1);
		return (0);
	}
	if (ft_strcmp(ifo->name, nfo->name) > 0 && opt->r == 1)
		return (1);
	if (ft_strcmp(ifo->name, nfo->name) < 0 && opt->r == 0)
		return (1);
	return (0);
}

void		ft_lstsortadd(t_list **begin, t_list *new, t_opt *opt)
{
	t_file	*ifo;
	t_file	*nfo;
	t_list	*prv;
	t_list	*cur;

	ifo = (*begin)->content;
	nfo = new->content;
	cur = (*begin);
	prv = NULL;
	while (ft_sortnt(ifo, nfo, opt))
	{
		prv = cur;
		if (cur->next)
			cur = cur->next;
		else
			break ;
		ifo = cur->content;
	}
	ft_addlink(begin, prv, new, cur);
}

void		ft_infodel(void *ptr, size_t size, t_opt *opt)
{
	t_file *info;

	info = ptr;
	if (!opt->ug)
		ft_strdel(&(info->name));
	ft_strdel(&(info->cname));
	ft_strdel(&(info->date));
	if (opt->l)
	{
		ft_strdel(&(info->grp));
		ft_strdel(&(info->usr));
		ft_strdel(&(info->lnk));
	}
	ft_strdel(&(info->perm));
	ft_strdel(&(info->rep));
	ft_bzero(ptr, size);
	free(ptr);
	size++;
	ptr = NULL;
}

void		ft_lstd(t_list **alst,
	void (*del)(void *, size_t, t_opt *), t_opt *opt)
{
	t_list *cur;
	t_list *tmp;

	cur = *alst;
	while (cur != NULL)
	{
		tmp = cur->next;
		del(cur->content, cur->content_size, opt);
		free(cur);
		cur = tmp;
	}
	*alst = NULL;
}
