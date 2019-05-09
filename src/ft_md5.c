/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 04:15:06 by ikourkji          #+#    #+#             */
/*   Updated: 2019/05/04 10:25:20 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_md5.h"

const t_uint4	g_md5keys[64] =
{
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

const t_uint4		g_md5const[16] =
{ 7, 12, 17, 22, 5, 9, 14, 20, 4, 11, 16, 23, 6, 10, 15, 21 };

/*
** what I've called "final" above ought to contain all of the 
** original message, chunked (see x in "Decode" in og)
*/

/*
** Load magic initialization constants.
** ^ that's literally the original comment in RFC 1321 sweet jesus
*/
void	md5init(t_md5_ctx *ctx)
{
	ctx->chunk[0] = 0x67452301;
	ctx->chunk[1] = 0xefcdab89;
	ctx->chunk[2] = 0x98badcfe;
	ctx->chunk[3] = 0x10325476;
	ctx->count[0] = 0;
	ctx->count[1] = 0;
}

/*
** let's be honest I have no idea what this does

void	md5update(t_md5_ctx *ctx, unsigned char *input, unsigned int inlen)
{
	unsigned int	i;
	unsigned int	index;
	unsigned int	partlen;

	//get numbytes %64
	index = (unsigned int)((ctx->chunk[0] >> 3) & 0x3f); //&0x3f == %64
	if ((ctx->chunk[0] += ((t_uint4)inlen << 3)) < ((t_uint4)inlen << 3))
		ctx->chunk[1]++;
	ctx->chunk[1] += ((t_uint4)inlen >> 29);
	partlen = 64 - index;
	if (inlen >= partlen)
	{
		
	}
}

*/

char	*ft_md5(char *to_encrypt, int flags)
{
	return (to_encrypt);
}
