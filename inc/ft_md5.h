/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:33:45 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/11 20:41:05 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** derived from the RSA Data Security, Inc. MD5 Message-Digest Algorithm
** half this header is directly from RFC 1321
** https://tools.ietf.org/html/rfc1321
*/

#ifndef FT_MD5_H
# define FT_MD5_H
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
