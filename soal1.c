/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 5 - Foundation of Algorithm
 *   Hari dan Tanggal    : Rabu, 13 Mei 2026
 *   Nama (NIM)          : Faiz Azmi Irwan (13224040)
 *   Nama File           : soal1_prak.c
 *   Deskripsi           : Membuat banyak kemungkinan susunan valid dari tanda kurung sesuai dengan jumlah pasangan yang diminta oleh user 
 *                         dengan output berupa kemungkinan susunan tanda kurung tersebut dan jumlahnya
 * 
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

// prosedur rekursi agar terjadi looping
void print_kurung_semua(int pos, int n, int buka, int tutup);

// kondisi awal verifikasi ketika nilai yang diinginkan lebih dari 0
void print_kurung(int n) {
    if (n > 0) {
        print_kurung_semua(0, n, 0, 0);
    }
    return;
}

void print_kurung_semua(int pos, int n, int buka, int tutup) {
    static char str[MAX];

    // kondisi ketika jumlah pasangan yang diinginkan tercapai
    if (tutup == n) {
        // output dari susunan pasangan tanda kurung
        printf("%s \n", str);
        return;
    }
    // kondisi ketika membuat string deretan tanda kurung sesuai leksikografis (perbaikan #2: mengubah urutan if else)
    else {
        if (buka < n) {
            str[pos] = '(';
            print_kurung_semua(pos + 1, n, buka + 1, tutup);
        }

        if (buka > tutup) {
            str[pos] = ')';
            print_kurung_semua(pos + 1, n, buka, tutup + 1);
        }
    }
}

unsigned int faktorial(int N) {
    int fact = 1, i;

    // loop dari 1 hingga N dalam memperoleh nilai faktorial
    for (i = 1; i <= N; i++) {
        fact *= i;
    }

    return fact;
}


// fungsi utama
int main() {
    // inisialisasi variabel
    int n;
    scanf("%d", &n);

    // rumus jumlah kemungkinan susunan pasangan tanda kurung (perbaikan #1: mencari total kemungkinan)
    int eq = faktorial(2*n)/(faktorial(n+1)*faktorial(n));

    // pemanggilan fungsi rekursi
    print_kurung(n);
    printf("TOTAL %d", eq);


    return 0;
}
