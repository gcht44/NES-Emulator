/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addressing_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 21:05:43 by gabch             #+#    #+#             */
/*   Updated: 2026/05/25 16:33:49 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.c"
#include "bus.h"

/*
Exemple :
LDA #$10
Le byte apres l'opcode est la valeur
*/
uint8_t	immediate(t_cpu *cpu)
{
	return (read_bus(cpu->pc++));
}

/* Exemple :
LDA $80
L’adresse est sur 1 byte
Le CPU lit :
A = mem[0x0080]
*/
uint8_t	zero_page(t_cpu *cpu)
{
	return (read_bus(read_bus(cpu->pc++)));
}

/* Exemple :
Meme chose que pour zero_page_x mais on ajoute x
Il est possible d'avoir un overflow comme on utilise
une valeur sur 16 bits on recupere que le lsb
*/
uint8_t	zero_page_x(t_cpu *cpu)
{
	uint16_t addr = (read_bus(cpu->pc++) + cpu->x) & 0xFF;
	return (read_bus(addr));
}

/* Exemple :
Lit simplement a l'addresse specifier par les deux octets apres l'opcode
*/
uint8_t	absolute(t_cpu *cpu)
{
	uint16_t addr = read_bus(read_bus(cpu->pc++)) | (read_bus(read_bus(cpu->pc++)) << 8);
	return (read_bus(addr));
}

uint8_t	absolute_x(t_cpu *cpu)
{
	uint16_t addr = (read_bus(read_bus(cpu->pc++)) | (read_bus(read_bus(cpu->pc++)) << 8)) + cpu->x;
	return (read_bus(addr));
}

uint8_t	absolute_y(t_cpu *cpu)
{
	uint16_t addr = (read_bus(read_bus(cpu->pc++)) | (read_bus(read_bus(cpu->pc++)) << 8)) + cpu->y;
	return (read_bus(addr));
}

/*
Etape 1: ajouter x au byte apres l'opcode
Etape 2: on lit a l'addresse ptr et ptr + 1 pour former une addresse 16 bits
Etape 3: on lit a addresse
*/
uint8_t	indirect_x(t_cpu *cpu)
{
	uint16_t ptr = read_bus(cpu->pc++) + cpu->x;
	uint16_t addr = read_bus(ptr) | (read_bus((ptr + 1) & 0xFF) << 8);
	return (read_bus(addr));
}

/*
Etape 1: lire byte apres l'opcode
Etape 2: on lit a l'addresse ptr et ptr + 1 pour former une addresse 16 bits et on ajoute y a ce moment
Etape 3: on lit a addresse
*/
uint8_t	indirect_y(t_cpu *cpu)
{
	uint16_t ptr = read_bus(cpu->pc++);
	uint16_t addr = (read_bus(ptr) | (read_bus((ptr + 1) & 0xFF) << 8)) + cpu->y;
	return (read_bus(addr));
}
