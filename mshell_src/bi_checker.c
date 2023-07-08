/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:29:58 by vgribkov          #+#    #+#             */
/*   Updated: 2023/07/08 17:30:04 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char **arr)
{
	int	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str1 - *str2 == 0)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

int	bi_avail(t_shell *shell)
{
	char **arr;
	
	arr = ft_split(shell -> token -> token, ' ');
	if (ft_strcmp("env", arr[0]) == 0 ||
		ft_strcmp("pwd", arr[0]) == 0 ||
		ft_strcmp("echo", arr[0]) == 0 ||
		ft_strcmp("cd", arr[0]) == 0 ||
		ft_strcmp("exit", arr[0]) == 0 ||
		ft_strcmp("export", arr[0]) == 0 ||
		ft_strcmp("unset", arr[0]) == 0 ||
		ft_strcmp("env ", arr[0]) == 0 ||
		ft_strcmp("pwd ", arr[0]) == 0 ||
		ft_strcmp("echo ", arr[0]) == 0 ||
		ft_strcmp("cd ", arr[0]) == 0 ||
		ft_strcmp("exit ", arr[0]) == 0 ||
		ft_strcmp("export ", arr[0]) == 0 ||
		ft_strcmp("unset ", arr[0]) == 0
		)
		{
			ft_free(arr);
			return (1);
		}
		ft_free(arr);
		return (0);
}