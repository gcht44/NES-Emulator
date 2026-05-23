/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:03:00 by gabch             #+#    #+#             */
/*   Updated: 2026/05/22 16:43:18 by gchalmel         ###   ########.fr       */
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
		printf("Initialisation de la memoire ROM: ERR");
		return (0);
	}
	printf("Initialisation de la memoire ROM: OK");
	init_cpu(&cpu);
	return (0);
}
