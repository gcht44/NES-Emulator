/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:08:08 by gabch             #+#    #+#             */
/*   Updated: 2026/05/22 16:43:24 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"
#include <stdio.h>

void	init_cpu(t_cpu *cpu)
{
	cpu->a = 0;
	cpu->pc = 0;
	cpu->sp = 0x0100;
	cpu->sr = 0x20;
	cpu->x = 0;
	cpu->y = 0;
	printf("Initialisation du cpu; A:%02X, PC:%02X, SP:%02X, SR:%02X, X:%02X, Y:%02X", cpu->a, cpu->pc, cpu->sp, cpu->sr, cpu->x, cpu->y);
}
