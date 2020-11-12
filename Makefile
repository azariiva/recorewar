# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/01 20:07:00 by rnugroho          #+#    #+#              #
#    Updated: 2020/11/12 20:20:03 by blinnea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= asm
FTASMPATH:= asm/
FTASM:= $(shell find src/asm -name '*.c')
FTASM:= $(FTASM:src/asm/%.c=%)

NAME_VM:= corewar
FTVMPATH:= ft_vm/
FTVM:=	ft_vm \
		options \
		vm_decompiler \
		vm_decompiler_file \
		checker \
		exec \
		vm_print \
		error \
		free_funk \
		vm_helper_1 vm_helper_2 \

FTVMOPPATH:= ft_vm/vm_op/
FTVMOP:= and_op add_op aff_op fork_op \
		ld_op ldi_op lfork_op live_op \
		lld_op lldi_op or_op st_op \
		sti_op sub_op xor_op zjmp_op

# ----- Libft ------
LFTDIR:=./libft
# ==================

# ------------------
COMPILER:=gcc
LINKER:=ar rc
SRCPATH:=src/
HDRPATH:=include/
CCHPATH:=obj/
IFLAGS:=-I $(HDRPATH) -I $(LFTDIR)/include
LFLAGS:=-L $(LFTDIR) -lft
CFLAGS:= $(IFLAGS) #-Wall -Werror -Wextra
# ==================

# ----- Colors -----
BLACK:="\033[1;30m"
RED:=\033[1;31m
GREEN:=\033[1;32m
CYAN:=\033[1;35m
GREENB:=\033[42m
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:=\033[0;0m
# ==================

FILES_ASM:=$(addprefix $(FTASMPATH),$(FTASM))
FILES_VM:=$(addprefix $(FTVMPATH),$(FTVM))
FILES_VM_OP:=$(addprefix $(FTVMOPPATH),$(FTVMOP))

# ------ Auto ------
SRC_ASM:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES_ASM)))
OBJ_ASM:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES_ASM)))

SRC_VM:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES_VM)))
OBJ_VM:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES_VM)))

SRC_VM+=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES_VM_DRAW)))
OBJ_VM+=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES_VM_DRAW)))

SRC_VM+=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES_VM_OP)))
OBJ_VM+=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES_VM_OP)))

# ==================

all: $(NAME) $(NAME_VM)

$(NAME): obj_asm | libft
	@$(COMPILER) $(CFLAGS) $(SRC_ASM) $(LFLAGS) -o $(NAME)
	@echo "> $(GREEN)ASM created$(EOC)"

$(NAME_VM): obj_vm | libft
	@$(COMPILER) $(CFLAGS) $(SRC_VM) $(LFLAGS) -o $(NAME_VM) -lncurses
	@echo "> $(GREEN)VM created$(EOC)"

$(CCHPATH)%.o: $(SRCPATH)%.c | dir
	@echo "$(GREENB) $(EOC)\c"
	@$(COMPILER) $(CFLAGS) -c $< -o $@

obj_asm: $(OBJ_ASM)
	@echo "\n> $(GREEN)ASM object-files created$(EOC)"

obj_vm: $(OBJ_VM)
	@echo "\n> $(GREEN)VM object-files created$(EOC)"

libft:
	@make -C libft

dir:
	@mkdir -p $(CCHPATH)
	@mkdir -p $(CCHPATH)$(FTASMPATH)
	@mkdir -p $(CCHPATH)$(FTVMPATH)
	@mkdir -p $(CCHPATH)$(FTVMOPPATH)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)
	@cd $(LFTDIR) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_VM)
	@rm -rf $(NAME).dSYM/
	@rm -rf $(NAME_VM).dSYM/
	@cd $(LFTDIR) && $(MAKE) fclean
	@rm -f out1 out2

re: fclean
	@$(MAKE) all

assemble: asm
	@./asm -m tests/asm/v*/*.s tests/vm/[bclo]*/*.s

clean_cor:
	@rm -f tests/asm/v*/*.cor tests/vm/[bclo]*/*.cor

.PHONY: all clean fclean re assemble clean_cor libft dir obj_asm obj_vm
