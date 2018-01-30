/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   readder.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 18:38:11 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 16:20:44 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_flagurhandler(t_list *begin, t_opt *opt)
{
	t_file	*info;

	opt->blck = 0;
	while (begin)
	{
		info = begin->content;
		if (info->perm[0] == 'd' &&
		(ft_strcmp(info->name, "\e[1;36m.\e[0m") != 0 &&
		ft_strcmp(info->name, "\e[1;36m..\e[0m") != 0) &&
		(ft_strcmp(info->name, ".") != 0 &&
		ft_strcmp(info->name, "..") != 0))
			ft_filereadder(info->rep, opt);
		begin = begin->next;
	}
}

static int	ft_printerror(const char *rep)
{
	if (errno == 2)
		return (-1);
	if (errno == 20)
	{
		ft_putstr(rep);
		ft_putchar('\n');
		return (1);
	}
	ft_putstr("ft_ls: ");
	if (ft_strchr(rep, '/'))
		ft_putstr(ft_strrchr(rep, '/') + 1);
	else
		ft_putstr(rep);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putchar('\n');
	return (-1);
}

static void	ft_printcur(const char *rep, t_opt *opt)
{
	//dprintf(1, "%i\n", opt->dir);
	if (opt->dir > 1 || opt->dir == -1)
	{
		if (opt->dir == -1)
			ft_putchar('\n');
		ft_putstr(rep);
		ft_putstr(":\n");
	}
}

int			ft_filereadder(const char *rep, t_opt *opt)
{
	struct dirent	*file;
	t_list			*begin;
	t_file			*info;
	DIR				*dir;

	dir = opendir(rep);
	begin = NULL;
	if (dir == NULL)
		return (ft_printerror(rep));
	ft_printcur(rep, opt);
	while ((file = readdir(dir)) != NULL)
	{
		if (opt->a == 0 && file->d_name[0] == '.')
			continue ;
		info = ft_fileinfo(rep, file->d_name, opt);
		begin == NULL ? begin = ft_lstnew(info, sizeof(t_file)) :
		ft_lstsortadd(&begin, ft_lstnew(info, sizeof(t_file)), opt);
		free(info);
	}
	closedir(dir);
	ft_print(begin, opt);
	opt->dir = -1;
	opt->ur ? ft_flagurhandler(begin, opt) : 0;
	ft_lstd(&begin, ft_infodel, opt);
	return (1);
}
