/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:19:17 by gabch             #+#    #+#             */
/*   Updated: 2026/05/25 20:16:54 by gabch            ###   ########.fr       */
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
		cpu->sr &= 0xFB;
		clear_it = -1;
	}
	if (clear_it > 0)
		clear_it--;

	switch (opcode)
	{
		case 0x06:
			asl(cpu, zero_page(cpu), 1);
			break;
		case 0x0A:
			am.value = cpu->a;
			am.addr_return = 0;
			asl(cpu, am, 0);
			break;
		case 0x0E:
			asl(cpu, absolute(cpu), 1);
			break;
		case 0x10:
			bpl(cpu);
			break;
		case 0x16:
			asl(cpu, zero_page_x(cpu), 1);
			break;
		case 0x18:
			clc(cpu);
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
		case 0x29:
			and(cpu, immediate(cpu));
			break;
		case 0x2C:
			bit(cpu, absolute(cpu));
			break;
		case 0x2D:
			and(cpu, absolute(cpu));
			break;
		case 0x30:
			bme(cpu);
			break;
		case 0x31:
			and(cpu, indirect_y(cpu));
			break;
		case 0x35:
			and(cpu, zero_page_x(cpu));
			break;
		case 0x39:
			and(cpu, absolute_y(cpu));
			break;
		case 0x3D:
			and(cpu, absolute_x(cpu));
			break;
		case 0x41:
			eor(cpu, indirect_x(cpu));
			break;
		case 0x45:
			eor(cpu, zero_page(cpu));
			break;
		case 0x49:
			eor(cpu, immediate(cpu));
			break;
		case 0x4C:
			jmp(cpu, absolute(cpu));
			break;
		case 0x4D:
			eor(cpu, absolute(cpu));
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
		case 0x58:
			clear_it = 1;
			break;
		case 0x59:
			eor(cpu, absolute_y(cpu));
			break;
		case 0x5D:
			eor(cpu, absolute_x(cpu));
			break;
		case 0x61:
			adc(cpu, indirect_x(cpu), CY_FLAG(cpu->sr));
			break;
		case 0x65:
			adc(cpu, zero_page(cpu), CY_FLAG(cpu->sr));
			break;
		case 0x69:
			adc(cpu, immediate(cpu), CY_FLAG(cpu->sr));
			break;
		case 0x6C:
			jmp(cpu, indirect(cpu));
			break;
		case 0x6D:
			adc(cpu, absolute(cpu), CY_FLAG(cpu->sr));
			break;
		case 0x70:
			bvs(cpu);
			break;
		case 0x71:
			adc(cpu, indirect_y(cpu), CY_FLAG(cpu->sr));
			break;
		case 0x75:
			adc(cpu, zero_page_x(cpu), CY_FLAG(cpu->sr));
			break;
		case 0x79:
			adc(cpu, absolute_y(cpu), CY_FLAG(cpu->sr));
			break;
		case 0x7D:
			adc(cpu, absolute_x(cpu), CY_FLAG(cpu->sr));
			break;
		case 0x88:
			dey(cpu);
			break;
		case 0x90:
			bcc(cpu);
			break;
		case 0xB0:
			bcs(cpu);
			break;
		case 0xB8:
			clv(cpu);
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
		case 0xE4:
			cpx(cpu, zero_page(cpu));
			break;
		case 0xE6:
			inc(cpu, zero_page(cpu));
			break;
		case 0xE8:
			inx(cpu);
			break;
		case 0xEC:
			cpx(cpu, absolute(cpu));
			break;
		case 0xEE:
			inc(cpu, absolute(cpu));
			break;
		case 0xF0:
			beq(cpu);
			break;
		case 0xF6:
			inc(cpu, zero_page_x(cpu));
			break;
		case 0xFE:
			inc(cpu, absolute_x(cpu));
			break;
		default:
			break;
	}
}