/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:20:53 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:20:53 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ne, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (hay[0] == '\0' && ne[0] == '\0')
		return ("\0");
	while (hay[i] != '\0' && ne[k] != '\0' && i != len)
	{
		if (hay[i] != ne[k])
		{
			k = 0;
			i = j++;
		}
		if (hay[i] == ne[k])
			k++;
		i++;
	}
	if (hay[i - k] == '\0')
		return (NULL);
	if (ft_strlen(ne) == k)
		return ((char *)hay + i - k);
	return (NULL);
}
