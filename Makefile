################################################################################
# Makefile
################################################################################

# Makefile by fletcher97
# Version: 1.3

# This makefile can be copied to a directory and it will generate the file
# structure and initialize a git repository with the .init rule. Any variables
# and rules for the specifique project can be added in the appropriate section.

################################################################################
# Project Variables
################################################################################

# Name of a single binary. Add as many variables as required by the project
NAME1 = push_swap
NAME2 = chacker

# The names of all the binaries. Add aditional variables created above.
NAMES = ${NAME1} ${NAME2}

# Libft
LIBFT_ROOT := ${LIB_ROOT}libft/
LIBFT_INC := ${LIBFT_ROOT}inc/
LIBFT := ${LIBFT_ROOT}bin/libft.a
LIBS := -L${LIBFT_ROOT}bin -lft

################################################################################
# Configs
################################################################################

# Verbose levels
# 0: Make will be totaly silenced
# 1: Make will print echos and printf
# 2: Make will not be silenced but target commands will not be printed
# 3: Make will print each command
# 4: Make will print all debug info
#
# If no value is specified or an incorrect value is given make will print each
# command like if VERBOSE was set to 3.
VERBOSE = 1

################################################################################
# Compiler & Flags
################################################################################

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Wvla
DFLAGS = -g -fsanitize=address

################################################################################
# Folders & Files
################################################################################

BIN_ROOT = bin/
DEP_ROOT = dep/
INC_ROOT = inc/
LIB_ROOT = lib/
OBJ_ROOT = obj/
SRC_ROOT = src/
TESTS_ROOT = tests/

DIRS = push_swap/ checker/

SRC_DIRS := $(addprefix ${SRC_ROOT}, ${DIRS})
OBJ_DIRS := $(addprefix ${OBJ_ROOT}, ${DIRS})
DEP_DIRS := $(addprefix ${DEP_ROOT}, ${DIRS})
INC_DIRS := ${INC_ROOT}

SRCS_MAIN := $(foreach dir, $(filter-out ${SRC_ROOT}/checker/%, ${SRC_DIRS}), \
	$(wildcard ${dir}*.c))
SRCS_CHECKER := $(foreach dir, $(filter-out ${SRC_ROOT}/push_swap/%, \
	${SRC_DIRS}), $(wildcard ${dir}*.c))
OBJS_MAIN := $(subst ${SRC_ROOT}, ${OBJ_ROOT}, ${SRCS_MAIN:.c=.o})
OBJS_CHECKER := $(subst ${SRC_ROOT}, ${OBJ_ROOT}, ${SRCS_CHECKER:.c=.o})
SRCS := $(foreach dir, ${SRC_DIRS}, $(wildcard ${dir}*.c))
OBJS := $(subst ${SRC_ROOT}, ${OBJ_ROOT}, ${SRCS:.c=.o})
DEPS := $(subst ${SRC_ROOT}, ${DEP_ROOT}, ${SRCS:.c=.d})

TESTS := $(wildcard ${TESTS_ROOT}*.c)

INCS := ${addprefix -I, ${INC_DIRS}}

BINS := ${addprefix ${BIN_ROOT}, ${NAMES}}
TEST := ${TESTS_ROOT}mytest

################################################################################
# VPATHS
################################################################################

vpath %.o $(OBJ_ROOT)
vpath %.h $(INC_ROOT)
vpath %.c $(SRC_DIRS)
vpath %.d $(DEP_DIRS)

################################################################################
# Conditions
################################################################################

ifeq ($(shell uname), Linux)
	SED := sed -i.tmp --expression
	SED_END = && rm -f $@.tmp
else ifeq ($(shell uname), Darwin)
	SED = sed -i.tmp
	SED_END = && rm -f $@.tmp
endif

ifeq ($(VERBOSE),0)
	MAKEFLAGS += --silent
	BLOCK = &>/dev/null
else ifeq ($(VERBOSE),1)
	MAKEFLAGS += --silent
else ifeq ($(VERBOSE),2)
	AT = @
else ifeq ($(VERBOSE),4)
	MAKEFLAGS += --debug=v
endif

################################################################################
# Project Target
################################################################################

all: ${BINS}

${NAME1}: ${LIBFT} ${OBJS_MAIN}
	${AT}printf "\033[38;5;46m[CREATING ${NAME} ]\033[0m\n" ${BLOCK}
	${AT}mkdir -p ${BIN_ROOT}
	${AT}${CC} ${CFLAGS} ${INCS} ${OBJS_MAIN} ${LIBS} -o ${BIN_ROOT}$@

