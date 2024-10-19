## so_long: Building and Running the Game
`so_long` is a simple 2D game developed using the MiniLibX library for rendering. The game features basic controls and gameplay where the player interacts with a map, collecting items and finding exit.

**Requirements:**

  * **Compiler:** gcc (or compatible)
  * **Libraries:**
      * MiniLibX (https://github.com/42Paris/minilibx-linux.git)

**Building the Game:**

1.  **Clone or Download the Project:**
    Make sure you have a copy of the project directory containing the `Makefile`.

	```bash
    git clone https://github.com/thanthtetaung4/ft_so_long.git
	cd ft_so_long
    ```

2.  **Compile Dependencies:**
    The Makefile relies on two external libraries, MiniLibX and Libft. You need to compile these libraries before building `so_long`.

      * **MiniLibX:**

          * If you haven't already, download or clone the MiniLibX library from its repository.
          * Navigate to the MiniLibX directory within your project (usually `./mlx`).
          * Run `make` to compile the library. This will create `libmlx.a` which the Makefile references.

      * **Libft:**

          * It is included in this git :).

3.  **Build `so_long`:**
    Navigate back to the main project directory containing the `Makefile`.
    Run the following command:

    ```bash
    make
    ```

    This will build the `so_long` executable using the compiled libraries and your source code.

**Running the Game:**

  * Once the build is successful, you should have an executable named `so_long` in the project directory.

  * You can run the game by executing:

    ```bash
    ./so_long $(MAP_PATH)
    ```

This will launch the `so_long` game (assuming you have the required libraries installed or linked correctly).

**Additional Notes:**

  * The `make clean` command removes all object files generated during compilation.
  * The `make fclean` command removes both object files and the final executable.
  * The `make re` command performs a full clean and then rebuilds everything.

**Customization:**

  * You can modify the `CFLAGS` variable in the Makefile to add compiler flags for warnings or optimizations (e.g., `CFLAGS=-Wall -Wextra`).

**Testing (Optional):**

The Makefile includes a basic test target named `test`. If you've defined any test source files in the `./test` directory, you can build and run the tests using:

```bash
make test
```

This will compile the test executable and (potentially) run any tests defined within those files.
