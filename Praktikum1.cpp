//Nama : Ahmad Sofian Aris S
//NPM : 21081010211
//Kelas : E081
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <windows.h>

	//Struct dan Semua Data yang akan dipakai
	typedef struct Vaksinasi{
	char *nama_kota, *nama_provinsi;
	int jumlah_penduduk, jumlah_lansia, penduduk_vaksin, lansia_vaksin;
	int level;
}v; 


//Memasukan Data Penduduk
void DataPenduduk(struct Vaksinasi* v){
	v[0].nama_kota = "Gresik";
	v[0].nama_provinsi = "Jawa Timur";
	v[0].jumlah_penduduk = 10000;
	v[0].jumlah_lansia = 4000;
	v[0].penduduk_vaksin = 8450;
	v[0].lansia_vaksin = 1201;
	
	v[1].nama_kota = "Depok";
	v[1].nama_provinsi = "Jawa Barat";
	v[1].jumlah_penduduk = 9500;
	v[1].jumlah_lansia = 2000;
	v[1].penduduk_vaksin = 6700;
	v[1].lansia_vaksin = 1700;
	
	v[2].nama_kota = "Surakarta";
	v[2].nama_provinsi = "Jawa Tengah";
	v[2].jumlah_penduduk = 11000;
	v[2].jumlah_lansia = 5200;
	v[2].penduduk_vaksin = 10000;
	v[2].lansia_vaksin = 5000;
	
	v[3].nama_kota = "Pontianak";
	v[3].nama_provinsi = "Kalimantan Barat";
	v[3].jumlah_penduduk = 15000;
	v[3].jumlah_lansia = 7000;
	v[3].penduduk_vaksin = 1500;
	v[3].lansia_vaksin = 2000;
	
	v[4].nama_kota = "Batu";
	v[4].nama_provinsi = "Jawa Timur";
	v[4].jumlah_penduduk = 13540;
	v[4].jumlah_lansia = 7850;
	v[4].penduduk_vaksin = 3540;
	v[4].lansia_vaksin = 2540;
	
	v[5].nama_kota = "Brebes";
	v[5].nama_provinsi = "Jawa Tengah";
	v[5].jumlah_penduduk = 19018;
	v[5].jumlah_lansia = 2715;
	v[5].penduduk_vaksin = 15426;
	v[5].lansia_vaksin = 1541;
	
	v[6].nama_kota = "Bondowoso";
	v[6].nama_provinsi = "Jawa Timur";
	v[6].jumlah_penduduk = 17465;
	v[6].jumlah_lansia = 10005;
	v[6].penduduk_vaksin = 14582;
	v[6].lansia_vaksin = 7456;
	
	v[7].nama_kota = "Bojonegoro";
	v[7].nama_provinsi = "Jawa Timur";
	v[7].jumlah_penduduk = 13578;
	v[7].jumlah_lansia = 7012;
	v[7].penduduk_vaksin = 3540;
	v[7].lansia_vaksin = 3521;
	
	v[8].nama_kota = "Subang";
	v[8].nama_provinsi = "Jawa Barat";
	v[8].jumlah_penduduk = 20125;
	v[8].jumlah_lansia = 12544;
	v[8].penduduk_vaksin = 16253;
	v[8].lansia_vaksin = 10214;
	
	v[9].nama_kota = "Garut";
	v[9].nama_provinsi = "Jawa Barat";
	v[9].jumlah_penduduk = 25412;
	v[9].jumlah_lansia = 10214;
	v[9].penduduk_vaksin = 20658;
	v[9].lansia_vaksin = 5142;
}

int main(){
	Vaksinasi v[10];
	DataPenduduk(v);
	int a, x;

	do{
	//Menampilkan Menu Pilihan
	printf ("Program Level PPKM\n");
	printf ("=====================\n");
	printf ("1. Tampilkan Data Dari 10 Kota\n");
	printf ("2. Tampilkan Level PPKM Kota\n");
	printf ("3. Urutkan Data\n");
	printf ("==================================\n");
	printf ("Masukkan pilihan: ");
	scanf ("%i", &x);
	
	switch (x){
		case 1:
			//Menampilkan Data Yang Telah Dimasukan
			printf ("======================================================================================================================\n");
			printf ("|Nama Kota|\t\t|Provinsi|\t\t|Penduduk|\t|Lansia|\t|Total Vaksinasi|\t|Vaksinasi Lansia|\n");
			printf ("======================================================================================================================\n");
			for(a=0; a<10; a++){
				printf ("%d. %s\t\t %s \t\t%.0f\t\t%.0f\t\t%.0f\t\t\t%.0f\n", a+1, v[a].nama_kota, v[a].nama_provinsi, v[a].jumlah_penduduk, v[a].jumlah_lansia, v[a].penduduk_vaksin, v[a].lansia_vaksin);
			}
			printf ("======================================================================================================================\n");
	break;
	
		case 2:
			//Rumus Level PPKM 
			int hasil_peduduk[10];
			int i, j;
				for(i=0;i<10;i++)
				{
					hasil_peduduk[i] = v[i].penduduk_vaksin / v[i].jumlah_penduduk;
					hasil_peduduk[i] = hasil_peduduk[i] * 100;
				}
			
				int hasil_lansia[10];
				for(i=0;i<10;i++)
				{
					hasil_lansia[i] = v[i].lansia_vaksin / v[i].jumlah_lansia;
					hasil_lansia[i] = hasil_lansia[i] * 100;
				}
				
				for(i=0;i<10;i++){
					if((hasil_peduduk[i] >= 70) && (hasil_lansia[i] > 60)){
						v[i].level=1;
					}
					else if((hasil_peduduk[i] >= 50) && (hasil_lansia[i] < 70)){
						v[i].level=2;
					}
					else{
						v[i].level=3;
					}
				}	
				
				printf ("==========================================\n");
				printf ("Nama Kota\tLevel PPKM\n");
				printf ("==========================================\n");
				for (int i=0; i<10; i++){
					printf ("%s\t\tLevel-%.0f\n", v[i].nama_kota, v[i].level);
				}
				printf ("==========================================\n\n");
	break;
	
		case 3:
			int min=0;
			
			Vaksinasi temp;
			for (i=0; i<10; i++){
					min = i;
					
					for (j = i; j<10; j++){
						if(v[min].level > v[j].level){
							min = j;
						}
					}
					temp = v[i];
					v[i] = v[min];
					v[min] = temp;
				}
			
				printf ("==========================================\n");
				printf ("Nama Kota\tLevel PPKM\n");
				printf ("==========================================\n");
				for (int i=0; i<10; i++){
					printf ("%s\t\tLevel-%.0f\n", v[i].nama_kota, v[i].level);
				}
				printf ("==========================================\n\n");
	break;
	}

}while (x!=3);
return 0;
}
