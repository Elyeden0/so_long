# Compiler and flags
CC       = cc
CFLAGS   = -Wall -Wextra -Werror


# Colors for messages
YELLOW = \033[1;33m
GREEN = \033[1;32m
RESET = \033[0m

BOX_TOP    = ╔══════════════════════╗
BOX_MIDDLE = ║                      ║
BOX_BOTTOM = ╚══════════════════════╝

# Directories
SRC_DIR  = srcs
BONUS_DIR = bonus
OBJ_DIR  = objs
LIBFT_DIR = libft
MLX_DIR  = .minilibx-linux

# Libraries
LIBFT    = $(LIBFT_DIR)/libft.a
MLX      = $(MLX_DIR)/libmlx_Linux.a
LIBS     = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm

# Includes
INCLUDES = -I$(LIBFT_DIR) -I$(MLX_DIR) -Iinclude
BONUS_INCLUDES = -Ibonus_include -I$(MLX_DIR) -I$(LIBFT_DIR)

# Source files and object files
SRCS     = $(SRC_DIR)/check_map.c \
		   $(SRC_DIR)/tools.c \
		   $(SRC_DIR)/check_exit_and_coll.c \
		   $(SRC_DIR)/parse_map.c \
		   $(SRC_DIR)/player_data.c \
		   $(SRC_DIR)/player_can_exit.c \
		   $(SRC_DIR)/load_textures.c \
		   $(SRC_DIR)/movement.c \
		   $(SRC_DIR)/main.c \

BONUS_SRCS = $(BONUS_DIR)/check_exit_and_coll.c \
             $(BONUS_DIR)/check_map.c \
			 $(BONUS_DIR)/load_textures.c \
			 $(BONUS_DIR)/main.c \
			 $(BONUS_DIR)/movement.c \
			 $(BONUS_DIR)/parse_map.c \
			 $(BONUS_DIR)/player_can_exit.c \
			 $(BONUS_DIR)/player_data.c \
			 $(BONUS_DIR)/tools.c \
			 $(BONUS_DIR)/animation.c \

OBJS     = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_OBJS = $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

# Output executable
NAME     = so_long
BONUS_NAME = so_long_bonus

# Rules
all: $(LIBFT) $(MLX) $(NAME)

# Make bonus version
bonus: $(LIBFT) $(MLX) $(BONUS_NAME)

# Compile libft if not already compiled
$(LIBFT):
	@echo "$(YELLOW)Compiling my beautiful libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) all > /dev/null
	@echo "$(GREEN)Compilation of libft finished.$(RESET)"

# Compile MiniLibX if not already compiled
$(MLX):
	@echo "$(YELLOW)Compiling MiniLibX...$(RESET)"
	@$(MAKE) -s -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(GREEN)Compilation of MiniLibX finished.$(RESET)"

# Create object directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(BONUS_INCLUDES) -c $< -o $@

# Link the executable
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)$(BOX_TOP)"
	@echo "$(GREEN)║ Executable compiled. ║$(RESET)"
	@echo "$(GREEN)$(BOX_BOTTOM)$(RESET)"

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBS) -o $(BONUS_NAME)
	@echo "$(GREEN)$(BOX_TOP)"
	@echo "║ Bonus ver. compiled. ║$(RESET)"
	@echo "$(GREEN)$(BOX_BOTTOM)$(RESET)"

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Clean done."

# Clean object files and executable
fclean: clean
	@echo "$(YELLOW)Cleaning MinilibX...$(RESET)"
	@$(MAKE) -s -C $(MLX_DIR) clean > /dev/null 2>&1
	@echo "$(GREEN)MinilibX cleaned.$(RESET)"
	@echo "$(YELLOW)Cleaning libft...$(RESET)"
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)MinilibX cleaned.$(RESET)"
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "$(GREEN)Full clean done.$(RESET)"

# Rebuild
re: fclean all
rebonus: fclean bonus
.PHONY: all clean fclean re
