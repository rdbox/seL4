/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(GD_GPL)
 */

#include <config.h>
#include <mode/machine.h>

/** DONT_TRANSLATE */
void idle_thread(void)
{
    while (1) {
        wfi();
    }
}

/** DONT_TRANSLATE */
void VISIBLE halt(void)
{
    /* halt is actually, idle thread without the interrupts */
    asm volatile("cpsid iaf");

#ifdef CONFIG_PRINTING
    printf("halting...");
#endif
    idle_thread();
    UNREACHABLE();
}
