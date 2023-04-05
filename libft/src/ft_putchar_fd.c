/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:31:33 by kblok         #+#    #+#                 */
/*   Updated: 2023/04/03 13:11:40 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// COMMENTS:

// De Kernel heeft voor elk open bestand een tabel met gegevens over dat bestand
// en zijn toestand (waar staat het bestand, waar zijn we met lezen gebleven,
// enz. enz.). Deze tabel heet de File Descriptor. File descriptors hebben een
// unieke identificatie binnen de Kernel, ten eerste de PID en daarna een nummer
// uniek binnen de PID. Ieder proces dat wordt gestart krijgt al gelijk van de
// Kernel drie file descriptors met vastgestelde file descriptor nummers:
// standard input (stdin met nummer 0), standard output (stdout met nummer 1)
// en standard error (stderr met nummer 2).
