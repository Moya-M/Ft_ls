/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 17:13:13 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 16:50:54 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

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
# include "libft.h"

typedef struct	s_opt {
	int			ur;
	int			r;
	int			l;
	int			a;
	int			ug;
	int			t;
	int			j;
	blkcnt_t	blck;
}				t_opt;

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
}				t_file;

int		ft_filereadder(const char *rep, t_opt *opt);
void	ft_print(t_list *begin, t_opt *opt);
#endif
