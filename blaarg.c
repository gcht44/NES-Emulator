/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blaarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 02:36:02 by gabch             #+#    #+#             */
/*   Updated: 2026/05/28 02:51:27 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/blaarg.h"
#include "includes/bus.h"

#include <unistd.h>

void	handle_status(t_cpu *cpu)
{
	uint8_t status = (0x6000);

	if (status == 0x81)
		cpu->pc = (read_bus(0xFFFD) << 8) || read_bus(0xFFFC);
	else if ((status >= 0) && (status <= 0x7F))
	{
		uint16_t addr = 0x6004;
		uint8_t c = read_bus(addr);
		while (c != 0)
		{
			printf("%c", (char)c);
			addr++;
			c = read_bus(addr);
		}
	}
}