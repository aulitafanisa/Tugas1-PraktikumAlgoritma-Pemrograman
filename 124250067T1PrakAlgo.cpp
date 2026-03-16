#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct karyawan {
	int id;
	char nama[50];
};

struct barang {
	char namab [50];
	int stok, harga;
};

void Menu();
void MenuAdmin();
void TambahData();
void LihatData();
void searchKaryawan();
void MenuKaryawan();
void TambahBarang();
void TampilBarang();
void EditBarang();
void CariBarang();

bool Login() {
	char user[20], pass[20];
	printf("\n==================================\n");
	printf("           LOGIN ADMIN            \n");
	printf("==================================\n");
	printf("Username : ");
	scanf("%s", user);
	printf("Password : ");
	scanf("%s", pass);
	
	if (strcmp(user, "admin") == 0 && strcmp(pass, "12345") == 0) {
        printf("\nLogin Berhasil!\n");
        return true;
    } else {
        printf("Username atau Password salah, ");
        return false;
    }
}


int main() {
	int pilih;
	do {
		Menu();
		printf("\nMasukkan Pilihan Menu: ");
		scanf("%d", &pilih);
		
		switch (pilih) {
			case 1: 
					if (Login() == true) {
					MenuAdmin(); 
					} else {
						printf("gagal login.\n");
					} break;
			case 2: MenuKaryawan(); break;
			case 3: 
					printf("Terimakasih telah menggunakan sistem Cocoa Heaven!\n");
					return 0;
					default: printf("Pilihan Tidak Valid.\n");
		}
	} while (pilih != 3);
	return 0;
}

void Menu() {
	printf("\n====== WELCOME TO COCOA HEAVEN ======\n");
	printf("1. Login Admin\n");
	printf("2. Karyawan\n");
	printf("3. Keluar\n");
	printf("=====================================\n");
}

void MenuAdmin() {
	int a;
	do {
		printf("\n==================================\n");
		printf("           HALLO ADMIN!           \n");
		printf("==================================\n");
		printf("1. Tambah Data Karyawan\n");
		printf("2. Lihat Data Karyawan\n");
		printf("3. Searching Data Karyawan\n");
		printf("4. Logout\n");
		printf("==================================\n");
		printf("Pilih : ");
		scanf("%d", &a);
		
		switch (a) {
			case 1: TambahData(); break;
			case 2: LihatData(); break;
			case 3: searchKaryawan(); break;
			case 4: printf("\nLogout, Kembali ke Menu Utama.");
					return;
					default: printf("Pilihan tidak valid.\n");
		}
	} while (a != 4);
}

void TambahData() {
	int jml;
	karyawan dftrkaryawan[100];
	karyawan *ptrk = dftrkaryawan;
	
	printf("\n------ Tambah Data Karyawan ------\n");
	printf("Jumlah Input Data: ");
	scanf("%d", &jml);
	
	FILE *file = fopen("karyawan.txt", "a");
	if (file != NULL) {
		for (int i = 0; i < jml; i++) {
			printf("\nData Karyawan ke-%d\n", i + 1);
			printf("ID        : ");
			scanf("%d", &(ptrk + i)->id);
			getchar();
			printf("Nama      : ");
			scanf(" %[^\n]", (ptrk + i)->nama);
			
			fprintf(file, "%d#%s\n", (ptrk + i)->id, (ptrk + i)->nama);
		}
		fclose(file);
		printf("\nData Berhasil Ditambahkan!");
	} else {
		printf("Gagal Menambah Data.");
	}
}

void LihatData() {
	karyawan temp;
	int i = 1;
	
	FILE *file = fopen("karyawan.txt", "r");
	if (file != NULL) {
		printf("\n+--------- Data Karyawan ---------+\n");
		while (fscanf(file, " %d#%[^\n]\n", &temp.id, temp.nama) != EOF) {
			printf("\nData Karyawan ke-%d\n", i);
            printf("ID Karyawan   : %d\n", temp.id);
            printf("Nama Karyawan : %s\n", temp.nama);
            i++;
		}   printf("-----------------------------------\n");
		fclose(file);
	} else { 
		printf("File tidak ditemukan atau kosong.\n");
	}
}

