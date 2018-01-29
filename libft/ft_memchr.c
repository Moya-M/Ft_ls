/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:16:25 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:16:28 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dst, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptd;

	i = 0;
	ptd = (unsigned char *)dst;
	while (i != n)
	{
		if (ptd[i] == (unsigned char)c)
			return (&ptd[i]);
		i++;
	}
	return (NULL);
}
