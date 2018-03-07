/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 17:13:13 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:03:34 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/syslimits.h>
# include <sys/stat.h>
# include "../libft/libft.h"

/*
**	FLAG_STRUCT
*/

typedef struct	s_opt {
	int			ur;
	int			r;
	int			l;
	int			a;
	int			ug;
	int			t;
	int			j;
	int			max;
	blkcnt_t	blck;
	int			dir;
}				t_opt;

/*
**	FILE_INFO
*/

typedef	struct	s_file {
	char		*perm;
	int			link;
	char		*grp;
	char		*usr;
	off_t		size;
	char		*date;
	char		*name;
	char		*cname;
	char		*lnk;
	char		*rep;
	int			dev;
	long		stamp;
}				t_file;

/*
**	FUNCTION
*/

t_file			*ft_fileinfo(const char *rep, char *name, t_opt *opt);
char			*ft_lltoa(off_t l);
int				file_reader(const char *rep, t_opt *opt);
char			*ft_cname(char *name, char *c);
char			*ft_filedate(__darwin_time_t ftime);
void			ft_putll(long long l);
void			ft_print(t_list *begin, t_opt *opt);
void			ft_lstsortadd(t_list **begin, t_list *new, t_opt *opt);
void			ft_infodel(void *ptr, size_t size, t_opt *opt);
void			ft_lstd(t_list **alst,
	void (*del)(void *, size_t, t_opt *), t_opt *opt);

#endif
