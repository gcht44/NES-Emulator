/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:08:08 by gabch             #+#    #+#             */
/*   Updated: 2026/05/28 01:39:50 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"
#include <stdio.h>

uint8_t	get_sr(t_flags flags)
{
	return ((flags.n << 7) | (flags.v << 6) | (1 << 5) | (flags.b << 4) | (flags.d << 3) | (flags.i << 2) | (flags.z << 1) | flags.c);
}

void	init_cpu(t_cpu *cpu)
{
	cpu->a = 0;
	cpu->pc = 0xFFFC;
	cpu->sp = 0xFD;
	cpu->flags.i = 1;
	cpu->flags.c = 0;
	cpu->flags.z = 0;
	cpu->flags.d = 0;
	cpu->flags.b = 0;
	cpu->flags.v = 0;
	cpu->flags.n = 0;
	cpu->x = 0;
	cpu->y = 0;
	printf("Initialisation du cpu; A:%02X, PC:%02X, SP:%02X, SR:%02X, X:%02X, Y:%02X\n", cpu->a, cpu->pc, cpu->sp, get_sr(cpu->flags), cpu->x, cpu->y);
}