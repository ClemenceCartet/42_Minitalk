/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:17:42 by ccartet           #+#    #+#             */
/*   Updated: 2022/01/19 16:59:59 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	recept_ok(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, "Message reçu\n", 13);
		exit(EXIT_SUCCESS);
	}
}

void	send_signal(char c, pid_t pid)
{
	int				bit;
	int				result;

	bit = 7;
	while (bit >= 0)
	{
		result = c >> bit;
		if ((result & 1) > 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
		bit--;
	}
}

void	check_arg(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		error("Le nombre d'arguments est incorrect !", NULL);
	i = 0;
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]))
			i++;
		else
			error("Le PID n'est pas valide !", NULL);
	}
	if (kill(ft_atoi(argv[1]), 0) == -1)
		error("Le PID n'est pas valide !", NULL);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	check_arg(argc, argv);
	pid = ft_atoi(argv[1]);
	if (signal(SIGUSR1, recept_ok) == SIG_ERR)
		error("Erreur signal", NULL);
	while (argv[2][i])
		send_signal(argv[2][i++], pid);
	send_signal(argv[2][i], pid);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
