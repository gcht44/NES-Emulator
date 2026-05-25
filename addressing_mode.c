/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addressing_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 21:05:43 by gabch             #+#    #+#             */
/*   Updated: 2026/05/25 19:46:29 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.c"
#include "bus.h"

/*
Exemple :
LDA #$10
Le byte apres l'opcode est la valeur
*/
t_am	immediate(t_cpu *cpu)
{
	t_am am;
	am.addr_return = 0;
	am.value = read_bus(cpu->pc++);
	return (am);
}

/* Exemple :
LDA $80
L’adresse est sur 1 byte
Le CPU lit :
A = mem[0x0080]
*/
t_am	zero_page(t_cpu *cpu)
{
	t_am am;
	am.addr_return = read_bus(cpu->pc++);
	am.value = read_bus(am.addr_return);
	return (am);
}

/* Exemple :
Meme chose que pour zero_page_x mais on ajoute x
Il est possible d'avoir un overflow comme on utilise
une valeur sur 16 bits on recupere que le lsb
*/
t_am	zero_page_x(t_cpu *cpu)
{
	t_am am;
	am.addr_return = (read_bus(cpu->pc++) + cpu->x) & 0xFF;
	am.value = read_bus(am.addr_return);
	return (am);
}

/* Exemple :
Lit simplement a l'addresse specifier par les deux octets apres l'opcode
*/
t_am	absolute(t_cpu *cpu)
{
	t_am am;
	am.addr_return = read_bus(read_bus(cpu->pc++)) | (read_bus(read_bus(cpu->pc++)) << 8);
	am.value = read_bus(am.addr_return);
	return (am);
}

t_am	absolute_x(t_cpu *cpu)
{
	t_am am;
	am.addr_return = (read_bus(read_bus(cpu->pc++)) | (read_bus(read_bus(cpu->pc++)) << 8)) + cpu->x;
	am.value = read_bus(am.addr_return);
	return (am);
}

t_am	absolute_y(t_cpu *cpu)
{
	t_am am;
	am.addr_return = (read_bus(read_bus(cpu->pc++)) | (read_bus(read_bus(cpu->pc++)) << 8)) + cpu->y;
	am.value = read_bus(am.addr_return);
	return (am);
}

/*
Etape 1: ajouter x au byte apres l'opcode
Etape 2: on lit a l'addresse ptr et ptr + 1 pour former une addresse 16 bits
Etape 3: on lit a addresse
*/
t_am	indirect_x(t_cpu *cpu)
{
	t_am am;
	uint16_t ptr = read_bus(cpu->pc++) + cpu->x;
	am.addr_return = read_bus(ptr) | (read_bus((ptr + 1) & 0xFF) << 8);
	am.value = read_bus(am.addr_return);
	return (am);
}

/*
Etape 1: lire byte apres l'opcode
Etape 2: on lit a l'addresse ptr et ptr + 1 pour former une addresse 16 bits et on ajoute y a ce moment
Etape 3: on lit a addresse
*/
t_am	indirect_y(t_cpu *cpu)
{
	t_am am;
	uint16_t ptr = read_bus(cpu->pc++);
	am.addr_return = (read_bus(ptr) | (read_bus((ptr + 1) & 0xFF) << 8)) + cpu->y;
	am.value = read_bus(am.addr_return);
	return (am);
}

t_am	indirect(t_cpu *cpu)
{
	t_am	am;
	uint16_t addr = read_bus(cpu->pc++) | (read_bus(cpu->pc++) << 8);
	am.value = read_bus(addr) | (read_bus(addr + 1) << 8);
	return (am);
}
