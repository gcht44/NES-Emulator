/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blaarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 02:36:02 by gabch             #+#    #+#             */
/*   Updated: 2026/05/28 03:14:22 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/blaarg.h"
#include "includes/bus.h"

#include <stdlib.h>
#include <stdio.h>

void	handle_status(void)
{
	uint8_t status = read_bus(0x6000);
	if (status <= 0x7F)
	{
		uint16_t addr = 0x6004;
		uint8_t c = read_bus(addr);
		while (c != 0)
		{
			printf("%c", (char)c);
			addr++;
			c = read_bus(addr);
		}
		exit(1);
	}
}