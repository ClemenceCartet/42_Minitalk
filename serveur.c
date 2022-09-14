/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:17:55 by ccartet           #+#    #+#             */
/*   Updated: 2022/01/19 16:59:30 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_msg;

int	print_msg(void)
{
	ft_putendl_fd(g_msg, 1);
	free(g_msg);
	g_msg = NULL;
	return (0);
}

void	build_msg(char c, int i)
{	
	char		*tmp;

	tmp = g_msg;
	g_msg = malloc(sizeof(char) * i + 2);
	if (!g_msg)
	{
		free(tmp);
		error("Problème de malloc", g_msg);
	}
	ft_strlcpy(g_msg, tmp, i + 1);
	free(tmp);
	g_msg[i] = c;
	g_msg[i + 1] = '\0';
}

void	sig_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	static int		c;
	static int		bit;
	static int		index;
	static pid_t	client_pid;

	(void)ucontext;
	if (index == 0 && bit == 0)
		client_pid = siginfo->si_pid;
	if (signum == SIGUSR2)
		c += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			index = print_msg();
			if (kill(client_pid, SIGUSR1) == -1)
				error("Erreur transmission", g_msg);
		}
		else
			build_msg(c, index++);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;
	sigset_t			set;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sa.sa_sigaction = sig_handler;
	sa.sa_mask = set;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		error("Erreur signal", g_msg);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		error("Erreur signal", g_msg);
	while (1)
		pause ();
	return (EXIT_SUCCESS);
}
