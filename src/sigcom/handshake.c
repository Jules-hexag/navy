/*
** EPITECH PROJECT, 2023
** navy
** File description:
** laposte.c
*/

/**
 * @file laposte.c
 * @brief every function of handshakes
 */

#include <signal.h>
#include <unistd.h>
#include "my.h"
#include "my_navy.h"

extern global_t globale;

/**
 * Fills the @c opponent member of @c globale, print a message to the console
 * and stop the loop of handshake (set @c start of @c globale to @c true).
 * @fn static void connect(int signo, siginfo_t *siginfo, void *context)
 * @brief Sigaction for handshake.
 * @see handshake()
 * @param signo id of the signal.
 * @param siginfo info of the signal.
 * @param context some dark magic appears here.
 * @todo criterion
 */
static void connect(int signo, siginfo_t *siginfo,
    __attribute__((unused))void *context)
{
    if (signo != SIGUSR1)
        return;
    globale.opponent = siginfo->si_pid;
    my_printf("enemy connected\n\n");
    globale.start = true;
}

/**
 * @brief sends a greeting to another process to initiate handshake
 * @param pid[in] the pid of the other process
 * @see handshake()
 * @retval EPITECH_SUCCESS in case of success
 * @retval EPITECH_FAILURE in case of failure
 * @todo criterion
 */
int send_greetings(int pid)
{
    if (kill(pid, SIGUSR1) == 0) {
        my_printf("successfully connected\n\n");
        globale.opponent = pid;
        globale.start = 1;
        return NAVY_SUCCESS;
    }
    write(1, "wrong pid\n", 10);
    return NAVY_ERR;
}

/**
 * If @p player is 0, then wait for a signal form an other process and
 * fills opponent member of globale. @n
 * If @p player is 1, then function send @c SIGUSR1 to the specified pid
 * and store it to the opponent member of globale.
 * @fn int handshake(int player, int pid)
 * @brief Handshake agent for two opponent.
 * @param player[in] player of current process.
 * @param pid[in] pid of the opponent pid when player is 1.
 * @see connect()
 * @see send_greetings()
 * @retval EPITECH_SUCCESS in case of success
 * @retval EPITECH_FAILURE in case of failure
 * @todo criterion
 */
int handshake(int player, int pid)
{
    int my_pid = getpid();
    my_printf("my_pid: %d\n", my_pid);
    if (player)
        return send_greetings(pid);
    my_printf("waiting for enemy connection...\n\n");
    struct sigaction newact;
    struct sigaction oldact;
    sigaction(SIGUSR1, NULL, &oldact);
    newact = oldact;
    newact.sa_flags = SA_SIGINFO;
    newact.sa_sigaction = &connect;
    if (sigaction(SIGUSR1, &newact, NULL) == -1)
        return NAVY_ERR;
    globale.start = false;
    while (globale.start == false)
        pause();
    signal(SIGUSR1, SIG_DFL);
    return NAVY_SUCCESS;
}
