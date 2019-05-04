/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 02:36:55 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/30 08:03:37 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*std_commands[NUM_STD] = {};
char	*md_commands[NUM_MD] = {"md5", "sha1", "sha224", "sha256", "sha384",\
	"sha512"};
char	*cph_commands[NUM_CPH] = {};

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
	while (cmd < NUM_MD)
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
	while (*av && (*av)[0] == '-' && !(*av)[2])
	{
		(*av)[1] == 'p' ? *flags |= F_P : 0;
		(*av)[1] == 'q' ? *flags |= F_Q : 0;
		(*av)[1] == 'r' ? *flags |= F_R : 0;
		(*av)[1] == 's' ? *flags |= F_S : 0;
		if ((*av)[1] < 'p' || (*av)[1] > 'r')
			break ;
		av++;
	}
	if ( *av && (*av)[1] == 's' && !(*av)[2])
		av++;
	return (av);
}

t_encf		*make_ftab(void)
{
	t_encf	*tab;
	int		i;

	tab = ft_memalloc(sizeof(*tab) * TOT_CMD);
	i = 0;
	tab[i++] = &ft_md5;
	tab[i++] = &ft_sha1;
	tab[i++] = &ft_sha224;
	tab[i++] = &ft_sha256;
	tab[i++] = &ft_sha384;
	tab[i++] = &ft_sha512;
	return (tab);
}

void		print_encrypt(char *to_encrypt, char *encrypted, int flags)
{
	if (flags & F_P)
		ft_printf("%s\n", to_encrypt);
	ft_printf("%s\n", encrypted);
}

int			main(int ac, char **av)
{
	int				cmd;
	unsigned char	flags;
	t_encf			*encryptors;

	if (ac == 1)
	{
		ft_putstr("usage: ft_ssl command [command opts] [command args]\n");
		return (0);
	}
	cmd = ft_findintabn(md_commands, av[1], TOT_CMD);
	if (cmd == -1)
		return (invalid_cmd(av[1]));
	encryptors = make_ftab();
	
	print_encrypt(*av, encryptors[cmd](*av, flags), flags);
	flags = 0;
	av = parse_flags(av + 2, &flags);
	while (*av)
	{
		//need flags in encryptors for string or file
		print_encrypt(*av, encryptors[cmd](*av, flags), flags);
		av++;
	}

	return (0);
}
