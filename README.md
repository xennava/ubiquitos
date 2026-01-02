# Ubiquitos

<!--toc:start-->

- [Ubiquitos](#ubiquitos)
  - [✨ Fitur Utama](#fitur-utama)
  - [📂 Struktur Proyek](#📂-struktur-proyek)
  - [Build & Run (Console)](#build-run-console)
  - [Tentang AI & Randomness](#tentang-ai-randomness)
  - [Tujuan Proyek](#tujuan-proyek)
  <!--toc:end-->

**Ubiquitos** adalah proyek pembelajaran dan eksperimen pemrograman berbasis C yang berfokus pada **desain modular**, **efisiensi eksekusi**, dan **fleksibilitas antarmuka** (console maupun GUI).

Awalnya dikembangkan sebagai permainan _tic-tac-toe_, proyek ini dirancang agar logika inti tetap independen dari tampilan, sehingga mudah diperluas, diuji, dan dikembangkan ke arah yang lebih kompleks di masa depan.

---

## ✨ Fitur Utama

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

## 📂 Struktur Proyek

ubiquitos/
├── src/
│ ├── init.c # Inisialisasi board
│ ├── logic.c # Core game logic
│ ├── input.c # Implementasi input
│ ├── declare.c # Deklarasi buffer & interface logic
│ └── main.c # Entry point (console)
├── .gitignore
├── README.md
└── CMakeLists.txt / build config

> Struktur bisa berkembang seiring penambahan GUI atau executable terpisah.

---

## Build & Run (Console)

Contoh build sederhana menggunakan `cmake`:

```bash
CC="ccache clang" cmake -S . -B build -G Ninja
cmake --build build
./build/ubiquitos
```

---

## Tentang AI & Randomness

AI pada proyek ini belum sempurna, tapi:

- Gampang dipahami dan diimplementasi
- Cepat dieksekusi

Contoh pendekatan AI memakai randomness:

- Ambil daftar posisi kosong
- Pilih satu secara acak dengan satu pemanggilan random.

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
