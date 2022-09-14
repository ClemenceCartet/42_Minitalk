/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:18:10 by ccartet           #+#    #+#             */
/*   Updated: 2022/01/20 10:21:40 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include "libft/libft.h"
# include <signal.h>
# include <sys/types.h>
# include <stdio.h>

void	error(char *str, char *msg);
void	check_arg(int argc, char **argv);
void	send_signal(char c, pid_t pid);
void	recept_ok(int signum);
void	sig_handler(int signum, siginfo_t *siginfo, void *ucontext);
void	build_msg(char c, int i);
int		print_msg(void);

#endif