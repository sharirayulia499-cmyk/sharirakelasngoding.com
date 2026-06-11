latihan 1 
#include <stdio.h>
#include <stdlib.h>
int main() {
 float angka;
 // meminta input dari pengguna
 printf("masukkan sebuah angka: ");
 scanf("%f", &angka);
 // mengepaluasi kondisi menggunakan percabangan
 if (angka > 0) {
 // jika angka lebih besar dari nol
 printf("bilangan tersebut adalah POSITIF\n");
 }
 else if (angka < 0 ) {
 // jika angka kurang dari nol
 printf("bilangan tersebut adalah NEGATIF\n");
 }
 else {
 // jika nilai sama dengan nol
 printf("bilangan tersebut adalah NOL\n");
 }
 return 0;
}

latihan 2
#include <stdio.h>
#include <stdlib.h>
int main(){
 float jam_parkir, total_biaya;
 printf("=== SISTEM PARKIR ===\n");
 printf("Tarif: Rp3.000/jam (2 jam pertama)\n");
 printf(" Rp2.000/jam (sisa jam)\n");
 printf("============================\n");
 // Input dengan validasi
 printf("Masukkan lama parkir (jam): ");
 if (scanf("%f", &jam_parkir) != 1 || jam_parkir < 0) {
 printf("ERROR: Masukkan angka jam yang valid (>= 0)!\n");
 return 1;
}
// Hitung total biaya menggunakan percabangan
if (jam_parkir <= 2) {
 // 2 jam pertama atau kurang: Rp3.000/jam
 total_biaya = jam_parkir * 3000;
 printf("\n--- Rincian Perhitungan ---\n");
 printf("Jam parkir: %.1f jam\n", jam_parkir);
 printf("Tarif: Rp3.000/jam\n");
}
else {
 // Lebih dari 2 jam: 2 jam pertama Rp3.000 + sisa Rp2.000
 float jam_pertama = 2.0;
 float sisa_jam = jam_parkir - 2.0;
 total_biaya = (jam_pertama * 3000) + (sisa_jam * 2000);
 printf("\n--- Rincian Perhitungan ---\n");
 printf("Jam parkir: %.1f jam\n", jam_parkir);
 printf("2 jam pertama: 2.0 x Rp3.000 = Rp6.000\n");
 printf("Sisa %.1f jam: %.1f x Rp2.000 = Rp%.0f\n", sisa_jam, sisa_jam, sisa_jam * 2000);
}
// Output total biaya
printf("===========================\n");
printf("TOTAL BIAYA PARKIR: Rp%.0f\n", total_biaya);
printf("===========================\n");
return 0;
}

latihan 3 
#include <stdio.h>
#include <stdlib.h>
int main() {
 int hari;
 printf("=== PENCARI HARI ===\n");
 printf("1 = Senin | 2 = Selasa | 3 = Rabu\n");
 printf("4 = Kamis | 5 = Jumat | 6 = Sabtu\n");
 printf("7 = Minggu\n");
 printf("=======================\n");
 // Input dengan validasi
 printf("Masukkan angka hari (1-7): ");
 if (scanf("%d", &hari) != 1) {
 printf("ERROR: Input harus berupa angka!\n");
 return 1;
}
// Clear input buffer
int c;
while ((c = getchar()) != '\n' && c != EOF);
printf("\n--- HASIL ---\n");
// Switch case untuk menentukan nama hari
switch (hari) {
 case 1:
 printf("Hari ke-%d = **SENIN**\n", hari);
 break;
 case 2:
 printf("Hari ke-%d = **SELASA**\n", hari);
 break;
 case 3:
 printf("Hari ke-%d = **RABU**\n", hari);
 break;
 case 4:
 printf("Hari ke-%d = **KAMIS**\n", hari);
 break;
 case 5:
 printf("Hari ke-%d = **JUMAT**\n", hari);
 break;
 case 6:
 printf("Hari ke-%d = **SABTU**\n", hari);
 break;
 case 7:
 printf("Hari ke-%d = **MINGGU**\n", hari);
 break;
 default:
 printf("❌ INPUT TIDAK VALID!\n");
 printf("Masukkan angka 1-7 saja!\n");
 return 1;
 }
 return 0;
}
