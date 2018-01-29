/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:19:03 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:19:08 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	char		*d;
	const char	*s;
	size_t		size;
	size_t		dlen;

	d = s1;
	s = s2;
	size = n;
	while (size-- != 0 && *d != '\0')
		d++;
	dlen = d - s1;
	size = n - dlen;
	if (size == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (size != 1)
		{
			*d++ = *s;
			size--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - s2));
}
