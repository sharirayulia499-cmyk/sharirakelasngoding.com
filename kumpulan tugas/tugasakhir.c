#include <stdio.h>
#include <string.h>

int main() {
    int jumlahSiswa;

    // 1. INPUT JUMLAH SISWA
    printf("Masukkan jumlah siswa: ");
    scanf("%d", &jumlahSiswa);
    getchar(); // Membersihkan buffer newline setelah input angka

    // 2. PENYIMPANAN DATA (Deklarasi Array)
    char nama[jumlahSiswa][50]; // Array string untuk nama (maksimal 50 karakter per nama)
    int nilai[jumlahSiswa];      // Array integer untuk nilai
    
    int totalNilai = 0;
    float rataRata;

    printf("\n--- INPUT DATA SISWA ---\n");
    for (int i = 0; i < jumlahSiswa; i++) {
        printf("\nSiswa ke-%d\n", i + 1);
        
        // Input Nama Siswa
        printf("Masukkan Nama: ");
        fgets(nama[i], sizeof(nama[i]), stdin);
        nama[i][strcspn(nama[i], "\n")] = 0; // Menghilangkan karakter newline di akhir fungsi fgets

        // Input Nilai Siswa
        printf("Masukkan Nilai: ");
        scanf("%d", &nilai[i]);
        getchar(); // Membersihkan buffer newline lagi

        // 4. PERHITUNGAN (Akumulasi Total Nilai)
        totalNilai += nilai[i];
    }

    // 4. PERHITUNGAN (Rata-rata Kelas)
    if (jumlahSiswa > 0) {
        rataRata = (float)totalNilai / jumlahSiswa;
    } else {
        rataRata = 0;
    }

    // 5. OUTPUT DATA
    printf("\n==================================================\n");
    printf("%-5s | %-20s | %-6s | %-12s\n", "No", "Nama Siswa", "Nilai", "Status");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < jumlahSiswa; i++) {
        // 3. PROSES DATA (Penentuan Kelulusan)
        char status[15];
        if (nilai[i] >= 75) {
            strcpy(status, "Lulus");
        } else {
            strcpy(status, "Tidak Lulus");
        }

        // Menampilkan daftar siswa, nilai, dan status
        printf("%-5d | %-20s | %-6d | %-12s\n", i + 1, nama[i], nilai[i], status);
    }

    printf("==================================================\n");
    // Menampilkan total nilai dan rata-rata kelas
    printf("Total Nilai Kelas : %d\n", totalNilai);
    printf("Rata-rata Kelas   : %.2f\n", rataRata);
    printf("==================================================\n");

    return 0;
}