void searchKaryawan() {
	
	FILE *file = fopen("karyawan.txt", "r");
	if (file == NULL) {
		printf("File tidak ditemukan atau kosong.\n");
		return;
	}
	
	int cariID;
	bool found = false;
	karyawan temp;
	
	printf("Masukkan ID karyawan yang dicari: ");
	scanf("%d", &cariID);
	while ( fscanf(file, " %d#%[^\n]\n", &temp.id, temp.nama) != EOF) {
		if (temp.id == cariID) {
			found = true;
			printf("\nData ditemukan!\n");
			printf("ID Karyawan    : %d\n", temp.id);
			printf("Nama Karyawan  : %s\n", temp.nama);
			break;
		}
	}
	
	if (!found) {
		printf("Data dengan ID %d tidak ditemukan.\n", cariID);
	}
	fclose(file);
}

void MenuKaryawan() {
	int p;
	do {
		printf("\n==================================\n");
		printf("          HALLO KARYAWAN!         \n");
		printf("==================================\n");
		printf("1. Tambah Data Barang\n");
		printf("2. Lihat Data Barang\n");
		printf("3. Edit Data Barang\n");
		printf("4. Cari Data Barang\n");
		printf("5. Logout\n");
		printf("==================================\n");
		printf("Pilih: ");
		scanf("%d", &p);
		
		switch (p) {
			case 1: TambahBarang(); break;
			case 2: TampilBarang(); break;
			case 3: EditBarang(); break;
			case 4: CariBarang(); break;
			case 5: printf("\nKembali ke Menu Utama.");
			return;
			default: printf("Pilihan tidak valid.");
		}
	} while (p != 5);
		
}

void TambahBarang() {
	int n;
	barang daftar[100];
	barang *ptr = daftar;
	
	printf("\n+--------- Tambah Data Barang ---------+\n");
	printf("\nMasukkan Jumlah Barang: "); 
	scanf("%d", &n);
	
	FILE *f = fopen("barang.txt", "a");
	
	if (f != NULL) {
		for (int i = 0; i < n; i++) {
			printf("\nBarang ke-%d\n", i + 1);
			getchar();
			printf(" Nama Barang  : ");
			cin.getline((ptr + i)->namab, 50);
			printf(" Harga Barang : ");
			scanf("%d", &(ptr + i)->harga);
			printf(" Stok Barang  : ");
			scanf("%d", &(ptr + i)->stok);
			
			fprintf(f, "%s#%d#%d\n", (ptr + i)->namab, (ptr + i)->harga, (ptr + i)->stok);
		}
		fclose(f);
		printf("Data Berhasil Disimpan!\n");
	}
}

void TampilBarang() {
	barang daftar[100];
	int n = 0;
	int u;
	
	FILE *f = fopen("barang.txt", "r");
	if (f == NULL) {
		printf ("Data kosong!\n");
		return;
	}
	
	while (fscanf(f, "%[^#]#%d#%d\n", daftar[n].namab, &daftar[n].harga, &daftar[n].stok) != EOF) {
		n++;
	}
	fclose(f);
	
	printf("\n----- Urutan -----");
	printf("\n1. Ascending");
	printf("\n2. Descending");
	printf("\n------------------");
	printf("\nPilih: ");
	scanf("%d", &u);
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if ( u == 1) {
				if (daftar[j].harga > daftar[j + 1].harga) {
					barang temp = daftar[j];
					daftar[j] = daftar[j + 1];
					daftar[j + 1] = temp;
				}
			} else if ( u == 2 ){
				if(daftar[j].harga < daftar[j + 1].harga) {
					barang temp = daftar[j];
					daftar[j] = daftar[j + 1];
					daftar[j + 1] = temp;
				}
			} else { 
				printf("Pilihan Tidak Valid.\n");
				return;
			}
		}
	}
	printf("\n----------------------------------------------------------");	
	printf("\n%-20s | %-12s | %-10s\n", "Nama Barang", "Harga", "Stok");
	printf("----------------------------------------------------------\n");

	for (int i = 0; i < n; i++) {
		printf("%-20s | Rp %-10d | %-10d\n", (daftar + i)->namab, (daftar + i)->harga, (daftar + i)->stok);
	}
	printf("----------------------------------------------------------\n");
}

