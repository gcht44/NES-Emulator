/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ram.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 02:19:39 by gabch             #+#    #+#             */
/*   Updated: 2026/05/28 02:26:47 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_H
# define RAM_H

# include <stdint.h>

uint8_t	read_ram(uint16_t addr);
void	write_ram(uint16_t addr, uint8_t value);

#endif