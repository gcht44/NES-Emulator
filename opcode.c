/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:02:22 by gabch             #+#    #+#             */
/*   Updated: 2026/05/25 20:34:39 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"
#include "bus.h"
#include "stack.h"

// OPCODE POUR PLUS TARD: BRK

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

void	bpl(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (!N_FLAG(cpu->sr))
		cpu->pc += offset;
}

void	bvc(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (!O_FLAG(cpu->sr))
		cpu->pc += offset;
}

void	bvs(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (O_FLAG(cpu->sr))
		cpu->pc += offset;
}

void	clc(t_cpu *cpu)
{
	cpu->sr &= 0xFE;
}

void	cld(t_cpu *cpu)
{
	cpu->sr &= 0xF7;
}

void	clv(t_cpu *cpu)
{
	cpu->sr &= 0xBF;
}

void	cmp(t_cpu *cpu, t_am am)
{
	uint16_t a_tmp = cpu->a - am.value;
	cpu->sr |= DEFINE_Z(a_tmp);
	cpu->sr |= DEFINE_N(a_tmp);
	cpu->sr |= cpu->a >= am.value;
}

void	cpx(t_cpu *cpu, t_am am)
{
	uint16_t tmp = cpu->x - am.value;
	cpu->sr |= DEFINE_Z(tmp);
	cpu->sr |= DEFINE_N(tmp);
	cpu->sr |= cpu->x >= am.value;
}

void	cpy(t_cpu *cpu, t_am am)
{
	uint16_t tmp = cpu->y - am.value;
	cpu->sr |= DEFINE_Z(tmp);
	cpu->sr |= DEFINE_N(tmp);
	cpu->sr |= cpu->y >= am.value;
}

void	dec(t_cpu *cpu, t_am am)
{
	uint8_t tmp = am.value - 1;
	cpu->sr |= DEFINE_Z(tmp);
	cpu->sr |= DEFINE_N(tmp);
	write_bus(am.addr_return, tmp);
}

void	dex(t_cpu *cpu)
{
	uint8_t tmp = cpu->x - 1;
	cpu->sr |= DEFINE_Z(tmp);
	cpu->sr |= DEFINE_N(tmp);
	cpu->x = tmp;
}

void	dey(t_cpu *cpu)
{
	uint8_t tmp = cpu->y - 1;
	cpu->sr |= DEFINE_Z(tmp);
	cpu->sr |= DEFINE_N(tmp);
	cpu->y = tmp;
}

void	eor(t_cpu *cpu, t_am am)
{
	uint16_t a_tmp = cpu->a ^ am.value;
	cpu->sr |= DEFINE_Z(a_tmp);
	cpu->sr |= DEFINE_N(a_tmp);
	cpu->a = a_tmp & 0xFF;
}

void	inc(t_cpu *cpu, t_am am)
{
	uint8_t tmp = am.value + 1;
	cpu->sr |= DEFINE_Z(tmp);
	cpu->sr |= DEFINE_N(tmp);
	write_bus(am.addr_return, tmp);
}

void	inx(t_cpu *cpu)
{
	uint8_t tmp = cpu->x + 1;
	cpu->sr |= DEFINE_Z(tmp);
	cpu->sr |= DEFINE_N(tmp);
	cpu->x = tmp;
}

void	iny(t_cpu *cpu)
{
	uint8_t tmp = cpu->y + 1;
	cpu->sr |= DEFINE_Z(tmp);
	cpu->sr |= DEFINE_N(tmp);
	cpu->y = tmp;
}

void	jmp(t_cpu *cpu, t_am am)
{
	cpu->pc = am.addr_return;
}

void	jsr(t_cpu *cpu, t_am am)
{
	push_stack(cpu, (cpu->pc & 0xFF00) >> 8);
	push_stack(cpu, cpu->pc & 0x00FF);
	cpu->pc = am.addr_return;
}

void	lda(t_cpu *cpu, t_am am)
{
	cpu->a = am.value;
	cpu->sr |= DEFINE_Z(cpu->a);
	cpu->sr |= DEFINE_N(cpu->a);
}

void	ldx(t_cpu *cpu, t_am am)
{
	cpu->x = am.value;
	cpu->sr |= DEFINE_Z(cpu->x);
	cpu->sr |= DEFINE_N(cpu->x);
}

void	ldy(t_cpu *cpu, t_am am)
{
	cpu->y = am.value;
	cpu->sr |= DEFINE_Z(cpu->y);
	cpu->sr |= DEFINE_N(cpu->y);
}

void	lsr(t_cpu *cpu, t_am am, int dest_is_mem)
{

	cpu->sr |= (am.value & 1);
	uint16_t tmp = am.value >> 1;
	cpu->sr |= DEFINE_Z(tmp);
	cpu->sr |= DEFINE_N(tmp);
	if (dest_is_mem)
		write_bus(am.addr_return, tmp & 0xFF);
	else
		cpu->a = tmp & 0xFF;
}
