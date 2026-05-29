/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:03:00 by gabch             #+#    #+#             */
/*   Updated: 2026/05/29 03:08:32 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: MAPPER 002

#include "rom.h"
#include "bus.h"
#include "cpu.h"
#include "opcode.h"
#include "blaarg.h"
#include <stdio.h>

int	main(void)
{
	t_cpu	cpu;

	if (init_memory_rom("ROMS/test_roms/cpu_instr/01-basics.nes"))
	{
		printf("Initialisation de la memoire ROM: ERR\n");
		return (0);
	}
	printf("Initialisation de la memoire ROM: OK\n");
	init_cpu(&cpu);
	while (1)
	{
		handle_status();
		printf("PC:%04X (%02X,%02X,%02X) -> %c%c%c%c%c%c%c A:%02X X:%02X Y:%02X SP:%02X\n",
		cpu.pc, read_bus(cpu.pc),  read_bus(cpu.pc + 1),  read_bus(cpu.pc + 2), cpu.flags.n ? 'N' : '-', cpu.flags.v ? 'V' : '-',
		cpu.flags.b ? 'B' : '-', cpu.flags.d ? 'D' : '-', cpu.flags.i ? 'I' : '-',
		cpu.flags.z ? 'Z' : '-', cpu.flags.c ? 'C' : '-', cpu.a, cpu.x, cpu.y, cpu.sp);
		exec_opcode(&cpu);
	}
	return (0);
}
