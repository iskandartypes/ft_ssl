/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 02:45:33 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/11 20:41:56 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

# include "ft_md5.h"

# define NUM_MD 6

char *md_commands[NUM_MD] = {"md5", "sha1", "sha224", "sha256", "sha384",\
	"sha512"};

#endif
