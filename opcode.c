/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:02:22 by gabch             #+#    #+#             */
/*   Updated: 2026/05/25 16:49:35 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

// A rajouter Overflow flag
void	adc(t_cpu *cpu, uint8_t value, uint8_t c)
{
	cpu->a += value + c;
	cpu->sr |= DEFINE_CY(cpu->a);
	cpu->sr |= DEFINE_Z(cpu->a);
	cpu->sr |= DEFINE_N(cpu->a);
}
