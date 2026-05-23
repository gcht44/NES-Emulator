/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:02:22 by gabch             #+#    #+#             */
/*   Updated: 2026/05/23 20:18:34 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

// A rajouter Overflow flag
void	adc(uint8_t *reg_A, uint8_t value, uint8_t c)
{
	*reg_A += value + c;
	DEFINE_CY(*reg_A);
	DEFINE_Z(*reg_A);
	DEFINE_N(*reg_A);
}
