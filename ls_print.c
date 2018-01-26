/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 14:27:08 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 19:47:04 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_catitoa(char *out, int link)
{
	char	*tmp;

	if (!(tmp = ft_itoa(link)))
		exit(-1);
	ft_strcat(out, tmp);
	ft_strdel(&tmp);
	return (out);
}

char	*ft_catdev(char *out, t_file *info)
{
	char	*tmp;
	char	*tmp2;

	if (*info->perm == 'c' || *info->perm == 'b')
	{
		if (!(tmp = ft_itoa(major(info->dev))))
			exit(-1);
		if (!(tmp2 = ft_itoa(major(info->dev))))
			exit(-1);
		ft_strcat(out, tmp);
		ft_strcat(out, ", ");
		ft_strcat(out, tmp2);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	else
	{
		tmp = ft_itoa(info->size);
		ft_strcat(out, tmp);
		ft_strdel(&tmp);
	}
	return (out);
}

char	*ft_catout(t_file *info, size_t size)
{
	char	*out;

	if (!(out = ft_strnew(size)))
		exit(-1);
	ft_strcat(out, info->perm);
	ft_strcat(out, " ");
	ft_catitoa(out, info->link);
	ft_strcat(out, " ");
	ft_strcat(out, info->grp);
	ft_strcat(out, " ");
	ft_strcat(out, info->usr);
	ft_strcat(out, " ");
	ft_catdev(out, info);
	ft_strcat(out, " ");
	ft_strcat(out, info->date);
	ft_strcat(out, " ");
	ft_strcat(out, info->name);
	if (*info->lnk != '\0')
	{
		ft_strcat(out, " -> ");
		ft_strcat(out, info->lnk);
	}
	ft_strcat(out, "\n");
	return (out);
}

void	ft_listprint(t_file *info)
{
	size_t	size;
	size_t	msiz;
	char	*out;

	if (*info->perm == 'c' || *info->perm == 'b')
		msiz = ft_countdigit(major(info->dev)) + ft_countdigit(minor(info->dev)) + 4;
	else
		msiz = ft_countdigit(info->size);
	size = ft_strlen(info->perm) + ft_countdigit(info->link) + msiz +
	ft_strlen(info->grp) + ft_strlen(info->usr) + ft_strlen(info->date) +
	ft_strlen(info->name) + ft_strlen(info->lnk) +
	(ft_strlen(info->lnk) > 0 ? 4 : 0) + 7;
	out = ft_catout(info, size);
	write(1, out, size);
	ft_strdel(&out);
}

void	ft_print(t_list *begin, t_opt *opt)
{
	t_file *info;

	if (opt->l)
	{
		write(1, "total ", 6);
		ft_putnbr(opt->blck);
		write(1, "\n", 1);
	}
	opt->blck = 0;
	while (begin)
	{
		info = begin->content;
		if (opt->l)
		{
			if (opt->ug)
			{
				ft_strdel(&(info->name));
				info->name = info->cname;
			}
			ft_listprint(info);
		}
		else
		{
			ft_putstr(opt->ug ? info->cname : info->name);
			ft_putchar(' ');
		}
		begin = begin->next;
	}
}
