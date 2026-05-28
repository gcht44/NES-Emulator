/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ram.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 02:20:52 by gabch             #+#    #+#             */
/*   Updated: 2026/05/28 02:25:33 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ram.h"

static uint8_t ram[0x800];

uint8_t	read_ram(uint16_t addr)
{
	return (ram[addr]);
}

void	write_ram(uint16_t addr, uint8_t value)
{
	ram[addr] = value;
}