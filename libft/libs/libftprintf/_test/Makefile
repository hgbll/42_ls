# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 09:24:07 by hbally            #+#    #+#              #
#    Updated: 2018/12/31 13:09:17 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	ftprintf_test

LIBFT				=	libft

BINDIR				=	.

SRCSDIR   			=	srcs

SRCS			   :=	$(SRCSDIR)/main.c					\
						$(SRCSDIR)/test_string.c			\
						$(SRCSDIR)/test_double.c			\
						$(SRCSDIR)/test_int.c				\
						$(SRCSDIR)/loops.c					\
						$(SRCSDIR)/debug_print_memory.c	

OBJSDIR   			=	objs

OBJS  			   :=	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

DEPENDENCIES		=	$(OBJS:%.o=%.d)

INCLUDES			=	-I includes							\
						-I $(LIBFT)/includes

LIBS				=	-L./$(LIBFT)/ -lft

CC					=	gcc

CFLAGS			   +=	

all					:	libs $(BINDIR)/$(NAME)

.PHONY				:	libs
libs				:
						@make -C $(LIBFT)

.PHONY				:	run
run					:	all
						rm -f testoutput_printf
						rm -f testoutput_ft_printf
						./ftprintf_test printf > testoutput_printf
						./ftprintf_test ft_printf > testoutput_ft_printf
						diff testoutput_printf testoutput_ft_printf

.PHONY				:	runstdout
runstdout			:	all
						./ftprintf_test printf
						./ftprintf_test ft_printf

$(BINDIR)/$(NAME)	: 	$(OBJS) 
						$(CC) -o $@ $(CFLAGS) $(OBJS) $(LIBS)

-include $(DEPENDENCIES)

$(OBJS)				: 	$(OBJSDIR)/%.o : $(SRCSDIR)/%.c
						@mkdir -p objs
						$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

.PHONY				:	clean
clean				:
						rm -f $(OBJS) $(DEPENDENCIES)
						rm -rf $(OBJSDIR)

.PHONY				:	fclean
fclean				:	clean
						rm -f $(BINDIR)/$(NAME)

re					:	fclean all
