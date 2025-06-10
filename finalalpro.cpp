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
#include <windows.h>  
// Untuk mengatur warna

using namespace std;
//1. STRUCT
// Struktur untuk Akun & Menu

struct Akun {
    string username;
    string password;
};

struct Menu
{
    string namaMenu, jenisMenu;
    int idMenu;
    int harga;
};

// Struktur untuk pelanggan
struct Pelanggan
{
    string namaPelanggan;
    int idPelanggan;
    int jumlahPesanan;
    int pesanan[100];      // menyimpan ID menu dipesan
    int jumlahMenu[100];   // menyimpan jumlah dari tiap menu dipesan
    int totalHarga;        // total harga pesanan pelanggan
};

//2.ARRAY
Menu daftarMenu[100];
Pelanggan daftarPelanggan[100];
int jumlahMenu = 0; // inisiasi menu awal (bawaan)
int jumlahPelanggan = 0;

void tampilanAwal();
// Deklarasi fungsi setWarna
void setWarna(int warna);
void signUp();
bool login();
void menuUtama();
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
void hitungTotalHarga(Pelanggan &p);  
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
void quickhargamenu(Menu arr[], int low, int high, bool ascending);  
// Mengurutkan harga menu menggunakan algoritma Quick Sort dengan arah pengurutan sesuai parameter (ascending/descending).
void sortingharga(bool ascending);  
// Mengatur metode pengurutan harga, bisa memanggil bubble sort atau quick sort tergantung kebutuhan.
void bubbleIdMenu(bool ascending);
void quickIdMenu(Menu arr[], int low, int high, bool ascending);
void insertionIdMenu(bool ascending) ;
void bubbleNamaMenu(bool ascending);
void quickNamaMenu(Menu arr[], int low, int high, bool ascending);
void insertionNamaMenu(bool ascending);
void bubblehargamenu(bool ascending);
void quickhargamenu(Menu arr[], int low, int high, bool ascending);
void insertionhargamenu(bool ascending);

void menuEditMenu();  
// Menampilkan atau mengatur proses untuk mengedit data menu yang sudah ada.
void menuEditPelanggan();  
// Menampilkan atau mengatur proses untuk mengedit data pelanggan yang sudah ada.


// Fungsi utama
int main() {
    int pilihanLogin;
    bool akses = false;
 //   bool = tipe data boolean, hanya memiliki dua nilai: true atau false.
 //	  akses =  nama variabel, dalam konteks ini digunakan untuk menyimpan status apakah user sudah berhasil login atau belum.
 //	  = false = berarti user belum login saat program pertama kali dijalankan.

    do {
        tampilanAwal();
        cin >> pilihanLogin;

        switch (pilihanLogin) {
            case 1:
				system("cls");
                signUp();
                // Menampilkan menu login/signup
                break;
            case 2:
				system("cls");
                akses = login();
                // login() akan mengembalikan true jika berhasil, false jika gagal
                break;
            case 3:
				
                setWarna(9);
                cout << "Terima kasih telah menggunakan BIZ RESTO!\n";
                setWarna(7);
                return 0;
            default:
				
                setWarna(12);
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                setWarna(7);
        }

        if (!akses) {
            system("pause");
        }

    } while (!akses);
	  // Ulangi jika akses masih false

	// Hanya dijalankan jika akses = true
    menuUtama();
    return 0;
}

// Fungsi untuk mengatur warna teks
void setWarna(int warna) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), warna);
 //   Fungsi dari Windows API untuk mengatur warna teks di console.
 //   Mengambil handle (pengontrol) ke layar console (output standar).
}

// Fungsi untuk menampilkan tampilan awal dengan warna
void tampilanAwal() {
    system("cls");

    int lebar = 50;

    // Fungsi bantu cetak teks rata tengah
    auto cetakTengah = [&](const std::string& teks) {
        int spasi = (lebar - (int)teks.length()) / 2;
        cout << string(spasi, ' ') << teks << endl;
    };

    // Header kuning
    setWarna(14);
    cout << setfill('=') << setw(lebar) << "=" << endl;
    cetakTengah("BIZ RESTO SYSTEM");
    cout << setfill('=') << setw(lebar) << "=" << endl;

    // Teks putih rata tengah
    setWarna(7);
    cetakTengah("Selamat Datang di Aplikasi Kasir BIZ RESTO");
    cetakTengah("Silakan pilih opsi untuk melanjutkan");

    cout << setfill('-') << setw(lebar) << "-" << endl;
	cout << setfill(' ') << left;
    // Opsi hijau rata kiri dengan border
    setWarna(10);
    cout << "| " << setw(3) << left << "1" << " | " << setw(40) << left << "Sign Up (Daftar Akun Baru)" << "|\n";
    cout << "| " << setw(3) << left << "2" << " | " << setw(40) << left << "Login (Masuk Akun)" << "|\n";
    cout << "| " << setw(3) << left << "3" << " | " << setw(40) << left << "Exit (Keluar dari Program)" << "|\n";

    setWarna(7);
    cout << setfill('-') << setw(lebar) << "-" << endl;

    cout << "Masukkan Pilihan Anda (1-3): ";
}

