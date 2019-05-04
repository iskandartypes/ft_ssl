/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapend32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 02:21:02 by ikourkji          #+#    #+#             */
/*   Updated: 2019/05/02 05:26:18 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** swaps endianness for 32-bit vals
*/

uint32_t	ft_swapend32(uint32_t n)
{
	uint32_t swapped;

	swapped = (n & 0x000000ff) << 24u;
	swapped |= (n & 0x0000ff00) << 8u;
	swapped |= (n & 0x00ff0000) >> 8u;
	swapped |= (n & 0xff000000) >> 24u;
	return (swapped);
}
