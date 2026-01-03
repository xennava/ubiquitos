#include "game.h"
#include "game_context.h"
#include "utils/msg.h"
#include "utils/trit.h"
#include <stdio.h>

static void winning(GameContext *ctx) {
  const U8 winT = ctx->winner_player;
  if (winT != 0 && ctx->current_turn != 0) {
    snprintf(what, 31, "Ada yang menang nih! %d", winT);
    if (winT == 2) {
      ctx->higher_score++;
    } else if (winT == 1) {
      ctx->lower_score++;
    }
    ctx->current_turn = 0;
    ctx->winner_player = 0;
  }
}

void win(GameContext *ctx) {
  // 1. Dicek dulu ctx->winner_player-nya siapa, karena awalnya pasti 0,
  // 2. simpan nilai sekali akses ctx->winner_player di variabel winT,
  // 3. Logic:
  //    a. Apakah nilai winT tidak sama dengan 0 dan nilai asli state juga tidak
  //    sama dengan 0?
  //    b. Jika tidak, lewati blok dalam. c. Jika iya, debug,
  //    kalau winT sama dengan 2, naikkan 1 menang untuk P2, kalau winT sama
  //    dengan 2, naikkan 1 untuk P1.
  //    c. nol-kan state agar Player tidak bisa memilih dan nol-kan
  //    ctx->winner_player agar menyesuaikan logika permainan.

  //
  //
  if (((pGetTrit16(voidState, 0) != 0) &&
       (pGetTrit16(voidState, 0) == pGetTrit16(voidState, 1)) &&
       (pGetTrit16(voidState, 0) == pGetTrit16(voidState, 2)))) {
    ctx->winner_player = pGetTrit16(voidState, 0);
    winning(ctx);
    return;
  }
  if (((pGetTrit16(voidState, 3) != 0) &&
       (pGetTrit16(voidState, 3) == pGetTrit16(voidState, 4)) &&
       (pGetTrit16(voidState, 3) == pGetTrit16(voidState, 5)))) {
    ctx->winner_player = pGetTrit16(voidState, 3);
    winning(ctx);
    return;
  }
  if (((pGetTrit16(voidState, 6) != 0) &&
       (pGetTrit16(voidState, 6) == pGetTrit16(voidState, 7)) &&
       (pGetTrit16(voidState, 6) == pGetTrit16(voidState, 8)))) {
    ctx->winner_player = pGetTrit16(voidState, 6);
    winning(ctx);
    return;
  }
  if (((pGetTrit16(voidState, 0) != 0) &&
       (pGetTrit16(voidState, 0) == pGetTrit16(voidState, 3)) &&
       (pGetTrit16(voidState, 0) == pGetTrit16(voidState, 6)))) {
    ctx->winner_player = pGetTrit16(voidState, 0);
    winning(ctx);
    return;
  }
  if (((pGetTrit16(voidState, 1) != 0) &&
       (pGetTrit16(voidState, 1) == pGetTrit16(voidState, 4)) &&
       (pGetTrit16(voidState, 1) == pGetTrit16(voidState, 7)))) {
    ctx->winner_player = pGetTrit16(voidState, 1);
    winning(ctx);
    return;
  }
  if (((pGetTrit16(voidState, 2) != 0) &&
       (pGetTrit16(voidState, 2) == pGetTrit16(voidState, 5)) &&
       (pGetTrit16(voidState, 2) == pGetTrit16(voidState, 8)))) {
    ctx->winner_player = pGetTrit16(voidState, 2);
    winning(ctx);
    return;
  }
  if (((pGetTrit16(voidState, 0) != 0) &&
       (pGetTrit16(voidState, 0) == pGetTrit16(voidState, 4)) &&
       (pGetTrit16(voidState, 0) == pGetTrit16(voidState, 8)))) {
    ctx->winner_player = pGetTrit16(voidState, 0);
    winning(ctx);
    return;
  }
  if (((pGetTrit16(voidState, 2) != 0) &&
       (pGetTrit16(voidState, 2) == pGetTrit16(voidState, 4)) &&
       (pGetTrit16(voidState, 2) == pGetTrit16(voidState, 6)))) {
    ctx->winner_player = pGetTrit16(voidState, 2);
    winning(ctx);
    return;
  };
  if (0)
    rstTrit16;
}
