/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:43:51 by ssalorin          #+#    #+#             */
/*   Updated: 2025/03/27 12:43:52 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_token
{
	t_type			type;
	char			*data;
	char			*file;
	t_char			quote;
	t_bool			unclosed;
	t_type			specific_redir;
	t_bool			ambiguous;
	t_bool			expanded;
	struct s_token	*next;
}	t_token;

typedef struct s_cmd
{
	char			*name;
	char			**args;
	int				num;
	int				infile;
	int				outfile;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_block
{
	t_token			*start;
	t_token			*end;
	struct s_block	*next;
}	t_block;

typedef struct s_ms
{
	int		exit_status;
	char	**envp;
	char	**exported;
	t_token	*tokens;
	t_block	*blocks;
	t_cmd	*cmds;
	t_bool	history_file;
	char	*history[500];
	int		history_num;
	char	**heredoc_files;
	int		heredoc_count;
	int		no_env;
	char	*pwd;
	int		err;
	int		unset_pwd_exp_old;
}	t_ms;

typedef struct s_expand
{
	char	*data;
	char	*key;
	int		len;
	t_char	quote;
	t_bool	if_first;
	t_bool	expanded;
}	t_expand;

typedef struct s_envp
{
	char			*name;
	char			*value;
	struct s_envp	*next;
}	t_envp;

typedef struct s_pipe
{
	int		num_cmds;
	int		cmd_num;
	int		fd[2];
	int		cur_fd;
	pid_t	last_pid;
	pid_t	*pids;
	t_ms	*ms;
}	t_pipe;

#endif
