# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 17:37:07 by blinnea           #+#    #+#              #
#    Updated: 2020/11/08 17:48:19 by fhilary          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL=/bin/zsh
# **************************************************************************** #
#                                 COLOURS                                      #
# **************************************************************************** #
DEFAULT = \033[0m
YELLOW = \033[1;33m
GREEN = \033[1;32m
RED = \033[1;31m
GREENB = \033[42m

# **************************************************************************** #
#                               COMPILER OPTIONS                               #
# **************************************************************************** #
CC = clang
CF = -Wall -Wextra -Werror -m64 -ggdb -fPIE

NAME = libft

# **************************************************************************** #
#                                 HEADERS                                      #
# **************************************************************************** #
FT_H =		include/$(NAME).h
LST_H =		include/$(NAME)_list.h
STR_H =		include/$(NAME)_string.h
CTP_H =		include/$(NAME)_ctype.h
IO_H =		include/$(NAME)_io.h
QUE_H =		include/$(NAME)_queue.h
MEM_H =		include/$(NAME)_memory.h
INT_H =		include/$(NAME)_integer.h
GNL_H =		include/$(NAME)_get_next_line.h
FLT_H =		include/$(NAME)_float.h
PFB_H =		include/$(NAME)_pfbuffer.h
GOP_H =		include/$(NAME)_getopt.h
DLST_H =	include/$(NAME)_dlist.h
ALG_H =		include/$(NAME)_algo.h
ELST_H =	include/$(NAME)_elist.h
ARRAY_H =	include/ft_array.h

# **************************************************************************** #
#                                 FILENAMES                                    #
# **************************************************************************** #
LSTFILES =		$(shell find src/list -name '*.c')
STRFILES =		$(shell find src/string -name '*.c')
CTPFILES =		$(shell find src/ctype -name '*.c')
IOFILES =		$(shell find src/io -name '*.c')
QUEFILES =		$(shell find src/queue -name '*.c')
MEMFILES =		$(shell find src/memory -name '*.c')
INTFILES =		$(shell find src/integer -name '*.c')
GNLFILES =		$(shell find src/get_next_line -name '*.c')
FLTFILES =		$(shell find src/float -name '*.c')
PFBFILES =		$(shell find src/pfbuffer -name '*.c')
PFFILES =		$(shell find src/printf -name '*.c')
GOPFILES =		$(shell find src/getopt -name '*.c')
DLSTFILES =		$(shell find src/dlist -name '*.c')
ALGFILES =		$(shell find src/algo -name '*.c')
ELSTFILES =		$(shell find src/elist -name '*.c')
ARRAYFILES =	$(shell find src/ft_array -name '*.c')

LSTOFILES =		$(addprefix obj/, $(LSTFILES:src/list/%.c=%.o))
STROFILES =		$(addprefix obj/, $(STRFILES:src/string/%.c=%.o))
CTPOFILES =		$(addprefix obj/, $(CTPFILES:src/ctype/%.c=%.o))
IOOFILES =		$(addprefix obj/, $(IOFILES:src/io/%.c=%.o))
QUEOFILES =		$(addprefix obj/, $(QUEFILES:src/queue/%.c=%.o))
MEMOFILES =		$(addprefix obj/, $(MEMFILES:src/memory/%.c=%.o))
INTOFILES =		$(addprefix obj/, $(INTFILES:src/integer/%.c=%.o))
GNLOFILES = 	$(addprefix obj/, $(GNLFILES:src/get_next_line/%.c=%.o))
FLTOFILES = 	$(addprefix obj/, $(FLTFILES:src/float/%.c=%.o))
PFBOFILES = 	$(addprefix obj/, $(PFBFILES:src/pfbuffer/%.c=%.o))
PFOFILES =		$(addprefix obj/, $(PFFILES:src/printf/%.c=%.o))
GOPOFILES =		$(addprefix obj/, $(GOPFILES:src/getopt/%.c=%.o))
DLSTOFILES =	$(addprefix obj/, $(DLSTFILES:src/dlist/%.c=%.o))
ALGOFILES =		$(addprefix obj/, $(ALGFILES:src/algo/%.c=%.o))
ELSTOFILES =	$(addprefix obj/, $(ELSTFILES:src/elist/%.c=%.o))
ARRAYOFILES =	$(addprefix obj/, $(ARRAYFILES:src/ft_array/%.c=%.o))

ALLOFILES =		$(LSTOFILES) $(STROFILES) $(CTPOFILES) $(IOOFILES) $(QUEOFILES)\
				$(MEMOFILES) $(INTOFILES) $(GNLOFILES) $(FLTOFILES)\
				$(PFBOFILES) $(PFOFILES) $(GOPOFILES) $(DLSTOFILES)\
				$(ALGOFILES) $(ELSTOFILES) $(ARRAYOFILES)

.PHONY: dir clean fclean re all

all: dir $(NAME).a

$(NAME).a: Makefile $(ALLOFILES)
	@ar rc $@ $(ALLOFILES)
	@ranlib $@
	@echo "\n> $(GREEN)$(NAME) created$(DEFAULT)"

# create temporary directories
dir:
	@mkdir -p obj

# create list object files
obj/%.o: src/list/%.c $(MEM_H) $(LST_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create string object files
obj/%.o: src/string/%.c $(CTP_H) $(MEM_H) $(STR_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create ctype object files
obj/%.o: src/ctype/%.c $(CTP_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create io object files
obj/%.o: src/io/%.c $(FT_H) $(STR_H) $(IO_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create queue object files
obj/%.o: src/queue/%.c $(MEM_H) $(LST_H) $(QUE_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create memory object files
obj/%.o: src/memory/%.c $(MEM_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create integer object files
obj/%.o: src/integer/%.c $(CTP_H) $(STR_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create get_next_line object files
obj/%.o: src/get_next_line/%.c $(MEM_H) $(STR_H) $(LST_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create float object files
obj/%.o: src/float/%.c $(MEM_H) $(STR_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create pfbuffer object files
obj/%.o: src/pfbuffer/%.c $(MEM_H) $(STR_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create printf object files
obj/%.o: src/printf/%.c $(MEM_H) $(STR_H) $(INT_H) $(PFB_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create getopt object files
obj/%.o: src/getopt/%.c $(STR_H) $(GOP_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create dlist object files
obj/%.o: src/dlist/%.c $(MEM_H) $(DLST_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create algo object files
obj/%.o: src/algo/%.c $(ALG_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create elist object files
obj/%.o: src/elist/%.c $(DLST_H) $(ELST_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create array object files
obj/%.o: src/ft_array/%.c $(ARRAY_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

clean:
	@rm -f $(ALLOFILES)
	@rm -fd obj
	@echo "> $(YELLOW)$(NAME) clean$(DEFAULT)"

fclean: clean
	@rm -f $(NAME).a
	@echo "> $(RED)$(NAME) fclean$(DEFAULT)"

re: fclean all
