/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rom.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:13:42 by gabch             #+#    #+#             */
/*   Updated: 2026/05/29 13:36:46 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rom.h"
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static uint8_t	*g_rom_mem = NULL;
static uint8_t	prg_rom[32768] = {0};

// Mapper 1 for blaarg ne pas merge ca car pas du tout implementer completement
int	init_memory_rom(const char *name)
{
	FILE	*fp;
	long	len_rom;

	printf("Initialisation de la memoire ROM\n");
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
	printf("ROM SIZE: %ldKb\n", len_rom / 1000);
	if (fread(g_rom_mem, 1, len_rom, fp) != (size_t)len_rom)
	{
		printf("ERR (INIT ROM): Survenue lors de la lecture de la rom\n");
		return (EXIT_FAILURE);
	}
	if (g_rom_mem[0x04] == 1)
	{
		for (int i=0; i < 16384 ; i++)
			prg_rom[i] = g_rom_mem[0x10 + i];
	}
	else
	{
		for (int i=0; i < 32768 ; i++)
			prg_rom[i] = g_rom_mem[0x10 + i];
	}
	return (EXIT_SUCCESS);
}

uint8_t	read_rom(uint16_t addr)
{
	if ((addr - 0x8000) >= 0x4000)
		addr -= 0x4000;
	return (prg_rom[addr - 0x8000]);
}
