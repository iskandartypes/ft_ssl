/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 05:30:18 by ikourkji          #+#    #+#             */
/*   Updated: 2019/05/02 05:35:37 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** "is little endian": I know there's a whole "is" folder,
** but this is about bits dammit.
** tests machine bit storage.
** 1 = Little Endian, 2 = Big Endian
*/

int	ft_islend(void)
{
	short int	word;
	char		*b;

	word = 0x0001;
	b = (char*)&word;
	return (b[0] ? 1 : 0);
}
