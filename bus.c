/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bus.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 22:02:53 by gabch             #+#    #+#             */
/*   Updated: 2026/02/23 20:10:21 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bus.h"
#include <stdlib.h>

void	write_bus(uint16_t addr, uint8_t data)
{
	if (addr < 0x0800) // 2KB internal RAM
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	else if (addr < 0x2000) // Mirror of 0x0000 0x07FF
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	else if (addr < 0x2008) // NES PPU registers
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	else if (addr < 0x4000) // Mirrors of $2000–$2007 (repeats every 8 bytes) 
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	else if (addr < 0x4018) // NES APU and I/O registers
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	else if (addr < 0x4020) // NES APU and I/O registers
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	else if (addr < 0x8000) // idk
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	else if (addr < 0x8000) // idk
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	if (addr <= 0xFFFF)
	{
		
	}
}

uint8_t	read_bus(uint16_t addr)
{
	if (addr < 0x0800) // 2KB internal RAM
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	else if (addr < 0x2000) // Mirror of 0x0000 0x07FF
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	else if (addr < 0x2008) // NES PPU registers
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	else if (addr < 0x4000) // Mirrors of $2000–$2007 (repeats every 8 bytes) 
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	else if (addr < 0x4018) // NES APU and I/O registers
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	else if (addr < 0x4020) // NES APU and I/O registers
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	else if (addr < 0x8000) // idk
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	else if (addr < 0x8000) // idk
	{
		printf("BUS (write): %04X not implemented\n", addr);
		exit(EXIT_FAILURE);
	}
	if (addr <= 0xFFFF)
	{
		
	}
}
