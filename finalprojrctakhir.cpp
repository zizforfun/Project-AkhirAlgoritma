#include <iostream> 
// Digunakan untuk input dan output standar, seperti cout dan cin.
#include <iomanip> 
// Diperlukan untuk manipulasi format output, seperti setw (lebar kolom), left (rata kiri), dan right (rata kanan).
#include <fstream> 
// Digunakan untuk operasi file, seperti membaca dan menulis ke file teks.
#include <windows.h> 
// Header khusus Windows. Digunakan untuk berbagai fungsi spesifik sistem operasi Windows, misalnya mengatur warna teks di console, delay, atau membersihkan layar.
#include <string> 
// Digunakan untuk memanipulasi dan menyimpan string (teks), seperti std::string.
#include <limits> 
// Digunakan untuk mendapatkan batas nilai dari tipe data primitif, atau untuk membersihkan buffer input (misalnya dengan std::numeric_limits<std::streamsize>::max()).
#include <algorithm> 
// Digunakan untuk berbagai algoritma standar, seperti transform (mengubah huruf menjadi huruf kecil/kapital, sorting, searching, dll).
#include <vector> 
// Digunakan untuk menyimpan data dalam array dinamis (std::vector), berguna untuk menyimpan dan mengolah banyak data secara fleksibel, termasuk menyaring item menu dalam kasus ini.


using namespace std;

// Struktur untuk menu
struct menu
{
    string namaMenu, jenisMenu;
    int harga, idMenu;
};

// Struktur untuk pelanggan
struct pelanggan
{
    string namaPelanggan;
    int idPelanggan;
    int jumlahPesanan;
    int pesanan[100];      // menyimpan ID menu dipesan
    int jumlahMenu[100];   // menyimpan jumlah dari tiap menu dipesan
    int totalHarga;        // total harga pesanan pelanggan
};

menu daftarMenu[100];
pelanggan daftarPelanggan[100];
int jumlahMenu = 3; // inisiasi menu awal (bawaan)
int jumlahPelanggan = 0;

// Deklarasi fungsi
void about();  
// Menampilkan informasi tentang program (seperti pembuat, versi, atau deskripsi program).
void tambahDataMenu();  
// Menambahkan data menu baru ke sistem (seperti makanan/minuman yang dijual).
void tambahDataPelanggan();  
// Menambahkan data pelanggan baru ke sistem (seperti nama, pesanan, jumlah pesanan, dll).
void melihatDataMenu();  
// Menampilkan semua data menu yang tersedia.
void melihatDataPelanggan();  
// Menampilkan semua data pelanggan yang tersimpan.
void daftarMenuAwal();  
// Menampilkan daftar menu awal saat program dijalankan (mungkin sebagai tampilan awal/menu utama).
void hitungTotalHarga(pelanggan &p);  
// Menghitung total harga berdasarkan pesanan pelanggan (parameter berupa referensi ke objek pelanggan).
void hapusdatamenu();  
// Menghapus data menu tertentu dari sistem.
void hapusDataPelanggan();  
// Menghapus data pelanggan tertentu dari sistem.
void cariPelanggan();  
// Mencari data pelanggan berdasarkan kriteria tertentu (seperti nama atau ID).
void carimenu();  
// Mencari menu berdasarkan kriteria tertentu (seperti nama atau ID menu).
void simpanpelanggan();  
// Menyimpan data pelanggan ke dalam file untuk keperluan penyimpanan permanen.
void bacapelanggan();  
// Membaca data pelanggan dari file dan memuatnya ke dalam program.
void simpanMenu();  
// Menyimpan data menu ke dalam file.
void bacaMenu();  
// Membaca data menu dari file.
void sortingNama();  
// Mengurutkan data pelanggan atau menu berdasarkan nama (secara alfabetis).
void sortingId();  
// Mengurutkan data pelanggan atau menu berdasarkan ID (biasanya angka atau kode tertentu).
void bubblehargamenu(bool ascending);  
// Mengurutkan harga menu menggunakan algoritma Bubble Sort, bisa naik (ascending) atau turun (descending) tergantung parameter.
void quickhargamenu(menu arr[], int low, int high, bool ascending);  
// Mengurutkan harga menu menggunakan algoritma Quick Sort dengan arah pengurutan sesuai parameter (ascending/descending).
void sortingharga(bool ascending);  
// Mengatur metode pengurutan harga, bisa memanggil bubble sort atau quick sort tergantung kebutuhan.
void menuEditMenu();  
// Menampilkan atau mengatur proses untuk mengedit data menu yang sudah ada.
void menuEditPelanggan();  
// Menampilkan atau mengatur proses untuk mengedit data pelanggan yang sudah ada.


