#include <iostream>
using namespace std;

int main() {
    int N, K;
    cout << "Masukkan N: ";
    cin >> N;
    cout << "Masukkan K: ";
    cin >> K;

    // Membuat array astronot secara manual (pengganti vector)
    int astronot[1000];   // asumsi N tidak lebih dari 1000
    int jumlahTersisa = N;

    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }

    int posisi = 0;
    int urutanEliminasi[1000];
    int jumlahEliminasi = 0;

    while (jumlahTersisa > 1) {
        int idx = (posisi + K - 1) % jumlahTersisa;
        int korban = astronot[idx];

        urutanEliminasi[jumlahEliminasi] = korban;
        jumlahEliminasi++;

        // Menghapus elemen ke-idx secara manual (pengganti .erase())
        for (int i = idx; i < jumlahTersisa - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        jumlahTersisa--; // pengganti .size() yang berkurang otomatis

        if (korban % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }
        if (K < 2) {
            K = 2;
        }

        posisi = idx % jumlahTersisa;
    }

    cout << "Urutan astronot yang dieliminasi: ";
    for (int i = 0; i < jumlahEliminasi; i++) {
        cout << urutanEliminasi[i];
        if (i != jumlahEliminasi - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "Astronot yang bertahan (pemenang): " << astronot[0] << endl;

    return 0;
}