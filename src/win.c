#include "game.h"
#include "game_context.h"
#include "utils/msg.h"
#include "utils/trit.h"
#include <stdio.h>

static void winning(GameContext *ctx) {
  const U8 winT = ctx->winner_player;
  if (winT != 0 && ctx->current_turn != 0) {
    snprintf(getWhat(), 31, "Ada yang menang nih! %d", winT);
    if (winT == 2) {
      ctx->higher_score++;
    } else if (winT == 1) {
      ctx->lower_score++;
    }
    ctx->current_turn = 0;
    ctx->winner_player = 0;
  }
}

void adjCheck(GameContext *ctx, U16 now, U16 n1, U16 n2) {
#define getTrit16LocalHelper(index) pGetTrit16(getInternalStatePointer(), index)
  now = getTrit16LocalHelper(now);
  if (((now != 0) && (now == getTrit16LocalHelper(n1)) &&
       (now == getTrit16LocalHelper(n2)))) {
    ctx->winner_player = now;
    winning(ctx);
    return;
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

  adjCheck(ctx, 0, 1, 2);
  adjCheck(ctx, 3, 4, 5);
  adjCheck(ctx, 6, 7, 8);

  adjCheck(ctx, 0, 3, 6);
  adjCheck(ctx, 1, 4, 7);
  adjCheck(ctx, 2, 5, 8);

  adjCheck(ctx, 0, 4, 8);
  adjCheck(ctx, 2, 4, 6);

  // if (0)
  //   rstTrit16;
}
