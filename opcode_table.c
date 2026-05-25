/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:19:17 by gabch             #+#    #+#             */
/*   Updated: 2026/05/25 16:49:11 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"
#include "cpu.h"
#include "bus.h"

void	exec_opcode(t_cpu *cpu)
{
	uint8_t opcode = read_bus(cpu->pc++);
	uint8_t value8bits;
	uint16_t value16bits;
	
	switch (opcode)
	{
		case 0x61:
			adc(cpu, indirect_x(cpu), CY_FLAG(cpu->sr));
			break;
		case 0x65:
			adc(cpu, zero_page(cpu), CY_FLAG(cpu->sr));
			break;
		case 0x69:
			adc(cpu, immediate(cpu), CY_FLAG(cpu->sr));
			break;
		case 0x6D:
			adc(cpu, absolute(cpu), CY_FLAG(cpu->sr));
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

		default:
			break;
	}
}