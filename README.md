## so_long: Building and Running the Game

This README provides instructions on how to build and run the `so_long` game using the provided Makefile.

**Requirements:**

  * **Compiler:** gcc (or compatible)
  * **Libraries:**
      * MiniLibX ([https://github.com/yazan-metax/minilibX](https://www.google.com/url?sa=E&source=gmail&q=https://github.com/yazan-metax/minilibX))

**Building the Game:**

1.  **Clone or Download the Project:**
    Make sure you have a copy of the project directory containing the `Makefile`.

2.  **Compile Dependencies:**
    The Makefile relies on two external libraries, MiniLibX and Libft. You need to compile these libraries before building `so_long`.

      * **MiniLibX:**

          * If you haven't already, download or clone the MiniLibX library from its repository.
          * Navigate to the MiniLibX directory within your project (usually `./mlx`).
          * Run `make` to compile the library. This will create `libmlx.a` which the Makefile references.

      * **Libft (Optional):**

          * If you plan to use the included `libft` library (for internal functions), follow similar steps to compile it within the `./libft` directory.

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
    ./so_long
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
