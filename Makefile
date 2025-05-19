# Détection du système d'exploitation
UNAME_S := $(shell uname -s)

# changement en fonction de l'os je supprime a la fin
ifeq ($(UNAME_S),Darwin)  # Si c'est macOS
	READLINE =	-I/opt/homebrew/opt/readline/include \
				-L/opt/homebrew/opt/readline/lib \
				-lreadline \
				-lncurses
	READLINE_PART = $(word 1, $(READLINE))
else ifeq ($(UNAME_S),Linux)  # Si c'est Linux
	READLINE = -lreadline -lhistory
	READLINE_PART =
else
	$(error Unsupported OS)
endif

NAME = 	minishell.a
EXEC =	minishell
HDRS = 	minishell.h
OBJDIR = objs
SRCDIR = srcs/
FILEC =	minishell.c \
		set_shlvl.c \
		input_utils.c \
		signals.c \
		get_cmde.c \
		magic_split.c \
		liberation.c \
		liberation_2.c \
		2nd_blade.c \
		2nd_blade_1.c \
		2nd_blade_2.c \
		expand.c \
		make_tree.c \
		make_tree_2.c \
		make_tree_3.c \
		tree_utils.c \
		tree_utils_2.c \
		builtin_cd.c \
		builtin_export.c \
		builtin_export_1.c \
		builtin_exit.c \
		builtin_exit_1.c \
		builtin_pwd.c \
		builtin_echo.c \
		input_errors.c \
		init_env.c \
		main_loop.c	\
		linklist_utils.c \
		expand_2.c \
		history.c \
		error_test.c \
		error_test_2.c \
		error_test_3.c \
		error_rfile_check.c \
		error_rfile_check_2.c \
		error_rfile_check_3.c \
		heredoc.c \
		heredoc_2.c \
		heredoc_3.c \
		heredoc_4.c \
		expand_1.c \
		exec_com.c \
		exec_com_1.c \
		exec_com_2.c \
		exec_com_3.c \
		exec_com_4.c

OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(FILEC))
SRCS = $(addprefix	$(SRCDIR),	$(FILEC))
LDIR = libft
LIBR = $(LDIR)/libft.a
FLAGS = -fPIC -Wall -Werror -Wextra
CC = cc
AR = ar -rcs

all:		$(OBJDIR)	$(NAME)	$(EXEC)

$(NAME):	$(OBJS)	$(LIBR) $(HDRS)
			$(AR) $(NAME) $(OBJS)	

# Compilation des fichiers .o dans obj/
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(FLAGS) $(READLINE_PART) -I. -I$(LDIR) -c $< -o $@

# Création du dossier obj/ si nécessaire
$(OBJDIR):
	mkdir -p $(OBJDIR)
			
$(LIBR):		
			[ -d $(LDIR) ] && $(MAKE) -C $(LDIR) all
			cp $(LIBR) .
			mv $(notdir $(LIBR)) $(NAME)

$(EXEC):	$(SRCS) $(HDRS)
# $(CC) $(FLAGS) $(READLINE) $(SRCS) -I. -o $(EXEC) $(NAME) -g
			$(CC) $(FLAGS) $(SRCS) $(NAME) -I. -o $(EXEC) -g $(READLINE)

clean:		
			rm -rf	$(OBJS)
			$(MAKE) -C $(LDIR) clean

fclean:		clean
			$(MAKE) -C $(LDIR) fclean
			rm -rf $(NAME) $(EXEC)	

re:			fclean all

.PHONY:		all clean fclean re
