/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 02:36:55 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/12 04:08:58 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** pretty prints list of commands at an invalid command, returns 0 for main
*/

static int	invalid_cmd(char *inv)
{
	int cmd;

	ft_dprintf(2, "ft_ssl: Error: '%s' is an invalid command.\n", inv);
	ft_dprintf(2, "\nStandard commands:\n");
	ft_dprintf(2, "\nMessage Digest commands:\n");
	cmd = 0;
	while (md_commands[cmd])
	{
		ft_dprintf(2, "%-20s", md_commands[cmd++]);
		cmd != 1 && cmd % 4 == 0 ? ft_puterror("\n") : 0;
	}
	cmd % 4 == 0 ? 0 : ft_puterror("\n");
	ft_dprintf(2, "\nCipher commands:\n");
	return (0);
}

static char	**parse_flags(char **av, unsigned char *flags)
{
	while (*av && *av[0] == '-' && !(*av[2]))
	{
		*av[1] == 'p' ? flags | F_P : 0;
		*av[1] == 'q' ? flags | F_Q : 0;
		*av[1] == 'r' ? flags | F_R : 0;
		*av[1] == 's' ? flags | F_S : 0;
		if (*av[1] < 'p' || *av[1] > 's')
			break ;
		av++;
		if (*av[1] == 's')
			break ;
	}
	return (av);
}

//make ftab
//but should it be made here or static in header?
//probs here for easier adding of features huh
//yeah

int			main(int ac, char **av)
{
	int				cmd;
	unsigned char	flags;

	if (ac == 1)
	{
		ft_putstr("usage: ft_ssl command [command opts] [command args]\n");
		return (0);
	}
	cmd = ft_findintabn(md_commands, av[1], NUM_MD);
	if (cmd == -1)
		return (invalid_cmd(av[1]));
	flags = 0;
	av = parse_flags(av + 2, &flags);


	return (0);
}
