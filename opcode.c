/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:02:22 by gabch             #+#    #+#             */
/*   Updated: 2026/05/25 16:52:23 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

// A rajouter Overflow flag
void	adc(t_cpu *cpu, uint8_t value, uint8_t c)
{
	uint16_t a_tmp = cpu->a + value + c;
	cpu->sr |= DEFINE_CY(a_tmp);
	cpu->sr |= DEFINE_Z(a_tmp);
	cpu->sr |= DEFINE_N(a_tmp);
	cpu->a = a_tmp & 0xFF;
}

void	and(t_cpu *cpu, uint8_t value)
{
	uint16_t a_tmp = cpu->a & value;
	cpu->sr |= DEFINE_Z(a_tmp);
	cpu->sr |= DEFINE_N(a_tmp);
	cpu->a = a_tmp & 0xFF;
}
