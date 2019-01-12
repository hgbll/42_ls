# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 09:24:07 by hbally            #+#    #+#              #
#    Updated: 2019/01/09 15:44:36 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	ft_list_dir

SRCSDIR   			=	.

SRCS				:=	$(SRCSDIR)/ft_list_dir.c			\
						$(SRCSDIR)/main.c

INCLUDES			=	-I libft/includes					\
						-I includes

OBJSDIR   			=	objs

OBJS				:=	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

DEPENDENCIES		=	$(OBJS:%.o=%.d)

CC					=	gcc

CFLAGS				+=	-Wall -Werror -Wextra

all					:	$(NAME)

$(NAME)				: 	$(OBJS)
						$(CC) -o $@ $(CFLAGS) -L./libft -lft $(OBJS)

-include $(DEPENDENCIES)

$(OBJS)				: 	$(OBJSDIR)/%.o : $(SRCSDIR)/%.c
						@mkdir -p objs
						$(CC) -o $@ $(CFLAGS) $(INCLUDES) -MMD -c $<

.PHONY				:	clean
clean				:
						rm -f $(OBJS) $(DEPENDENCIES)
						rm -rf $(OBJSDIR)

.PHONY				:	fclean
fclean				:	clean
						rm -f $(NAME)

.PHONY				:	re
re					:	fclean all
