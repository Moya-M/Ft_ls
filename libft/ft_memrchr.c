/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:16:47 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:16:53 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(const void *dst, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptd;

	ptd = (unsigned char *)dst;
	i = n;
	while (i != 0)
	{
		if (ptd[i] == (unsigned char)c)
			return (&ptd[i]);
		i--;
	}
	if (ptd[0] == (unsigned char)c)
		return (&ptd[0]);
	return (NULL);
}
