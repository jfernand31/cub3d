# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 19:45:19 by jfernand          #+#    #+#              #
#    Updated: 2025/04/22 11:45:28 by jfernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the project
NAME=get_new_line.a

# Object files
CFILES= ./get_next_line.c        \
		./get_next_line_utils.c  \

# .h files
HFILES= ./get_new_line.h       \
		./get_new_line_bonus.h \

# .c bonus files
BFILES= ./get_next_line_bonus.c       \
		./get_next_line_utils_bonus.c \

# Object files
OFILES= $(CFILES:.c=.o)

# Bonus object files
BOFILES= $(BFILES:.c=.o)

# Compiler
CC=@cc

# Flags for compiler
CCFLAGS=-Wall      \
        -Wextra    \
        -Werror    \

# Command used to archive target
AR= @ar -rcs

# Command used to clean target
RM = rm -rf

#
# Compilation and linking
#
all: $(NAME)

$(NAME): $(OFILES) 
	@ echo 'Building binary: $@'
	$(AR) $@ $^
	@ echo 'Finished building binary: $@'

bonus: $(OFILES) $(BOFILES)
	@ echo 'Building Bonus binary: $(NAME)'
	$(AR) $(NAME) $(OFILES) $(BOFILES)
	@ echo 'Finished building Bonus binary: $(NAME)'

$(OFILES): %.o:%.c
	@ echo 'Building target: $@'
	@ $(CC) $(CCFLAGS) -c $< -o $@

clean:
	@ $(RM) $(OFILES) $(BOFILES)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

.PHONY= all clean fclean re bonus




