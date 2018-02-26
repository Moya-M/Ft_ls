/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:16:22 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:16:23 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *pdst;
	unsigned char *psrc;

	if (n)
	{
		pdst = (unsigned char *)dst;
		psrc = (unsigned char *)src;
		if ((*pdst++ = *psrc++) == (unsigned char)c)
			return (pdst);
		while (--n != 0)
		{
			if ((*pdst++ = *psrc++) == (unsigned char)c)
				return (pdst);
		}
	}
	return (0);
}