void menuUtama() {
    bacaMenu();
    bacapelanggan();

    int pilihan;
    char ulang;

    do {
        system("cls");

        // Garis atas
        cout << setfill('-') << setw(42) << "" << endl;
        cout << setfill(' ');  // reset fill ke spasi

        cout << "======== PROGRAM KASIR BIZ RESTO ========\n";

        // Garis bawah header
        cout << setfill('-') << setw(42) << "" << endl;
        cout << setfill(' ');

        cout << setw(30) << right << "<<<<<<< Menu Utama >>>>>>>" << endl;

        cout << setfill('-') << setw(32) << "" << endl;
        cout << setfill(' ');

        cout << "|1. About\t\t\t|\n";
        cout << "|2. Tambah Data Menu\t\t|\n";
        cout << "|3. Tambah Data Pelanggan\t|\n";
        cout << "|4. Melihat Data Menu\t\t|\n";
        cout << "|5. Melihat Data Pelanggan\t|\n";
        cout << "|6. Hapus Daftar Menu\t\t|\n";
        cout << "|7. Hapus Daftar Pelanggan\t|\n";
        cout << "|8. Cari Pelanggan\t\t|\n";
        cout << "|9. Cari Menu\t\t\t|\n";
        cout << "|10. Edit Menu\t\t\t|\n"; 
        cout << "|11. Edit Pelanggan\t\t|\n"; 
        cout << "|12. Exit\t\t\t|\n";

        cout << setfill('-') << setw(32) << "" << endl;
        cout << setfill(' ');

        cout << "Isikan Pilihan Menu: ";
        cin >> pilihan;

        system("cls");

        switch(pilihan) {
            case 1: about(); break;
            case 2: tambahDataMenu(); break;
            case 3: tambahDataPelanggan(); break;
            case 4: melihatDataMenu(); break;
            case 5: melihatDataPelanggan(); break;
            case 6: hapusdatamenu(); break;
            case 7: hapusDataPelanggan(); break;
            case 8: cariPelanggan(); break;
            case 9: carimenu(); break;
            case 10: menuEditMenu(); break;
            case 11: menuEditPelanggan(); break;
            case 12: 
                cout << "\t===PROGRAM SELESAI===\n";
                simpanpelanggan();
                return;
            default:
                cout << "==MOHON MAAF, PILIHAN ANDA TIDAK TERSEDIA==\n";
        }

        cout << "Apakah ingin mengulang program (y/n)?: ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    simpanMenu();
    simpanpelanggan();
}

void signUp() {
    Akun akunBaru;
    ofstream file("akun.txt", ios::app); 

    cout << "=== SIGN UP ===\n";
    cout << "Masukkan Username: ";
    cin >> akunBaru.username;
    cout << "Masukkan Password: ";
    cin >> akunBaru.password;

    file << akunBaru.username << " " << akunBaru.password << endl;
    // menulis data ke dalam file, dengan format tertentu
    file.close();

    cout << "Pendaftaran berhasil! Silakan login.\n";
}

bool login()
// untuk memberikan jawaban benar/salah atau sukses/gagal setelah proses login.
// Ini adalah bentuk yang paling sederhana dan efisien untuk menyatakan dua kemungkinan hasil dari proses login. 
{
    string inputUsername, inputPassword;
    int percobaan = 0;
    bool berhasilLogin = false;

    while (percobaan < 3) {
		
        cout << "\n=== LOGIN ===\n";
        cout << "Username: ";
        cin >> inputUsername;
        cout << "Password: ";
        cin >> inputPassword;

        ifstream file("akun.txt");
        
        string user, pass;
        //variabel untuk di file
        while (file >> user >> pass) 
    //  Ini adalah loop yang membaca file baris demi baris.
	//	Baca dua kata dari file:
	//	Kata pertama dimasukkan ke variabel user.
	//	Kata kedua dimasukkan ke variabel pass.
	//	contoh : Iterasi ke-1: user = "admin", pass = "12345"
	//	Iterasi ke-2: user = "user1", pass = "password1"
        {
            if (user == inputUsername && pass == inputPassword) 
            {
                berhasilLogin = true;
                break;
               // File dibaca baris per baris.
			   // Jika user dan pass dari file sama persis dengan yang dimasukkan, maka berhasilLogin = true dan keluar dari loop.
            }
        }

        file.close();

        if (berhasilLogin) {
            cout << "Login berhasil! Selamat datang, " << inputUsername << "!\n";
            return true;
        } else {
            cout << "Login gagal. Username atau password salah.\n";
            percobaan++;
           
        }
        
    }

    cout << "\nAnda telah gagal login sebanyak 3 kali. Program akan keluar.\n";
    return false;

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

//3.REKURSIF
int hitungharga(Pelanggan &p, int index = 0) {
    if (index == p.jumlahPesanan) return 0;

    int idMenuIndex = p.pesanan[index] - 1;
    if (idMenuIndex >= 0 && idMenuIndex < jumlahMenu) {
        return daftarMenu[idMenuIndex].harga * p.jumlahMenu[index] +
               hitungharga(p, index + 1);
               //ciri khas rekursif(memanggil dirinya sendiri)
    } else {
        return hitungharga(p, index + 1);
        //ciri khas rekursif
    }
}

void hitungTotalHarga(Pelanggan &p){
    p.totalHarga = hitungharga(p);

}

void hapusdatamenu() {
    system("cls");

    cout << "=======================================\n";
    cout << "           HAPUS DATA MENU\n";
    cout << "=======================================\n\n";

    if (jumlahMenu == 0) {
        cout << "Belum ada menu yang tersedia untuk dihapus.\n";
        cout << "Tekan tombol apapun untuk kembali...";
        system("pause > nul");
        return;
    }

    vector<Menu> makananMenu;
    vector<Menu> minumanMenu;

    for (int i = 0; i < jumlahMenu; ++i) {
        if (daftarMenu[i].jenisMenu == "Makanan") {
            makananMenu.push_back(daftarMenu[i]);
        } else if (daftarMenu[i].jenisMenu == "Minuman") {
            minumanMenu.push_back(daftarMenu[i]);
        }
    }

    // Tampilkan Makanan
    cout << "--- MAKANAN ---\n";
    if (makananMenu.empty()) {
        cout << "Tidak ada menu makanan yang tersedia saat ini.\n\n";
    } else {
        cout << setfill(' ') << left;
        cout << setw(5) << "ID" << setw(25) << "Nama Menu" << setw(15) << "Jenis"
             << right << setw(12) << "Harga (Rp)" << "\n";
        cout << setfill('-') << string(57, '-') << "\n";
        cout << setfill(' ');
        for (const auto& item : makananMenu) 
		// auto& item artinya:
		// auto = biarkan komputer yang menebak tipe data Menu.
		// & = referensi, artinya kita tidak membuat salinan baru dari item, tapi pakai data asli supaya cepat.
		// const = artinya kita hanya membaca data, tidak mengubahnya.
        {
            cout << left << setw(5) << item.idMenu << setw(25) << item.namaMenu
                 << setw(15) << item.jenisMenu << right << setw(12)
                 << fixed << setprecision(2) << item.harga << "\n";
                            // Menampilkan harga dengan format angka desimal, 2 digit di belakang koma
        }
        cout << setfill('-') << string(57, '-') << "\n\n";
        cout << setfill(' ');
    }

    // Tampilkan Minuman
    cout << "--- MINUMAN ---\n";
    if (minumanMenu.empty()) {
        cout << "Tidak ada menu minuman yang tersedia saat ini.\n\n";
    } else {
        cout << setfill(' ') << left;
        cout << setw(5) << "ID" << setw(25) << "Nama Menu" << setw(15) << "Jenis"
             << right << setw(12) << "Harga (Rp)" << "\n";
        cout << setfill('-') << string(57, '-') << "\n";
        cout << setfill(' ');
        for (const auto& item : minumanMenu) {
            cout << left << setw(5) << item.idMenu << setw(25) << item.namaMenu
                 << setw(15) << item.jenisMenu << right << setw(12)
                 << fixed << setprecision(2) << item.harga << "\n";
        }
        cout << setfill('-') << string(57, '-') << "\n";
    }

    // Input ID menu
    int idToDelete;
    cout << "\nMasukkan ID menu yang ingin dihapus: ";
    while (!(cin >> idToDelete)) {
        cout << "Input tidak valid. Mohon masukkan angka untuk ID menu: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int index = -1;
    for (int i = 0; i < jumlahMenu; i++) {
        if (daftarMenu[i].idMenu == idToDelete) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "\n---------------------------------------\n";
        cout << "ID menu " << idToDelete << " tidak ditemukan.\n";
        cout << "---------------------------------------\n";
        cout << "Tekan tombol apapun untuk kembali...";
        system("pause > nul");
        return;
    }

    char confirmChoice;
    cout << "Apakah Anda yakin ingin menghapus menu '"
         << daftarMenu[index].namaMenu << "' (ID: " << daftarMenu[index].idMenu
         << ")? (y/n): ";
    cin >> confirmChoice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (confirmChoice == 'y' || confirmChoice == 'Y') {
        for (int j = index; j < jumlahMenu - 1; j++) {
            daftarMenu[j] = daftarMenu[j + 1];
        }

        jumlahMenu--;

        // Update ulang ID menu agar tetap berurutan
        for (int i = 0; i < jumlahMenu; i++) {
            daftarMenu[i].idMenu = i + 1;
        }

        cout << "\n=======================================\n";
        cout << "       Menu berhasil dihapus!\n";
        cout << "=======================================\n";
        simpanMenu();
    } else {
        cout << "\nPenghapusan dibatalkan.\n";
    }

    cout << "Tekan tombol apapun untuk melanjutkan...";
    system("pause > nul");
}

void hapusDataPelanggan() {
    system("cls"); // Bersihkan layar console agar tampilan lebih rapi

    // Tampilan header untuk fungsi hapus data pelanggan
    cout << "=======================================\n";
    cout << "          HAPUS DATA PELANGGAN\n";
    cout << "=======================================\n\n";

    // Cek apakah ada data pelanggan yang tersedia untuk dihapus
    if (jumlahPelanggan == 0) {
        cout << "Belum ada pelanggan yang tersedia untuk dihapus.\n";
        cout << "Tekan tombol apapun untuk kembali...";
        system("pause > nul");
        return;
    }

    // Tampilkan daftar pelanggan yang tersedia
    cout << "--- Daftar Pelanggan Tersedia ---\n";
    cout << left << setw(5) << "ID" << setw(30) << "Nama Pelanggan" << "\n";
    cout << string(35, '-') << "\n";

    for (int i = 0; i < jumlahPelanggan; i++) {
        cout << left << setw(5) << daftarPelanggan[i].idPelanggan
             << setw(30) << daftarPelanggan[i].namaPelanggan << "\n";
    }
    cout << string(35, '-') << "\n\n";

    // Input ID pelanggan yang ingin dihapus
    int idToDelete;
    cout << "Masukkan ID pelanggan yang ingin dihapus: ";
    while (!(cin >> idToDelete)) {
        cout << "Input tidak valid. Mohon masukkan angka untuk ID pelanggan: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Cari pelanggan berdasarkan ID
    int indexToDelete = -1;
    for (int i = 0; i < jumlahPelanggan; i++) {
        if (daftarPelanggan[i].idPelanggan == idToDelete) {
            indexToDelete = i;
            break;
        }
    }

    // Jika ID tidak ditemukan
    if (indexToDelete == -1) {
        cout << "\n---------------------------------------\n";
        cout << "ID pelanggan " << idToDelete << " tidak ditemukan.\n";
        cout << "---------------------------------------\n";
        cout << "Tekan tombol apapun untuk kembali...";
        system("pause > nul");
        return;
    }

    // Konfirmasi penghapusan
    char confirmChoice;
    cout << "Apakah Anda yakin ingin menghapus pelanggan '"
         << daftarPelanggan[indexToDelete].namaPelanggan
         << "' (ID: " << daftarPelanggan[indexToDelete].idPelanggan
         << ")? (y/n): ";
    cin >> confirmChoice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (confirmChoice == 'y' || confirmChoice == 'Y') {
        // Geser data ke kiri untuk menghapus pelanggan
        for (int j = indexToDelete; j < jumlahPelanggan - 1; j++) {
            daftarPelanggan[j] = daftarPelanggan[j + 1];
        }

        jumlahPelanggan--; // Kurangi jumlah pelanggan

        // Update ulang ID pelanggan agar tetap berurutan dari 1
        for (int i = 0; i < jumlahPelanggan; i++) {
            daftarPelanggan[i].idPelanggan = i + 1;
        }

        cout << "\n=======================================\n";
        cout << "       Data pelanggan berhasil dihapus!\n";
        cout << "=======================================\n";

        simpanpelanggan(); // Simpan data ke file
    } else {
        cout << "\nPenghapusan dibatalkan.\n";
    }

    cout << "Tekan tombol apapun untuk melanjutkan...";
    system("pause > nul");
}

//5.SORTING
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
                Menu temp = daftarMenu[j];
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
                Menu temp = daftarMenu[j];
                daftarMenu[j] = daftarMenu[j + 1];
                daftarMenu[j + 1] = temp;
            }
        }
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

//================================
// Bubble Sort berdasarkan ID
void bubbleIdMenu(bool ascending) {
    for (int i = 0; i < jumlahMenu - 1; i++) {
        for (int j = 0; j < jumlahMenu - i - 1; j++) {
            if ((ascending && daftarMenu[j].idMenu > daftarMenu[j + 1].idMenu) ||
                (!ascending && daftarMenu[j].idMenu < daftarMenu[j + 1].idMenu)) {
                swap(daftarMenu[j], daftarMenu[j + 1]);
            }
        }
    }
}

// Quick Sort berdasarkan ID
void quickIdMenu(Menu arr[], int low, int high, bool ascending) {
    if (low < high) {
        int pivot = arr[high].idMenu;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if ((ascending && arr[j].idMenu < pivot) ||
                (!ascending && arr[j].idMenu > pivot)) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickIdMenu(arr, low, pi - 1, ascending);
        quickIdMenu(arr, pi + 1, high, ascending);
    }
}

// Insertion Sort berdasarkan ID
void insertionIdMenu(bool ascending) {
    for (int i = 1; i < jumlahMenu; i++) {
        Menu key = daftarMenu[i];
        int j = i - 1;
        while (j >= 0 && ((ascending && daftarMenu[j].idMenu > key.idMenu) ||
                          (!ascending && daftarMenu[j].idMenu < key.idMenu))) {
            daftarMenu[j + 1] = daftarMenu[j];
            j--;
        }
        daftarMenu[j + 1] = key;
    }
}

//================================
// Bubble Sort berdasarkan Nama
void bubbleNamaMenu(bool ascending) {
    for (int i = 0; i < jumlahMenu - 1; i++) {
        for (int j = 0; j < jumlahMenu - i - 1; j++) {
            if ((ascending && daftarMenu[j].namaMenu > daftarMenu[j + 1].namaMenu) ||
                (!ascending && daftarMenu[j].namaMenu < daftarMenu[j + 1].namaMenu)) {
                swap(daftarMenu[j], daftarMenu[j + 1]);
            }
        }
    }
}

// Quick Sort berdasarkan Nama
void quickNamaMenu(Menu arr[], int low, int high, bool ascending) {
    if (low < high) {
        string pivot = arr[high].namaMenu;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if ((ascending && arr[j].namaMenu < pivot) ||
                (!ascending && arr[j].namaMenu > pivot)) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickNamaMenu(arr, low, pi - 1, ascending);
        quickNamaMenu(arr, pi + 1, high, ascending);
    }
}

// Insertion Sort berdasarkan Nama
void insertionNamaMenu(bool ascending) {
    for (int i = 1; i < jumlahMenu; i++) {
        Menu key = daftarMenu[i];
        int j = i - 1;
        while (j >= 0 && ((ascending && daftarMenu[j].namaMenu > key.namaMenu) ||
                          (!ascending && daftarMenu[j].namaMenu < key.namaMenu))) {
            daftarMenu[j + 1] = daftarMenu[j];
            j--;
        }
        daftarMenu[j + 1] = key;
    }
}

//================================
// Bubble Sort harga
void bubblehargamenu(bool ascending) {
    for (int i = 0; i < jumlahMenu - 1; i++) {
        for (int j = 0; j < jumlahMenu - i - 1; j++) {
            if ((ascending && daftarMenu[j].harga > daftarMenu[j + 1].harga) ||
                (!ascending && daftarMenu[j].harga < daftarMenu[j + 1].harga)) {
                swap(daftarMenu[j], daftarMenu[j + 1]);
            }
        }
    }
}

// Quick Sort harga
void quickhargamenu(Menu arr[], int low, int high, bool ascending) {
    if (low < high) {
        float pivot = arr[high].harga;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if ((ascending && arr[j].harga < pivot) ||
                (!ascending && arr[j].harga > pivot)) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickhargamenu(arr, low, pi - 1, ascending);
        quickhargamenu(arr, pi + 1, high, ascending);
    }
}

// Insertion Sort harga
void insertionhargamenu(bool ascending) {
    for (int i = 1; i < jumlahMenu; i++) {
        Menu key = daftarMenu[i];
        int j = i - 1;
        while (j >= 0 && ((ascending && daftarMenu[j].harga > key.harga) ||
                          (!ascending && daftarMenu[j].harga < key.harga))) {
            daftarMenu[j + 1] = daftarMenu[j];
            j--;
        }
        daftarMenu[j + 1] = key;
    }
}

//===============================

void melihatDataMenu() {
    system("cls");

    cout << "=======================================\n";
    cout << "          TAMPILKAN DATA MENU\n";
    cout << "=======================================\n\n";

    if (jumlahMenu == 0) {
        cout << "Belum ada menu yang tersedia untuk ditampilkan.\n";
        cout << "Tekan tombol apapun untuk kembali...";
        system("pause > nul");
        return;
    }

    cout << "===== PILIHAN PENGURUTAN MENU =====\n";
    cout << "1. Berdasarkan ID Menu\n";
    cout << "2. Berdasarkan Nama Menu\n";
    cout << "3. Berdasarkan Harga\n";
    cout << "4. Tanpa Pengurutan (Default)\n";
    cout << "Pilih opsi pengurutan: ";

    int pilihSort;
    while (!(cin >> pilihSort) || pilihSort < 1 || pilihSort > 4) {
        cout << "Input tidak valid. Mohon masukkan angka antara 1-4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool ascending = true;
    int metode = 0;

    if (pilihSort != 4) {
        cout << "\n--- Pilihan Urutan ---\n";
        cout << "1. Ascending\n";
        cout << "2. Descending\n";
        cout << "Pilih urutan: ";

        int order;
        while (!(cin >> order) || (order != 1 && order != 2)) {
            cout << "Input tidak valid. Mohon masukkan 1 (Ascending) atau 2 (Descending): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ascending = (order == 1);

        cout << "\n--- Pilihan Metode Pengurutan ---\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Quick Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "Pilih metode pengurutan: ";

        while (!(cin >> metode) || metode < 1 || metode > 3) {
            cout << "Input tidak valid. Mohon masukkan angka antara 1 sampai 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    system("cls");

    if (pilihSort == 4) {
        cout << "Menampilkan menu tanpa pengurutan.\n\n";
    } else {
        // Jalankan sorting sesuai pilihan
        if (pilihSort == 1) {  // Berdasarkan ID
            if (metode == 1)
                bubbleIdMenu(ascending);
            else if (metode == 2)
                quickIdMenu(daftarMenu, 0, jumlahMenu - 1, ascending);
            else
                insertionIdMenu(ascending);

            cout << "Menu diurutkan berdasarkan ID dengan metode ";
        }
        else if (pilihSort == 2) {  // Berdasarkan Nama
            if (metode == 1)
                bubbleNamaMenu(ascending);
            else if (metode == 2)
                quickNamaMenu(daftarMenu, 0, jumlahMenu - 1, ascending);
            else
                insertionNamaMenu(ascending);

            cout << "Menu diurutkan berdasarkan Nama dengan metode ";
        }
        else {  // Berdasarkan Harga
            if (metode == 1)
                bubblehargamenu(ascending);
            else if (metode == 2)
                quickhargamenu(daftarMenu, 0, jumlahMenu - 1, ascending);
            else
                insertionhargamenu(ascending);

            cout << "Menu diurutkan berdasarkan Harga dengan metode ";
        }

        if (metode == 1) cout << "Bubble Sort.\n\n";
        else if (metode == 2) cout << "Quick Sort.\n\n";
        else cout << "Insertion Sort.\n\n";
    }

    // Tampilkan data menu (makanan & minuman) dengan format rapi
    cout << "=======================================\n";
    cout << "           DATA MENU RESTORAN\n";
    cout << "=======================================\n\n";

    vector<Menu> makananMenu;
    vector<Menu> minumanMenu;

    for (int i = 0; i < jumlahMenu; ++i) {
        if (daftarMenu[i].jenisMenu == "Makanan") {
            makananMenu.push_back(daftarMenu[i]);
        } else if (daftarMenu[i].jenisMenu == "Minuman") {
            minumanMenu.push_back(daftarMenu[i]);
        }
    }

    auto tampilkanMenu = [](const vector<Menu>& list, const string& jenis) {
        cout << "--- " << jenis << " ---\n";
        if (list.empty()) {
            cout << "Tidak ada menu " << jenis << " yang tersedia.\n\n";
            return;
        }

        cout << left << setw(5) << "ID"
             << setw(25) << "Nama Menu"
             << setw(15) << "Jenis"
             << right << setw(12) << "Harga (Rp)" << endl;
        cout << setfill('-') << string(57, '-') << endl;
        cout << setfill(' ');

        for (const auto& item : list) {
            cout << left << setw(5) << item.idMenu
                 << setw(25) << item.namaMenu
                 << setw(15) << item.jenisMenu
                 << right << setw(12) << fixed << setprecision(2) << item.harga << endl;
        }
        cout << setfill('-') << string(57, '-') << setfill(' ') << endl << endl;
    };

    tampilkanMenu(makananMenu, "MAKANAN");
    tampilkanMenu(minumanMenu, "MINUMAN");

    simpanMenu();

    cout << "Tekan tombol apapun untuk kembali...";
    system("pause > nul");
}


//4.SEARCHING
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
        //to_string(daftarPelanggan[i].idPelanggan) → Mengubah idPelanggan (tipe int) menjadi string (karena input juga berupa string, hasil dari getline())
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

    cout << string(60, '=') << "\n";
    cout << setw(30) << setfill(' ') << "" << "DATA PELANGGAN\n";
    cout << string(60, '=') << "\n\n";

    if (jumlahPelanggan == 0) {
        cout << setw(40) << setfill(' ') << "" << "Belum ada data pelanggan yang tersedia.\n\n";
    } else {
        for (int a = 0; a < jumlahPelanggan; ++a) {
            Pelanggan& p = daftarPelanggan[a];

            // Header pelanggan
            cout << "ID PELANGGAN  : " << p.idPelanggan << "\n";
            cout << "NAMA         : " << p.namaPelanggan << "\n";
            cout << "JUMLAH PESANAN : " << p.jumlahPesanan << "\n\n";

            cout << "DAFTAR PESANAN:\n";
            cout << string(60, '-') << "\n";
            cout << left
                 << setw(5)  << "NO"
                 << setw(20) << "NAMA MENU"
                 << setw(12) << "JENIS"
                 << setw(10) << "JUMLAH"
                 << setw(10) << "HARGA" << "\n";
            cout << string(60, '-') << "\n";

            if (p.jumlahPesanan == 0) {
                cout << "Tidak ada pesanan untuk pelanggan ini.\n";
            } else {
                for (int i = 0; i < p.jumlahPesanan; ++i) {
                    int idMenuIndex = p.pesanan[i] - 1;

                    if (idMenuIndex >= 0 && idMenuIndex < jumlahMenu) {
                        Menu& m = daftarMenu[idMenuIndex];
                        cout << left
                             << setw(5)  << (i + 1)
                             << setw(20) << m.namaMenu
                             << setw(12) << m.jenisMenu
                             << setw(10) << p.jumlahMenu[i]
                             << setw(10) << m.harga << "\n";
                    } else {
                        cout << left
                             << setw(5)  << (i + 1)
                             << setw(20) << "[Menu Tidak Ditemukan]"
                             << setw(12) << "-"
                             << setw(10) << p.jumlahMenu[i]
                             << setw(10) << "-" << "\n";
                    }
                }
            }

            cout << string(60, '-') << "\n";
            cout << "TOTAL HARGA : Rp " << p.totalHarga << "\n\n";
            cout << string(60, '=') << "\n\n";
        }
    }
    simpanpelanggan();
    system("pause");
}

//7.FILE
void simpanMenu() {
    ofstream file("menu_data.csv");

    if (!file) {
        cout << "Gagal membuka file menu_data.csv untuk penyimpanan." << endl;
        return;
    }

    // Menulis header
    file << "ID,NAMA_MENU,JENIS,HARGA\n";

    // Menulis data menu
    for (int i = 0; i < jumlahMenu; ++i) {
        Menu& m = daftarMenu[i]; // Asumsikan ada struct Menu

        file << m.idMenu << ",";
        file << m.namaMenu << ",";
        file << m.jenisMenu << ",";
        file << m.harga << "\n";
    }

    file.close();
    cout << "Data menu berhasil disimpan ke 'menu_data.csv'\n";
}


void bacaMenu() {
    ifstream file("menu_data.csv");
    if (!file) {
        cout << "File menu_data.csv tidak ditemukan.\n";
        return;
    }

    string line;
    jumlahMenu = 0;

    // Lewati baris header (ID,NAMA_MENU,JENIS,HARGA)
    getline(file, line);

    while (getline(file, line)) {
        if (jumlahMenu >= 100) break;

        stringstream ss(line);
        string token;
        Menu& m = daftarMenu[jumlahMenu];

        // Baca ID
        if (!getline(ss, token, ',')) continue;
        m.idMenu = stoi(token);

        // Baca Nama Menu
        if (!getline(ss, token, ',')) continue;
        m.namaMenu = token;

        // Baca Jenis Menu
        if (!getline(ss, token, ',')) continue;
        m.jenisMenu = token;

        // Baca Harga
        if (!getline(ss, token)) continue;
        m.harga = stod(token);  // Gunakan `stod` jika harga berupa desimal

        jumlahMenu++;
    }

    file.close();
    cout << "Data menu berhasil dimuat dari file.\n";
}

void simpanpelanggan() {
    ofstream file("pelanggan_data.csv");

    if (!file) {
        cout << "Gagal membuka file pelanggan_data.csv untuk penyimpanan." << endl;
        return;
    }

    for (int i = 0; i < jumlahPelanggan; i++) {
        Pelanggan& p = daftarPelanggan[i];

        file << p.idPelanggan << ",";
        file << p.namaPelanggan << ",";
        file << p.jumlahPesanan << ",";

        for (int j = 0; j < p.jumlahPesanan; j++) {
            file << p.pesanan[j] << "|" << p.jumlahMenu[j];
            if (j != p.jumlahPesanan - 1)
                file << ",";
        }

        file << "," << p.totalHarga << "\n";
    }

    file.close();
    cout << "Data pelanggan berhasil disimpan ke 'pelanggan_data.csv'\n";
}


void bacapelanggan() {
    ifstream file("pelanggan_data.csv");
    if (!file) {
        cout << "File pelanggan_data.csv tidak ditemukan.\n";
        return;
    }

    string line;
    jumlahPelanggan = 0;

    while (getline(file, line)) {
        if (jumlahPelanggan >= 100) break;

        stringstream ss(line);
        string token;
        Pelanggan& p = daftarPelanggan[jumlahPelanggan];

        // Baca ID
        if (!getline(ss, token, ',')) continue;
        p.idPelanggan = stoi(token);

        // Baca Nama
        if (!getline(ss, token, ',')) continue;
        p.namaPelanggan = token;

        // Baca jumlah pesanan
        if (!getline(ss, token, ',')) continue;
        p.jumlahPesanan = stoi(token);

        // Baca pesanan dan qty
        for (int i = 0; i < p.jumlahPesanan; i++) {
            if (!getline(ss, token, ',')) {
                p.pesanan[i] = 0;
                p.jumlahMenu[i] = 0;
            } else {
                size_t pos = token.find('|');
                if (pos != string::npos) {
                    p.pesanan[i] = stoi(token.substr(0, pos));
                    p.jumlahMenu[i] = stoi(token.substr(pos + 1));
                } else {
                    p.pesanan[i] = 0;
                    p.jumlahMenu[i] = 0;
                }
            }
        }

        // Baca totalHarga (sisa baris)
        if (!getline(ss, token)) continue;
        p.totalHarga = stoi(token);

        jumlahPelanggan++;
    }

    file.close();
    cout << "Data pelanggan berhasil dimuat dari file.\n";
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
    Menu* menuToEdit = nullptr; // Pointer untuk menampung alamat menu yang ditemukan
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
    simpanMenu();
    system("pause > nul"); // Pause modern tanpa output pesan
}
//6.POINTER
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
    Pelanggan* pelangganToEdit = nullptr; // Pointer inisialisasi null
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
	simpanpelanggan();
    system("pause > nul");
}
