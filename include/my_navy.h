/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.fradin
** File description:
** my_navy
*/

/**
 * @file my_navy.h
 * @brief navy header file
 */

#ifndef MY_NAVY_H_
    #define MY_NAVY_H_
    #include <stdbool.h>
    #include <stdint.h>

    /**
     * @def GET_STATE(mesg)
     * @brief Gets the meaning of the message received from the opponent.
     * @see byte_state
     * @param mesg[in] The message received form the opponent.
     * @see send_byte()
     * @see receive_byte()
     * @return The state of the message in @c byte_state.
     */
    #define GET_STATE(mesg) ((mesg >> 6) & 3U)

    /**
     * @def GET_COLUMN(mesg)
     * @brief Gets the column of the message received from the opponent.
     * @param mesg[in] The message received form the opponent.
     * @see send_byte()
     * @see receive_byte()
     * @return The column of the message @f$\in [0, 8[@f$.
     */
    #define GET_COLUMN(mesg) ((mesg >> 3) & 7U)

    /**
     * @def GET_LINE(mesg)
     * @brief Gets the line of the message received from the opponent.
     * @param mesg[in] The message received form the opponent.
     * @see send_byte()
     * @see receive_byte() @f$\in [0, 8[@f$
     * @return The line of the message @f$\in [0, 8[@f$.
     */
    #define GET_LINE(mesg) (mesg & 7U)

    /**
     * @def SET_STATE(mesg, state)
     * @brief Sets the state of message to be sent to the opponent.
     * @param mesg[in, out] The message to be sent to the opponent.
     * @param state[out] The state to write to the message in @c byte_state.
     * @see byte_state
     * @return The modified message.
     */
    #define SET_STATE(mesg, state) mesg |= (state << 6)

    /**
    * @def SET_COLUMN(mesg, column)
    * @brief Sets the state of message to be sent to the opponent.
    * @param mesg[in, out] The message to be sent to the opponent.
    * @param column[out] The column to write to the message @f$\in [0, 8[@f$.
    * @return The modified message.
    */
    #define SET_COLUMN(mesg, column) mesg |= ((column & 7U) << 3)

    /**
     * @def SET_LINE(mesg, line)
     * @brief Sets the state of message to be sent to the opponent.
     * @param mesg[in, out] The message to be sent to the opponent.
     * @param line[out] The line to write to the message @f$\in [0, 8[@f$.
     * @return The modified message.
     */
    #define SET_LINE(mesg, line) mesg |= (line & 7U)

    /**
     * @def SET_TORP(m, c, l)
     * @brief Sets a torpedo with given column and line.
     * @param m[out] The message to be sent to the opponent.
     * @param c[out] The column to write to the message @f$\in [0, 8[@f$.
     * @param l[out] The line to write to the message @f$\in [0, 8[@f$.
     * @return The message.
     */
    #define SET_TORP(m, c, l) m |= ((TORPEDO << 6) | ((c & 7U) << 3) | (l & 7U))

    /**
     * @brief
     */
    #define IS_HIT(msg) (msg & 0b00111111)

/**
 * @enum epitech_returns
 * @brief Store every exit codes of functions.
 * @var NAVY_SUCCESS
 * @brief 0
 * @var NAVY_ERR
 * @brief 84
 */
enum epitech_returns {
    NAVY_SUCCESS = 0,
    NAVY_ERR = 84
};

enum torpedo_return {
    SHIP_MISSED,
    SHIP_TOUCHE
};

/**
 * @enum byte_state
 * @brief Store every states of the message received from the opponent.
 * @var TORPEDO
 * @brief State for launching a torpedo to give coordinates.
 * @var TOUCHED
 * @brief State for telling the opponent that its torpedo touched a boat.
 * @var MISSED
 * @brief State for telling the opponent that its torpedo missed.
 */
enum byte_state {
    TORPEDO,
    RETURN
};

/**
 * @struct global_t
 * @brief Global variable for some sigaction dark behaviors
 */
typedef struct {
    int opponent; /**< @brief The pid of the opponent*/
    bool start; /**< @brief The started state of the game*/
    uint8_t mesg; /**< @brief The message */
    int cur; /**< @brief Bit index of the message to write*/
}global_t;

/**
 * @struct instance_t
 * @brief Contains every information of the instance
 */
typedef struct {
    unsigned player : 1; /**< @brief The player id*/
    int **seamap;
    int **enemy_map;
    int winner;
} instance_t;

/* SOURCE */
int my_navy(int argc, char const *const *argv);

/* MAP MANAGEMENT */
int **create_map(int argc, char const *const *argv);
int **create_enemy_map(void);
int push_vertical_ship(int ship_len, int **map, int min, int letter_index);
int push_horizontal_ship(int ship_len, int **map, int line_index,
    int letter_min);
void print_map(int **map);
void map_printer(instance_t *instance);

/* GAME LOOP */
int receive_shoot(instance_t *instance, uint8_t received_message);
void print_shoot_result(int input[2], instance_t *instance, uint8_t msg);
int i_won(instance_t *instance);
int i_lose(instance_t *instance);

/* INPUT */
int user_input(int argc, char const *const *argv, instance_t *instance);
void print_help(void);
int verify_file_validity(char const *path);

/* COMMUNICATION */
void send_byte(uint8_t byte);
uint8_t receive_byte(void);
int handshake(int player, int pid);

#endif /* !MY_NAVY_H_ */
