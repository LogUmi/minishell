#!/bin/bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --trace-children=yes --suppressions=bin/readline_leaks.supp ./minishell
