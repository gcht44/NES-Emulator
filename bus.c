/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bus.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 22:02:53 by gabch             #+#    #+#             */
/*   Updated: 2026/05/29 03:17:07 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bus.h"
#include "rom.h"
#include "ram.h"
#include <stdlib.h>
#include <stdio.h>

void	write_bus(uint16_t addr, uint8_t data)
{
	(void)data;
	if (addr < 0x0800) // 2KB internal RAM
		write_ram(addr, data);
	else if (addr < 0x2000) // Mirror of 0x0000 0x07FF
	{
		printf("BUS (write): %04X not implemented\n", addr);
		return ;
	}
	else if (addr < 0x2008) // NES PPU registers
	{
		printf("BUS (write): %04X not implemented\n", addr);
		return ;
	}
	else if (addr < 0x4000) // Mirrors of $2000–$2007 (repeats every 8 bytes)
	{
		printf("BUS (write): %04X not implemented\n", addr);
		return ;
	}
	else if (addr < 0x4018) // NES APU and I/O registers
	{
		printf("BUS (write): %04X not implemented\n", addr);
		return ;
	}
	else if (addr < 0x4020) // APU and I/O functionality that is normally disabled. See CPU Test Mode
	{
		printf("BUS (write): %04X not implemented\n", addr);
		return ;
	}
	else if (addr < 0x6000) // idk
	{
		printf("BUS (write): %04X not implemented\n", addr);
		return ;
	}
	else if (addr < 0x8000) // RAM
		write_ext_ram(addr, data);
	else // ROM with mappers register
	{
		printf("BUS (write): %04X cant write ROM\n", addr);
	}
}

uint8_t	read_bus(uint16_t addr)
{
	if (addr < 0x0800) // 2KB internal RAM
		return (read_ram(addr));
	else if (addr < 0x2000) // Mirror of 0x0000 0x07FF
	{
		printf("BUS (write): %04X not implemented\n", addr);
		return (0);
	}
	else if (addr < 0x2008) // NES PPU registers
	{
		printf("BUS (write): %04X not implemented\n", addr);
		return (0);
	}
	else if (addr < 0x4000) // Mirrors of $2000–$2007 (repeats every 8 bytes)
	{
		printf("BUS (write): %04X not implemented\n", addr);
		return (0);
	}
	else if (addr < 0x4018) // NES APU and I/O registers
	{
		printf("BUS (write): %04X not implemented\n", addr);
		return (0);
	}
	else if (addr < 0x4020) // APU and I/O functionality that is normally disabled. See CPU Test Mode
	{
		printf("BUS (write): %04X not implemented\n", addr);
		return (0);
	}
	else if (addr < 0x6000) // Expansion / mappers
	{
		printf("BUS (write): %04X not implemented\n", addr);
		return (0);
	}
	else if (addr < 0x8000) // SRAM de la cartouche (sauvegardes)
		return (read_ext_ram(addr));
	else
		return (read_rom(addr));
}
