/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:07:32 by gabch             #+#    #+#             */
/*   Updated: 2026/02/22 18:03:08 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_H
# define CPU_H

# include <stdint.h>

# define CARRY_FLAGS

typedef struct s_cpu
{
	uint8_t		a;
	uint8_t		x;
	uint8_t		y;
	uint8_t		sr;
	uint8_t		sp;
	uint16_t	pc;
}	t_cpu;

void	init_cpu(t_cpu *cpu);

#endif