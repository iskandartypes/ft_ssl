/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:33:45 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/12 01:44:05 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** half this header is directly from RFC 1321
** https://tools.ietf.org/html/rfc1321
** ... and I'm reimplementing the algorithm in the software
** So, in accordance with its notice:
** Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All
** rights reserved.
** 
** License to copy and use this software is granted provided that it
** is identified as the "RSA Data Security, Inc. MD5 Message-Digest
** Algorithm" in all material mentioning or referencing this software
** or this function.
** 
** License is also granted to make and use derivative works provided
** that such works are identified as "derived from the RSA Data
** Security, Inc. MD5 Message-Digest Algorithm" in all material
** mentioning or referencing the derived work.
** 
** RSA Data Security, Inc. makes no representations concerning either
** the merchantability of this software or the suitability of this
** software for any particular purpose. It is provided "as is"
** without express or implied warranty of any kind.
** 
** These notices must be retained in any copies of any part of this
** documentation and/or software.
*/

#ifndef FT_MD5_H
# define FT_MD5_H

/*
** 2 and 4 refer to bytes
** fun fact: ints are actually the length of either shorts or longs in C
*/

typedef unsigned short	t_uint2;
typedef unsigned long	t_uint4;

/*
** state:	ABCD
** count:	# of bits, mod 2**64 (lsb first)
** buf:		input buf
*/

typedef struct		s_md5_ctx
{
	t_uint4			state[4];
	t_uint4			count[2];
	unsigned char	buf[64];
}					t_md5_ctx;

static unsigned char MD_PADDING[64] = {
  0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/*
** F, G, H and I are basic MD5 functions.
*/

# define MD_F(x, y, z) (((x) & (y)) | ((~x) & (z)))
# define MD_G(x, y, z) (((x) & (z)) | ((y) & (~z)))
# define MD_H(x, y, z) ((x) ^ (y) ^ (z))
# define MD_I(x, y, z) ((y) ^ ((x) | (~z)))

/*
** ROTATE_LEFT rotates x left n bits.
*/

# define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

#endif
