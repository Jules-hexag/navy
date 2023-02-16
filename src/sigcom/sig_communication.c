/*
** EPITECH PROJECT, 2023
** navy
** File description:
** colgate.c
*/

#include <stdint.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include "my_navy.h"

/**
 * @file colgate.c
 * @brief every function of i/o of bytes
 */

extern global_t globale;

/**
 * Sends bits from @p in <b>one by one</b> to the other @c pid via the usage of
 * @c SIGUSR1 as 0 and @c SIGUSR2 as 1 received by @c receive_byte().
 * @fn void send_byte(uint8_t in)
 *
 * @brief send_byte a byte to the @c pid defined in @c globale.
 *
 * @msc
 *  user,opponent;
 *  user->opponent [label = "bit 1"];
 *  ...;
 *  user->opponent [label = "bit 8"];
 * @endmsc
 *
 * @see receive_byte()
 * @param byte[in] byte to send.
 * @todo criterion
 */
void send_byte(uint8_t byte)
{
    for (int i = 0; i < 8; i++) {
        int bit = byte >> i & 1;
        usleep(10000);
        if (bit == 0) {
            kill(globale.opponent, SIGUSR1);
            continue;
        }
        kill(globale.opponent , SIGUSR2);
    }
}

/**
 * @fn static void sa_receive(int signo, siginfo_t *siginfo, void *context)
 * @brief Sigaction for receive_byte function.
 * @param signo[in] contain the id of the signal.
 * @param siginfo[in] contains info of the signal.
 * @param context[in] who knows ?
 * @see receive_byte()
 * @todo criterion
 */
static void sa_receive(int signo, siginfo_t *siginfo,
    __attribute__((unused))void *context)
{
    if (siginfo->si_pid != globale.opponent)
        return;
    if (signo == SIGUSR1)
        globale.cur++;
    if (signo == SIGUSR2)
        globale.mesg |= 1 << globale.cur++;
}

/**
 * Receives bits one by one from signals with SIGUSR1 as 0, SIGUSR2 as 1 sent
 * by send_byte().
 * @fn uint8_t receive_byte(void)
 * @brief Receive a byte from an opponent defined in pid.
 * @see send_byte()
 * @see sa_receive()
 * @return the received byte.
 * @todo criterion
 */
uint8_t receive_byte(void)
{
    struct sigaction oldact;
    struct sigaction newact;
    sigaction(SIGUSR1, NULL, &oldact);
    sigaction(SIGUSR2, NULL, &oldact);
    newact = oldact;
    newact.sa_flags = SA_SIGINFO;
    newact.sa_sigaction = &sa_receive;
    if (sigaction(SIGUSR1, &newact, NULL) || sigaction(SIGUSR2, &newact, NULL))
        return NAVY_ERR;
    globale.cur = 0;
    globale.mesg = 0;
    while (globale.cur < 8) pause();
    return globale.mesg;
}
