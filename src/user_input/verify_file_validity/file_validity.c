/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.fradin
** File description:
** file_validity
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_navy.h"
#include "my.h"

/**
 * @see operate_on_line()
 *
 * @brief verify line's content validity, such as 'in borders' given letters
          and numbers.
 *
 * @param word_array[in] the word array of the currently read line.
 * @retvam NAVY_SUCCESS on success.
 * @retval NAVY_ERR on failure.
 * @todo criterion
 */
static int verify_content_line(char **word_array)
{
    for (int i = 1; i < 3; i++) {
        if (word_array[i][0] < 'A' || word_array[i][0] > 'H') {
            write(2, "Letters must be between 'A' & 'H' inclusive.\n", 45);
            return NAVY_ERR;
        }
        if (word_array[i][1] < '0' || word_array[i][1] > '8') {
            write(2, "Numbers must be between 1 & 8 inclusive.\n", 41);
            return NAVY_ERR;
        }
    }
    if ((word_array[1][0] != word_array[2][0] &&
            word_array[1][1] != word_array[2][1])
        || (word_array[1][0] == word_array[2][0] &&
        word_array[1][1] == word_array[2][1]))
        return NAVY_ERR;
    return NAVY_SUCCESS;
}

/**
 * @see looping_on_lines()
 *
 * @brief verify file's first column validity and initiate the lines' content
 *        verification.
 *
 * @param line_checker that's a good question.
 * @param word_array the word array of the currently read line.
 * @retval NAVY_SUCCESS on success.
 * @retval NAVY_ERR on failure.
 * @todo criterion
 */
static int operate_on_line(int line_checker, char **word_array)
{
    char *free_me = my_itoa(line_checker);
    if (line_checker < 6 && my_strncmp(word_array[0],
        free_me, 1)) {
        write(2, "Line arrangement not valid : must be in this order \
2, 3, 4, 5. No more nor less.\n", 80);
        return NAVY_ERR;
    }
    free(free_me);
    if (verify_content_line(word_array)) return NAVY_ERR;
    return NAVY_SUCCESS;
}

/**
 * @see verify_file_validity()
 *
 * @brief read the file line by line to prepare content validity verification.
 *
 * @param file_ptr[in] pointer to a FILE.
 * @retval NAVY_SUCCESS on success.
 * @retval NAVY_ERR on failure.
 * @todo criterion
 */
static int looping_on_lines(FILE *file_ptr)
{
    int bytes_read = 0;
    int number_of_lines = 0;
    size_t len = 0;
    int line_checker = 2;
    char *lineptr = NULL;
    while ((bytes_read = getline(&lineptr, &len, file_ptr) != -1)) {
        if (my_strlen(lineptr) != 8) return NAVY_ERR;
        char **word_array = my_str_to_word_array_free_delimiter(lineptr);
        if (char_tab_len(word_array) != 3) {
            write(2, "Invalid number of columns in one or more line: must be \
3.\n", 58);
            return NAVY_ERR;
        } number_of_lines++;
        if (operate_on_line(line_checker, word_array)) return NAVY_ERR;
        line_checker++;
        free_str_tab(word_array);
    } if (number_of_lines != 4) {
        write(2, "Invalid number of lines.\n", 25);
        return NAVY_ERR;
    } return NAVY_SUCCESS;
}

/**
 * @see user_input()
 *
 * @brief verify, line  by line,
 *        the conditions precised in @c file_validity_conditions.txt .
 *
 * @param path[in] to the file to be opened.
 * @retval NAVY_SUCCESS on success.
 * @retval NAVY_ERR on failure.
 * @todo criterion
 */
int verify_file_validity(char const *path)
{
    FILE *file_ptr = NULL;
    file_ptr = fopen(path, "r");
    if (file_ptr == NULL) { write(2, "Failed to open the file.\n", 25);
        return NAVY_ERR;
    }
    if (looping_on_lines(file_ptr))  {
        fclose(file_ptr);
        return NAVY_ERR;
    }
    fclose(file_ptr);
    return NAVY_SUCCESS;
}
