NAME				=	ft_ls

# Dir Variables

SRCSDIR   			=	srcs

OBJSDIR   			=	objs

TESTDIR				=	_test

LIBDIR				=	libs

LIBSUBDIR			:=	$(LIBDIR)/libft

INCDIR				:=	$(LIBSUBDIR:%=%/includes) \
						includes

# File Variables

SRCS_RAW			:=	main.c 						\
						get_options.c

SRCS				:=	$(SRCS_RAW:%.c=$(SRCSDIR)/%.c)

OBJS  				:=	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

DEPENDENCIES		:=	$(OBJS:%.o=%.d)

# Compiler Config

CC					=	gcc

CFLAGS				+=	-Wall -Werror -Wextra

INCLUDES			:=	$(addprefix -I ,$(INCDIR))

LIBS				:=	$(foreach LIB, $(LIBSUBDIR), -L $(LIBSUBDIR) $(subst lib,-l,$(notdir $(LIB))))

# Main Target

all					:	libs $(NAME)

$(NAME)				: 	$(OBJS)
						$(CC) -o $@ $(CFLAGS) $(LIBS) $(OBJS)

# Make Libs

.PHONY				:	libs
libs				:
						@$(foreach LIB, $(LIBSUBDIR), make -C $(LIB);)

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
						@$(foreach LIB, $(LIBSUBDIR), make clean -C $(LIB);)

.PHONY				:	fclean
fclean				:	clean
						rm -f $(NAME)
						@$(foreach LIB, $(LIBSUBDIR), make fclean -C $(LIB);)

.PHONY				:	re
re					:	fclean all
