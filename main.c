/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:03:00 by gabch             #+#    #+#             */
/*   Updated: 2026/05/23 19:54:04 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rom.h"
#include "cpu.h"
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
	return (0);
}
