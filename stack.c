/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:54:07 by gabch             #+#    #+#             */
/*   Updated: 2026/05/25 20:08:49 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "bus.h"

void	push_stack(t_cpu *cpu, uint8_t value)
{
	write_bus(cpu->sp, value);
	cpu->sp--;
}

uint8_t	pop_stack(t_cpu *cpu)
{
	cpu->sp++;
	return (read_bus(cpu->sp - 0x100));
}