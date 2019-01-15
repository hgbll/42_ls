# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 17:12:52 by hbally            #+#    #+#              #
#    Updated: 2019/01/15 18:00:04 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	ft_ls

# Dir Variables

SRCSDIR   			=	srcs

OBJSDIR   			=	objs

TESTDIR				=	_test

LIBDIR				=	.

LIBSUBDIRS			:=	$(LIBDIR)/libft

INCDIR				:=	$(LIBSUBDIRS:%=%/includes) \
						includes

# File Variables

SRCS_RAW			:=	main.c 						\
						get_options.c				\
						display_dir.c				\
						error_handler.c				\
						stats_type.c				\
						get_dirlist.c				\
						exit_dir.c					\
						print_dir.c

SRCS				:=	$(SRCS_RAW:%.c=$(SRCSDIR)/%.c)

OBJS  				:=	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

DEPENDENCIES		:=	$(OBJS:%.o=%.d)

LIBFILES			:=	$(foreach LIB, $(LIBSUBDIRS), $(LIB)/$(notdir $(LIB)).a)

# Compiler Config

CC					=	gcc

CFLAGS				+=	-Wall -Werror -Wextra

INCLUDES			:=	$(addprefix -I ,$(INCDIR))

INCLIBS				:=	$(foreach LIB, $(LIBSUBDIRS), -L $(LIB) $(subst lib,-l,$(notdir $(LIB))))

# Main Target

all					:	libs $(NAME)

$(NAME)				: 	$(OBJS) $(LIBFILES)
						$(CC) -o $@ $(CFLAGS) $(LIBS) $(OBJS)

# Make Libs

.PHONY				:	libs
libs				:
						@git submodule foreach git pull origin master
						@$(foreach LIB, $(LIBSUBDIRS), make -C $(LIB);)

# Objs Target

-include $(DEPENDENCIES)

$(OBJS)				: 	$(OBJSDIR)/%.o : $(SRCSDIR)/%.c
						@mkdir -p objs
						$(CC) -o $@ $(CFLAGS) $(INCLUDES) -MMD -c $<

# Cleanup

.PHONY				:	clean
clean				:
						rm -f $(OBJS) $(DEPENDENCIES)
						rm -rf $(OBJSDIR)
						@$(foreach LIB, $(LIBSUBDIRS), make clean -C $(LIB);)

.PHONY				:	fclean
fclean				:	clean
						rm -f $(NAME)
						@$(foreach LIB, $(LIBSUBDIRS), make fclean -C $(LIB);)

.PHONY				:	re
re					:	fclean all