int main(){
    // Inisialisasi 3 menu awal ke dalam array daftarMenu
    daftarMenu[0] = { "Nasi Ayam Goreng","Makanan",15000,1 };
    daftarMenu[1] = { "Ikan Rebus","Makanan",20000,2 };
    daftarMenu[2] = { "Nasi Sambel","Makanan",3000,3 };

    // Membaca data menu dan data pelanggan dari file (jika ada)
    bacaMenu(); 
    bacapelanggan();

    int pilihan;  // Menyimpan pilihan menu dari pengguna
    char ulang;   // Digunakan untuk menanyakan apakah user ingin kembali ke menu utama

    do
    {
        system("cls");  // Membersihkan layar (hanya berfungsi di Windows)
        cout << setfill(' ');
        cout << endl;

        // Menampilkan header dan menu utama
        cout << setw(42) << setfill('-') << "\n";
        cout << "======== PROGRAM KASIR BIZ RESTO ========\n";
        cout << setw(42) << setfill('-') << "\n";
        cout << setfill(' ');
        cout << setw(30) << "<<<<<<< Menu Utama >>>>>>>\n";
        cout << "--------------------------------\n";
        cout << "|" << "1. About" << "\t\t\t|\n";
        cout << "|" << "2. Daftar Menu" << "\t\t\t|\n";
        cout << "|" << "3. Tambah Data Menu" << "\t\t|\n";
        cout << "|" << "4. Tambah Data Pelanggan" << "\t|\n";
        cout << "|" << "5. Melihat Data Menu" << "\t\t|\n";
        cout << "|" << "6. Melihat Data Pelanggan" << "\t|\n";
        cout << "|" << "7. Hapus Daftar Menu" << "\t\t|\n";
        cout << "|" << "8. Hapus Daftar Pelanggan" << "\t|\n";
        cout << "|" << "9. Cari Pelanggan" << "\t\t|\n";
        cout << "|" << "10. Cari Menu" << "\t\t\t|\n";
        cout << "|" << "11. Edit Menu" << "\t\t\t|\n"; 
        cout << "|" << "12. Edit Pelanggan" << "\t\t|\n"; 
        cout << "|" << "13. Exit" << "\t\t\t|\n";
        cout << "--------------------------------\n";

        // Menerima input dari user untuk memilih menu
        cout << "Isikan Pilihan Menu: ";
        cin >> pilihan;
        system("cls");  // Bersihkan layar setelah input pilihan

        // Proses pilihan menu menggunakan switch-case
        switch (pilihan)
        {
        case 1:
            about(); // Menampilkan informasi tentang program
            break;
        case 2:
            daftarMenuAwal(); // Menampilkan daftar menu awal
            break;
        case 3:
            tambahDataMenu(); // Menambahkan menu baru
            break;
        case 4:
            tambahDataPelanggan(); // Menambahkan pelanggan baru
            break;
        case 5:
            melihatDataMenu(); // Menampilkan semua data menu
            break;
        case 6:
            melihatDataPelanggan(); // Menampilkan semua data pelanggan
            break;
        case 7:
            hapusdatamenu(); // Menghapus data menu
            break;
        case 8:
            hapusDataPelanggan(); // Menghapus data pelanggan
            break;
        case 9:
            cariPelanggan(); // Mencari data pelanggan berdasarkan kriteria
            break;
        case 10:
            carimenu(); // Mencari data menu berdasarkan kriteria
            break;
        case 11:
            menuEditMenu(); // Mengedit data menu
            break;
        case 12:
            menuEditPelanggan(); // Mengedit data pelanggan
            break;
        case 13:
            // Menyimpan data sebelum keluar
            cout << "\t===PROGRAM SELESAI===\n";
            simpanpelanggan(); // Simpan data pelanggan ke file
            return 0; // Keluar dari program
        default:
            // Penanganan jika user memilih nomor yang tidak valid
            cout << "==MOHON MAAF, PILIHAN ANDA TIDAK TERSEDIA==\n";
        }

        // Menanyakan kepada user apakah ingin kembali ke menu utama
        cout << "Apakah ingin mengulang program (y/n)?: ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y'); // Ulang jika user menjawab 'y' atau 'Y'

    // Setelah keluar dari loop, simpan semua data ke file
    simpanMenu(); 
    simpanpelanggan();

    return 0; // Program selesai
}

void about(){
    system("cls");  
    // Membersihkan layar konsol agar tampilan lebih rapi (khusus Windows).
    cout << "======== ABOUT THE PROGRAM ========\n";
    // Menampilkan judul bagian "About".
    cout << setw(42) << setfill('-') << "\n";
    // Menampilkan garis pemisah sepanjang 42 karakter menggunakan simbol '-'.
    cout << "Program ini dibuat oleh : \n";
    // Menjelaskan tujuan dari bagian ini, yaitu informasi pembuat program.
    cout << setw(42) << setfill('-') << "\n";
    // Garis pemisah lagi.
    // Menampilkan nama pembuat program
    cout << "Nama\t: Bima Putra F\n"
         << "\t  Nur Aziz Ramadhan\n";
    // Menampilkan NIM (Nomor Induk Mahasiswa) dari masing-masing pembuat
    cout << "NIM\t: 123230003 \n"
         << "\t  123240261 \n";
    // Menampilkan kelas
    cout << "Kelas\t: If-M\n";
    cout << setw(42) << setfill('-') << "\n";
    // Garis pemisah penutup
    system("pause");  
    // Memberhentikan layar agar pengguna bisa membaca informasi sebelum lanjut.
    // User harus menekan tombol untuk melanjutkan kembali ke menu utama.
}

void daftarMenuAwal() {
    system("cls"); // Bersihkan layar konsol untuk tampilan yang bersih

    // Header tampilan menu
    cout << "=======================================\n";
    cout << "          DAFTAR MENU RESTORAN\n";
    cout << "=======================================\n\n";

    // Jika tidak ada data menu yang tersedia
    if (jumlahMenu == 0) {
        cout << "Belum ada menu yang ditambahkan. Silakan tambahkan menu terlebih dahulu.\n";
        cout << "Tekan tombol apapun untuk kembali...";
        system("pause > nul"); // Tunggu input user tanpa pesan default
        return; // Keluar dari fungsi
    }

    // =============================================================
    // Penjelasan Mengapa Menggunakan vector:
    // =============================================================
    // Kita ingin mengelompokkan menu ke dalam dua kategori:
    //    1. Makanan
    //    2. Minuman
    //
    // Tapi kita tidak tahu jumlah pastinya berapa banyak menu makanan atau minuman.
    // Maka dari itu kita butuh struktur data yang:
    //    - Bisa menampung jumlah elemen yang **berubah-ubah** (dinamis)
    //    - Mudah ditambahkan data (tanpa perlu indeks manual)
    //
    // vector adalah pilihan tepat karena:
    //    - Fleksibel → tidak perlu mendefinisikan ukuran tetap seperti array
    //    - Aman dan efisien → tidak ada risiko overflow
    //    - Bisa digunakan dengan loop modern (range-based for)
    // =============================================================

    vector<menu> makananMenu; // Menyimpan hanya menu makanan
    vector<menu> minumanMenu; // Menyimpan hanya menu minuman

    // Pisahkan menu berdasarkan jenisnya
    for (int i = 0; i < jumlahMenu; ++i) {
        if (daftarMenu[i].jenisMenu == "Makanan") {
            makananMenu.push_back(daftarMenu[i]); // Tambahkan ke vektor makanan
        } else if (daftarMenu[i].jenisMenu == "Minuman") {
            minumanMenu.push_back(daftarMenu[i]); // Tambahkan ke vektor minuman
        }
        // Jika ada jenis menu lain (misalnya "Snack", "Dessert"), bisa ditambahkan logika di sini.
    }

    // ============================
    // TAMPILKAN MENU MAKANAN
    // ============================
    cout << "--- MAKANAN ---\n";

    if (makananMenu.empty()) {
        cout << "Tidak ada menu makanan yang tersedia saat ini.\n\n";
    } else {
        // Header tabel makanan
        cout << setfill(' ') << left;
        cout << setw(5) << "ID"
             << setw(25) << "Nama Menu"
             << setw(15) << "Jenis"
             << right << setw(12) << "Harga (Rp)" << "\n";
        cout << setfill('-') << string(57, '-') << "\n";
        cout << setfill(' ');

        // Tampilkan semua data makanan
        for (const auto& item : makananMenu) {
            cout << left << setw(5) << item.idMenu
                 << setw(25) << item.namaMenu
                 << setw(15) << item.jenisMenu
                 << right << setw(12) << fixed << setprecision(2) << item.harga << "\n";
        }

        // Garis bawah tabel
        cout << setfill('-') << string(57, '-') << setfill(' ') << "\n\n";
    }

    // ============================
    // TAMPILKAN MENU MINUMAN
    // ============================
    cout << "--- MINUMAN ---\n";

    if (minumanMenu.empty()) {
        cout << "Tidak ada menu minuman yang tersedia saat ini.\n\n";
    } else {
        // Header tabel minuman
        cout << setfill(' ') << left;
        cout << setw(5) << "ID"
             << setw(25) << "Nama Menu"
             << setw(15) << "Jenis"
             << right << setw(12) << "Harga (Rp)" << "\n";
        cout << setfill('-') << string(57, '-') << "\n";
        cout << setfill(' ');

        // Tampilkan semua data minuman
        for (const auto& item : minumanMenu) {
            cout << left << setw(5) << item.idMenu
                 << setw(25) << item.namaMenu
                 << setw(15) << item.jenisMenu
                 << right << setw(12) << fixed << setprecision(2) << item.harga << "\n";
        }

        // Garis bawah tabel
        cout << setfill('-') << string(57, '-') << setfill(' ') << "\n";
    }

    // Tunggu user menekan tombol sebelum kembali
    cout << "\nTekan tombol apapun untuk kembali...";
    system("pause > nul");
}

void tambahDataMenu(){
    system("cls"); // Membersihkan layar konsol

    // Header tampilan
    cout << setw(40) << setfill('=') << "" << " << TAMBAH DAFTAR MENU >>" << setw(40) << setfill('=') << "\n";
    cout << "Jumlah Menu Saat Ini: " << jumlahMenu << endl; // Menampilkan total menu saat ini

    // --- Tampilkan daftar menu yang sudah ada sebelumnya ---
    cout << "\n--- DAFTAR MENU YANG SUDAH ADA ---\n";
    if (jumlahMenu == 0) {
        cout << "Belum ada menu yang terdaftar.\n"; // Pesan jika belum ada data
    } else {
        // Tampilkan header kolom
        cout << setfill(' ') << left;
        cout << setw(5) << "ID"
             << setw(25) << "Nama Menu"
             << setw(15) << "Jenis"
             << right << setw(10) << "Harga" << endl;

        // Garis pemisah
        cout << setfill('-') << setw(5) << ""
             << setw(25) << ""
             << setw(15) << ""
             << setw(10) << "" << endl;
        cout << setfill(' ');

        // Tampilkan semua menu yang telah ada
        for (int i = 0; i < jumlahMenu; ++i) {
            cout << left << setw(5) << daftarMenu[i].idMenu 
                 << setw(25) << daftarMenu[i].namaMenu 
                 << setw(15) << daftarMenu[i].jenisMenu 
                 << right << setw(10) << daftarMenu[i].harga << endl;
        }
        // Garis bawah penutup tabel
        cout << setfill('-') << setw(55) << "" << setfill(' ') << endl;
    }

    cout << "\n";

    // --- Form isian untuk menambah menu baru ---
    cout << setw(105) << setfill('=') << "\n";
    cout << setw(30) << "\t\t--ISIKAN MENU YANG AKAN DITAMBAHKAN--\n";
    cout << setw(17) << setfill('-') << "\n";
    cout << "|TAMBAHAN MENU |\n";
    cout << setw(17) << setfill('-') << "\n";

    // Input jumlah menu yang ingin ditambahkan
    cout << "Jumlah menu yang ingin ditambahkan: ";
    int total;
    cin >> total;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Menghapus sisa input di buffer

    for (int a = 0; a < total; ++a)
    {
        // Validasi jika jumlah menu sudah penuh (kapasitas maksimum 100)
        if (jumlahMenu >= 100) {
            cout << "Kapasitas menu penuh. Tidak bisa menambahkan lebih banyak menu.\n";
            break;
        }

        // Set ID menu secara otomatis
        daftarMenu[jumlahMenu].idMenu = jumlahMenu + 1;

        // Tampilkan pilihan jenis
        cout << setw(17) << setfill('=') << "\n";
        cout << " JENIS MENU \n";
        cout << setw(17) << setfill('=') << "\n";
        cout << " - Makanan \n";
        cout << " - Minuman \n";
        cout << setw(17) << setfill('-') << "\n";
        cout << "ID Menu\t\t\t: " << daftarMenu[jumlahMenu].idMenu << endl;

        // --- Validasi input jenis menu (harus Makanan atau Minuman) ---
        string jenisInput;
        bool jenisValid = false;

        while (!jenisValid) {
            cout << "Masukkan Jenis Menu\t: ";
            getline(cin, jenisInput);

            // Ubah semua huruf ke huruf kecil untuk memudahkan validasi
            transform(jenisInput.begin(), jenisInput.end(), jenisInput.begin(), ::tolower);

            if (jenisInput == "makanan") {
                daftarMenu[jumlahMenu].jenisMenu = "Makanan";
                jenisValid = true;
            } else if (jenisInput == "minuman") {
                daftarMenu[jumlahMenu].jenisMenu = "Minuman";
                jenisValid = true;
            } else {
                cout << "\nPERINGATAN: Jenis menu tidak valid!\n";
                cout << "Mohon masukkan 'Makanan' atau 'Minuman'.\n\n";
            }
        }

        // Input nama menu
        cout << "Masukkan Nama Menu\t: ";
        getline(cin, daftarMenu[jumlahMenu].namaMenu);

        // Input harga menu
        cout << "Masukkan Harga Menu\t: ";
        cin >> daftarMenu[jumlahMenu].harga;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer

        jumlahMenu++; // Tambah jumlah menu yang tersimpan
    }

    // Tampilkan pesan konfirmasi
    cout << setw(30) << setfill('=') << "" << "DAFTAR MENU BERHASIL DI TAMBAHKAN" << setw(30) << setfill('=') << "\n";
    system("pause"); // Tunggu input user sebelum kembali
}

void tambahDataPelanggan(){
    system("cls"); // Bersihkan layar konsol
    cout << setw(40) << setfill('=') << "" << " << TAMBAH DAFTAR PELANGGAN >>" << setw(40) << setfill('=') << "\n";
    cout << "Jumlah Pelanggan : " << jumlahPelanggan << endl;

    // Header tampilan input pelanggan baru
    cout << setw(110) << setfill('=') << "\n";
    cout << setw(30) << "\t\t--ISIKAN DATA PELANGGAN YANG AKAN DITAMBAHKAN--\n";
    cout << setw(20) << setfill('-') << "\n";
    cout << "|TAMBAH PELANGGAN |\n";
    cout << setw(20) << setfill('-') << "\n";

    // Input berapa banyak pelanggan yang akan ditambahkan
    cout << "Jumlah Pelanggan yang ingin ditambahkan: ";
    int total;
    cin >> total;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan sisa input buffer

    for (int a = 0; a < total; ++a)
    {
        // Validasi kapasitas
        if (jumlahPelanggan >= 100) {
            cout << "Kapasitas pelanggan penuh.\n";
            break;
        }

        // Set ID pelanggan otomatis
        daftarPelanggan[jumlahPelanggan].idPelanggan = jumlahPelanggan + 1;
        cout << "ID Pelanggan\t\t: " << daftarPelanggan[jumlahPelanggan].idPelanggan << endl;

        // Input nama pelanggan
        cout << "Masukkan Nama Pelanggan : ";
        getline(cin, daftarPelanggan[jumlahPelanggan].namaPelanggan);

        // --- Menu untuk mengurutkan daftar menu sebelum ditampilkan ---
        system("cls");
        cout << setw(71) << setfill('=');
        cout << "\n\t|PILIH CARA PENGURUTAN MENU:|\n";
        cout << setw(40) << setfill('=') << "\n";

        int pilihanSort;
        cout << "1. Berdasarkan ID Menu\n";
        cout << "2. Berdasarkan Nama Menu\n";
        cout << "3. Berdasarkan Harga\n";
        cout << "4. Tanpa Pengurutan (Default)\n";
        cout << "Pilih Pengurutan Menu: ";
        cin >> pilihanSort;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Jika tidak ada menu tersedia
        if (jumlahMenu == 0) {
            cout << "Belum ada menu yang tersedia.\n";
            system("pause");
            return;
        }

        // Sorting menu berdasarkan pilihan pengguna
        switch (pilihanSort) {
            case 1:
                sortingId();
                cout << "Menu diurutkan berdasarkan ID.\n";
                break;
            case 2:
                sortingNama();
                cout << "Menu diurutkan berdasarkan Nama.\n";
                break;
            case 3: {
                // Sorting berdasarkan harga: naik/turun
                cout << "1. Harga Termurah (Ascending)\n";
                cout << "2. Harga Termahal (Descending)\n";
                cout << "Pilih urutan harga: ";
                int order;
                cin >> order;
                bool ascending = (order == 1);
                sortingharga(ascending);
                cout << "Menu diurutkan berdasarkan Harga.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            case 4:
                cout << "Menu ditampilkan tanpa pengurutan.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Menu ditampilkan tanpa pengurutan.\n";
                break;
        }

        system("pause");
        system("cls");

        // --- Menampilkan semua menu makanan ---
        cout << setw(71) << setfill('=');
        cout << "\n\t|DAFTAR MENU YANG TERSEDIA:|\n";
        cout << setw(40) << setfill('=') << "\n";

        cout << "\n================= KATEGORI MAKANAN ================\n";
        cout << setfill(' ') << left;
        cout << setw(5) << "ID"
             << setw(25) << "Nama Menu"
             << setw(15) << "Jenis"
             << right << setw(10) << "Harga" << endl;
        cout << setfill('-') << setw(5) << "" << setw(25) << "" << setw(15) << "" << setw(10) << "" << endl;
        cout << setfill(' ');

        bool foundFood = false;
        for (int i = 0; i < jumlahMenu; ++i)
        {
            if (daftarMenu[i].jenisMenu == "Makanan") {
                cout << left << setw(5) << daftarMenu[i].idMenu << " "
                     << setw(25) << daftarMenu[i].namaMenu << " "
                     << setw(15) << daftarMenu[i].jenisMenu << " "
                     << right << setw(10) << daftarMenu[i].harga << endl;
                foundFood = true;
            }
        }
        if (!foundFood) {
            cout << "              (Tidak ada menu makanan yang tersedia)\n";
        }
        cout << setfill('-') << setw(55) << "" << setfill(' ') << endl;

        // --- Menampilkan semua menu minuman ---
        cout << "\n================= KATEGORI MINUMAN ================\n";
        cout << setfill(' ') << left;
        cout << setw(5) << "ID"
             << setw(25) << "Nama Menu"
             << setw(15) << "Jenis"
             << right << setw(10) << "Harga" << endl;
        cout << setfill('-') << setw(5) << "" << setw(25) << "" << setw(15) << "" << setw(10) << "" << endl;
        cout << setfill(' ');

        bool foundDrink = false;
        for (int i = 0; i < jumlahMenu; ++i)
        {
            if (daftarMenu[i].jenisMenu == "Minuman") {
                cout << left << setw(5) << daftarMenu[i].idMenu << " "
                     << setw(25) << daftarMenu[i].namaMenu << " "
                     << setw(15) << daftarMenu[i].jenisMenu << " "
                     << right << setw(10) << daftarMenu[i].harga << endl;
                foundDrink = true;
            }
        }
        if (!foundDrink) {
            cout << "             (Tidak ada menu minuman yang tersedia)\n";
        }
        cout << setfill('-') << setw(55) << "" << setfill(' ') << endl;

        // --- Input pesanan pelanggan ---
        int i = 0;
        daftarPelanggan[jumlahPelanggan].jumlahPesanan = 0;
        while (true)
        {
            if (i >= 100) {
                cout << "Kapasitas pesanan penuh untuk pelanggan ini.\n";
                break;
            }

            // Input ID menu yang ingin dipesan
            cout << "Masukkan ID Menu yang dipesan (0 untuk selesai) : ";
            int inputIdMenu;
            cin >> inputIdMenu;

            // Validasi input numerik
            if (cin.fail()) {
                cout << "\nPERINGATAN: Masukkan ID dalam angka yang valid!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            // Keluar dari input pesanan jika 0
            if (inputIdMenu == 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

            // Cari apakah ID valid
            int idCheckIndex = -1;
            for (int k = 0; k < jumlahMenu; ++k) {
                if (daftarMenu[k].idMenu == inputIdMenu) {
                    idCheckIndex = k;
                    break;
                }
            }

            if (idCheckIndex == -1) {
                cout << "ID Menu tidak ditemukan. Silakan coba lagi.\n";
                continue;
            }

            // Jika valid, simpan ID pesanan
            daftarPelanggan[jumlahPelanggan].pesanan[i] = inputIdMenu;

            // Input jumlah menu yang dipesan
            cout << "Masukkan Jumlah Pesanan\t: ";
            cin >> daftarPelanggan[jumlahPelanggan].jumlahMenu[i];

            // Validasi jumlah
            if (cin.fail()) {
                cout << "Input jumlah tidak valid.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (daftarPelanggan[jumlahPelanggan].jumlahMenu[i] <= 0) {
                cout << "Jumlah pesanan harus lebih dari 0.\n";
                continue;
            }

            i++;
        }

        // Simpan total jumlah pesanan yang telah dimasukkan untuk pelanggan ini
        daftarPelanggan[jumlahPelanggan].jumlahPesanan = i;

        // Hitung total harga pesanan pelanggan berdasarkan data pesanan dan daftar menu
        hitungTotalHarga(daftarPelanggan[jumlahPelanggan]);

        // Tambah jumlah pelanggan setelah data lengkap dimasukkan
        jumlahPelanggan++;
    }

    // Tampilkan pesan sukses setelah pelanggan dan pesanan berhasil ditambahkan
    cout << setw(30) << setfill('=') << "" << "DATA PELANGGAN BERHASIL DI TAMBAHKAN" << setw(30) << setfill('=') << "\n";

    // Simpan data pelanggan ke penyimpanan (file/database) agar data tidak hilang setelah program selesai
    simpanpelanggan();

    // Pause sejenak agar user dapat melihat pesan di layar
    system("pause");
}

void hitungTotalHarga(pelanggan &p){
    int total = 0; // Inisialisasi variabel total harga pesanan pelanggan dengan nilai 0
    
    // Loop sebanyak jumlah pesanan yang dimiliki pelanggan p
    for (int i = 0; i < p.jumlahPesanan; ++i)
    {
        // idMenuIndex adalah indeks dari menu dalam array daftarMenu,
        // didapat dengan mengurangi 1 dari ID menu yang dipesan karena ID biasanya mulai dari 1,
        // sedangkan indeks array mulai dari 0
        int idMenuIndex = p.pesanan[i] - 1;

        // Validasi indeks agar tidak out of bounds pada array daftarMenu
        if (idMenuIndex >= 0 && idMenuIndex < jumlahMenu)
        {
            // Hitung total harga dengan mengalikan harga menu dengan jumlah pesanan untuk menu tersebut
            total += daftarMenu[idMenuIndex].harga * p.jumlahMenu[i];
        }
    }

    // Simpan total harga yang sudah dihitung ke atribut totalHarga pelanggan p
    p.totalHarga = total;
}

void hapusdatamenu() {
    system("cls"); // Bersihkan layar console

    // Tampilan header fungsi hapus data menu
    cout << "=======================================\n";
    cout << "           HAPUS DATA MENU\n";
    cout << "=======================================\n\n";

    // Jika belum ada menu yang tersimpan, langsung keluar fungsi dengan pesan
    if (jumlahMenu == 0) {
        cout << "Belum ada menu yang tersedia untuk dihapus.\n";
        cout << "Tekan tombol apapun untuk kembali...";
        system("pause > nul");
        return; // Keluar fungsi karena tidak ada data yang bisa dihapus
    }

    // Pisahkan daftar menu menjadi dua kategori, makanan dan minuman,
    // dengan menggunakan vector agar lebih mudah memanipulasi dan menampilkan
    vector<menu> makananMenu;
    vector<menu> minumanMenu;

    // Loop untuk memisahkan menu sesuai jenisnya ke vector yang sesuai
    for (int i = 0; i < jumlahMenu; ++i) {
        if (daftarMenu[i].jenisMenu == "Makanan") {
            makananMenu.push_back(daftarMenu[i]);
        } else if (daftarMenu[i].jenisMenu == "Minuman") {
            minumanMenu.push_back(daftarMenu[i]);
        }
    }

    // Tampilkan daftar menu makanan
    cout << "--- MAKANAN ---\n";
    if (makananMenu.empty()) {
        cout << "Tidak ada menu makanan yang tersedia saat ini.\n\n";
    } else {
        cout << setfill(' ') << left;
        cout << setw(5) << "ID"
             << setw(25) << "Nama Menu"
             << setw(15) << "Jenis"
             << right << setw(12) << "Harga (Rp)" << "\n";
        cout << setfill('-') << string(57, '-') << "\n";
        cout << setfill(' ');

        // Loop menampilkan setiap item makanan secara rapih
        for (const auto& item : makananMenu) {
            cout << left << setw(5) << item.idMenu
                 << setw(25) << item.namaMenu
                 << setw(15) << item.jenisMenu
                 << right << setw(12) << fixed << setprecision(2) << item.harga << "\n";
        }
        cout << setfill('-') << string(57, '-') << setfill(' ') << "\n\n";
    }

    // Tampilkan daftar menu minuman
    cout << "--- MINUMAN ---\n";
    if (minumanMenu.empty()) {
        cout << "Tidak ada menu minuman yang tersedia saat ini.\n\n";
    } else {
        cout << setfill(' ') << left;
        cout << setw(5) << "ID"
             << setw(25) << "Nama Menu"
             << setw(15) << "Jenis"
             << right << setw(12) << "Harga (Rp)" << "\n";
        cout << setfill('-') << string(57, '-') << "\n";
        cout << setfill(' ');

        // Loop menampilkan setiap item minuman secara rapih
        for (const auto& item : minumanMenu) {
            cout << left << setw(5) << item.idMenu
                 << setw(25) << item.namaMenu
                 << setw(15) << item.jenisMenu
                 << right << setw(12) << fixed << setprecision(2) << item.harga << "\n";
        }
        cout << setfill('-') << string(57, '-') << setfill(' ') << "\n";
    }

    // Minta input ID menu yang ingin dihapus
    int idToDelete;
    cout << "\nMasukkan ID menu yang ingin dihapus: ";
    // Validasi input agar user memasukkan angka yang benar
    while (!(cin >> idToDelete)) {
        cout << "Input tidak valid. Mohon masukkan angka untuk ID menu: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Cari index menu pada array daftarMenu berdasarkan ID yang dimasukkan
    int index = -1;
    for (int i = 0; i < jumlahMenu; i++) {
        if (daftarMenu[i].idMenu == idToDelete) {
            index = i;
            break;
        }
    }

    // Jika ID tidak ditemukan, tampilkan pesan dan keluar fungsi
    if (index == -1) {
        cout << "\n---------------------------------------\n";
        cout << "ID menu " << idToDelete << " tidak ditemukan.\n";
        cout << "---------------------------------------\n";
        cout << "Tekan tombol apapun untuk kembali...";
        system("pause > nul");
        return;
    }

    // Konfirmasi penghapusan menu dengan user (y/n)
    char confirmChoice;
    cout << "Apakah Anda yakin ingin menghapus menu '" << daftarMenu[index].namaMenu << "' (ID: " << daftarMenu[index].idMenu << ")? (y/n): ";
    cin >> confirmChoice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Jika konfirmasi ya, lakukan penghapusan
    if (confirmChoice == 'y' || confirmChoice == 'Y') {
        // Geser data menu di array untuk menimpa data yang dihapus
        for (int j = index; j < jumlahMenu - 1; j++) {
            daftarMenu[j] = daftarMenu[j + 1];
        }
        jumlahMenu--; // Kurangi jumlah menu karena sudah dihapus

        cout << "\n=======================================\n";
        cout << "       Menu berhasil dihapus!\n";
        cout << "=======================================\n";
        // simpanMenu(); // Bisa dipanggil untuk menyimpan data setelah penghapusan jika ada fungsi simpan
    } else {
        // Jika batal, tampilkan pesan pembatalan
        cout << "\nPenghapusan dibatalkan.\n";
    }
    
    cout << "Tekan tombol apapun untuk melanjutkan...";
    system("pause > nul"); // Tunggu input user sebelum kembali
}

void hapusDataPelanggan() {
    system("cls"); // Bersihkan layar console agar tampilan lebih rapi

    // Tampilan header untuk fungsi hapus data pelanggan
    cout << "=======================================\n";
    cout << "          HAPUS DATA PELANGGAN\n";
    cout << "=======================================\n\n";

    // --- Cek apakah ada data pelanggan yang tersedia untuk dihapus ---
    if (jumlahPelanggan == 0) {
        cout << "Belum ada pelanggan yang tersedia untuk dihapus.\n";
        cout << "Tekan tombol apapun untuk kembali...";
        system("pause > nul"); // Tunggu input user tanpa menampilkan pesan "Press any key"
        return; // Keluar fungsi karena tidak ada data pelanggan
    }

    // --- Tampilkan daftar pelanggan yang tersedia dengan format rapi ---
    cout << "--- Daftar Pelanggan Tersedia ---\n";
    cout << left << setw(5) << "ID"             // Lebar kolom 5 karakter untuk ID
              << setw(30) << "Nama Pelanggan" << "\n"; // Lebar kolom 30 karakter untuk nama
    cout << string(35, '-') << "\n"; // Garis horizontal pemisah

    // Loop untuk menampilkan semua pelanggan yang tersimpan
    for (int i = 0; i < jumlahPelanggan; i++) {
        cout << left << setw(5) << daftarPelanggan[i].idPelanggan
                  << setw(30) << daftarPelanggan[i].namaPelanggan << "\n";
    }
    cout << string(35, '-') << "\n\n";

    // --- Meminta input ID pelanggan yang ingin dihapus dengan validasi ---
    int idToDelete;
    cout << "Masukkan ID pelanggan yang ingin dihapus: ";
    // Loop hingga user memasukkan input yang valid (angka)
    while (!(cin >> idToDelete)) {
        cout << "Input tidak valid. Mohon masukkan angka untuk ID pelanggan: ";
        cin.clear(); // Reset error flags pada cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buang input salah di buffer
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan sisa input dari buffer

    // --- Cari indeks pelanggan berdasarkan ID yang dimasukkan ---
    int indexToDelete = -1; // Inisialisasi indeks dengan -1 (belum ditemukan)
    for (int i = 0; i < jumlahPelanggan; i++) {
        if (daftarPelanggan[i].idPelanggan == idToDelete) {
            indexToDelete = i; // Temukan posisi pelanggan di array
            break;
        }
    }

    // --- Jika ID pelanggan tidak ditemukan ---
    if (indexToDelete == -1) {
        cout << "\n---------------------------------------\n";
        cout << "ID pelanggan " << idToDelete << " tidak ditemukan.\n";
        cout << "---------------------------------------\n";
        cout << "Tekan tombol apapun untuk kembali...";
        system("pause > nul");
        return; // Keluar fungsi karena data tidak ditemukan
    }

    // --- Konfirmasi penghapusan data pelanggan ---
    char confirmChoice;
    cout << "Apakah Anda yakin ingin menghapus pelanggan '" << daftarPelanggan[indexToDelete].namaPelanggan
         << "' (ID: " << daftarPelanggan[indexToDelete].idPelanggan << ")? (y/n): ";
    cin >> confirmChoice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer input

    if (confirmChoice == 'y' || confirmChoice == 'Y') {
        // --- Proses penghapusan data dengan menggeser elemen berikutnya ke depan ---
        for (int j = indexToDelete; j < jumlahPelanggan - 1; j++) {
            daftarPelanggan[j] = daftarPelanggan[j + 1];
            // Catatan: jika ingin membuat ID pelanggan tetap berurutan setelah penghapusan,
            // bisa menambahkan kode untuk mengupdate idPelanggan di sini.
            // Namun, biasanya ID pelanggan unik dan tidak berubah.
        }
        jumlahPelanggan--; // Kurangi jumlah pelanggan karena ada yang dihapus

        cout << "\n=======================================\n";
        cout << "       Data pelanggan berhasil dihapus!\n";
        cout << "=======================================\n";

        // Simpan perubahan data pelanggan ke file atau media penyimpanan lain
        simpanpelanggan(); 
    } else {
        cout << "\nPenghapusan dibatalkan.\n";
    }
    
    cout << "Tekan tombol apapun untuk melanjutkan...";
    system("pause > nul"); // Tunggu input user sebelum kembali ke menu
}

void sortingNama(){
    // Loop luar untuk mengulangi proses sorting sebanyak (jumlahMenu - 1) kali
    for (int i = 0; i < jumlahMenu - 1; i++)
    {
        // Loop dalam untuk membandingkan elemen-elemen bertetangga
        // hingga posisi yang sudah terurut di akhir array
        for (int j = 0; j < jumlahMenu - i - 1; j++)
        {
            // Bandingkan namaMenu pada indeks j dan j+1 secara leksikografis (alfabetis)
            if (daftarMenu[j].namaMenu > daftarMenu[j + 1].namaMenu)
            {
                // Jika nama pada j lebih besar (urutnya setelah nama j+1),
                // lakukan pertukaran posisi agar nama yang lebih kecil/awal alfabet
                // berada di posisi yang lebih awal dalam array
                menu temp = daftarMenu[j];
                daftarMenu[j] = daftarMenu[j + 1];
                daftarMenu[j + 1] = temp;
            }
        }
    }
}

void sortingId(){
    for (int i = 0; i < jumlahMenu - 1; i++)
    {
        for (int j = 0; j < jumlahMenu - i - 1; j++)
        {
            if (daftarMenu[j].idMenu > daftarMenu[j + 1].idMenu)
            {
                menu temp = daftarMenu[j];
                daftarMenu[j] = daftarMenu[j + 1];
                daftarMenu[j + 1] = temp;
            }
        }
    }
}

void bubblehargamenu(bool ascending){
    // Loop luar mengontrol jumlah iterasi sorting
    for (int i = 0; i < jumlahMenu - 1; i++)
    {
        // Loop dalam untuk membandingkan elemen yang berdampingan
        for (int j = 0; j < jumlahMenu - i - 1; j++)
        {
            // Jika sorting ascending (harga terkecil ke terbesar)
            // lakukan swap jika harga elemen sekarang lebih besar daripada elemen berikutnya
            // Jika sorting descending (harga terbesar ke terkecil)
            // lakukan swap jika harga elemen sekarang lebih kecil daripada elemen berikutnya
            if ((ascending && daftarMenu[j].harga > daftarMenu[j + 1].harga) ||
                (!ascending && daftarMenu[j].harga < daftarMenu[j + 1].harga))
            {
                // Tukar posisi menu agar sesuai urutan harga yang diinginkan
                swap(daftarMenu[j], daftarMenu[j + 1]);
            }
        }
    }
}

void quickhargamenu(menu arr[], int low, int high, bool ascending){
    // Basis rekursi: jika low sudah tidak kurang dari high, hentikan pemanggilan rekursif
    if (low < high)
    {
        // Pivot diambil dari elemen terakhir pada sub-array saat ini
        int pivot = arr[high].harga;
        int i = low - 1; // Index untuk elemen yang lebih kecil dari pivot (ascending) atau lebih besar (descending)

        // Loop untuk membandingkan elemen dari low sampai high-1
        for (int j = low; j < high; j++)
        {
            // Jika ascending, cek harga lebih kecil dari pivot
            // Jika descending, cek harga lebih besar dari pivot
            if ((ascending && arr[j].harga < pivot) || (!ascending && arr[j].harga > pivot))
            {
                i++; // Naikkan index i
                swap(arr[i], arr[j]); // Tukar elemen agar elemen yang sesuai kondisi berada di kiri pivot
            }
        }

        // Tempatkan pivot ke posisi yang benar (setelah semua elemen yang sesuai)
        swap(arr[i + 1], arr[high]);

        // Posisi pivot yang baru setelah penempatan
        int pi = i + 1;

        // Rekursif untuk sub-array kiri dari pivot
        quickhargamenu(arr, low, pi - 1, ascending);

        // Rekursif untuk sub-array kanan dari pivot
        quickhargamenu(arr, pi + 1, high, ascending);
    }
}

// Fungsi untuk mengurutkan data menu berdasarkan harga dengan satu parameter
void sortingharga(bool ascending){
    // Memanggil fungsi bubblehargamenu untuk melakukan pengurutan
    // Parameter 'ascending' menentukan apakah urutan menaik (true) atau menurun (false)
    bubblehargamenu(ascending); 

    // Menampilkan pesan bahwa data menu telah berhasil diurutkan
    cout << "Data menu sudah diurutkan berdasarkan harga." << endl;

    // Menunggu input pengguna untuk melanjutkan, biasanya untuk memberi waktu membaca pesan
    system("pause");
}

void melihatDataMenu(){
    system("cls"); // Bersihkan layar console untuk tampilan yang rapi

    // Menampilkan judul tampilan menu
    cout << "=======================================\n";
    cout << "          TAMPILKAN DATA MENU\n";
    cout << "=======================================\n\n";

    // Jika belum ada menu yang tersedia, tampilkan pesan dan keluar fungsi
    if (jumlahMenu == 0) {
        cout << "Belum ada menu yang tersedia untuk ditampilkan.\n";
        cout << "Tekan tombol apapun untuk kembali...";
        system("pause > nul"); // Pause tanpa menampilkan teks "Press any key..."
        return;
    }

    // Menampilkan pilihan metode pengurutan data menu
    cout << "===== PILIHAN PENGURUTAN MENU =====\n";
    cout << "1. Berdasarkan ID Menu\n";
    cout << "2. Berdasarkan Nama Menu\n";
    cout << "3. Berdasarkan Harga\n";
    cout << "4. Tanpa Pengurutan (Default)\n";
    cout << "Pilih opsi pengurutan: ";

    int pilihSort;
    // Validasi input agar hanya menerima angka 1 sampai 4
    while (!(cin >> pilihSort) || pilihSort < 1 || pilihSort > 4) {
        cout << "Input tidak valid. Mohon masukkan angka antara 1-4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer input

    system("cls"); // Bersihkan layar setelah memilih opsi pengurutan

    // Proses pengurutan sesuai pilihan pengguna
    if (pilihSort == 1) {
        sortingId(); // Fungsi untuk mengurutkan menu berdasarkan ID
        cout << "Menu diurutkan berdasarkan ID.\n\n";
    } else if (pilihSort == 2) {
        sortingNama(); // Fungsi untuk mengurutkan menu berdasarkan nama
        cout << "Menu diurutkan berdasarkan Nama.\n\n";
    } else if (pilihSort == 3) {
        // Jika memilih berdasarkan harga, tampilkan pilihan urutan harga
        cout << "\n--- Pilihan Urutan Harga ---\n";
        cout << "1. Ascending (Harga Termurah ke Termahal)\n";
        cout << "2. Descending (Harga Termahal ke Termurah)\n";
        cout << "Pilih urutan harga: ";

        int order;
        // Validasi input agar hanya menerima angka 1 atau 2
        while (!(cin >> order) || (order != 1 && order != 2)) {
            cout << "Input tidak valid. Mohon masukkan 1 (Ascending) atau 2 (Descending): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer input

        bool ascending = (order == 1);
        sortingharga(ascending); // Fungsi untuk mengurutkan menu berdasarkan harga dengan urutan ascending/descending
        cout << "Menu diurutkan berdasarkan Harga " << (ascending ? "Ascending" : "Descending") << ".\n\n";
    } else {
        // Jika pilihSort == 4, tampilkan menu tanpa pengurutan
        cout << "Menampilkan menu tanpa pengurutan.\n\n";
    }

    // Menampilkan header tabel data menu restoran
    cout << "=======================================\n";
    cout << "           DATA MENU RESTORAN\n";
    cout << "=======================================\n\n";

    // Membuat dua vector untuk memisahkan menu makanan dan minuman
    vector<menu> makananMenu;
    vector<menu> minumanMenu;

    // Memisahkan daftar menu berdasarkan jenisnya
    for (int i = 0; i < jumlahMenu; ++i) {
        if (daftarMenu[i].jenisMenu == "Makanan") {
            makananMenu.push_back(daftarMenu[i]);
        } else if (daftarMenu[i].jenisMenu == "Minuman") {
            minumanMenu.push_back(daftarMenu[i]);
        }
        // Bisa ditambahkan else untuk kategori lain atau validasi data
    }

    // Menampilkan daftar makanan
    cout << "--- MAKANAN ---\n";
    if (makananMenu.empty()) {
        cout << "Tidak ada menu makanan yang tersedia.\n\n";
    } else {
        // Menampilkan header tabel makanan dengan format rapi
        cout << setfill(' ') << left;
        cout << setw(5) << "ID"
             << setw(25) << "Nama Menu"
             << setw(15) << "Jenis"
             << right << setw(12) << "Harga (Rp)" << endl;
        cout << setfill('-') << string(57, '-') << endl;
        cout << setfill(' ');

        // Menampilkan tiap menu makanan dengan format kolom yang rapi
        for (const auto& item : makananMenu) {
            cout << left << setw(5) << item.idMenu
                 << setw(25) << item.namaMenu
                 << setw(15) << item.jenisMenu
                 << right << setw(12) << fixed << setprecision(2) << item.harga << endl;
        }
        cout << setfill('-') << string(57, '-') << setfill(' ') << endl;
        cout << "\n";
    }

    // Menampilkan daftar minuman
    cout << "--- MINUMAN ---\n";
    if (minumanMenu.empty()) {
        cout << "Tidak ada menu minuman yang tersedia.\n\n";
    } else {
        // Menampilkan header tabel minuman dengan format rapi
        cout << setfill(' ') << left;
        cout << setw(5) << "ID"
             << setw(25) << "Nama Menu"
             << setw(15) << "Jenis"
             << right << setw(12) << "Harga (Rp)" << endl;
        cout << setfill('-') << string(57, '-') << endl;
        cout << setfill(' ');

        // Menampilkan tiap menu minuman dengan format kolom yang rapi
        for (const auto& item : minumanMenu) {
            cout << left << setw(5) << item.idMenu
                 << setw(25) << item.namaMenu
                 << setw(15) << item.jenisMenu
                 << right << setw(12) << fixed << setprecision(2) << item.harga << endl;
        }
        cout << setfill('-') << string(57, '-') << setfill(' ') << endl;
    }

    // Akhiri dengan menunggu input pengguna sebelum kembali
    cout << "\nTekan tombol apapun untuk kembali...";
    system("pause > nul");
}

void cariPelanggan(){
    system("cls");  // Bersihkan layar console agar tampilan lebih rapi

    cout << "\n===== CARI DATA PELANGGAN =====\n";
    cout << "Masukkan ID atau Nama Pelanggan: ";

    string input;
    // Bersihkan buffer input sebelumnya agar getline bekerja dengan benar
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Membaca input pengguna berupa string (bisa ID atau nama pelanggan)
    getline(cin, input);

    bool found = false;  // Flag untuk menandai apakah data ditemukan atau tidak

    // Loop untuk mencari data pelanggan di dalam array daftarPelanggan
    for (int i = 0; i < jumlahPelanggan; i++)
    {
        // Membandingkan input dengan id pelanggan (diubah jadi string) atau nama pelanggan
        if (to_string(daftarPelanggan[i].idPelanggan) == input || daftarPelanggan[i].namaPelanggan == input)
        {
            // Jika ditemukan, tampilkan data pelanggan secara rinci
            cout << "\nData Pelanggan Ditemukan:\n";
            cout << "ID      : " << daftarPelanggan[i].idPelanggan << endl;
            cout << "Nama    : " << daftarPelanggan[i].namaPelanggan << endl;
            cout << "Jumlah Pesanan: " << daftarPelanggan[i].jumlahPesanan << endl;
            cout << "Total Harga    : Rp " << daftarPelanggan[i].totalHarga << endl;

            found = true;  // Tandai bahwa data ditemukan
            break;         // Hentikan pencarian setelah data ditemukan
        }
    }

    // Jika setelah pencarian data tidak ditemukan
    if (!found)
    {
        cout << "\n== Data pelanggan tidak ditemukan ==\n";
    }

    system("pause");  // Tunggu hingga pengguna menekan tombol untuk kembali
}

void carimenu(){
    system("cls"); // Membersihkan layar console agar tampilan lebih rapi

    cout << "\n===== CARI MENU =====\n";
    cout << "Masukkan nama menu: ";

    string input;
    // Membersihkan buffer input sebelumnya agar getline dapat membaca input dengan benar
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Membaca input nama menu yang ingin dicari dari pengguna, bisa berupa string dengan spasi
    getline(cin, input);

    bool found = false; // Flag untuk menandai apakah menu ditemukan

    // Loop untuk mencari menu berdasarkan nama di array daftarMenu
    for (int i = 0; i < jumlahMenu; i++)
    {
        // Membandingkan input dengan nama menu di daftarMenu
        if (daftarMenu[i].namaMenu == input)
        {
            // Jika ditemukan, tampilkan detail menu tersebut
            cout << "\nMenu Ditemukan:\n";
            cout << "ID         : " << daftarMenu[i].idMenu << endl;
            cout << "Nama       : " << daftarMenu[i].namaMenu << endl;
            cout << "Jenis Menu : " << daftarMenu[i].jenisMenu << endl;
            cout << "Harga      : Rp " << daftarMenu[i].harga << endl;

            found = true; // Tandai bahwa menu ditemukan
            break;        // Hentikan pencarian setelah menemukan menu
        }
    }

    // Jika menu tidak ditemukan setelah seluruh pencarian
    if (!found)
    {
        cout << "\n== Menu tidak ditemukan ==\n";
    }

    system("pause"); // Tunggu input pengguna sebelum kembali ke menu utama atau layar sebelumnya
}

void melihatDataPelanggan(){
    system("cls"); // Bersihkan layar console agar tampilan lebih rapi dan baru

    // Tampilkan header utama dengan garis '=' sepanjang 80 karakter
    cout << setw(80) << setfill('=') << "" << "\n";
    cout << setw(30) << setfill(' ') << "" << "=== DATA PELANGGAN ===" << "\n";
    cout << setw(80) << setfill('=') << "" << "\n\n";

    // Cek apakah ada data pelanggan yang tersedia
    if (jumlahPelanggan == 0) {
        // Jika tidak ada pelanggan, tampilkan pesan pemberitahuan
        cout << setw(40) << setfill(' ') << "" << "Belum ada data pelanggan yang tersedia.\n\n";
    } else {
        // Jika ada data pelanggan, tampilkan satu per satu
        for (int a = 0; a < jumlahPelanggan; ++a)
        {
            // Garis pemisah atas setiap pelanggan menggunakan karakter '-'
            cout << setw(80) << setfill('-') << " " << "\n";
            cout << setfill(' '); // Reset fill menjadi spasi

            // Tampilkan ID Pelanggan dengan format kolom rapi
            cout << left << setw(20) << "| ID Pelanggan" << " | " << setw(53) << daftarPelanggan[a].idPelanggan << " |\n";
            cout << setw(80) << setfill('-') << " " << "\n";
            cout << setfill(' ');

            // Tampilkan Nama Pelanggan
            cout << left << setw(20) << "| Nama Pelanggan" << " | " << setw(53) << daftarPelanggan[a].namaPelanggan << " |\n";
            cout << setw(80) << setfill('-') << " " << "\n";
            cout << setfill(' ');

            // Tampilkan Jumlah Pesanan pelanggan tersebut
            cout << left << setw(20) << "| Jumlah Pesanan" << " | " << setw(53) << daftarPelanggan[a].jumlahPesanan << " |\n";
            cout << setw(80) << setfill('-') << " " << "\n";
            cout << setfill(' ');

            // Tampilkan Total Tagihan pelanggan, dengan format mata uang Rp
            cout << left << setw(20) << "| Total Tagihan" << " | Rp " << setw(50) << daftarPelanggan[a].totalHarga << " |\n";
            cout << setw(80) << setfill('-') << " " << "\n";
            cout << setfill(' ');

            // Judul untuk rincian pesanan pelanggan
            cout << "\n" << setw(30) << setfill(' ') << "" << "RINCIAN PESANAN:\n";
            cout << setw(80) << setfill('-') << "" << "\n";
            cout << setfill(' ');

            // Header tabel rincian pesanan: ID Menu, Nama Menu, Jumlah, Harga Satuan, Subtotal
            cout << left << setw(10) << "ID Menu"
                 << setw(25) << "Nama Menu"
                 << setw(10) << "Jumlah"
                 << setw(15) << "Harga Satuan"
                 << right << setw(15) << "Subtotal" << endl;

            // Garis bawah header
            cout << setfill('-') << setw(10) << ""
                 << setw(25) << ""
                 << setw(10) << ""
                 << setw(15) << ""
                 << setw(15) << "" << endl;
            cout << setfill(' '); // Reset fill menjadi spasi

            // Jika pelanggan tidak memiliki pesanan
            if (daftarPelanggan[a].jumlahPesanan == 0) {
                cout << left << setw(80) << "Tidak ada pesanan untuk pelanggan ini." << endl;
            } else {
                // Loop untuk menampilkan setiap pesanan pelanggan
                for (int i = 0; i < daftarPelanggan[a].jumlahPesanan; ++i)
                {
                    int idMenuIndex = daftarPelanggan[a].pesanan[i] - 1; // Index menu di array daftarMenu

                    // Validasi apakah index menu valid
                    if (idMenuIndex >= 0 && idMenuIndex < jumlahMenu)
                    {
                        // Hitung subtotal = jumlah pesanan * harga satuan menu
                        int subtotal = daftarPelanggan[a].jumlahMenu[i] * daftarMenu[idMenuIndex].harga;

                        // Tampilkan detail pesanan (ID Menu, Nama Menu, Jumlah, Harga Satuan, Subtotal)
                        cout << left << setw(10) << daftarPelanggan[a].pesanan[i]
                             << setw(25) << daftarMenu[idMenuIndex].namaMenu
                             << setw(10) << daftarPelanggan[a].jumlahMenu[i]
                             << setw(15) << daftarMenu[idMenuIndex].harga
                             << right << setw(15) << subtotal << endl;
                    }
                    else
                    {
                        // Jika menu tidak ditemukan (mungkin sudah dihapus), tampilkan pesan khusus
                        cout << left << setw(10) << daftarPelanggan[a].pesanan[i]
                             << setw(25) << "[Menu Tidak Ditemukan]"
                             << setw(10) << daftarPelanggan[a].jumlahMenu[i]
                             << setw(15) << "N/A"
                             << right << setw(15) << "N/A" << endl;
                    }
                }
            }

            // Garis pemisah bawah rincian pesanan
            cout << setfill('-') << setw(80) << "" << setfill(' ') << "\n";

            // Tampilkan total harga seluruh pesanan pelanggan
            cout << left << setw(65) << "TOTAL HARGA:" << right << setw(15) << daftarPelanggan[a].totalHarga << "\n";

            // Garis pemisah akhir untuk pelanggan
            cout << setw(80) << setfill('=') << "" << "\n";
            cout << "\n\n"; // Jeda spasi antar pelanggan
        }
    }
    system("pause"); // Tunggu input pengguna agar bisa membaca hasil sebelum lanjut
}

void simpanMenu() {
    using namespace std;

    // Membuka file "menu.txt" dengan mode output (menulis) dan truncate (menghapus isi file lama)
    ofstream file("menu2.txt", ios::out | ios::trunc);

    // Cek apakah file berhasil dibuka untuk menulis
    if (!file.is_open()) {
        cerr << "Error: Tidak dapat membuka file menu.txt untuk penyimpanan.\n";
        return; // Jika gagal membuka file, keluar dari fungsi
    }

    // Menulis header kolom ke file untuk memudahkan pembacaan file
    // Menggunakan manipulasi format setw untuk mengatur lebar kolom dan left agar rata kiri
    file << left
         << setw(5) << "ID"
         << setw(30) << "NAMA_MENU"
         << setw(15) << "JENIS"
         << setw(15) << "HARGA"
         << endl;

    // Menulis garis pemisah berupa karakter '-' dengan lebar kolom yang sama seperti header
    file << setfill('-') << setw(5) << ""
         << setw(30) << ""
         << setw(15) << ""
         << setw(15) << ""
         << setfill(' ') << endl;  // Reset karakter pengisi kembali ke spasi

    // Loop untuk menulis data setiap menu ke file dengan format yang sudah ditentukan
    for (int i = 0; i < jumlahMenu; ++i) {
        file << left
             << setw(5) << daftarMenu[i].idMenu           // ID menu
             << setw(30) << daftarMenu[i].namaMenu        // Nama menu
             << setw(15) << daftarMenu[i].jenisMenu       // Jenis menu (misal: Makanan/Minuman)
             << setw(15) << daftarMenu[i].harga           // Harga menu
             << endl;  // Pindah baris untuk data menu berikutnya
    }

    // Menutup file setelah selesai menulis agar data tersimpan dengan baik
    file.close();

    // Informasi bahwa proses penyimpanan berhasil
    cout << "Daftar menu berhasil disimpan ke menu.txt\n";
}

void bacaMenu() {
    // Membuka file "menu.txt" untuk membaca data menu
    ifstream file("menu2.txt");

    // Cek apakah file berhasil dibuka
    if (!file.is_open()) {
        cerr << "Error: Tidak dapat membuka file menu.txt\n";
        return;  // Jika gagal, keluar dari fungsi
    }

    string line;
    // Reset jumlahMenu ke 3 (seharusnya 0 jika ingin mulai dari awal, 
    // mungkin ini bagian bug atau kode sementara)
    jumlahMenu = 3;

    // Baca file baris per baris
    while (getline(file, line)) {
        // Cek kapasitas maksimal array menu (misal maksimal 100)
        if (jumlahMenu >= 100) {
            cout << "Kapasitas array menu penuh saat membaca dari file. Beberapa data mungkin tidak terbaca.\n";
            break; // Berhenti membaca jika sudah penuh
        }

        // Cari posisi koma yang memisahkan data (format diasumsikan CSV: id,nama,jenis,harga)
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1); // posisi koma ketiga untuk harga

        // Validasi format baris agar sesuai dengan format CSV yang diharapkan
        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) {
            cerr << "Peringatan: Baris tidak valid di menu.txt (format 'id,nama,jenis,harga'): " << line << endl;
            continue;  // Lewati baris jika format tidak sesuai
        }

        try {
            // Parsing dan mengisi data ke array daftarMenu
            daftarMenu[jumlahMenu].idMenu = stoi(line.substr(0, pos1)); // Ambil ID (int)
            daftarMenu[jumlahMenu].namaMenu = line.substr(pos1 + 1, pos2 - (pos1 + 1)); // Ambil nama (string)

            // Asumsi jenisMenu bertipe int (contoh: kategori menu)
            daftarMenu[jumlahMenu].jenisMenu = stoi(line.substr(pos2 + 1, pos3 - (pos2 + 1)));

            // Harga juga bertipe int, ambil substring setelah koma ketiga
            daftarMenu[jumlahMenu].harga = stoi(line.substr(pos3 + 1));

            // Increment jumlahMenu untuk data yang sudah dibaca
            jumlahMenu++;

        } catch (const exception& e) {
            // Tangani error saat konversi string ke int (misalnya data tidak valid)
            cerr << "Kesalahan saat mengurai baris di menu.txt: '" << line << "' (" << e.what() << ")" << endl;
            // Bisa memilih untuk break jika error terlalu fatal
        }
    }

    // Tutup file setelah selesai membaca
    file.close();
}

void simpanpelanggan() {
    // Membuka file "pelanggan.txt" dalam mode tulis (menimpa isi file lama)
    ofstream file("pelanggan2.txt");

    // Cek apakah file berhasil dibuka
    if (!file) {
        cout << "Gagal membuka file pelanggan.txt untuk penyimpanan." << endl;
        return;  // Jika gagal membuka file, keluar dari fungsi
    }

    // Loop untuk menulis semua data pelanggan ke file
    for (int i = 0; i < jumlahPelanggan; i++) {
        // Menulis data pelanggan ke file dengan format CSV (dipisah koma)
        // Format: idPelanggan,namaPelanggan,totalHarga
        file << daftarPelanggan[i].idPelanggan << ","
             << daftarPelanggan[i].namaPelanggan << ","
             << daftarPelanggan[i].totalHarga;
        file << endl;  // Pindah baris setelah setiap data pelanggan
    }

    // Tutup file setelah selesai menulis
    file.close();
}

void bacapelanggan(){
    // Membuka file "pelanggan.txt" untuk membaca data pelanggan
    ifstream file("pelanggan2.txt");

    // Jika file gagal dibuka (misal file tidak ada), langsung keluar fungsi
    if (!file)
    {
        return;
    }

    string line;
    jumlahPelanggan = 0; // Reset jumlah pelanggan sebelum mulai membaca data baru

    // Membaca file baris per baris
    while (getline(file, line))
    {
        // Jika kapasitas array pelanggan sudah penuh (misal max 100),
        // berhenti membaca dan beri peringatan
        if (jumlahPelanggan >= 100) {
            cout << "Kapasitas array pelanggan penuh saat membaca dari file. Beberapa data mungkin tidak terbaca.\n";
            break;
        }

        // Cari posisi koma pertama dan kedua sebagai pemisah data CSV
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);

        // Validasi apakah format baris benar (minimal ada 2 koma)
        if (pos1 == string::npos || pos2 == string::npos)
        {
            cerr << "Peringatan: Baris tidak valid di pelanggan.txt: " << line << endl;
            continue; // Lewati baris ini jika format salah
        }

        try
        {
            // Parsing dan mengisi data pelanggan dari substring berdasarkan posisi koma
            daftarPelanggan[jumlahPelanggan].idPelanggan = stoi(line.substr(0, pos1)); // ID pelanggan (int)
            daftarPelanggan[jumlahPelanggan].namaPelanggan = line.substr(pos1 + 1, pos2 - (pos1 + 1)); // Nama pelanggan (string)
            daftarPelanggan[jumlahPelanggan].totalHarga = stoi(line.substr(pos2 + 1)); // Total harga (int)

            // Set jumlahPesanan ke 0 karena file tidak menyimpan detail pesanan
            daftarPelanggan[jumlahPelanggan].jumlahPesanan = 0;

            // Increment jumlah pelanggan yang sudah dibaca
            jumlahPelanggan++;
        }
        catch (const std::exception& e)
        {
            // Jika terjadi error saat parsing angka (stoi), tampilkan pesan error
            cerr << "Kesalahan saat mengurai baris di pelanggan.txt: " << line << " (" << e.what() << ")" << endl;
        }
    }

    // Tutup file setelah selesai membaca
    file.close();
}

void menuEditMenu() {
    system("cls"); // Membersihkan layar console agar tampilan rapi

    // Judul menu edit
    cout << "=======================================\n";
    cout << "           EDIT DATA MENU\n";
    cout << "=======================================\n\n";

    // Cek apakah ada menu yang bisa diedit
    if (jumlahMenu == 0) {
        cout << "Belum ada menu yang tersedia untuk diedit.\n";
        cout << "Tekan tombol apapun untuk kembali...";
        system("pause > nul"); // Pause tanpa menampilkan pesan "Press any key..."
        return; // Keluar dari fungsi jika tidak ada data menu
    }

    // Menampilkan daftar menu yang tersedia dengan format tabel
    cout << "--- Daftar Menu Tersedia ---\n";
    cout << setfill(' ') << left; // Atur spasi dan rata kiri untuk tampilan tabel
    cout << setw(5) << "ID"
         << setw(25) << "Nama Menu"
         << setw(15) << "Jenis"
         << right << setw(12) << "Harga (Rp)" << endl; // Header kolom harga di rata kanan
    cout << setfill('-') << setw(5) << ""
         << setw(25) << ""
         << setw(15) << ""
         << setw(12) << "" << endl; // Garis pemisah header
    cout << setfill(' '); // Reset fill karakter kembali ke spasi

    // Loop menampilkan data menu satu per satu
    for (int i = 0; i < jumlahMenu; i++) {
        cout << left << setw(5) << daftarMenu[i].idMenu
             << setw(25) << daftarMenu[i].namaMenu
             << setw(15) << daftarMenu[i].jenisMenu
             << right << setw(12) << fixed << setprecision(2) << daftarMenu[i].harga << endl; // Harga 2 desimal
    }
    cout << setfill('-') << setw(57) << "" << setfill(' ') << endl; // Garis pemisah akhir tabel
    cout << "\n";

    // Minta user memasukkan ID menu yang ingin diedit, dengan validasi input
    int idToEdit;
    cout << "Masukkan ID menu yang ingin diedit: ";
    while (!(cin >> idToEdit)) { // Loop jika input bukan angka
        cout << "Input tidak valid. Harap masukkan angka untuk ID menu: ";
        cin.clear(); // Bersihkan flag error pada cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buang input yang salah
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan sisa input di buffer

    // Cari menu dengan ID yang diminta menggunakan pointer
    menu* menuToEdit = nullptr; // Pointer untuk menampung alamat menu yang ditemukan
    for (int i = 0; i < jumlahMenu; i++) {
        if (daftarMenu[i].idMenu == idToEdit) {
            menuToEdit = &daftarMenu[i]; // Simpan alamat menu yang cocok
            break; // Stop loop jika sudah ditemukan
        }
    }

    // Jika menu tidak ditemukan, tampilkan pesan error dan keluar fungsi
    if (menuToEdit == nullptr) {
        cout << "\n---------------------------------------\n";
        cout << "ID menu " << idToEdit << " tidak ditemukan.\n";
        cout << "---------------------------------------\n";
        cout << "Tekan tombol apapun untuk kembali...";
        system("pause > nul");
        return;
    }

    // Tampilkan data menu saat ini sebagai referensi sebelum edit
    cout << "\n--- Detail Menu Saat Ini ---\n";
    cout << left << setw(15) << "ID Menu"     << ": " << menuToEdit->idMenu << endl;
    cout << left << setw(15) << "Jenis Menu"  << ": " << menuToEdit->jenisMenu << endl;
    cout << left << setw(15) << "Nama Menu"   << ": " << menuToEdit->namaMenu << endl;
    cout << left << setw(15) << "Harga"       << ": Rp " << fixed << setprecision(2) << menuToEdit->harga << endl;
    cout << "------------------------------\n\n";

    // Input data baru dari user
    string newJenis, newNama;
    double newHargaDouble;

    cout << "Masukkan Jenis Menu Baru (biarkan kosong jika tidak ingin mengubah): ";
    getline(cin, newJenis);
    if (!newJenis.empty()) { // Jika input tidak kosong, update jenis menu
        menuToEdit->jenisMenu = newJenis;
        cout << "Jenis menu berhasil diubah.\n";
    }

    cout << "Masukkan Nama Menu Baru (biarkan kosong jika tidak ingin mengubah): ";
    getline(cin, newNama);
    if (!newNama.empty()) { // Jika input tidak kosong, update nama menu
        menuToEdit->namaMenu = newNama;
        cout << "Nama menu berhasil diubah.\n";
    }

    // Input harga baru, dengan validasi input angka >= 0
    cout << "Masukkan Harga Menu Baru (masukkan 0 untuk tidak mengubah): Rp ";
    while (!(cin >> newHargaDouble) || newHargaDouble < 0) {
        cout << "Input harga tidak valid. Harap masukkan angka positif atau 0: Rp ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer input

    if (newHargaDouble != 0) { // Jika harga bukan 0, update harga menu
        menuToEdit->harga = newHargaDouble;
        cout << "Harga menu berhasil diubah.\n";
    } else {
        cout << "Harga menu tidak diubah.\n";
    }

    // Pesan konfirmasi bahwa edit berhasil
    cout << "\n=======================================\n";
    cout << "        Menu berhasil diedit!\n";
    cout << "=======================================\n";

    // Simpan perubahan ke file (jika ada fungsi simpanMenu)
    // simpanMenu();

    cout << "Tekan tombol apapun untuk melanjutkan...";
    system("pause > nul"); // Pause modern tanpa output pesan
}

void menuEditPelanggan() {
    system("cls"); // Bersihkan layar console agar tampilan menu rapi dan tidak berantakan

    // Menampilkan header menu edit pelanggan
    cout << "=======================================\n";
    cout << "         EDIT DATA PELANGGAN\n";
    cout << "=======================================\n\n";

    // Cek apakah ada data pelanggan yang tersedia untuk diedit
    if (jumlahPelanggan == 0) {
        cout << "Belum ada pelanggan yang tersedia untuk diedit.\n";
        cout << "Tekan tombol apapun untuk kembali...";
        system("pause > nul"); // Pause tanpa menampilkan pesan default
        return; // Kembali ke menu utama jika tidak ada data pelanggan
    }

    // Menampilkan daftar pelanggan yang tersedia dengan format rapih
    cout << "--- Daftar Pelanggan Tersedia ---\n";
    cout << left << setw(5) << "ID"
              << setw(30) << "Nama Pelanggan" << "\n";
    cout << string(35, '-') << "\n"; // Garis pemisah horizontal
    for (int i = 0; i < jumlahPelanggan; i++) {
        cout << left << setw(5) << daftarPelanggan[i].idPelanggan
                  << setw(30) << daftarPelanggan[i].namaPelanggan << "\n";
    }
    cout << string(35, '-') << "\n\n";

    // Minta input ID pelanggan yang ingin diedit, dengan validasi input
    int idToEdit;
    cout << "Masukkan ID pelanggan yang ingin diedit: ";
    while (!(cin >> idToEdit)) { // Validasi input: harus angka
        cout << "Input tidak valid. Mohon masukkan angka untuk ID pelanggan: ";
        cin.clear(); // Reset error flags pada cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buang input yang salah
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer sebelum getline

    // Cari pelanggan berdasarkan ID menggunakan pointer untuk memudahkan modifikasi
    pelanggan* pelangganToEdit = nullptr; // Pointer inisialisasi null
    for (int i = 0; i < jumlahPelanggan; i++) {
        if (daftarPelanggan[i].idPelanggan == idToEdit) {
            pelangganToEdit = &daftarPelanggan[i]; // Simpan alamat pelanggan yang ditemukan
            break; // Keluar dari loop jika ditemukan
        }
    }

    // Jika pelanggan dengan ID yang diminta tidak ditemukan
    if (pelangganToEdit == nullptr) {
        cout << "\n---------------------------------------\n";
        cout << "ID pelanggan " << idToEdit << " tidak ditemukan.\n";
        cout << "---------------------------------------\n";
        cout << "Tekan tombol apapun untuk kembali...";
        system("pause > nul");
        return;
    }

    // Tampilkan data pelanggan saat ini sebelum diedit
    cout << "\n--- Data Pelanggan Saat Ini ---\n";
    cout << left << setw(15) << "ID Pelanggan" << ": " << pelangganToEdit->idPelanggan << "\n";
    cout << left << setw(15) << "Nama Pelanggan" << ": " << pelangganToEdit->namaPelanggan << "\n";
    cout << "-------------------------------\n";

    // Meminta input nama pelanggan baru, biarkan kosong jika tidak ingin mengubah
    string newNamaPelanggan;
    cout << "\nMasukkan Nama Pelanggan Baru (biarkan kosong jika tidak ingin mengubah): ";
    getline(cin, newNamaPelanggan);
    if (!newNamaPelanggan.empty()) { // Jika input tidak kosong, update nama pelanggan
        pelangganToEdit->namaPelanggan = newNamaPelanggan;
        cout << "Nama pelanggan berhasil diubah menjadi: " << pelangganToEdit->namaPelanggan << ".\n";
    }

    // Tanya apakah ingin mengedit detail pesanan pelanggan
    char pilihanEditPesanan;
    cout << "\nApakah Anda ingin mengedit detail pesanan pelanggan ini? (y/n): ";
    cin >> pilihanEditPesanan;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer

    if (pilihanEditPesanan == 'y' || pilihanEditPesanan == 'Y') {
        system("cls"); // Bersihkan layar sebelum mulai edit pesanan
        cout << "=======================================\n";
        cout << "         EDIT DETAIL PESANAN\n";
        cout << "=======================================\n\n";

        // Menampilkan daftar menu yang tersedia sebagai referensi
        cout << "--- Daftar Menu Tersedia ---\n";
        cout << setfill(' ') << left;
        cout << setw(5) << "ID"
                  << setw(25) << "Nama Menu"
                  << setw(15) << "Jenis"
                  << right << setw(12) << "Harga (Rp)" << "\n";
        cout << string(57, '-') << "\n";
        cout << setfill(' ');
        for (int i = 0; i < jumlahMenu; ++i) {
            cout << left << setw(5) << daftarMenu[i].idMenu
                      << setw(25) << daftarMenu[i].namaMenu
                      << setw(15) << daftarMenu[i].jenisMenu
                      << right << setw(12) << fixed << setprecision(2) << daftarMenu[i].harga << "\n";
        }
        cout << string(57, '-') << "\n\n";

        // Loop utama untuk mengelola pesanan: tambah, hapus, ubah jumlah, atau selesai
        char tambahHapus;
        while (true) {
            // Tampilkan detail pesanan saat ini untuk pelanggan
            cout << "--- Detail Pesanan Saat Ini Untuk " << pelangganToEdit->namaPelanggan << " ---\n";
            if (pelangganToEdit->jumlahPesanan == 0) {
                cout << "Belum ada pesanan untuk pelanggan ini.\n";
            } else {
                cout << left << setw(10) << "ID Menu"
                          << setw(25) << "Nama Menu"
                          << setw(10) << "Jumlah" << "\n";
                cout << string(45, '-') << "\n";
                cout << setfill(' ');
                for (int i = 0; i < pelangganToEdit->jumlahPesanan; ++i) {
                    string namaMenuItem = "Menu Tidak Ditemukan";
                    // Cari nama menu berdasarkan ID menu pada pesanan
                    for (int j = 0; j < jumlahMenu; ++j) {
                        if (daftarMenu[j].idMenu == pelangganToEdit->pesanan[i]) {
                            namaMenuItem = daftarMenu[j].namaMenu;
                            break;
                        }
                    }
                    cout << left << setw(10) << pelangganToEdit->pesanan[i]
                              << setw(25) << namaMenuItem
                              << setw(10) << pelangganToEdit->jumlahMenu[i] << "\n";
                }
            }
            cout << string(45, '-') << "\n";

            // Minta input aksi dari user: tambah (t), hapus (h), ubah (u), atau selesai (s)
            cout << "\nPilih aksi (t: tambah, h: hapus, u: ubah jumlah, s: selesai): ";
            cin >> tambahHapus;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (tambahHapus == 's' || tambahHapus == 'S') {
                cout << "\nKeluar dari mode edit pesanan.\n";
                break; // Keluar dari loop edit pesanan
            }

            // Input ID menu yang akan diedit (tambah/hapus/ubah)
            int idMenuAction;
            cout << "Masukkan ID Menu yang akan di " << (tambahHapus == 't' || tambahHapus == 'T' ? "tambah" : (tambahHapus == 'h' || tambahHapus == 'H' ? "hapus" : "ubah")) << ": ";
            while (!(cin >> idMenuAction)) {
                cout << "Input tidak valid. Mohon masukkan angka untuk ID Menu: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Validasi apakah ID menu tersebut ada di daftar menu
            int menuIndex = -1;
            for (int i = 0; i < jumlahMenu; ++i) {
                if (daftarMenu[i].idMenu == idMenuAction) {
                    menuIndex = i;
                    break;
                }
            }

            if (menuIndex == -1) {
                cout << "--> ID Menu tidak valid atau tidak ditemukan dalam daftar menu. Silakan coba lagi.\n";
                continue; // Kembali ke awal loop aksi
            }

            // Proses aksi tambah pesanan
            if (tambahHapus == 't' || tambahHapus == 'T') {
                int jumlah;
                cout << "Masukkan jumlah yang akan ditambahkan: ";
                while (!(cin >> jumlah) || jumlah <= 0) {
                    cout << "Jumlah tidak valid (harus angka positif). Penambahan dibatalkan.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                // Cek apakah menu sudah ada di pesanan, jika ya update jumlah
                bool foundInPesanan = false;
                for (int i = 0; i < pelangganToEdit->jumlahPesanan; ++i) {
                    if (pelangganToEdit->pesanan[i] == idMenuAction) {
                        pelangganToEdit->jumlahMenu[i] += jumlah;
                        foundInPesanan = true;
                        cout << "--> Jumlah pesanan untuk menu '" << daftarMenu[menuIndex].namaMenu << "' berhasil diperbarui.\n";
                        break;
                    }
                }
                // Jika belum ada, tambahkan menu baru ke pesanan pelanggan
                if (!foundInPesanan) {
                    if (pelangganToEdit->jumlahPesanan < 100) { // Batasi kapasitas pesanan
                        pelangganToEdit->pesanan[pelangganToEdit->jumlahPesanan] = idMenuAction;
                        pelangganToEdit->jumlahMenu[pelangganToEdit->jumlahPesanan] = jumlah;
                        pelangganToEdit->jumlahPesanan++;
                        cout << "--> Menu '" << daftarMenu[menuIndex].namaMenu << "' berhasil ditambahkan ke pesanan baru.\n";
                    } else {
                        cout << "--> Kapasitas pesanan pelanggan penuh. Tidak dapat menambahkan menu baru.\n";
                    }
                }
            }
            // Proses hapus menu dari pesanan
            else if (tambahHapus == 'h' || tambahHapus == 'H') {
                int itemIndexToRemove = -1;
                for (int i = 0; i < pelangganToEdit->jumlahPesanan; ++i) {
                    if (pelangganToEdit->pesanan[i] == idMenuAction) {
                        itemIndexToRemove = i;
                        break;
                    }
                }
                if (itemIndexToRemove != -1) {
                    // Geser elemen array ke kiri untuk menghapus item
                    for (int i = itemIndexToRemove; i < pelangganToEdit->jumlahPesanan - 1; ++i) {
                        pelangganToEdit->pesanan[i] = pelangganToEdit->pesanan[i+1];
                        pelangganToEdit->jumlahMenu[i] = pelangganToEdit->jumlahMenu[i+1];
                    }
                    pelangganToEdit->jumlahPesanan--; // Kurangi jumlah item pesanan
                    cout << "--> Menu '" << daftarMenu[menuIndex].namaMenu << "' berhasil dihapus dari pesanan.\n";
                } else {
                    cout << "--> Menu ini tidak ditemukan dalam pesanan pelanggan.\n";
                }
            }
            // Proses ubah jumlah menu dalam pesanan
            else if (tambahHapus == 'u' || tambahHapus == 'U') {
                int newJumlah;
                cout << "Masukkan jumlah baru untuk menu ini (0 untuk menghapus menu dari pesanan): ";
                while (!(cin >> newJumlah) || newJumlah < 0) {
                    cout << "Jumlah tidak valid (harus angka positif atau 0). Pengubahan dibatalkan.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                bool foundInPesanan = false;
                for (int i = 0; i < pelangganToEdit->jumlahPesanan; ++i) {
                    if (pelangganToEdit->pesanan[i] == idMenuAction) {
                        if (newJumlah == 0) {
                            // Jika jumlah 0, hapus item dari pesanan
                            for (int j = i; j < pelangganToEdit->jumlahPesanan - 1; ++j) {
                                pelangganToEdit->pesanan[j] = pelangganToEdit->pesanan[j+1];
                                pelangganToEdit->jumlahMenu[j] = pelangganToEdit->jumlahMenu[j+1];
                            }
                            pelangganToEdit->jumlahPesanan--;
                            cout << "--> Menu '" << daftarMenu[menuIndex].namaMenu << "' dihapus dari pesanan karena jumlah 0.\n";
                        } else {
                            // Update jumlah pesanan
                            pelangganToEdit->jumlahMenu[i] = newJumlah;
                            cout << "--> Jumlah pesanan untuk menu '" << daftarMenu[menuIndex].namaMenu << "' diubah menjadi " << newJumlah << ".\n";
                        }
                        foundInPesanan = true;
                        break;
                    }
                }
                if (!foundInPesanan) {
                    cout << "--> Menu ini tidak ditemukan dalam pesanan pelanggan. Gunakan opsi tambah untuk menambah menu.\n";
                }
            } else {
                cout << "--> Aksi tidak dikenali. Silakan coba lagi.\n";
            }
        } // End while edit pesanan
    } // End if edit pesanan

    cout << "\nData pelanggan berhasil diperbarui.\n";
    cout << "Tekan tombol apapun untuk kembali ke menu utama...";
    system("pause > nul");
}
