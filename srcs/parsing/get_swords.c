/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_swords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:27:19 by raydogmu          #+#    #+#             */
/*   Updated: 2025/08/23 14:54:27 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_words(char **words)
{
	int	n;

	n = 0;
	if (!words)
		return (0);
	while (words[n])
		n++;
	return (n);
}

static char	**get_words(char **words, char *word)
{
	int		old_count;
	char	**new_words;
	int		i;

	old_count = count_words(words);
	new_words = malloc(sizeof(char *) * (old_count + 2));
	if (!new_words)
		return (NULL);
	i = 0;
	while (i < old_count)
	{
		new_words[i] = ft_strdup(words[i]);
		i++;
	}
	new_words[i] = ft_strdup(word);
	new_words[i + 1] = NULL;
	if (words)
		free_all(words);
	return (new_words);
}

char	**get_swords(char **words, char *word)
{
	char	**result;
	int		i;
	int		word_num;

	i = 0;
	word_num = count_words(words) + 1;
	result = get_words(words, word);
	if (!result)
		return (NULL);
	while (i < word_num)
	{
		if (!result[i])
		{
			free_all(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}