void EditBarang() {
    barang daftar[100];
    int n = 0;
    char cariNama[50];
    bool found = false;

    FILE *f = fopen("barang.txt", "r");
    if (f == NULL) {
        printf("Data tidak ditemukan!\n");
        return;
    }

    while (fscanf(f, "%[^#]#%d#%d\n", daftar[n].namab, &daftar[n].harga, &daftar[n].stok) != EOF) {
        n++;
    }
    fclose(f);

	printf("\n+--------- Edit Data Barang ---------+\n");
    printf("\nMasukkan Nama Barang yang ingin di-edit: ");
    scanf(" %[^\n]", cariNama);

    for (int i = 0; i < n; i++) {
        if (strcmp(daftar[i].namab, cariNama) == 0) {
            found = true;
            printf("\n--- Data Lama ---");
            printf("\nNama  : %s", daftar[i].namab);
            printf("\nHarga : %d", daftar[i].harga);
            printf("\nStok  : %d", daftar[i].stok);
            printf("\n\n--- Input Data Baru ---");
            printf("\nNama Baru  : "); 
            scanf(" %[^\n]", daftar[i].namab);
            printf("Harga Baru : "); 
            scanf("%d", &daftar[i].harga);
            printf("Stok Baru  : "); 
            scanf("%d", &daftar[i].stok);
            break; 
        }
    }

    if (found) {
        f = fopen("barang.txt", "w");
        for (int i = 0; i < n; i++) {
            fprintf(f, "%s#%d#%d\n", daftar[i].namab, daftar[i].harga, daftar[i].stok);
        }
        fclose(f);
        printf("\nData berhasil diperbarui!\n");
    } else {
        printf("Barang dengan nama '%s' tidak ditemukan.\n", cariNama);
    }
}

void CariBarang() {
    barang daftar[100];
    int n = 0;
    char cariNama[50];
    int metode;

    FILE *f = fopen("barang.txt", "r");
    if (f == NULL) {
        printf("Data barang masih kosong!\n");
        return;
    }
    while (fscanf(f, "%[^#]#%d#%d\n", daftar[n].namab, &daftar[n].harga, &daftar[n].stok) != EOF) {
        n++;
    }
    fclose(f);

    printf("\n------ MENU PENCARIAN BARANG ------");
    printf("\n1. Sequential Search");
    printf("\n2. Binary Search");
    printf("\n-----------------------------------");
    printf("\nPilih metode: "); scanf("%d", &metode);
    printf("Masukkan nama barang yang dicari: "); 
    scanf(" %[^\n]", cariNama);

    if (metode == 1) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (strcmp(daftar[i].namab, cariNama) == 0) {
                printf("\nData Ditemukan (Sequential):");
                printf("\nNama  : %s", daftar[i].namab);
                printf("\nHarga : %d", daftar[i].harga);
                printf("\nStok  : %d\n", daftar[i].stok);
                found = true;
                break;
            }
        }
        if (!found) printf("Barang tidak ditemukan.\n");

    } else if (metode == 2) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (strcmp(daftar[j].namab, daftar[j + 1].namab) > 0) {
                    barang temp = daftar[j];
                    daftar[j] = daftar[j + 1];
                    daftar[j + 1] = temp;
                }
            }
        }

        int awal = 0, akhir = n - 1, tengah;
        bool found = false;
        while (awal <= akhir) {
            tengah = (awal + akhir) / 2;
            int res = strcmp(daftar[tengah].namab, cariNama);

            if (res == 0) {
                printf("\nData Ditemukan (Binary):");
                printf("\nNama  : %s", daftar[tengah].namab);
                printf("\nHarga : %d", daftar[tengah].harga);
                printf("\nStok  : %d\n", daftar[tengah].stok);
                found = true;
                break;
            } else if (res < 0) {
                awal = tengah + 1;
            } else {
                akhir = tengah - 1;
            }
        }
        if (!found) printf("Barang tidak ditemukan.\n");
    } else {
        printf("Pilihan metode tidak valid!\n");
    }
}
			
	
	
	
