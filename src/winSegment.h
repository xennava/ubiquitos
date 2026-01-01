#ifndef WINSEGMENT_H
#define WINSEGMENT_H

#define lineCheck(a, b, c)                                                     \
  ((getTrit16(a) != 0) && (getTrit16(a) == getTrit16(b)) &&                    \
   (getTrit16(a) == getTrit16(c)))
#define defWinner(ws, a, b, c)                                                 \
  if (lineCheck(a, b, c)) {                                                    \
    ws = getTrit16(a);                                                         \
    winning();                                                                 \
    return;                                                                    \
  }

#define winCheck(winState)                                                     \
  defWinner(winState, 0, 1, 2) defWinner(winState, 3, 4, 5)                    \
      defWinner(winState, 6, 7, 8) defWinner(winState, 0, 3, 6)                \
          defWinner(winState, 1, 4, 7) defWinner(winState, 2, 5, 8)            \
              defWinner(winState, 0, 4, 8) defWinner(winState, 2, 4, 6)

#endif
