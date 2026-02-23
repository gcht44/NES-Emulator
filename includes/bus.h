/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bus.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 22:03:24 by gabch             #+#    #+#             */
/*   Updated: 2026/02/23 20:10:38 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUS_H
# define BUS_H

# include <stdint.h>

void	write_bus(uint16_t addr, uint8_t data);
uint8_t	read_bus(uint16_t addr);

#endif