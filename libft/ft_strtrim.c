/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:20:56 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:20:56 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	count_blank(char *s, int i, int rev)
{
	int j;

	j = 0;
	if (rev == 0)
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
	if (rev == 1)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i--;
			j++;
		}
		return (j);
	}
	return (i);
}

static char	*handle_str(int len, int i, const char *s)
{
	char *str;

	if (len == 0)
	{
		if (!(str = ft_strnew(sizeof(s))))
			return (NULL);
		str = ft_strcpy(str, (char *)s);
	}
	if (len == i)
		if (!(str = ft_strnew(0)))
			return (NULL);
	return (str);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*str;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	i = count_blank((char *)s, 0, 0);
	len = ft_strlen(s);
	if (len == 0 || len == i)
		return (str = handle_str(len, i, s));
	j = len - 1;
	k = count_blank((char *)s, j, 1);
	if (!(str = ft_strnew(len - i - k)))
		return (NULL);
	j = 0;
	while (s[i + k] != '\0')
		str[j++] = s[i++];
	return (str);
}
