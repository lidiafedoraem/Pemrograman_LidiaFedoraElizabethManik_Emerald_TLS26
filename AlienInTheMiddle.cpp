#include <iostream>
using namespace std;

// Function manual untuk menghitung panjang teks (pengganti .length())
int hitungPanjang(char teks[]) {
    int panjang = 0;
    while (teks[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

int main() {
    char pesanSandi[100];
    cout << "Masukkan pesan sandi: ";
    cin >> pesanSandi;

    int panjang = hitungPanjang(pesanSandi);

    char hasil[100];
    hasil[0] = pesanSandi[0]; // huruf pertama tidak berubah

    for (int i = 1; i < panjang; i++) {
        int nilaiSandi = pesanSandi[i] - 'A' + 1;
        int nilaiSebelumnya = hasil[i - 1] - 'A' + 1;

        int nilaiAsli = nilaiSandi - nilaiSebelumnya;

        if (nilaiAsli <= 0) {
            nilaiAsli = nilaiAsli + 26;
        }

        hasil[i] = 'A' + (nilaiAsli - 1);
    }

    hasil[panjang] = '\0'; // menandai akhir teks secara manual

    cout << "Pesan asli: " << hasil << endl;

    return 0;
}