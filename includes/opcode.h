/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:00:44 by gabch             #+#    #+#             */
/*   Updated: 2026/05/30 16:23:12 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPCODE_H
# define OPCODE_H

# include <stdint.h>
# include "cpu.h"

typedef struct s_am
{
	uint16_t	addr_return;
	uint8_t		value;
} t_am;

# define DEFINE_CY(value) value > 0xFF ? 1 : 0
# define DEFINE_Z(value) (value == 0x00 ? 1 : 0)
# define DEFINE_N(value) ((value & 0x80) > 0x00 ? 1 : 0)

void	exec_opcode(t_cpu *cpu);

// ADDRESSING MODE
t_am	immediate(t_cpu *cpu);
t_am	zero_page(t_cpu *cpu);
t_am	zero_page_x(t_cpu *cpu);
t_am	zero_page_y(t_cpu *cpu);
t_am	absolute(t_cpu *cpu);
t_am	absolute_x(t_cpu *cpu);
t_am	absolute_y(t_cpu *cpu);
t_am	indirect_x(t_cpu *cpu);
t_am	indirect_y(t_cpu *cpu);
t_am	indirect(t_cpu *cpu);

// OPCODE
void	adc(t_cpu *cpu, t_am am, uint8_t c);
void	and(t_cpu *cpu, t_am am);
void	asl(t_cpu *cpu, t_am am, int dest_is_mem);
void	bcc(t_cpu *cpu);
void	bcs(t_cpu *cpu);
void	beq(t_cpu *cpu);
void	bit(t_cpu *cpu, t_am am);
void	bmi(t_cpu *cpu);
void	bne(t_cpu *cpu);
void	bpl(t_cpu *cpu);
void	bvc(t_cpu *cpu);
void	bvs(t_cpu *cpu);
void	clc(t_cpu *cpu);
void	cld(t_cpu *cpu);
void	clv(t_cpu *cpu);
void	cmp(t_cpu *cpu, t_am am);
void	cpx(t_cpu *cpu, t_am am);
void	cpy(t_cpu *cpu, t_am am);
void	dec(t_cpu *cpu, t_am am);
void	dex(t_cpu *cpu);
void	dey(t_cpu *cpu);
void	eor(t_cpu *cpu, t_am am);
void	inc(t_cpu *cpu, t_am am);
void	inx(t_cpu *cpu);
void	iny(t_cpu *cpu);
void	jmp(t_cpu *cpu, t_am am);
void	jsr(t_cpu *cpu, t_am am);
void	lda(t_cpu *cpu, t_am am);
void	ldx(t_cpu *cpu, t_am am);
void	ldy(t_cpu *cpu, t_am am);
void	lsr(t_cpu *cpu, t_am am, int dest_is_mem);
void	ora(t_cpu *cpu, t_am am);
void	pha(t_cpu *cpu);
void	php(t_cpu *cpu);
void	pla(t_cpu *cpu);
void	plp(t_cpu *cpu);
void	rol(t_cpu *cpu, t_am am, int dest_is_mem);
void	ror(t_cpu *cpu, t_am am, int dest_is_mem);
void	rti(t_cpu *cpu);
void	rts(t_cpu *cpu);
void	sbc(t_cpu *cpu, t_am am, uint8_t c);
void	sec(t_cpu *cpu);
void	sed(t_cpu *cpu);
void	sei(t_cpu *cpu);
void	sta(t_cpu *cpu, t_am am);
void	stx(t_cpu *cpu, t_am am);
void	sty(t_cpu *cpu, t_am am);
void	tax(t_cpu *cpu);
void	tay(t_cpu *cpu);
void	tsx(t_cpu *cpu);
void	txa(t_cpu *cpu);
void	txs(t_cpu *cpu);
void	tya(t_cpu *cpu);
void	brk(t_cpu *cpu);

// illegal opcode
void	lax(t_cpu *cpu, t_am am);
void	sax(t_cpu *cpu, t_am am);
void	usbc(t_cpu *cpu, t_am am, uint8_t c);
void	dcp(t_cpu *cpu, t_am am);
void	isc(t_cpu *cpu, t_am am);
void	slo(t_cpu *cpu, t_am am);
void	rla(t_cpu *cpu, t_am am);
void	rra(t_cpu *cpu, t_am am);
void	sre(t_cpu *cpu, t_am am);

#endif