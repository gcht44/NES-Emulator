/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:54:07 by gabch             #+#    #+#             */
/*   Updated: 2026/05/25 20:04:52 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "bus.h"

static uint8_t stack[0x100];

void	push_stack(t_cpu *cpu, uint8_t value)
{
	stack[cpu->sp - 0x100] = value;
	cpu->sp -= 1;
}

uint8_t	pop_stack(t_cpu *cpu)
{
	cpu->sp += 1;
	return (stack[cpu->sp - 0x100]);
}