${NAME2}: ${LIBFT} ${OBJS_CHECKER}
	${AT}printf "\033[38;5;46m[CREATING ${NAME} ]\033[0m\n" ${BLOCK}
	${AT}mkdir -p ${BIN_ROOT}
	${AT}${CC} ${CFLAGS} ${INCS} ${OBJS_CHECKER} ${LIBS} -o ${BIN_ROOT}$@

################################################################################
# Setup Target
################################################################################

.init:
	${AT}printf "\033[33m[CREATING FOLDER STRUCTURE]\033[0m\n" ${BLOCK}
	${AT}mkdir -p ${BIN_ROOT} ${BLOCK}
	${AT}mkdir -p ${DEP_ROOT} ${BLOCK}
	${AT}mkdir -p ${INC_ROOT} ${BLOCK}
	${AT}mkdir -p ${OBJ_ROOT} ${BLOCK}
	${AT}mkdir -p ${SRC_ROOT} ${BLOCK}
	${AT}mkdir -p ${TESTS_ROOT} ${BLOCK}
	${AT}printf "\033[33m[INITIALIZING GIT REPOSITORY]\033[0m\n" ${BLOCK}
	${AT}git init ${BLOCK}
	${AT}echo "*.o\n*.d\n.vscode\na.out\n.DS_Store" > .gitignore ${BLOCK}
	${AT}date > $@ ${BLOCK}
	${AT}printf "\033[33m[CREATING FIRST COMMIT]\033[0m\n" ${BLOCK}
	${AT}git add .gitignore ${BLOCK}
	${AT}git add $@ ${BLOCK}
	${AT}git add Makefile ${BLOCK}
	${AT}git commit -m "init" ${BLOCK}

################################################################################
# Clean Targets
################################################################################

clean:
	${AT}printf "\033[38;5;1m[REMOVING OBJECTS]\033[0m\n" ${BLOCK}
	${AT}mkdir -p ${OBJ_ROOT} ${BLOCK}
	${AT}find ${OBJ_ROOT} -type f -delete ${BLOCK}

fclean: clean
	${AT}printf "\033[38;5;1m[REMOVING BINARIES]\033[0m\n" ${BLOCK}
	${AT}mkdir -p ${BIN_ROOT} ${BLOCK}
	${AT}find ${BIN_ROOT} -type f -delete ${BLOCK}

clean_dep:
	${AT}printf "\033[38;5;1m[REMOVING DEPENDENCIES]\033[0m\n" ${BLOCK}
	${AT}mkdir -p ${DEP_ROOT} ${BLOCK}
	${AT}find ${DEP_ROOT} -type f -delete ${BLOCK}

clean_all: clean_dep fclean

re: fclean all

################################################################################
# Debug Targets
################################################################################

debug: CFLAGS += ${DFLAGS}
debug: all

debug_re: fclean debug

################################################################################
# Test Targets
################################################################################

testre: debug_re ${TEST}

testm: debug ${TEST}

${TEST}: CFLAGS += ${DFLAGS}
${TEST}:

################################################################################
# .PHONY
################################################################################

.PHONY : clean fclean clean_dep clean_all re all testre testm ${TEST}

################################################################################
# Function
################################################################################

define make_bin
${1} : ${2}
endef

define make_obj
${1} : ${2} ${3}
	$${AT}printf "\033[38;5;14m[OBJ]: \033[38;5;47m$$@\033[0m\n" $${BLOCK}
	$${AT}mkdir -p $${@D} $${BLOCK}
	$${AT}$${CC} $${CFLAGS} $${INCS} -c $$< -o $$@ $${BLOCK}
endef

define make_dep
${1} : ${2}
	$${AT}printf "\033[38;5;13m[DEP]: \033[38;5;47m$$@\033[0m\n" $${BLOCK}
	$${AT}mkdir -p $${@D} $${BLOCK}
	$${AT}$${CC} -MM $$< -I $${INC_ROOT} -MF $$@ $${BLOCK}
	$${AT}$${SED} 's|:| $$@ :|' $$@ $${SED_END} $${BLOCK}
	$${AT}$${SED} '1 s|^|$${@D}/|' $$@ $${SED_END} $${BLOCK}
endef

################################################################################
# Function Generator
################################################################################

$(foreach bin, $(BINS), $(eval \
$(call make_bin, $(bin), $(notdir $(bin)))))

$(foreach src, $(SRCS), $(eval \
$(call make_dep, $(subst ${SRC_ROOT}, ${DEP_ROOT}, $(src:.c=.d)), $(src))))

$(foreach src, $(SRCS), $(eval \
$(call make_obj, $(subst ${SRC_ROOT}, ${OBJ_ROOT}, $(src:.c=.o)), \
$(src), \
$(subst ${SRC_ROOT}, ${DEP_ROOT}, $(src:.c=.d)))))

################################################################################
# Includes
################################################################################

-include ${DEPS}
