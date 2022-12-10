#pragma once
#include <stdio.h>

static inline void empty_stdin (void) /* simple helper-function to empty stdin */
{
  int c = getchar();

  while (c != '\n' && c != EOF)
    c = getchar();
}
