soal 1
#include <stdio.h>
#include <string.h>
#define MAX 100
struct Mahasiswa {
 char nama[50];
 int nilai;
 char huruf;
};
struct Mahasiswa mhs[MAX];
int n;
// Fungsi nilai huruf
char getNilaiHuruf(int nilai) {
 if (nilai >= 85) return 'A';
 else if (nilai >= 70) return 'B';
 else if (nilai >= 60) return 'C';
 else if (nilai >= 50) return 'D';
 else return 'E';
}
int main() {
 printf("Masukkan jumlah mahasiswa: ");
 scanf("%d", &n);
 getchar();
 for (int i = 0; i < n; i++) {
 printf("\nMahasiswa ke-%d\n", i + 1);
 printf("Nama: ");
 fgets(mhs[i].nama, sizeof(mhs[i].nama), stdin);
 mhs[i].nama[strcspn(mhs[i].nama, "\n")] = 0;
 do {
 printf("Nilai (0-100): ");
 scanf("%d", &mhs[i].nilai);
 if (mhs[i].nilai < 0 || mhs[i].nilai > 100) {
 printf("Nilai tidak valid! Ulangi.\n");
 }
 } while (mhs[i].nilai < 0 || mhs[i].nilai > 100);
 mhs[i].huruf = getNilaiHuruf(mhs[i].nilai);
 getchar();
 }
 printf("\n=== Data Mahasiswa ===\n");
 for (int i = 0; i < n; i++) {
 printf("%s | Nilai: %d | Huruf: %c\n",
 mhs[i].nama, mhs[i].nilai, mhs[i].huruf);
 }
 return 0;
}


soal 2 
#include <stdio.h>
#include <string.h>
int main() {
 int nilai[] = {80, 90, 70, 50, 60};
 int jumlah = 5;
 int total = 0, max = nilai[0], min = nilai[0];
 int lulus = 0, tidak = 0;
 for (int i = 0; i < jumlah; i++) {
 total += nilai[i];
 if (nilai[i] > max) max = nilai[i];
 if (nilai[i] < min) min = nilai[i];
 if (nilai[i] >= 60) lulus++;
 else tidak++;
 }
 float rata = (float) total / jumlah;
 printf("Rata-rata: %.2f\n", rata);
 printf("Tertinggi: %d\n", max);
 printf("Terendah: %d\n", min);
 printf("Lulus: %d\n", lulus);
 printf("Tidak Lulus: %d\n", tidak);
 return 0;
}


soal 3 
#include <stdio.h>
#include <string.h>
int main() {
 char nama[5][50] = {"ara", "billy", "cepi", "dede", "erman"};
 int nilai[5] = {85, 80, 75, 61, 31};
 char huruf[5] = {'B','A','C','C','B'};
 int jumlah = 5;
 for (int i = 0; i < jumlah; i++) {
 for (int j = 0; j < jumlah - 1; j++) {
 if (nilai[j] < nilai[j + 1]) {
 int temp = nilai[j];
 nilai[j] = nilai[j + 1];
 nilai[j + 1] = temp;
 char tempNama[50];
 strcpy(tempNama, nama[j]);
 strcpy(nama[j], nama[j + 1]);
 strcpy(nama[j + 1], tempNama);
 char tempH = huruf[j];
 huruf[j] = huruf[j + 1];
 huruf[j + 1] = tempH;
 }
 }
 }
 printf("=== RANKING ===\n");
 for (int i = 0; i < jumlah; i++) {
 printf("Peringkat %d: %s - %d - %c\n", i + 1, nama[i], nilai[i], huruf[i]);
 }
 return 0;
}

soal 4 
#include <stdio.h>
#include <string.h>
#define MAX 100
int main() {
 // Deklarasi variabel
 char nama[MAX][50];
 int nilai[MAX];
 char huruf[MAX];
 int jumlah = 0;
 int pilih;
 do {
 // Tampilan Menu
 printf("\n==============================");
 printf("\n SISTEM DATA MAHASISWA");
 printf("\n==============================");
 printf("\n1. Input Data Mahasiswa");
 printf("\n2. Tampilkan Daftar Nilai (Grade)");
 printf("\n3. Analisis Statistik");
 printf("\n4. Keluar");
 printf("\nPilih menu (1-4): ");
 // Validasi input menu agar tidak error jika diisi huruf
 if (scanf("%d", &pilih) != 1) {
 printf("Error: Masukkan angka saja!\n");
 while (getchar() != '\n');
 continue;
 }
 while (getchar() != '\n'); // Pembersih buffer wajib
 switch (pilih) {
 case 1:
 printf("\n--- INPUT DATA ---");
 printf("\nBerapa jumlah mahasiswa? ");
 scanf("%d", &jumlah);
 while (getchar() != '\n');
 for (int i = 0; i < jumlah; i++) {
 printf("\nMahasiswa ke-%d\n", i + 1);
 // Input Nama
 printf("Nama: ");
 fgets(nama[i], 50, stdin);
 nama[i][strcspn(nama[i], "\n")] = 0; // Buang enter di akhir nama
 // Input Nilai dengan validasi 0-100
 do {
 printf("Nilai (0-100): ");
 if (scanf("%d", &nilai[i]) == 1 && nilai[i] >= 0 && nilai[i] <= 100) {
 while (getchar() != '\n');
 break;
 }
 printf("Nilai tidak valid! Coba lagi.\n");
 while (getchar() != '\n');
 } while (1);
 // --- LOGIKA PENENTUAN HURUF (Langsung diisi ke array) ---
 if (nilai[i] >= 85) huruf[i] = 'A';
 else if (nilai[i] >= 70) huruf[i] = 'B';
 else if (nilai[i] >= 60) huruf[i] = 'C';
 else if (nilai[i] >= 50) huruf[i] = 'D';
 else huruf[i] = 'E';
 }
 printf("\nData berhasil disimpan!\n");
 break;
 case 2:
 if (jumlah == 0) {
 printf("\nData masih kosong! Pilih menu 1 dulu.\n");
 } else {
 printf("\n--- DAFTAR NILAI MAHASISWA ---");
 printf("\n%-3s | %-20s | %-5s | %-5s", "No", "Nama", "Nilai", "Grade");
 printf("\n-------------------------------------------");
 for (int i = 0; i < jumlah; i++) {
 printf("\n%-3d | %-20s | %-5d | %-5c", i+1, nama[i], nilai[i], huruf[i]);
 }
 printf("\n-------------------------------------------\n");
 }
 break;
 case 3:
 if (jumlah == 0) {
 printf("\nData kosong! Tidak ada yang bisa dianalisis.\n");
 } else {
 int total = 0, max = nilai[0], min = nilai[0], lulus = 0;
 for (int i = 0; i < jumlah; i++) {
 total += nilai[i];
 if (nilai[i] > max) max = nilai[i];
 if (nilai[i] < min) min = nilai[i];
 if (nilai[i] >= 60) lulus++;
 }
 float rata = (float)total / jumlah;
 printf("\n--- ANALISIS DATA ---");
 printf("\nRata-rata Nilai : %.2f", rata);
 printf("\nNilai Tertinggi : %d", max);
 printf("\nNilai Terendah : %d", min);
 printf("\nJumlah Lulus : %d", lulus);
 printf("\nTidak Lulus : %d", jumlah - lulus);
 printf("\n---------------------\n");
 }
 break;
 case 4:
 printf("\nKeluar program. Sampai jumpa!\n");
 break;
 default:
 printf("\nPilihan tidak tersedia!\n");
 }
 } while (pilih != 4);
 return 0;
}
