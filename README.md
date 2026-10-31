# Ubiquitos

Ubiquitos adalah proyek permainan Tic-Tac-Toe berbasis bahasa C yang dikembangkan sebagai sarana pembelajaran dan eksperimen pemrograman. Proyek ini menyediakan permainan melalui antarmuka terminal dengan logika permainan dan pemilihan langkah komputer yang diimplementasikan secara terpisah.

## Fitur

- **Tic-Tac-Toe:** Permainan papan 3×3 melalui terminal.
- **Computer Opponent:** Pemilihan langkah komputer berdasarkan posisi yang masih tersedia.
- **Random Move Selection:** Komputer memilih salah satu posisi kosong secara acak.
- **Pemisahan Komponen:** Logika permainan, pemilihan langkah, dan interaksi terminal ditempatkan pada bagian kode yang berbeda.

## Build & Run

Pastikan compiler C dan CMake telah tersedia di sistem.

Jalankan skrip build dari direktori utama proyek:

```bash
./buildnrun.sh
```

Skrip tersebut mengonfigurasi proyek menggunakan CMake, melakukan proses build, dan menjalankan program.

### Argumen Skrip

| Perintah | Fungsi |
|---|---|
| `./buildnrun.sh` | Mengonfigurasi, membangun, dan menjalankan program |
| `./buildnrun.sh r` | Menjalankan program menggunakan hasil build yang tersedia |
| `./buildnrun.sh run` | Alternatif untuk perintah `r` |
| `./buildnrun.sh c` | Menghapus direktori build |
| `./buildnrun.sh clean` | Alternatif untuk perintah `c` |

## Computer Opponent

Pemilihan langkah komputer menggunakan pendekatan berbasis random selection. Program terlebih dahulu mengidentifikasi posisi papan yang masih kosong, kemudian memilih salah satunya secara acak.

Pendekatan ini digunakan untuk menghasilkan lawan komputer sederhana tanpa algoritma pencarian langkah atau evaluasi strategi permainan.

Implementasinya dapat dilihat pada [`src/ai.c`](https://github.com/xennava/ubiquitos/blob/main/src/ai.c).

## Struktur dan Pengembangan

Kode program dibagi berdasarkan tanggung jawab masing-masing komponen, sehingga logika permainan tidak sepenuhnya bergantung pada interaksi terminal.

Pemisahan ini menjadi dasar untuk eksperimen lebih lanjut, seperti pengembangan antarmuka grafis atau penambahan pendekatan pemilihan langkah yang berbeda.

## Tujuan

Proyek ini dikembangkan untuk mempraktikkan:

- Pemrograman C dan pengorganisasian kode.
- Pemisahan logika program dari interaksi pengguna.
- Pengelolaan kondisi dan status permainan.
- Penggunaan fungsi dan struktur program dalam implementasi permainan sederhana.

## Status Pengembangan

- [x] Logika dasar permainan Tic-Tac-Toe
- [x] Antarmuka terminal
- [x] Pemilihan langkah komputer secara acak
- [ ] Antarmuka grafis (GUI)
- [ ] Pengembangan strategi komputer yang lebih baik
