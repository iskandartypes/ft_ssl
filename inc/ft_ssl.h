/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 02:45:33 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/19 07:51:13 by ikourkji         ###   ########.fr       */
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
# define TOT_CMD	(NUM_STD + NUM_MD + NUM_CPH)

# define F_P 0x01
# define F_Q 0x02
# define F_R 0x04
# define F_S 0x08

/*
** the string they ret is the printable string
*/
typedef char	*(*t_encf)(char *to_encrypt, int flags);

char	*ft_md5(char *to_encrypt, int flags);
char	*ft_sha1(char *to_encrypt, int flags);
char	*ft_sha224(char *to_encrypt, int flags);
char	*ft_sha256(char *to_encrypt, int flags);
char	*ft_sha384(char *to_encrypt, int flags);
char	*ft_sha512(char *to_encrypt, int flags);

#endif
