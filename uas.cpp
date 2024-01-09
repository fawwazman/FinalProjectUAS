#include <iostream>
#include <map>
#include <string>
#include <limits>

using namespace std;

struct Barang
{
  string nama;
  int stok;
};

int main()
{
  string username, password, nama;
  int jumlah, pilihan;
  map<string, Barang> daftarBarang;
  Barang barang;

  cout << endl
       << "===================================" << endl;
  cout << "Selamat datang di management stock" << endl;
  cout << "===================================" << endl
       << endl;

  cout << "<<< Silahkan login >>>" << endl;
  cout << "Username: ";
  cin >> username;
  cout << "Password: ";
  cin >> password;

  if (username == "Admin" && password == "Admin")
  {
    cout << endl
         << "=============================================" << endl;
    cout << "Login berhasil. Selamat datang, " << username << "!" << endl;
    cout << "=============================================" << endl
         << endl;

    while (true)
    {
      cout << "|============|"
           << endl;
      cout << "| Menu Utama |" << endl;
      cout << "|============|" << endl
           << endl;
      cout << "1. Tambah stok barang" << endl;
      cout << "2. Kurangi stok barang" << endl;
      cout << "3. Tampilkan stok barang" << endl;
      cout << "4. Hapus stok barang" << endl;
      cout << "5. Keluar" << endl
           << endl;

      cout << "==========================" << endl;
      cout << "Pilih menu (1/2/3/4/5)?: ";
      cin >> pilihan;
      cout << endl
           << endl;

      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout
            << "input tidak valid Ganteng, mohon masukin angka yang benar Ganteng!!" << endl;
      }
      else
      {

        if (pilihan == 1)
        {
          cout << "Nama barang: ";
          cin >> barang.nama;
          if (barang.nama.empty())
          {
            cout << "Nama barang tidak boleh kosong." << endl;
          }
          else
          {
            cout << "Stok awal: ";
            cin >> barang.stok;
            daftarBarang[barang.nama] = barang;
          }
        }
        else if (pilihan == 2)
        {
          cout << "Nama barang: ";
          cin >> nama;
          if (daftarBarang.find(nama) != daftarBarang.end())
          {
            cout << "Jumlah yang akan dikurangi: ";
            cin >> jumlah;
            if (daftarBarang[nama].stok >= jumlah)
            {
              daftarBarang[nama].stok -= jumlah;
            }
            else
            {
              cout << "maaf, pengurangan stok melebih batas " << endl;
            }
          }
          else
          {
            cout << "Maaf, barang tidak ditemukan " << endl;
          }
        }
        else if (pilihan == 3)
        {
          cout << "===========================================" << endl;
          cout << "|    NAMA BARANG     |     JUMLAH STOK    |" << endl;
          cout << "===========================================" << endl;
          for (map<string, Barang>::const_iterator it = daftarBarang.begin(); it != daftarBarang.end(); ++it)
          {
            cout << "\t" << it->first << "\t\t\t" << it->second.stok << endl;
          }
        }
        else if (pilihan == 4)
        {
          cout << "Nama barang: ";
          cin >> nama;
          if (daftarBarang.find(nama) != daftarBarang.end())
          {
            daftarBarang.erase(nama);
            cout << "Barang berhasil dihapus dari stok." << endl;
          }
          else
          {
            cout << "Barang tidak ditemukan " << endl;
          }
        }
        else if (pilihan == 5)
        {
          cout << "Terima kasih telah menggunakan Aplikasi Manajemen Stok, sampai jumpaa!" << endl
               << endl;
          break;
        }
        else
        {
          cout << "Pilihan tidak valid" << endl;
        }
      }
      cout << "Tekan enter untuk kembali ke menu utama..." << endl;
      cin.ignore();
      cin.get();
    }
  }
  else
  {
    cout << "Login gagal. Akses ditolak." << endl;
  }

  return 0;
}
