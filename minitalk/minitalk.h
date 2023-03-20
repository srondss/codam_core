/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:26:55 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/20 12:25:06 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>

# include "final_printf/ft_printf.h"

int		ft_strlen(char const *str);
void	handler_sigusr_server(int signum, siginfo_t *info, void *context);
void	update_string(int signum, char *string, int id);
void	send_str_len(int pid, char *string);
void	handler_sigusr(int signum, siginfo_t *info, void *context);
void	send_binary_signals(int pid, char *string);
void	send_null(int pid);
void	handle_string_length(int signum, int *len, int id, char **str);
void	handle_string_chars(int signum, char **string, int id, int len);
void	print_and_reset(char **string, int *ptr_len, int *ptr_id);
void	send_bit(char *string, int bit, int pid, int i);
int		ft_atoi(const char *string);
void	wait_for_connection(int pid);
void	error_handling_server(char *str);
void	error_handling_client(void);
#endif
