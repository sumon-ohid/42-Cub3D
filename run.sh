#!/bin/bash

#norminette -RCheckForbiddenHeader

make re

valgrind --suppressions=valgrind.supp --leak-check=full --show-leak-kinds=all ./cub3D maps/wood.cub 

make fclean