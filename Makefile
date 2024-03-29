#-------------------------- Key Values -----------------------------------------
NAME		:=	21sh
CFLAGS		:=	-Wall -Werror -Wextra
CC			:=	gcc

DIR_INC		:=	includes/
DIR_SRC		:=	source/
DIR_OBJ		:=	object/
CH_SRC		:=	c
CH_OBJ		:=	o

COR			:=	core/
LNP			:=	line_parser/
RL			:=	read_line/
ENV			:=	environ_manipulation/

DIR_LIB		:=	libft/
DIR_LIB_INC	:=	$(DIR_LIB)$(DIR_INC)libc/\
				$(DIR_LIB)$(DIR_INC)printf/\
				$(DIR_LIB)$(DIR_INC)get_next_line/\
				$(DIR_LIB)$(DIR_INC)containers/
LIBFT		:=	$(DIR_LIB)libft.a

#-------------------------- Paths ----------------------------------------------
DIR_COR_INC	:=	$(DIR_INC)$(COR)
DIR_LNP_INC	:=	$(DIR_INC)$(LNP)
DIR_RL_INC	:=	$(DIR_INC)$(RL)
DIR_ENV_INC	:=	$(DIR_INC)$(ENV)

DIR_COR_SRC	:=	$(DIR_SRC)$(COR)
DIR_LNP_SRC	:=	$(DIR_SRC)$(LNP)
DIR_RL_SRC	:=	$(DIR_SRC)$(RL)
DIR_ENV_SRC	:=	$(DIR_SRC)$(ENV)

# core
DIR_BLT		:=	$(DIR_COR_SRC)builtin/
DIR_EXC		:=	$(DIR_COR_SRC)exec/
DIR_HLP		:=	$(DIR_COR_SRC)helpers/
DIR_INI		:=	$(DIR_COR_SRC)init/
DIR_SIG		:=	$(DIR_COR_SRC)signal/

#environ_manipulation
DIR_ENV_EVS	:=	$(DIR_ENV_SRC)env_events/

# line_parser
DIR_LPCMD	:=	$(DIR_LNP_SRC)lp_commands/
DIR_RDR		:=	$(DIR_LPCMD)redirect/

# read_line
DIR_LS		:=	$(DIR_RL_SRC)line_syntax/
DIR_KE		:=	$(DIR_RL_SRC)key_events/
DIR_HS		:=	$(DIR_RL_SRC)history/
DIR_AC		:=	$(DIR_KE)Tab/
DIR_ACCL	:=	$(DIR_AC)command_logic/
DIR_ACPL	:=	$(DIR_AC)path_logic/
DIR_AROWS	:=	$(DIR_KE)arrows/
DIR_CTRL	:=	$(DIR_KE)ctrl/

# init
DIR_INI_RL	:=	$(DIR_INI)init_read_line/
DIR_INI_LP	:=	$(DIR_INI)init_line_parser/

#-------------------------- Header files ---------------------------------------
COR_H		:=	$(DIR_COR_INC)shell.h\
				$(DIR_COR_INC)syntax_characters.h\
				$(DIR_COR_INC)tokens.h\
				$(DIR_COR_INC)builtin_static_box.h\
				$(DIR_COR_INC)builtin.h\
				$(DIR_COR_INC)info.h

ENV_H		:=	$(DIR_ENV_INC)environ_manipulation.h

LNP_H		:=	$(DIR_LNP_INC)line_parser.h

RL_H		:=	$(DIR_RL_INC)read_line.h\
				$(DIR_RL_INC)button_keys.h\
				$(DIR_RL_INC)line_syntax.h\
				$(DIR_RL_INC)history_search.h\
				$(DIR_RL_INC)read_line_signals.h\
				$(DIR_RL_INC)heredoc.h\
				$(DIR_RL_INC)auto_completion.h

#-------------------------- Source files ---------------------------------------
COR_C		:=	$(DIR_COR_SRC)main.c\
				$(DIR_INI)sh_init.c\
				$(DIR_INI)sh_init_env.c\
				$(DIR_INI)sh_init_term.c\
				$(DIR_INI_RL)sh_init_rl_history.c\
				$(DIR_INI_RL)sh_init_read_line.c\
				$(DIR_INI_LP)init_line_parser.c\
				$(DIR_SIG)sh_signals.c\
				$(DIR_BLT)sh_cd.c\
				$(DIR_BLT)sh_exit.c\
				$(DIR_BLT)sh_echo.c\
				$(DIR_BLT)sh_env.c\
				$(DIR_BLT)sh_setenv.c\
				$(DIR_BLT)sh_unsetenv.c\
				$(DIR_BLT)sh_hash.c\
				$(DIR_EXC)sh_exec.c\
				$(DIR_EXC)sh_process_cmd.c\
				$(DIR_EXC)sh_check_exec_path.c\
				$(DIR_HLP)sh_check_path_permision.c\
				$(DIR_HLP)sh_utility.c\
				$(DIR_HLP)sh_is.c\
				$(DIR_HLP)sh_join_path_to_pwd.c\
				$(DIR_HLP)sh_get_word.c

