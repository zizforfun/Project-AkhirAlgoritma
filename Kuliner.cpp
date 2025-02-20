#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

	struct menu
	{
	 string namaMenu,jenisMenu;
	 int harga,idMenu;
	};
	
	
	struct pelanggan
	{
	 string namaPelanggan;
	 int idPelanggan;
	 int jumlahPesanan;	
	 int pesanan[100]; // menyimpan ID menu dipesan
	 int jumlahMenu[100];//menyimpan jumlah dari tiap menu dipesan
	 int totalHarga;//total harga pesanan pelanggan
	};
	
	menu daftarMenu[100];
	pelanggan daftarPelanggan[100];
	int jumlahMenu = 3; //inisiasi menu awal(bawaan)
	int jumlahPelanggan =0;
	
	void about();
	void tambahDataMenu();
	void tambahDataPelanggan();
	void melihatDataMenu();
	void melihatDataPelanggan();
	void daftarMenuAwal();
	void hitungTotalHarga(pelanggan &p); // fungsi menghtiung total harga
	void hapusdatamenu();

	
	int main()
	{
	 daftarMenu[0] = { "Nasi Ayam Goreng","Makanan",15000,1 };
	 daftarMenu[1] = { "Ikan Rebus","Makanan",20000,2 };
	 daftarMenu[2] = { "Nasi Sambel","Makanan",3000,3 };
	 
	 int pilihan;
	 char ulang;
	 
	 do 
	 {
	  system("cls");
	  cout << setfill(' ');
	  cout << endl;
	  cout << setw(42) << setfill('-') << "\n";
	  cout << "======== PROGRAM KASIR BIZ RESTO ========\n";
	  cout << setw(42) << setfill('-') << "\n";
	  cout << setfill(' ');
	  cout << setw(30) << "<<<<<<< Menu Utama >>>>>>>\n";
	  cout << "--------------------------------\n";
	  cout << "|" << "1. About"					<< "\t\t\t|\n";
	  cout << "|" << "2. Daftar Menu"       	<< "\t\t\t|\n";
	  cout << "|" << "3. Tambah Data Menu"  	<< "\t\t|\n";
	  cout << "|" << "4. Tambah Data Pelanggan" << "\t|\n";
	  cout << "|" << "5. Melihat Data Menu"		<< "\t\t|\n";
	  cout << "|" << "6. Melihat Data Pelanggan"<< "\t|\n";
	  cout << "|" << "7. Hapus Daftar Menu"     << "\t|\n";
	  cout << "|" << "8. Exit"					<< "\t\t\t|\n";
	  cout << "--------------------------------\n";
	  cout << "Isikan Pilihan Menu: ";
	  cin  >> pilihan;
			switch (pilihan)
				{
				 case 1:
					 about();
					 break;
			     case 2:
					 daftarMenuAwal();
					 break;
				 case 3:
					 tambahDataMenu();
					 break;
				 case 4:
					 tambahDataPelanggan();
					 break;
				 case 5:
					 melihatDataMenu();
					 break;
				 case 6:
					 melihatDataPelanggan();
					 break;
			     case 7: hapusdatamenu();
				     break;
				 case 8:
					 cout << "\t===PROGRAM SELESAI===\n";
					 return 0;
				 default:
					cout << "==MOHON MAAF, PILIIHAN ANDA TIDAK TERSEDIA==\n";
				 
				}
			
		cout << "Apakah ingin mengulang program (y/n)?: ";
		cin  >> ulang; 
	 }
	 
	  while (ulang=='y');
	  return 0;
	  	
	 }
	 
	 
	 
	  void about()
	 {
	  system("cls");
	  cout << "======== ABOUT THE PROGRAM ========\n";
	  cout << setw(42) << setfill('-') << "\n";
	  cout << "Program ini dibuat oleh : \n";
	  cout << setw(42) << setfill('-') << "\n";
	  cout << "Nama\t: Bima Putra F\n"
		   << "\t  Nur Aziz Ramadhan\n";
	  cout << "NIM\t: 123230003 \n"
	       << "\t  123240261 \n";
	  cout << "Kelas\t: If-M\n";
	  cout << setw(42) << setfill('-') << "\n";
	  
	 }
	 
	 void daftarMenuAwal()
	 {
	  system("cls");
	  cout << setw(40) << setfill('=') << " DAFTAR MENU AWAL " << setw(40) << setfill('=') << "\n";
	  if(jumlahMenu == 0)
		{
		 cout << " Belum ada menu yang di tambahkan. \n";
		}
	  
	  else 
		{
		 for(int i =0; i<jumlahMenu; ++i)
			{
			 cout << "ID Menu: " 	<< daftarMenu[i].idMenu 	<< endl;
			 cout << "Jenis Menu: " << daftarMenu[i].jenisMenu	<< endl;
			 cout << "Nama Menu: " 	<< daftarMenu[i].namaMenu 	<< endl;
			 cout << "Harga: "		<< daftarMenu[i].harga 		<< endl;
			 cout << "-------------------------------\n";
			}
		}
	 
	 }

	 
	 
	 void tambahDataMenu()
	 {
	  system("cls");
	  cout << setw(40) << setfill('=') << "" << " << TAMBAH DAFTAR MENU >>" << setw(40) << setfill('=') << "\n";
	  cout << "Jumlah Menu : " << jumlahMenu << endl;
	  cin.ignore();
	  
	  cout << setw(105) << setfill('=') << "\n";
	  cout << setw(30)  << "\t\t--ISIKAN MENU YANG AKAN DITAMBAHKAN--\n";
	  cout << setw(17)  << setfill('-') <<"\n";
	  cout << "|TAMBAHAN MENU  |\n";
	  cout << setw(17) 	<< setfill('-') << "\n";
	  
	  cout << "Jumlah menu yang ingin ditambahkan: ";
	  int total;
	  cin  >> total;
	  cin.ignore();
	  
	  for (int a = 0; a<total; ++a)
		{
		 daftarMenu[jumlahMenu].idMenu = jumlahMenu + 1;
		 cout << setw(17)  << setfill('=') <<"\n";
		 cout << " JENIS MENU \n";
		 cout << setw(17)  << setfill('=') <<"\n";
		 cout << " - Makanan \n";
		 cout << " - Minuman \n";
		 cout << setw(17)  << setfill('-') <<"\n";
		 cout << "ID Menu\t\t\t: " << daftarMenu[jumlahMenu].idMenu << endl;
		 cout << "Masukkan Jenis Menu\t: ";
		 getline (cin,daftarMenu[jumlahMenu].jenisMenu);
		 cout << "Masukkan Nama Menu\t: ";
		 getline (cin,daftarMenu[jumlahMenu].namaMenu);
		 cout << "Masukkan Harga Menu\t: ";
		 cin  >> daftarMenu[jumlahMenu].harga;
		 cin.ignore();
		 jumlahMenu++;//Menambah jumlah menu
		}
	
	cout << setw(30) << setfill('=') << "" << "DAFTAR MENU BERHASIL DI TAMBAHKAN" << setw(30) << setfill('=') << "\n";
	 }
	 
	 
	 
	 
	 	 
	 void tambahDataPelanggan()
	 {
	  system("cls");
	  cout << setw(40) 	<< setfill('=') << "" << " << TAMBAH DAFTAR PELANGGAN >>" << setw(40) << setfill('=') << "\n";
	  cout << "Jumlah Pelanggan : " << jumlahPelanggan << endl;
	  cin.ignore();
	  
	  cout << setw(110) << setfill('=') << "\n";
	  cout << setw(30)  << "\t\t--ISIKAN DATA PELANGGAN YANG AKAN DITAMBAHKAN--\n";
	  cout << setw(20)  << setfill('-') <<"\n";
	  cout << "|TAMBAH PELANGGAN |\n";
	  cout << setw(20) 	<< setfill('-') << "\n";
	  
	  cout << "Jumlah Pelanggan yang ingin ditambahkan: ";
	  int total;
	  cin  >> total;
	  cin.ignore();
	  
	  for (int a = 0; a<total; ++a)
		{
		 daftarPelanggan[jumlahPelanggan].idPelanggan = jumlahPelanggan + 1;
		 cout << "ID Pelanggan\t\t: " 		<< daftarPelanggan[jumlahPelanggan].idPelanggan << endl;
		 cout << "Masukkan Nama Pelanggan : ";
		 getline (cin,daftarPelanggan[jumlahPelanggan].namaPelanggan);
		 
		 //tampilkan daftar menu
		 cout << setw(71) << setfill('=');
		 cout << "\n\t|DAFTAR MENU YANG TERSEDIA:|\n";
		 cout << setw(40) << setfill('=') 	<< "\n";
		 for (int i=0;i<jumlahMenu;++i)
			{
			 cout << "ID Menu\t\t: "		<< daftarMenu[i].idMenu 	<< endl;
			 cout << "Nama Menu\t: " 		<< daftarMenu[i].namaMenu 	<< endl;
			 cout << "Harga\t\t: " 			<<daftarMenu[i].harga 		<< endl;
			 cout << setw(40) 				<< setfill('-') 			<< "\n" 	<< setfill(' ');
			}
		 cout << setw(20) << setfill('-') << "\n";
		 
		 //milih menu yang dipesan
		 int i = 0;
		 daftarPelanggan[jumlahPelanggan].jumlahPesanan = 0;
		 while (true) 
			{
			 cout << "Masukkan ID Menu yang dipesan (0 untuk selesai) : ";
			 cin  >> daftarPelanggan[jumlahPelanggan].pesanan[i];
			 if (daftarPelanggan[jumlahPelanggan].pesanan[i] == 0) break;
			 cout << "Masukkan Jumlah Pesanan\t: ";
			 cin  >> daftarPelanggan[jumlahPelanggan].jumlahMenu[i];
			
			//memastikan ID valid
			if(daftarPelanggan[jumlahPelanggan].pesanan[i] > jumlahMenu || daftarPelanggan[jumlahPelanggan].pesanan[i] < 1)
				{
				 cout << "ID Menu tidak valid Silakan coba lagi.\n";
				 continue;
				}
			
			 i++; //untuk pindah ke menu berikutnya
			}
			
			daftarPelanggan[jumlahPelanggan].jumlahPesanan = i; //jumlah pesanan sesuai banyak menu yang dipesan
			
			//hitung total harga
			hitungTotalHarga(daftarPelanggan[jumlahPelanggan]);
			jumlahPelanggan++;
		}
	
	  cout << setw(30) << setfill('=') << "" << "DAFTAR MENU BERHASIL DI TAMBAHKAN" << setw(30) << setfill('=') << "\n";
	 }
	 
	
	
	 void hitungTotalHarga(pelanggan &p)
		{
		 int total = 0;
		 for (int i = 0; i<p.jumlahPesanan; ++i)
			{
			 int idMenu = p.pesanan[i] - 1;
			 if (idMenu >= 0 && idMenu < jumlahMenu)
				{
				 total += daftarMenu[idMenu].harga * p.jumlahMenu[i];	
				}
			
			}
		  p.totalHarga = total;
		}

        void hapusdatamenu()
        {
				system("cls");
				cout<<"===== HAPUS MENU =====\n";
				melihatDataMenu();
				cout<<"masukkan ID menu yang ingin dihapus:";
				int hapus;
				cin>>hapus;
				bool ditemukan= true;
			
				for (int i=0; i<jumlahMenu; i++){
					if (daftarMenu[i].idMenu == hapus){
						ditemukan= false;
						for(int j=i; j<jumlahMenu - 1; j++){
							daftarMenu[j]= daftarMenu[j +1];
						}
						jumlahMenu--;
						cout<<"menu berhsil dihapus\n";
						break;
					}
				}
				if(ditemukan){
					cout<<"ID menu tidak ditemukan\n";
				}
			  
        }

     void melihatDataMenu()
	 {
	  system("cls");
	  cout << setw(40) << setfill('=') << " DATA MENU " << setw(40) << setfill('=') << "\n";
	  for (int a= 0; a < jumlahMenu; ++a)
			{
			 cout << setw(82) << setfill('-')   		<< "\n";
			 cout << "\t\tID Menu\t" << "\t\t|" 		<< "\t\t"  	<< daftarMenu[a].idMenu     << "\t\t\t|\n";
			 cout << setw(82) << setfill('-')   		<< "\n";
			 cout << "\t\tJenis Menu\t" << "\t|"		<< "\t\t" 	<< daftarMenu[a].jenisMenu  <<"\t\t\t|\n";
			 cout << setw(82) << setfill('-') 			<< "\n";
			 cout << "\t\tNama Menu\t" << "\t|" 		<< "\t\t"   << daftarMenu[a].namaMenu   <<"\t\t|\n";
			 cout << setw(82) << setfill('-') 			<< "\n";
			 cout << "\t\tHarga Menu\t" << "\t|" 		<< "\t\t"   << daftarMenu[a].harga      <<"\t\t\t|\n";
			 cout << setw(82) << setfill('-') 			<< "\n";
			}
	 }
	 
	 void melihatDataPelanggan()
	 {
	  system("cls");
	  cout << setw(40) << setfill('=') << " DATA PELANGGAN " 	<< setw(40) << setfill('=') << "\n";
	  for (int a= 0; a < jumlahPelanggan; ++a)
			{
			 cout << setw(82) << setfill('-') 	<< "\n";
			 cout << "\t\tID Pelanggan\t" 		<< "\t|" 		<< "\t\t" 	<< daftarPelanggan[a].idPelanggan 		<< "\t\t\t|\n";
			 cout << setw(82) << setfill('-') 	<< "\n";
			 cout << "\t\tNama Pelanggan\t" 	<< "\t|" 		<< "\t\t" 	<< daftarPelanggan[a].namaPelanggan 	<<"\t\t\t|\n";
			 cout << setw(82) << setfill('-') 	<< "\n";
			 cout << "\t\tJumlah Pesanan\t" 	<< "\t|" 		<< "\t\t" 	<< daftarPelanggan[a].jumlahPesanan 	<<"\t\t\t|\n";
			 cout << setw(82) << setfill('-') 	<< "\n";
			 cout << "\t\tTagihan\t\t" << "\t|" << "\t\t" 		<< daftarPelanggan[a].totalHarga 					<<"\t\t\t|\n";
			 cout << setw(82) << setfill('-') 	<< "\n";
			 
			 //menampilkan rincian pesanan pelanggan
			 cout << setw(40) << setfill('-');
			 cout << "\nRINCIAN PESANAN: \n";
			 cout << setw(40) << setfill('-') 	<< "\n";
			 cout << setfill(' ') << "\n";
			 cout << setw(6)  << "ID Menu"    	<< "\t|" 
				  << setw(18) << "Nama Menu" 	<< "\t|"
				  << setw(6)  << "Jumlah"      	<<"\t|" 
				  << setw(13) << "Harga Satuan" << "\t|"
				  << setw(13) << "Subtotal\n";
			 cout << setw(76) << (' ') 			<< "\n";
			 
			 for (int i = 0; i <daftarPelanggan[a].jumlahPesanan;++i)
					{
					 int idMenu = daftarPelanggan[a].pesanan[i] - 1;
					 if (idMenu >= 0 && idMenu < jumlahMenu)
							{
							 int subtotal = daftarPelanggan[a].jumlahMenu[i] * daftarMenu[idMenu].harga;
							 cout << setw(8)  << daftarPelanggan[a].pesanan[i]
								  << setw(20) << daftarMenu[idMenu].namaMenu
								  << setw(8)  << daftarPelanggan[a].jumlahMenu[i]
								  << setw(15) << daftarMenu[idMenu].harga
								  << setw(15) << subtotal << endl;
							}
					}
			//nampilkan total tagihan
			cout << setw(82) << setfill ('-') 			<< "\n";
			cout << "\t\t\t\t\t\t\t\tTOTAL HARGA: " 	<< daftarPelanggan[a].totalHarga << endl;
			cout << setw(82) << setfill('-') 			<< "\n";
			}
	 }

	  
	 
	
