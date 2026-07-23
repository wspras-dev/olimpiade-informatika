# 🏆 Competitive Programming & Olimpiade Informatika Solutions

<!-- [![Language](https://shields.io)](https://cppreference.com)
[![Status](https://shields.io)]()
[![License](https://shields.io)](LICENSE)
 -->
Repository ini berisi kumpulan solusi kode (C++) untuk berbagai soal Olimpiade Informatika dan *Competitive Programming*, mulai dari tingkat kabupaten (OSN-K), provinsi (OSN-P), nasional (OSN), hingga platform *online judge* internasional.

---

## 🚀 Daftar Isi Solusi

### Pembahasan Olimpiade Sains Nasional (OSN / TOKI)

| Kompetisi | Tahun | Nama Soal | Algoritma / Topik | Solusi C++ |
| :--- | :---: | :--- | :--- | :---: |
| OSN-P | 2025 | [A] String Cantik OSN-P | Dynamic Programming | [Lihat Kode](./OSN-P-2025/Kasus-A/main.cpp) |
| OSN-P | 2025 | [B] Gudang Penyimpanan Kardus | Dynamic Programming | [Lihat Kode](./OSN-P-2025/Kasus-B/main.cpp) |
| OSN-P | 2025 | [C] Balada Kemasan Telur | Dynamic Programming | [Lihat Kode](./OSN-P-2025/Kasus-C/main.cpp) |
| OSN-P | 2025 | [D] Telur Kemasan Balado | Dynamic Programming | [Lihat Kode](./OSN-P-2025/Kasus-D/main.cpp) |
| OSN-P | 2025 | [E] Tebas Tebang Bambu | Dynamic Programming | [Lihat Kode](./OSN-P-2025/Kasus-E/main.cpp) |
| OSN-P | 2025 | [F] Kandang Ayam Kandang Bebek | Dynamic Programming | [Lihat Kode](./OSN-P-2025/Kasus-F/main.cpp) |

### 🌐 Online Link (Optional)  

Baca PDF [Soal OSN-P-2025](./OSN-P-2025/Soal/OSNP2025.pdf)  
Lihat versi HTML [Pembahasan Semua Soal OSN-P-2025](./OSN-P-2025/Pembahasan/docs-osn-p-2025-final.html)  
Lihat versi PDF [Pembahasan Semua Soal OSN-P-2025](./OSN-P-2025/Pembahasan/docs-osn-p-2025.pdf)  

---

## 🛠️ Template Kode yang Digunakan

Semua solusi dalam repository ini menggunakan *boilerplate / template* standar C++20 untuk mengoptimalkan kecepatan I/O:

```cpp
#include <iostream>
using namespace std;

void solve() {
    // Tulis logika/solusi di sini
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t; // Aktifkan jika soal memiliki multiple testcases
    while(t--) {
        solve();
    }
    return 0;
}
```

---

## 📖 Cara Menggunakan Repository Ini

1. **Clone Repository:**
   ```bash
   git clone https://github.com/wspras-dev/olimpiade-informatika.git
   ```
2. **Cara Compile Manual (GCC/g++):**
   ```bash
   g++ -O3 -std=c++20 nama_file.cpp -o main
   ./main
   ```
3. **Compile dengan IDE (Integrated Development Environment) C++ offline yang digunakan saat ini.**  
   * MinGW Developer Studio.  
   * Code::Blocks.  
   * Dev-C++.
   * Clion.
   ```bash
   Gunakan runtime minimum gcc 3.x (98) dan disarankan menggunaan versi terbaru gcc 14.x (Winlibs)
   ```    
4. **Cara Compile Online (GCC/g++):**
   ```bash
   Silahkan gunakan keyword pencarian sperti "Compiler C++ online".
   ```

---

## ⚠️ Disklaimer & Hak Cipta
* Hak cipta teks soal sepenuhnya milik penyelenggara kompetisi masing-masing (TOKI, Puspresnas, Codeforces, dll).
* Kode solusi di dalam repository ini dibuat murni untuk tujuan pembelajaran individu dan dokumentasi pribadi.
* **PENTING:** Jangan menyalin kode ini saat kompetisi resmi sedang berlangsung (*anti-cheating/plagiarism policy*).

---
🙋‍♂️ **Dibuat oleh Widayat S Prasetiyo** - [@wspras-dev](https://github.com/wspras-dev)
