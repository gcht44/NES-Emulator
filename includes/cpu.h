/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:07:32 by gabch             #+#    #+#             */
/*   Updated: 2026/05/23 20:00:55 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_H
# define CPU_H

# include <stdint.h>

typedef struct s_cpu
{
	uint8_t		a;
	uint8_t		x;
	uint8_t		y;
	uint8_t		sr;
	uint16_t	sp;
	uint16_t	pc;
}	t_cpu;

void	init_cpu(t_cpu *cpu);

#endif