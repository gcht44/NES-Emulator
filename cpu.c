/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:08:08 by gabch             #+#    #+#             */
/*   Updated: 2026/05/23 19:53:50 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"
#include <stdio.h>

void	init_cpu(t_cpu *cpu)
{
	cpu->a = 0;
	cpu->pc = 0xFFFC;
	cpu->sp = 0x00FD;
	cpu->sr = 0b00100100;
	cpu->x = 0;
	cpu->y = 0;
	printf("Initialisation du cpu; A:%02X, PC:%02X, SP:%02X, SR:%02X, X:%02X, Y:%02X\n", cpu->a, cpu->pc, cpu->sp, cpu->sr, cpu->x, cpu->y);
}