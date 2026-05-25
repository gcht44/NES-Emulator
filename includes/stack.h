/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:54:12 by gabch             #+#    #+#             */
/*   Updated: 2026/05/25 20:09:11 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdint.h>
#include "cpu.h"

uint8_t	pop_stack(t_cpu *cpu);
void	push_stack(t_cpu *cpu, uint8_t value);

#endif