ENV_C		:=	$(DIR_ENV_SRC)env_convert.c\
				$(DIR_ENV_SRC)env_free.c\
				$(DIR_ENV_SRC)env_get.c\
				$(DIR_ENV_SRC)env_print.c\
				$(DIR_ENV_SRC)env_set.c\
				$(DIR_ENV_SRC)env_unset.c\
				$(DIR_ENV_SRC)env_make_clone.c\
				$(DIR_ENV_EVS)env_events.c\
				$(DIR_ENV_EVS)env_new_path.c

LNP_C		:=	$(DIR_LNP_SRC)line_parser.c\
				$(DIR_LNP_SRC)lp_arg_buf_control.c\
				$(DIR_LNP_SRC)lp_cmd_manipulation.c\
				$(DIR_LPCMD)lp_dollar.c\
				$(DIR_LPCMD)lp_backslash.c\
				$(DIR_LPCMD)lp_single_quotes.c\
				$(DIR_LPCMD)lp_double_quotes.c\
				$(DIR_LPCMD)lp_space.c\
				$(DIR_LPCMD)lp_semicolon.c\
				$(DIR_LPCMD)lp_tilde.c\
				$(DIR_LPCMD)lp_pipe.c\
				$(DIR_RDR)lp_redirect_in.c\
				$(DIR_RDR)lp_redirect_out.c\
				$(DIR_RDR)lp_check_redirection.c\
				$(DIR_RDR)lp_rdr_utility.c\
				$(DIR_RDR)lp_fd_manipulations.c\

RL_C		:=	$(DIR_RL_SRC)read_line.c\
				$(DIR_RL_SRC)rl_init.c\
				$(DIR_RL_SRC)rl_utility.c\
				$(DIR_RL_SRC)rl_move_cursor.c\
				$(DIR_RL_SRC)rl_edit_line.c\
				$(DIR_RL_SRC)rl_make_tc_magic.c\
				$(DIR_RL_SRC)rl_signals.c\
				$(DIR_HS)rl_history_manager.c\
				$(DIR_HS)rl_history_search.c\
				$(DIR_HS)rl_history_search_logic.c\
				$(DIR_LS)rl_line_syntax.c\
				$(DIR_LS)rl_ls_commands.c\
				$(DIR_LS)rl_ls_rap_commands.c\
				$(DIR_LS)rl_ls_handle_err.c\
				$(DIR_LS)rl_ls_new_prompt.c\
				$(DIR_LS)rl_ls_valid_word.c\
				$(DIR_LS)rl_ls_heredoc.c\
				$(DIR_KE)rl_key_events.c\
				$(DIR_KE)rl_basic_keys.c\
				$(DIR_AC)rl_ke_tab.c\
				$(DIR_AC)tab_proc_match.c\
				$(DIR_AC)tab_utility.c\
				$(DIR_AC)tab_print_matches.c\
				$(DIR_ACCL)tab_get_cmd_input_word.c\
				$(DIR_ACCL)tab_get_cmd_matches.c\
				$(DIR_ACPL)tab_get_path_input_word.c\
				$(DIR_ACPL)tab_get_path_matches.c\
				$(DIR_AROWS)rl_ke_arrows.c\
				$(DIR_AROWS)rl_ke_ctrl_arrows.c\
				$(DIR_AROWS)rl_ke_ctrl_shift_arrows.c\
				$(DIR_CTRL)rl_ke_ctrl_d_a_e_l_h.c\
				$(DIR_CTRL)rl_ke_ctrl_g_u_k.c\
				$(DIR_CTRL)rl_ke_ctrl_r.c

#-------------------------- Init OBJ, INC --------------------------------------
OBJ			:=	$(patsubst $(DIR_COR_SRC)%,$(DIR_OBJ)%,\
				$(COR_C:.$(CH_SRC)=.$(CH_OBJ)))
OBJ			+=	$(patsubst $(DIR_ENV_SRC)%,$(DIR_OBJ)%,\
				$(ENV_C:.$(CH_SRC)=.$(CH_OBJ)))
OBJ			+=	$(patsubst $(DIR_LNP_SRC)%,$(DIR_OBJ)%,\
				$(LNP_C:.$(CH_SRC)=.$(CH_OBJ)))
OBJ			+=	$(patsubst $(DIR_RL_SRC)%,$(DIR_OBJ)%,\
				$(RL_C:.$(CH_SRC)=.$(CH_OBJ)))

INC			:=	$(addprefix -I, $(DIR_LIB_INC) $(DIR_COR_INC) $(DIR_LNP_INC)\
				$(DIR_RL_INC) $(DIR_ENV_INC))

#-------------------------- Make -----------------------------------------------
all: lib $(DIR_OBJ) $(NAME)

lib:
	@make -C $(DIR_LIB)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

#-------------------------- Link Block -----------------------------------------
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT) -ltermcap
	@echo "Compiling" [ $(NAME) ]

#-------------------------- Compil Block ---------------------------------------
#COR
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_COR_SRC)%.$(CH_SRC)\
$(COR_H)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#ENV
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_ENV_SRC)%.$(CH_SRC)\
$(ENV_H)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#LNP
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_LNP_SRC)%.$(CH_SRC)\
$(COR_H) $(LNP_H)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#RL
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_RL_SRC)%.$(CH_SRC)\
$(COR_H) $(RL_H)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#-------------------------- Clean ----------------------------------------------
clean:
	@make -C $(DIR_LIB) clean
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files $(NAME) ]"

fclean:
	@make -C $(DIR_LIB) fclean
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files $(NAME) ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re
