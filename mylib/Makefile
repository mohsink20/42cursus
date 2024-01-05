GNL_DIR = get_next_line
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

LIB_NAME = mylib.a

all: $(LIB_NAME)

$(LIB_NAME): gnl libft printf
	@echo "Creating library: $(LIB_NAME)"
	@ar rcs $(LIB_NAME) $(PRINTF_DIR)/*.o $(GNL_DIR)/*.o $(LIBFT_DIR)/*.o
	@echo "Library creation completed."

gnl:
	@echo "Compiling GNL..."
	@$(MAKE) -C $(GNL_DIR) --no-print-directory --silent

libft:
	@echo "Compiling Libft..."
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory --silent

printf:
	@echo "Compiling Printf..."
	@$(MAKE) -C $(PRINTF_DIR) --no-print-directory --silent

clean:
	@echo "Cleaning GNL, Libft and Printf object files..."
	@$(MAKE) -C $(GNL_DIR) clean --no-print-directory --silent
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory --silent
	@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory --silent
	@echo "Clean complete."

fclean: clean
	@echo "Cleaning library and binaries..."
	@$(MAKE) -C $(GNL_DIR) fclean --no-print-directory --silent
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory --silent
	@$(MAKE) -C $(PRINTF_DIR) fclean --no-print-directory --silent
	@rm -f $(LIB_NAME)
	@echo "Full clean complete."

re: fclean all
	@echo "Recompilation complete."

.PHONY: all gnl libft printf clean fclean re
