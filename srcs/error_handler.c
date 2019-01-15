/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:04:59 by hbally            #+#    #+#             */
/*   Updated: 2019/01/15 18:04:35 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t				str_error_handler(char *string, char *arg, int8_t status)
{
	if (string)
		ft_printf("\nft_ls%s%s: %s\n", arg ? ": " : "", arg, string); //FIX FORMAT
	return (status);
}

int8_t				error_handler(char *arg, int8_t status)
{
	ft_printf("ft_ls%s%s: ", arg ? ": " : "", arg);
	perror(NULL);

	return (status);
}
