#ifndef MILLIS_H
#define MILLIS_H

typedef unsigned int millis_t;
static volatile millis_t milliseconds;

// function prototypes

void millis_init(void);
millis_t millis_get(void);

#endif