#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>

struct data{
	char tanggal[11];
	char nama[40];
	char jenis[30];
	char buku[50];
	int jumlah;
	int harga;
	int total;
};


void tambah_data(){
	FILE *fptr;
	fptr = fopen("sales.txt", "a");
	if(fptr==NULL){
		printf("Belum ada data!");
	}
	int banyak;
	
	printf("========================================\n");
	printf("| Menambah Data Laporan Penjualan Buku |");
	printf("\n========================================\n");
	
	printf("\nJumlah laporan penjualan buku yang ingin anda masukkan: ");
	scanf("%d", &banyak);
	struct data dt[banyak];
	
	for(int i=0; i<banyak; i++){
	    printf("\nLaporan Penjualan Buku ke-%d\n", i+1);
	    printf("Tanggal Transaksi [YYYY/MM/DD]: ");
    	scanf("%s", dt[i].tanggal);
    	printf("Nama Pelanggan: ");
    	getchar();
    	scanf("%s", dt[i].nama);
    	printf("Jenis Buku: ");
    	scanf("%s", dt[i].jenis);
    	printf("Nama Buku: ");
    	getchar();
    	scanf("%s", dt[i].buku);
    	printf("Jumlah Buku: ");
    	scanf("%d", &dt[i].jumlah);
    	printf("Harga Buku: ");
    	scanf("%d", &dt[i].harga);
    	
    	dt[i].total = dt[i].jumlah * dt[i].harga;
    	
    	fprintf(fptr,"\n%s %s %s %s %d %d %d", dt[i].tanggal, dt[i].nama, dt[i].jenis, dt[i].buku, dt[i].jumlah, dt[i].harga, dt[i].total);
	}
	fclose(fptr);
	printf("\nBerhasil menambahkan data.\n\n");
}

void urut_tanggal(){
	FILE *fptr;
	fptr = fopen("sales.txt", "r");
	if(fptr == NULL){
		printf("Belum ada data!\n");
		exit(1);
	}
	int N = sizeof(struct data);
	struct data dt[N], temp;
	
	printf("========================================================\n");
	printf("| Laporan Penjualan Buku Berdasarkan Tanggal Transaksi |");
	printf("\n========================================================\n\n");
	
	int i=0, count = 0;
	while(!feof(fptr)){
	    fscanf(fptr,"%s %s %s %s %d %d %d", dt[i].tanggal, dt[i].nama, dt[i].jenis, dt[i].buku, &dt[i].jumlah, &dt[i].harga, &dt[i].total);
		i++;
		count++;
	}

	for(int i=0; i<count; i++){
		for(int j=i+1; j<count; j++){
			if(strcmp(dt[i].tanggal,dt[j].tanggal)<0){
				temp = dt[i];
				dt[i] = dt[j];
				dt[j] = temp;
			}
		}
	}
	
	printf("==========================================================================================================================================================================================================\n");
	printf("| %-4s| %-20s | %-40s| %-30s| %-50s| %-12s| %-11s| %-17s|\n", "No.", "Tanggal [YYYY/MM/DD]", "Nama Pelanggan", "Jenis Buku", "Nama Buku", "Jumlah Buku", "Harga Buku", "Total Pembayaran");
	printf("==========================================================================================================================================================================================================\n");
	for(int i=0; i<count; i++){
		printf("| %-4d| %-20s | %-40s| %-30s| %-50s| %-12d| Rp %-11d| Rp %-11d|\n", i+1, dt[i].tanggal, dt[i].nama, dt[i].jenis, dt[i].buku, dt[i].jumlah, dt[i].harga, dt[i].total);
	}
	printf("==========================================================================================================================================================================================================\n");
	fclose(fptr);
}

void urut_terbanyak(){
	FILE *fptr;
	fptr = fopen("sales.txt", "r");
	if(fptr == NULL){
		printf("Belum ada data!\n");
		exit(1);
	}
	int N = sizeof(struct data);
	struct data dt[N], temp;
	
	printf("========================================================================\n");
	printf("| Laporan Penjualan Buku Berdasarkan Produk Yang Terjual Paling Banyak |");
	printf("\n========================================================================\n\n");
	
	int i=0, count = 0;
	while(!feof(fptr)){
	    fscanf(fptr,"%s %s %s %s %d %d %d", dt[i].tanggal, dt[i].nama, dt[i].jenis, dt[i].buku, &dt[i].jumlah, &dt[i].harga, &dt[i].total);
		i++;
		count++;
	}
	
	for(int i=0; i<count; i++){
		for(int j=i+1; j<count; j++){
			if(dt[i].jumlah < dt[j].jumlah){
				temp = dt[i];
				dt[i] = dt[j];
				dt[j] = temp;
			}
		}
	}
	
	printf("==========================================================================================================================================================================================================\n");
	printf("| %-4s| %-20s | %-40s| %-30s| %-50s| %-12s| %-11s| %-17s|\n", "No.", "Tanggal [YYYY/MM/DD]", "Nama Pelanggan", "Jenis Buku", "Nama Buku", "Jumlah Buku", "Harga Buku", "Total Pembayaran");
	printf("==========================================================================================================================================================================================================\n");
	for(int i=0; i<count; i++){
		printf("| %-4d| %-20s | %-40s| %-30s| %-50s| %-12d| Rp %-11d| Rp %-11d|\n", i+1, dt[i].tanggal, dt[i].nama, dt[i].jenis, dt[i].buku, dt[i].jumlah, dt[i].harga, dt[i].total);
	}
	printf("==========================================================================================================================================================================================================\n");
	fclose(fptr);
}

int main(){
	menu:
	printf("===========================================\n");
	printf("| Laporan Penjualan Planet of Book Store |");
	printf("\n===========================================\n");
	
	printf("\n1. Menambah data laporan penjualan buku\n");
	printf("2. Mencetak laporan penjualan buku berdasarkan tanggal transaksi\n");
	printf("3. Mencetak laporan penjualan buku berdasarkan produk yang terjual paling banyak\n");
	printf("4. Exit\n");
	
	
	int pilihan;
	printf("\nPilihan Anda: ");
	scanf("%d", &pilihan);
	
	printf("\n");
	
	switch(pilihan){
		case 1:
			system("cls");
			tambah_data();
			goto menu;
			
		case 2:
			system("cls");
			urut_tanggal();
			printf("\n");
			system("pause");
			goto menu;
			
		case 3:
			system("cls");
			urut_terbanyak();
			printf("\n");
			system("pause");
			goto menu;
						
		case 4:
			system("cls");
			printf("Data anda telah disimpan. Terima kasih.\n");
	}
	
	return 0;
}
