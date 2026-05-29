/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ram.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 02:20:52 by gabch             #+#    #+#             */
/*   Updated: 2026/05/29 02:40:56 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ram.h"

static uint8_t ram[0x800] = {0xFF};
static uint8_t external_ram[0x2000] = {0xFF};

uint8_t	read_ram(uint16_t addr)
{
	return (ram[addr]);
}

void	write_ram(uint16_t addr, uint8_t value)
{
	ram[addr] = value;
}

uint8_t	read_ext_ram(uint16_t addr)
{
	return (external_ram[addr - 0x6000]);
}

void	write_ext_ram(uint16_t addr, uint8_t value)
{
	external_ram[addr - 0x6000] = value;
}