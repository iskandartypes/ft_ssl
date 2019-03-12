/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 02:45:33 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/12 03:58:25 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

# define NUM_STD	0
# define NUM_MD		6
# define NUM_CPH	0

char	*std_commands[NUM_STD] = {};
char	*md_commands[NUM_MD] = {"md5", "sha1", "sha224", "sha256", "sha384",\
	"sha512"};
char	*cph_commands[NUM_CPH] = {};

# define F_P 0x01
# define F_Q 0x02
# define F_R 0x04
# define F_S 0x08

//need a function ptr for char functs 
//char *any_funct(char *arg (from av, file or string), unsigned char flags)
//the string they ret is the printable string
#endif
