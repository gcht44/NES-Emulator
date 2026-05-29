/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:54:07 by gabch             #+#    #+#             */
/*   Updated: 2026/05/29 16:35:22 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "bus.h"

void	push_stack(t_cpu *cpu, uint8_t value)
{
	write_bus((uint16_t)cpu->sp + (uint16_t)0x100, value);
	cpu->sp--;
}

uint8_t	pop_stack(t_cpu *cpu)
{
	cpu->sp++;
	return (read_bus((uint16_t)cpu->sp + (uint16_t)0x100));
}
