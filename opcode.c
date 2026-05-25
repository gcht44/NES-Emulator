/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:02:22 by gabch             #+#    #+#             */
/*   Updated: 2026/05/25 18:20:11 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"
#include "bus.h"

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

void	asl(t_cpu *cpu, t_am am, int dest_is_mem)
{

	uint16_t tmp = am.value << 1;
	cpu->sr |= (tmp & 0x100) > 0;
	cpu->sr |= DEFINE_Z(tmp);
	cpu->sr |= DEFINE_N(tmp);
	if (dest_is_mem)
		write_bus(am.addr_return, tmp & 0xFF);
	else
		cpu->a = tmp & 0xFF;
}

void	bcc(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (!CY_FLAG(cpu->sr))
		cpu->pc += offset;
}

void	bcs(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (CY_FLAG(cpu->sr))
		cpu->pc += offset;
}

void	beq(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (Z_FLAG(cpu->sr))
		cpu->pc += offset;
}
// overflow pas implementer
void	bit(t_cpu *cpu, t_am am)
{
	uint8_t tmp = cpu->a & am.value;
	cpu->sr |= DEFINE_Z(tmp);
	cpu->sr |= DEFINE_N(tmp);
}

void	bmi(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (N_FLAG(cpu->sr))
		cpu->pc += offset;
}

void	bne(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (!Z_FLAG(cpu->sr))
		cpu->pc += offset;
}
