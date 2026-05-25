/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:00:44 by gabch             #+#    #+#             */
/*   Updated: 2026/05/25 20:15:36 by gabch            ###   ########.fr       */
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


# define CY_FLAG(sr) sr & 0x01       // Carry flag
# define Z_FLAG(sr)  (sr & 0x2) >> 1 // Zero Flag
# define ID_FLAG(sr) (sr & 0x4) >> 2 // Interrupt disable
# define D_FLAG(sr)  (sr & 0x8) >> 3 // Decimal
# define B_FLAG(sr)  (sr & 0x10) >> 4 // B flag
# define O_FLAG(sr)  (sr & 0x40) >> 6 // Overflow flag
# define N_FLAG(sr)  (sr & 0x80) >> 7 // Negative flag

# define DEFINE_CY(value) value > 0xFF ? 1 : 0
# define DEFINE_Z(value) (value == 0x00 ? 1 : 0) << 1
# define DEFINE_O(value) (value ^ A) & (value ^ memory) & $80
# define DEFINE_N(value) ((value & 0x80) > 0x00 ? 1 : 0) << 7

// ADDRESSING MODE
t_am	immediate(t_cpu *cpu);
t_am	zero_page(t_cpu *cpu);
t_am	zero_page_x(t_cpu *cpu);
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

#endif