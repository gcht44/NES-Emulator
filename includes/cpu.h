/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:07:32 by gabch             #+#    #+#             */
/*   Updated: 2026/05/28 01:40:13 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_H
# define CPU_H

# include <stdint.h>

typedef struct s_flags
{
	uint8_t		c;
	uint8_t		z;
	uint8_t		i;
	uint8_t		d;
	uint8_t		b;
	uint8_t		v;
	uint8_t		n;
}	t_flags;


typedef struct s_cpu
{
	uint8_t		a;
	uint8_t		x;
	uint8_t		y;
	t_flags		flags;
	uint8_t		sp;
	uint16_t	pc;
}	t_cpu;

void	init_cpu(t_cpu *cpu);
uint8_t	get_sr(t_flags flags);

#endif