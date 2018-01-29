/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:19:01 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:19:02 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	ss1;
	size_t	ss2;

	if (!s1 || !s2)
		return (NULL);
	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	if (!(str = malloc(ss1 + ss2 + 1)))
		return (NULL);
	ft_strcpy(str, (char *)s1);
	ft_strcpy(str + ss1, (char *)s2);
	return (str);
}
