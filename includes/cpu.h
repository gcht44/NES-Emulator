/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:07:32 by gabch             #+#    #+#             */
/*   Updated: 2026/02/23 20:54:01 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_H
# define CPU_H

# include <stdint.h>

# define CY_FLAG(sr) sr & 0x01       // Carry flag
# define Z_FLAG(sr)  (sr & 0x2) >> 1 // Zero Flag
# define ID_FLAG(sr) (sr & 0x4) >> 2 // Interrupt disable
# define D_FLAG(sr)  (sr & 0x8) >> 3 // Decimal
# define B_FLAG(sr)  (sr & 0x10) >> 4 // B flag
# define O_FLAG(sr)  (sr & 0x40) >> 6 // Overflow flag
# define N_FLAG(sr)  (sr & 0x80) >> 7 // Negative flag


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