/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   readder.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 18:38:11 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 19:41:57 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
#include <string.h>

void	ft_lstsortadd(t_list **begin, t_list *new, t_opt *opt)
{
	t_file	*ifo;
	t_file	*nfo;
	t_list	*prv;
	t_list	*cur;

	ifo = (*begin)->content;
	nfo = new->content;
	cur = (*begin);
	prv = NULL;
	while ((opt->r == 1 && ft_strcmp(ifo->name, nfo->name) > 0) ||
	(opt->r == 0 && ft_strcmp(ifo->name, nfo->name) < 0))
	{
		prv = cur;
		if (cur->next)
			cur = cur->next;
		else
			break ;
		ifo = cur->content;
	}
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

char	ft_filetype(mode_t st_mode)
{
	if (S_ISDIR(st_mode))
		return ('d');
	else if (S_ISLNK(st_mode))
		return ('l');
	else if (S_ISBLK(st_mode))
		return ('b');
	else if (S_ISCHR(st_mode))
		return ('c');
	else if (S_ISSOCK(st_mode))
		return ('s');
	else if (S_ISFIFO(st_mode))
		return ('p');
	return ('-');
}

char	*ft_fileperm(struct stat fstat)
{
	char	*str;

	str = malloc(sizeof(char) * 11);
	str[0] = ft_filetype(fstat.st_mode);
	str[1] = (fstat.st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (fstat.st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = (fstat.st_mode & S_IXUSR) ? 'x' : '-';
	str[4] = (fstat.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (fstat.st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = (fstat.st_mode & S_IXGRP) ? 'x' : '-';
	str[7] = (fstat.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (fstat.st_mode & S_IWOTH) ? 'w' : '-';
	str[9] = (fstat.st_mode & S_IXOTH) ? 'x' : '-';
	str[10] = '\0';
	return (str);
}

char	*ft_cname(char *name, char *c)
{
	char	*out;
	char	*tmp;

	if (c[0] == 'd')
		out = ft_strjoin("\e[1;36m", name);
	else if (c[0] == 'l')
		out = ft_strjoin("\e[0;35m", name);
	else if (c[0] == '-' && c[9] == 'x')
		out = ft_strjoin("\e[0;31m", name);
	else if (c[0] == 'c')
		out = ft_strjoin("\e[0;34;43m", name);
	else if (c[0] == 'b')
		out = ft_strjoin("\e[0;34;46m", name);
	else
		out = ft_strdup(name);
	tmp = out;
	out = ft_strjoin(out, "\e[0m");
	ft_strdel(&tmp);
	return (out);
}

t_file	*ft_fileinfo(const char *rep, char *name, t_opt *opt)
{
	struct group	*grp;
	struct passwd	*psw;
	struct stat		fstat;
	t_file			*info;
	char			*lnk;

	info = malloc(sizeof(t_file));
	info->rep = ft_strnew(ft_strlen(rep) + ft_strlen(name) + 1);
	info->rep = ft_strcat(info->rep, rep);
	info->rep = ft_strcat(info->rep, "/");
	info->rep = ft_strcat(info->rep, name);
	lstat(info->rep, &fstat);
	if (opt->l)
	{
		grp = getgrgid(fstat.st_gid);
		psw = getpwuid(fstat.st_uid);
		info->link = fstat.st_nlink;
		info->grp = psw == NULL ? ft_itoa(fstat.st_uid) : ft_strdup(psw->pw_name);
		info->usr = grp == NULL ? ft_itoa(fstat.st_gid) : ft_strdup(grp->gr_name);
		info->size = fstat.st_size;
		if (S_ISLNK(fstat.st_mode))
		{
			lnk = ft_strnew(PATH_MAX);
			readlink(info->rep, lnk, PATH_MAX);
			info->lnk = lnk;
		}
		else
			info->lnk = ft_strnew(0);
		info->dev = fstat.st_rdev;
	}
	info->perm = ft_fileperm(fstat);
	info->date = ft_strndup(ctime(&fstat.st_mtimespec.tv_sec) + 4, 12);
	info->cname = opt->ug ? ft_cname(name, info->perm) : ft_strdup(name);
	info->name = ft_strdup(name);
	opt->blck += fstat.st_blocks;
	return (info);
}

/*
msize = (msize < ft_countdigit(info->size) ?
ft_countdigit(info->size) : msize);
mlink = (mlink < ft_countdigit(info->link) ?
ft_countdigit(info->link) : mlink);
mgrp = (mgrp < (int)ft_strlen(info->grp) ? ft_strlen(info->grp) : mgrp);
musr = (musr < (int)ft_strlen(info->usr) ? ft_strlen(info->usr) : musr);
*/

void	ft_flagurhandler(t_list *begin, t_opt *opt)
{
	t_file	*info;
	char	*rep;
	char	*tmp;

	while (begin)
	{
		info = begin->content;
		if (info->perm[0] == 'd' &&
		(ft_strcmp(info->name, "\e[1;36m.\e[0m") != 0 &&
		ft_strcmp(info->name, "\e[1;36m..\e[0m") != 0) &&
		(ft_strcmp(info->name, ".") != 0 &&
		ft_strcmp(info->name, "..") != 0))
		{
			rep = ft_strjoin("\n", info->rep);
			tmp = rep;
			rep = ft_strjoin(rep, ":\n");
			ft_strdel(&tmp);
			write(1, rep, ft_strlen(rep));
			ft_strdel(&rep);
			ft_filereadder(info->rep, opt);
		}
		begin = begin->next;
	}
}

void	ft_infodel(void *ptr, size_t size, t_opt *opt)
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

void	ft_lstdelopt(t_list **alst, void (*del)(void *, size_t, t_opt *), t_opt *opt)
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

int		ft_printerror(const char *rep)
{
	write(1, "ft_ls: ", 8);
	if (ft_strchr(rep, '/'))
		write(1, ft_strrchr(rep, '/') + 1, ft_strlen(ft_strrchr(rep, '/') + 1));
	else
		write(1, rep, ft_strlen(rep));
	write(1, ": ", 2);
	write(1, strerror(errno), ft_strlen(strerror(errno)));
	write(1, "\n", 1);
	return (-1);
}

int		ft_filereadder(const char *rep, t_opt *opt)
{
	struct dirent	*file;
	t_list			*begin;
	t_file			*info;
	DIR				*dir;

	dir = opendir(rep);
	begin = NULL;
	if (dir == NULL)
		return (ft_printerror(rep));
	while ((file = readdir(dir)) != NULL)
	{
		if (opt->a == 0 && file->d_name[0] == '.')
			continue ;
		info = ft_fileinfo(rep, file->d_name, opt);
		if (begin == NULL)
			begin = ft_lstnew(info, sizeof(t_file));
		else
			ft_lstsortadd(&begin, ft_lstnew(info, sizeof(t_file)), opt);
		free(info);
	}
	closedir(dir);
	ft_print(begin, opt);
	opt->ur ? ft_flagurhandler(begin, opt) : 0;
	opt->blck = 0;
	ft_lstdelopt(&begin, ft_infodel, opt);
	return (1);
}
