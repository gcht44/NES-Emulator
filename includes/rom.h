/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rom.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:15:05 by gabch             #+#    #+#             */
/*   Updated: 2026/02/23 20:17:26 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROM_H
# define ROM_H

# include <stdint.h>

typedef struct s_rom_ctx
{
	uint8_t	*memory;
}	t_rom_ctx;

int		init_memory_rom(const char *name);
uint8_t	read_rom(uint16_t addr);
#endif