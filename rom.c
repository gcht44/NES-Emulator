/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rom.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:13:42 by gabch             #+#    #+#             */
/*   Updated: 2026/02/23 20:17:15 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rom.h"
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static uint8_t	*g_rom_mem;

int	init_memory_rom(const char *name)
{
	FILE	*fp;
	long	len_rom;

	fp = fopen(name, "rb");
	if (fp == NULL)
	{
		printf("ERR (INIT ROM): No such file or directory (%s)\n", name);
		return (EXIT_FAILURE);
	}
	fseek(fp, 0, SEEK_END);
	len_rom = ftell(fp);
	rewind(fp);
	g_rom_mem = malloc(len_rom);
	if (fread(g_rom_mem, 1, len_rom, fp) != (size_t)len_rom)
	{
		printf("ERR (INIT ROM): Survenue lors de la lecture de la rom\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

uint8_t	read_rom(uint16_t addr)
{
	return (g_rom_mem[addr - 0x8000]);
}
