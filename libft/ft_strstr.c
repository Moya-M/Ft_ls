/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:20:55 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:20:55 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char *)&haystack[i]);
	while (haystack[i] != '\0' && needle[k] != '\0')
	{
		if (haystack[i] != needle[k])
		{
			i = j++ - 1;
			k = 0;
		}
		if (haystack[i] == needle[k])
			k++;
		i++;
	}
	if (haystack[i - k] == '\0')
		return (NULL);
	if (ft_strlen(needle) == k)
		return ((char *)haystack + i - k);
	return (NULL);
}
