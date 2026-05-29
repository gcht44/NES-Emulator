/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:19:17 by gabch             #+#    #+#             */
/*   Updated: 2026/05/29 03:11:07 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"
#include "cpu.h"
#include "bus.h"

void	exec_opcode(t_cpu *cpu)
{
	uint8_t	opcode = read_bus(cpu->pc++);
	t_am	am;
	int		clear_it = -1;

	if (clear_it == 0)
	{
		cpu->flags.i = 1;
		clear_it = -1;
	}
	if (clear_it > 0)
		clear_it--;

	switch (opcode)
	{
		case 0x01:
			ora(cpu, indirect_x(cpu));
			break;
		case 0x05:
			ora(cpu, zero_page(cpu));
			break;
		case 0x06:
			asl(cpu, zero_page(cpu), 1);
			break;
		case 0x08:
			pha(cpu);
			break;
		case 0x09:
			ora(cpu, immediate(cpu));
			break;
		case 0x0A:
			am.value = cpu->a;
			am.addr_return = 0;
			asl(cpu, am, 0);
			break;
		case 0x0D:
			ora(cpu, absolute(cpu));
			break;
		case 0x0E:
			asl(cpu, absolute(cpu), 1);
			break;
		case 0x10:
			bpl(cpu);
			break;
		case 0x11:
			ora(cpu, indirect_y(cpu));
			break;
		case 0x15:
			ora(cpu, zero_page_x(cpu));
			break;
		case 0x16:
			asl(cpu, zero_page_x(cpu), 1);
			break;
		case 0x18:
			clc(cpu);
			break;
		case 0x19:
			ora(cpu, absolute_y(cpu));
			break;
		case 0x1D:
			ora(cpu, absolute_x(cpu));
			break;
		case 0x1E:
			asl(cpu, absolute_x(cpu), 1);
			break;
		case 0x20:
			jsr(cpu, absolute(cpu));
			break;
		case 0x21:
			and(cpu, indirect_x(cpu));
			break;
		case 0x24:
			bit(cpu, zero_page(cpu));
			break;
		case 0x25:
			and(cpu, zero_page(cpu));
			break;
		case 0x26:
			rol(cpu, zero_page(cpu), 1);
			break;
		case 0x28: // plp y a des trucs a revoir au niveau du i qui doit etre delay
			plp(cpu);
			break;
		case 0x29:
			and(cpu, immediate(cpu));
			break;
		case 0x2A:
			am.value = cpu->a;
			rol(cpu, am, 0);
			break;
		case 0x2C:
			bit(cpu, absolute(cpu));
			break;
		case 0x2D:
			and(cpu, absolute(cpu));
			break;
		case 0x2E:
			rol(cpu, absolute(cpu), 1);
			break;
		case 0x30:
			bne(cpu);
			break;
		case 0x31:
			and(cpu, indirect_y(cpu));
			break;
		case 0x35:
			and(cpu, zero_page_x(cpu));
			break;
		case 0x36:
			rol(cpu, zero_page_x(cpu), 1);
			break;
		case 0x38:
			sec(cpu);
			break;
		case 0x39:
			and(cpu, absolute_y(cpu));
			break;
		case 0x3D:
			and(cpu, absolute_x(cpu));
			break;
		case 0x3E:
			rol(cpu, absolute_x(cpu), 1);
			break;
		case 0x40:
			rti(cpu);
			break;
		case 0x41:
			eor(cpu, indirect_x(cpu));
			break;
		case 0x45:
			eor(cpu, zero_page(cpu));
			break;
		case 0x46:
			lsr(cpu, zero_page(cpu), 1);
			break;
		case 0x48:
			pha(cpu);
			break;
		case 0x49:
			eor(cpu, immediate(cpu));
			break;
		case 0x4A:
			am.value = cpu->a;
			am.addr_return = 0;
			lsr(cpu, am, 0);
			break;
		case 0x4C:
			jmp(cpu, absolute(cpu));
			break;
		case 0x4D:
			eor(cpu, absolute(cpu));
			break;
		case 0x4E:
			lsr(cpu, absolute(cpu), 1);
			break;
		case 0x50:
			bvc(cpu);
			break;
		case 0x51:
			eor(cpu, indirect_y(cpu));
			break;
		case 0x55:
			eor(cpu, zero_page_x(cpu));
			break;
		case 0x56:
			lsr(cpu, zero_page_x(cpu), 1);
			break;
		case 0x58:
			clear_it = 1;
			break;
		case 0x59:
			eor(cpu, absolute_y(cpu));
			break;
		case 0x5D:
			eor(cpu, absolute_x(cpu));
			break;
		case 0x5E:
			lsr(cpu, absolute_x(cpu), 1);
			break;
		case 0x60:
			rti(cpu);
			break;
		case 0x61:
			adc(cpu, indirect_x(cpu), cpu->flags.c);
			break;
		case 0x65:
			adc(cpu, zero_page(cpu), cpu->flags.c);
			break;
		case 0x66:
			ror(cpu, zero_page(cpu), 1);
			break;
		case 0x68:
			pla(cpu);
			break;
		case 0x69:
			adc(cpu, immediate(cpu), cpu->flags.c);
			break;
		case 0x6A:
			am.value = cpu->a;
			ror(cpu, am, 0);
			break;
		case 0x6C:
			jmp(cpu, indirect(cpu));
			break;
		case 0x6D:
			adc(cpu, absolute(cpu), cpu->flags.c);
			break;
		case 0x6E:
			ror(cpu, absolute(cpu), 1);
			break;
		case 0x70:
			bvs(cpu);
			break;
		case 0x71:
			adc(cpu, indirect_y(cpu), cpu->flags.c);
			break;
		case 0x75:
			adc(cpu, zero_page_x(cpu), cpu->flags.c);
			break;
		case 0x76:
			ror(cpu, zero_page_x(cpu), 1);
			break;
		case 0x78:
			sei(cpu);
			break;
		case 0x79:
			adc(cpu, absolute_y(cpu), cpu->flags.c);
			break;
		case 0x7D:
			adc(cpu, absolute_x(cpu), cpu->flags.c);
			break;
		case 0x7E:
			ror(cpu, absolute_x(cpu), 1);
			break;
		case 0x81:
			sta(cpu, indirect_x(cpu));
			break;
		case 0x84:
			sty(cpu, zero_page(cpu));
			break;
		case 0x85:
			sta(cpu, zero_page(cpu));
			break;
		case 0x86:
			stx(cpu, zero_page(cpu));
			break;
		case 0x88:
			dey(cpu);
			break;
		case 0x8A:
			txa(cpu);
			break;
		case 0x8C:
			sty(cpu, absolute(cpu));
			break;
		case 0x8D:
			sta(cpu, absolute(cpu));
			break;
		case 0x8E:
			stx(cpu, absolute(cpu));
			break;
		case 0x90:
			bcc(cpu);
			break;
		case 0x91:
			sta(cpu, indirect_y(cpu));
			break;
		case 0x94:
			sty(cpu, zero_page_x(cpu));
			break;
		case 0x95:
			sta(cpu, zero_page_x(cpu));
			break;
		case 0x96:
			stx(cpu, zero_page_y(cpu));
			break;
		case 0x98:
			tya(cpu);
			break;
		case 0x99:
			sta(cpu, absolute_y(cpu));
			break;
		case 0x9A:
			txs(cpu);
			break;
		case 0x9D:
			sta(cpu, absolute_x(cpu));
			break;
		case 0xA0:
			ldy(cpu, immediate(cpu));
			break;
		case 0xA1:
			lda(cpu, indirect_x(cpu));
			break;
		case 0xA2:
			ldx(cpu, immediate(cpu));
			break;
		case 0xA4:
			ldy(cpu, zero_page(cpu));
			break;
		case 0xA5:
			lda(cpu, zero_page(cpu));
			break;
		case 0xA6:
			ldx(cpu, zero_page(cpu));
			break;
		case 0xA8:
			tay(cpu);
			break;
		case 0xA9:
			lda(cpu, immediate(cpu));
			break;
		case 0xAA:
			tax(cpu);
			break;
		case 0xAC:
			ldy(cpu, absolute(cpu));
			break;
		case 0xAD:
			lda(cpu, absolute(cpu));
			break;
		case 0xAE:
			ldx(cpu, absolute(cpu));
			break;
		case 0xB0:
			bcs(cpu);
			break;
		case 0xB1:
			lda(cpu, indirect_y(cpu));
			break;
		case 0xB4:
			ldy(cpu, zero_page_x(cpu));
			break;
		case 0xB5:
			lda(cpu, zero_page_x(cpu));
			break;
		case 0xB6:
			ldx(cpu, zero_page_y(cpu));
			break;
		case 0xB8:
			clv(cpu);
			break;
		case 0xB9:
			lda(cpu, absolute_y(cpu));
			break;
		case 0xBA:
			tsx(cpu);
			break;
		case 0xBC:
			ldy(cpu, absolute_x(cpu));
			break;
		case 0xBD:
			lda(cpu, absolute_x(cpu));
			break;
		case 0xBE:
			ldx(cpu, absolute_y(cpu));
			break;
		case 0xC0:
			cpy(cpu, immediate(cpu));
			break;
		case 0xC1:
			cmp(cpu, indirect_x(cpu));
			break;
		case 0xC4:
			cpy(cpu, zero_page(cpu));
			break;
		case 0xC5:
			cmp(cpu, zero_page(cpu));
			break;
		case 0xC6:
			dec(cpu, zero_page(cpu));
			break;
		case 0xC8:
			iny(cpu);
			break;
		case 0xC9:
			cmp(cpu, immediate(cpu));
			break;
		case 0xCA:
			dex(cpu);
			break;
		case 0xCC:
			cpy(cpu, absolute(cpu));
			break;
		case 0xCD:
			cmp(cpu, absolute(cpu));
			break;
		case 0xCE:
			dec(cpu, absolute(cpu));
			break;
		case 0xD0:
			bne(cpu);
			break;
		case 0xD1:
			cmp(cpu, indirect_y(cpu));
			break;
		case 0xD5:
			cmp(cpu, zero_page_x(cpu));
			break;
		case 0xD6:
			dec(cpu, zero_page_x(cpu));
			break;
		case 0xD8:
			cld(cpu);
			break;
		case 0xD9:
			cmp(cpu, absolute_y(cpu));
			break;
		case 0xDD:
			cmp(cpu, absolute_x(cpu));
			break;
		case 0xDE:
			dec(cpu, absolute_x(cpu));
			break;
		case 0xE0:
			cpx(cpu, immediate(cpu));
			break;
		case 0xE1:
			sbc(cpu, absolute_x(cpu), cpu->flags.c);
			break;
		case 0xE4:
			cpx(cpu, zero_page(cpu));
			break;
		case 0xE5:
			sbc(cpu, zero_page(cpu), cpu->flags.c);
			break;
		case 0xE6:
			inc(cpu, zero_page(cpu));
			break;
		case 0xE8:
			inx(cpu);
			break;
		case 0xE9:
			sbc(cpu, immediate(cpu), cpu->flags.c);
			break;
		case 0xEA: // NOP
			break;
		case 0xEC:
			cpx(cpu, absolute(cpu));
			break;
		case 0xED:
			sbc(cpu, absolute(cpu), cpu->flags.c);
			break;
		case 0xEE:
			inc(cpu, absolute(cpu));
			break;
		case 0xF0:
			beq(cpu);
			break;
		case 0xF1:
			sbc(cpu, indirect_y(cpu), cpu->flags.c);
			break;
		case 0xF5:
			sbc(cpu, zero_page_x(cpu), cpu->flags.c);
			break;
		case 0xF6:
			inc(cpu, zero_page_x(cpu));
			break;
		case 0xF8:
			sed(cpu);
			break;
		case 0xF9:
			sbc(cpu, absolute_y(cpu), cpu->flags.c);
			break;
		case 0xFD:
			sbc(cpu, absolute_x(cpu), cpu->flags.c);
			break;
		case 0xFE:
			inc(cpu, absolute_x(cpu));
			break;
		default:
			break;
	}
}