# Ubiquitos

<!--toc:start-->

- [Ubiquitos](#ubiquitos)
  - [Fitur Utama](#fitur-utama)
  - [Build & Run (Console)](#build-run-console)
  - [Tentang AI & Randomness](#tentang-ai-randomness)
  - [Tujuan Proyek](#tujuan-proyek)
  - [Status](#status)
  <!--toc:end-->

**Ubiquitos** adalah proyek pembelajaran dan eksperimen pemrograman berbasis C yang berfokus pada **desain modular**, **efisiensi eksekusi**, dan **fleksibilitas antarmuka** (console maupun GUI).

Awalnya dikembangkan sebagai permainan _tic-tac-toe_, proyek ini dirancang agar logika inti tetap independen dari tampilan, sehingga mudah diperluas, diuji, dan dikembangkan ke arah yang lebih kompleks di masa depan.

---

## Fitur Utama

- 🎮 **Game Tic-Tac-Toe**
  - Mode console (terminal)
  - Struktur siap dikembangkan ke GUI
- 🧠 **AI sederhana**
  - Pemilihan langkah berdasarkan _available moves_
  - Mengutamakan eksekusi cepat (single-random call)
- 🧩 **Desain modular**
  - Pemisahan logic, input, dan inisialisasi
  - Mudah diganti frontend (console / GUI)
- ⚡ **Efisiensi**
  - Minim loop yang tidak perlu
  - Eksperimen optimisasi random & operasi bit
- 🛠️ **Tooling-friendly**
  - Mudah di-build dengan compiler standar C
  - Cocok untuk eksplorasi tooling (clang, LSP, formatter, dsb.)

---

## Build & Run (Console)

Untuk pertama kali, pakai:

```bash
./build.sh
```

Ini akan membuat folder build, mengonfigurasi cmake, dan auto run.

Kalau mau **hapus folder build** cukup tambahkan parameter argumen `c` atau `clean`

Gunakan argumen `r` atau `run` jika sudah ada konfigurasi.

Contoh simpel memakai `./build.sh`.
`./build.sh` untuk awal-awal atau belum konfigurasi.
`./build.sh c` untuk hapus folder build.
`./build.sh r` run program tanpa konfigurasi awal lagi.

---

## Tentang AI & Randomness

AI pada proyek ini belum sempurna, tapi:

- Gampang dipahami dan diimplementasi
- Cepat dieksekusi

Contoh pendekatan AI memakai randomness:

- Ambil daftar posisi kosong
- Pilih satu secara acak dengan satu pemanggilan random.

lihat [AI di sini](https://github.com/xennava/ubiquitos/blob/main/src/AI.c)

## Tujuan Proyek

- Media belajar pemrograman C tingkat menengah.

- Melatih:
  - modularitas
  - pemisahan concern
  - pemikiran efisiensi (cycle & resource)

- Fondasi untuk:
  - GUI
  - AI yang lebih kompleks
  - atau game lainnya

## Status

- 🟢 Core logic stabil
- 🟢 Mode console
- ⚪ Mode GUI (planned)
- ⚪ Multiple executable (console / GUI)
- ⚪ Dokumentasi internal lebih detail
