/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadiaman <yadiaman@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:28:37 by yadiaman          #+#    #+#             */
/*   Updated: 2024/05/24 13:43:18 by yadiaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char *s, char c)
{
	size_t	count;
	size_t	i;

	if (!s)
		return (0);
	if (!ft_strlen(s))
		return (0);
	i = 0;
	count = s[i] != c;
	while (s[i])
	{
		count += (s[i] == c && s[i + 1] != c && s[i + 1] != '\0');
		i++;
	}
	return (count);
}

static int	ft_next_worlen(char const *s, int i, char c)
{
	int	count;

	count = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == '\0')
			return (count);
		i++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	tab_index;
	size_t	end;
	char	**tab;

	tab = ft_calloc(ft_wordcount((char *)s, c) + 1, sizeof(char *));
	if (!tab || !s)
		return (NULL);
	i = 0;
	tab_index = 0;
	while (tab_index < ft_wordcount((char *)s, c))
	{
		while (s[i] == c)
			i++;
		end = ft_next_worlen(s, i, c);
		tab[tab_index] = ft_substr(s, i, end);
		i += end;
		tab_index++;
		i++;
	}
	return (tab);
}
