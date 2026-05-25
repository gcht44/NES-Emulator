/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:02:22 by gabch             #+#    #+#             */
/*   Updated: 2026/05/25 17:48:48 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

// A rajouter Overflow flag
void	adc(t_cpu *cpu, t_am am, uint8_t c)
{
	uint16_t a_tmp = cpu->a + am.value + c;
	cpu->sr |= DEFINE_CY(a_tmp);
	cpu->sr |= DEFINE_Z(a_tmp);
	cpu->sr |= DEFINE_N(a_tmp);
	cpu->a = a_tmp & 0xFF;
}

void	and(t_cpu *cpu, t_am am)
{
	uint16_t a_tmp = cpu->a & am.value;
	cpu->sr |= DEFINE_Z(a_tmp);
	cpu->sr |= DEFINE_N(a_tmp);
	cpu->a = a_tmp & 0xFF;
}

/*void	asl(t_cpu *cpu, uint8_t value)
{
	uint16_t tmp = value << ;
	cpu->sr |= DEFINE_Z(tmp);
	cpu->sr |= DEFINE_N(tmp);
	cpu->a = tmp & 0xFF;
}*/
