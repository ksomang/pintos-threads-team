#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H

#include <round.h>
#include <stdint.h>

/* Number of timer interrupts per second. */
#define TIMER_FREQ 100

void timer_init (void);
void timer_calibrate (void);

int64_t timer_ticks (void);
int64_t timer_elapsed (int64_t);

/* timer_sleep()이 실제로 재울 때 부를 함수 CALLBACK을 등록한다.
   thread_init()에서 한 번만 호출한다.
   CALLBACK은 기상 틱(몇 번째 틱에 깰지, 절대값)을 인자로 받는다. */
void timer_on_sleep (void (*callback)(int64_t));
void timer_sleep (int64_t ticks);
void timer_msleep (int64_t milliseconds);
void timer_usleep (int64_t microseconds);
void timer_nsleep (int64_t nanoseconds);

void timer_print_stats (void);

#endif /* devices/timer.h */
