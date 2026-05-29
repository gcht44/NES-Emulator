/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:02:22 by gabch             #+#    #+#             */
/*   Updated: 2026/05/29 16:48:53 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"
#include "bus.h"
#include "stack.h"
#include <stdio.h>

void	overflow(t_cpu *cpu, t_am am, uint8_t result)
{
	cpu->flags.v |= ((result ^ cpu->a) & (result ^ am.value) & 0x80) << 6;
}

// OPCODE POUR PLUS TARD: BRK

void	adc(t_cpu *cpu, t_am am, uint8_t c)
{
	uint16_t a_tmp = cpu->a + am.value + c;
	cpu->flags.c = DEFINE_CY(a_tmp);
	cpu->flags.z = DEFINE_Z(a_tmp);
	cpu->flags.n = DEFINE_N(a_tmp);
	overflow(cpu, am, a_tmp);
	cpu->a = a_tmp & 0xFF;
}

void	and(t_cpu *cpu, t_am am)
{
	uint16_t a_tmp = cpu->a & am.value;
	cpu->flags.z = DEFINE_Z(a_tmp);
	cpu->flags.n = DEFINE_N(a_tmp);
	cpu->a = a_tmp & 0xFF;
}

void	asl(t_cpu *cpu, t_am am, int dest_is_mem)
{
	uint16_t tmp = am.value << 1;
	cpu->flags.c = (tmp & 0x100) > 0;
	cpu->flags.z = DEFINE_Z(tmp);
	cpu->flags.n = DEFINE_N(tmp);
	if (dest_is_mem)
		write_bus(am.addr_return, tmp & 0xFF);
	else
		cpu->a = tmp & 0xFF;
}

void	bcc(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (!cpu->flags.c)
		cpu->pc += offset;
}

void	bcs(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (cpu->flags.c)
		cpu->pc += offset;
}

void	beq(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (cpu->flags.z)
		cpu->pc += offset;
}

void	bit(t_cpu *cpu, t_am am)
{
	uint8_t tmp = cpu->a & am.value;
	cpu->flags.z = DEFINE_Z(tmp);
	cpu->flags.n = DEFINE_N(am.value);
	cpu->flags.v = (am.value & 0x40) > 0;
}

void	bmi(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (cpu->flags.n)
		cpu->pc += offset;
}

void	bne(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (!cpu->flags.z)
		cpu->pc += offset;
}

void	bpl(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (!cpu->flags.n)
		cpu->pc += offset;
}

void	bvc(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (!cpu->flags.v)
		cpu->pc += offset;
}

void	bvs(t_cpu *cpu)
{
	int8_t	offset = read_bus(cpu->pc++);
	if (cpu->flags.v)
		cpu->pc += offset;
}

void	clc(t_cpu *cpu)
{
	cpu->flags.c = 0;
}

void	cld(t_cpu *cpu)
{
	cpu->flags.d = 0;
}

void	clv(t_cpu *cpu)
{
	cpu->flags.v = 0;
}

void	cmp(t_cpu *cpu, t_am am)
{
	uint16_t a_tmp = cpu->a - am.value;
	cpu->flags.z = DEFINE_Z(a_tmp);
	cpu->flags.n = DEFINE_N(a_tmp);
	cpu->flags.c = cpu->a >= am.value;
}

void	cpx(t_cpu *cpu, t_am am)
{
	uint16_t tmp = cpu->x - am.value;
	cpu->flags.z = DEFINE_Z(tmp);
	cpu->flags.n = DEFINE_N(tmp);
	cpu->flags.c = cpu->x >= am.value;
}

void	cpy(t_cpu *cpu, t_am am)
{
	uint16_t tmp = cpu->y - am.value;
	cpu->flags.z = DEFINE_Z(tmp);
	cpu->flags.n = DEFINE_N(tmp);
	cpu->flags.c = cpu->y >= am.value;
}

void	dec(t_cpu *cpu, t_am am)
{
	uint8_t tmp = am.value - 1;
	cpu->flags.z = DEFINE_Z(tmp);
	cpu->flags.n = DEFINE_N(tmp);
	write_bus(am.addr_return, tmp);
}

void	dex(t_cpu *cpu)
{
	uint8_t tmp = cpu->x - 1;
	cpu->flags.z = DEFINE_Z(tmp);
	cpu->flags.n = DEFINE_N(tmp);
	cpu->x = tmp;
}

void	dey(t_cpu *cpu)
{
	uint8_t tmp = cpu->y - 1;
	cpu->flags.z = DEFINE_Z(tmp);
	cpu->flags.n = DEFINE_N(tmp);
	cpu->y = tmp;
}

void	eor(t_cpu *cpu, t_am am)
{
	uint16_t a_tmp = cpu->a ^ am.value;
	cpu->flags.z = DEFINE_Z(a_tmp);
	cpu->flags.n = DEFINE_N(a_tmp);
	cpu->a = a_tmp & 0xFF;
}

void	inc(t_cpu *cpu, t_am am)
{
	uint8_t tmp = am.value + 1;
	cpu->flags.z = DEFINE_Z(tmp);
	cpu->flags.n = DEFINE_N(tmp);
	write_bus(am.addr_return, tmp);
}

void	inx(t_cpu *cpu)
{
	uint8_t tmp = cpu->x + 1;
	cpu->flags.z = DEFINE_Z(tmp);
	cpu->flags.n = DEFINE_N(tmp);
	cpu->x = tmp;
}

void	iny(t_cpu *cpu)
{
	uint8_t tmp = cpu->y + 1;
	cpu->flags.z = DEFINE_Z(tmp);
	cpu->flags.n = DEFINE_N(tmp);
	cpu->y = tmp;
}

void	jmp(t_cpu *cpu, t_am am)
{
	cpu->pc = am.addr_return;
}

void	jsr(t_cpu *cpu, t_am am)
{
	push_stack(cpu, ((cpu->pc - 1) & 0xFF00) >> 8);
	push_stack(cpu, (cpu->pc - 1) & 0x00FF);
	cpu->pc = am.addr_return;
}

void	lda(t_cpu *cpu, t_am am)
{
	cpu->a = am.value;
	cpu->flags.z = DEFINE_Z(cpu->a);
	cpu->flags.n = DEFINE_N(cpu->a);
}

void	ldx(t_cpu *cpu, t_am am)
{
	cpu->x = am.value;
	cpu->flags.z = DEFINE_Z(cpu->x);
	cpu->flags.n = DEFINE_N(cpu->x);
}

void	ldy(t_cpu *cpu, t_am am)
{
	cpu->y = am.value;
	cpu->flags.z = DEFINE_Z(cpu->y);
	cpu->flags.n = DEFINE_N(cpu->y);
}

void	lsr(t_cpu *cpu, t_am am, int dest_is_mem)
{

	cpu->flags.c |= (am.value & 1);
	uint16_t tmp = am.value >> 1;
	cpu->flags.z = DEFINE_Z(tmp);
	cpu->flags.n = DEFINE_N(tmp);
	if (dest_is_mem)
		write_bus(am.addr_return, tmp & 0xFF);
	else
		cpu->a = tmp & 0xFF;
}

void	ora(t_cpu *cpu, t_am am)
{
	uint16_t a_tmp = cpu->a | am.value;
	cpu->flags.z = DEFINE_Z(a_tmp);
	cpu->flags.n = DEFINE_N(a_tmp);
	cpu->a = a_tmp & 0xFF;
}

void	pha(t_cpu *cpu)
{
	push_stack(cpu, cpu->a);
}

void	php(t_cpu *cpu)
{
	push_stack(cpu, get_sr(cpu->flags) | 0x30);
}

void	pla(t_cpu *cpu)
{
	cpu->a = pop_stack(cpu);
	cpu->flags.z = DEFINE_Z(cpu->a);
	cpu->flags.n = DEFINE_N(cpu->a);
}

void	plp(t_cpu *cpu)
{
	uint8_t tmp = pop_stack(cpu);
	cpu->flags.c = tmp & 1;
	cpu->flags.z = (tmp >> 1) & 1;
	cpu->flags.i = (tmp >> 2) & 1;
	cpu->flags.d = (tmp >> 3) & 1;
	// cpu->flags.b = (tmp >> 1) & 4;
	cpu->flags.v = (tmp >> 6) & 1;
	cpu->flags.n = (tmp >> 7) & 1;
}

void	rol(t_cpu *cpu, t_am am, int dest_is_mem)
{
	uint8_t		old_cy = cpu->flags.c;
	uint16_t	tmp = am.value << 1;
	tmp |= old_cy;
	cpu->flags.c |= (tmp & 0x100) > 0;
	cpu->flags.z = DEFINE_Z(tmp);
	cpu->flags.n = DEFINE_N(tmp);
	if (dest_is_mem)
		write_bus(am.addr_return, tmp & 0xFF);
	else
		cpu->a = tmp & 0xFF;
}

void	ror(t_cpu *cpu, t_am am, int dest_is_mem)
{
	uint8_t		new_cy = am.value & 1;
	uint16_t	tmp = am.value >> 1;
	tmp |= (cpu->flags.c << 7);
	cpu->flags.c |= new_cy;
	cpu->flags.z = DEFINE_Z(tmp);
	cpu->flags.n = DEFINE_N(tmp);
	if (dest_is_mem)
		write_bus(am.addr_return, tmp & 0xFF);
	else
		cpu->a = tmp & 0xFF;
}
void	rti(t_cpu *cpu)
{
	uint8_t tmp = pop_stack(cpu);
	cpu->flags.c = tmp & 1;
	cpu->flags.z = (tmp >> 1) & 1;
	cpu->flags.i = (tmp >> 1) & 2;
	cpu->flags.d = (tmp >> 1) & 3;
	cpu->flags.v = (tmp >> 1) & 6;
	cpu->flags.n = (tmp >> 1) & 7;
	cpu->pc = (pop_stack(cpu) | (pop_stack(cpu) >> 4)) + 1;
}

void	rts(t_cpu *cpu)
{
	// uint8_t lo = pop_stack(cpu);
	//uint8_t ho = pop_stack(cpu);
	// printf("lo:%02X, ho:%02X, addr:%04X\n", lo, ho, (ho << 8) | lo);
	cpu->pc = ((uint16_t)pop_stack(cpu) | ((uint16_t)pop_stack(cpu) << 8)) + 1;
}

void	sbc(t_cpu *cpu, t_am am, uint8_t c)
{
	uint16_t a_tmp = cpu->a - am.value - ~c;
	cpu->flags.c = !((int16_t)a_tmp < 0x00);
	cpu->flags.z = DEFINE_Z(a_tmp);
	cpu->flags.n = DEFINE_N(a_tmp);
	cpu->flags.v = ((a_tmp ^ cpu->a) & (a_tmp ^ ~am.value) & 0x80);
	cpu->a = a_tmp & 0xFF;
}

void	sec(t_cpu *cpu)
{
	cpu->flags.c = 1;
}

void	sed(t_cpu *cpu)
{
	cpu->flags.d = 1;
}

void	sei(t_cpu *cpu)
{
	cpu->flags.i = 1;
}

void	sta(t_cpu *cpu, t_am am)
{
	write_bus(am.addr_return, cpu->a);
}

void	stx(t_cpu *cpu, t_am am)
{
	write_bus(am.addr_return, cpu->x);
}

void	sty(t_cpu *cpu, t_am am)
{
	write_bus(am.addr_return, cpu->y);
}

void	tax(t_cpu *cpu)
{
	cpu->x = cpu->a;
}

void	tay(t_cpu *cpu)
{
	cpu->y = cpu->a;
}

void	tsx(t_cpu *cpu)
{
	cpu->x = cpu->sp;
}

void	txa(t_cpu *cpu)
{
	cpu->a = cpu->x;
}

void	txs(t_cpu *cpu)
{
	cpu->sp = cpu->x;
}

void	tya(t_cpu *cpu)
{
	cpu->a = cpu->y;
}
