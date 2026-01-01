#include "winSegment.h"
#include "tictactoe.h"
#include "trit.h"
#include <stdio.h>

void winning() {
  const uint8_t winT = winner;
  if (winT != 0 && state != 0) {
    snprintf(what, 31, "Ada yang menang nich! %d", winT);
    if (winT == 2) {
      setHPctr(getHPctr + 1); // P2
    } else if (winT == 1) {
      setLPctr(getLPctr + 1); // P1
    }
    state = 0;
    winner = 0;
  }
}

void winSegment(U8 *buffer) {
  // 1. Dicek dulu winner-nya siapa, karena awalnya pasti 0,
  // 2. simpan nilai sekali akses winner di variabel winT,
  // 3. Logic:
  //    a. Apakah nilai winT tidak sama dengan 0 dan nilai asli state juga tidak
  //    sama dengan 0?
  //    b. Jika tidak, lewati blok dalam. c. Jika iya, debug,
  //    kalau winT sama dengan 2, naikkan 1 menang untuk P2, kalau winT sama
  //    dengan 2, naikkan 1 untuk P1.
  //    c. nol-kan state agar Player tidak bisa memilih dan nol-kan winner agar
  //    menyesuaikan logika permainan.
  if (((pGetTrit16(voidState, 0) != 0) &&
       (pGetTrit16(voidState, 0) == pGetTrit16(voidState, 1)) &&
       (pGetTrit16(voidState, 0) == pGetTrit16(voidState, 2)))) {
    winner = pGetTrit16(voidState, 0);
    winning();
    return;
  }
  if (((pGetTrit16(voidState, 3) != 0) &&
       (pGetTrit16(voidState, 3) == pGetTrit16(voidState, 4)) &&
       (pGetTrit16(voidState, 3) == pGetTrit16(voidState, 5)))) {
    winner = pGetTrit16(voidState, 3);
    winning();
    return;
  }
  if (((pGetTrit16(voidState, 6) != 0) &&
       (pGetTrit16(voidState, 6) == pGetTrit16(voidState, 7)) &&
       (pGetTrit16(voidState, 6) == pGetTrit16(voidState, 8)))) {
    winner = pGetTrit16(voidState, 6);
    winning();
    return;
  }
  if (((pGetTrit16(voidState, 0) != 0) &&
       (pGetTrit16(voidState, 0) == pGetTrit16(voidState, 3)) &&
       (pGetTrit16(voidState, 0) == pGetTrit16(voidState, 6)))) {
    winner = pGetTrit16(voidState, 0);
    winning();
    return;
  }
  if (((pGetTrit16(voidState, 1) != 0) &&
       (pGetTrit16(voidState, 1) == pGetTrit16(voidState, 4)) &&
       (pGetTrit16(voidState, 1) == pGetTrit16(voidState, 7)))) {
    winner = pGetTrit16(voidState, 1);
    winning();
    return;
  }
  if (((pGetTrit16(voidState, 2) != 0) &&
       (pGetTrit16(voidState, 2) == pGetTrit16(voidState, 5)) &&
       (pGetTrit16(voidState, 2) == pGetTrit16(voidState, 8)))) {
    winner = pGetTrit16(voidState, 2);
    winning();
    return;
  }
  if (((pGetTrit16(voidState, 0) != 0) &&
       (pGetTrit16(voidState, 0) == pGetTrit16(voidState, 4)) &&
       (pGetTrit16(voidState, 0) == pGetTrit16(voidState, 8)))) {
    winner = pGetTrit16(voidState, 0);
    winning();
    return;
  }
  if (((pGetTrit16(voidState, 2) != 0) &&
       (pGetTrit16(voidState, 2) == pGetTrit16(voidState, 4)) &&
       (pGetTrit16(voidState, 2) == pGetTrit16(voidState, 6)))) {
    winner = pGetTrit16(voidState, 2);
    winning();
    return;
  };
  if (0)
    rstTrit16;
}
