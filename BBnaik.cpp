/* Program   : BBnaik.c */
/* Deskripsi : membuat program untuk meningkatkan berat badan dan menampilkannya di layar
/* NIM/Nama  : 24060119130095/Anjar Asmarani*/
/* Tanggal   : 18 Desember 2020*/

#include <stdio.h>

int main() 
{
	int bb;
	int hari;
	int jenis_makanan; 
	int daftar_makanan[100];
	int temp[100];
	int i, j;
	int kalori;
	int total_makanan = 1;
	int tmp;
	int penuh;
	
	printf("++++++++++PROGRAM PENINGKATAN BERAT BADAN++++++++++");
	printf("\nApa makanan tambahanmu?");
	
	//masukan jumlah makanan yang ada
	printf("\n\nMasukkan berapa jenis makanan yang ada: ");
	scanf("%d", &jenis_makanan);
	
	//masukan nilai kalori setiap jenis makanan
	printf("\nMasukkan nilai kalori dari masing-masing makanan:\n");
	for(i = 1; i <= jenis_makanan; i++){
		scanf("%d", &daftar_makanan[i]);
	}
	
	//mengurutkan kalori dari yang terbesar ke kecil
	for(i = 1; i < jenis_makanan; i++){
		for(j = i + 1; j <= jenis_makanan; j++){
			if(daftar_makanan[i] < daftar_makanan[j]){
				tmp = daftar_makanan[i];
				daftar_makanan[i] = daftar_makanan[j];
				daftar_makanan[j] = tmp;
			}
		}
	}
		
	//masukan berat badan yang ingin dinaikkan
	printf("\nBerat badan yang ingin ditingkatkan (dalam kg): ");
	scanf("%d", &bb);
	
	//masukan lama hari yang dibutuhkan
	printf("\nLama waktu yang dibutuhkan (dalam hari): ");
	scanf("%d", &hari);
	
	//menghitung jumlah makanan per jenisnya yang harus dikonsumsi dalam sehari
	kalori = bb * 7000 / hari; 
    for(i = 1; i <= jenis_makanan; i++){
		temp[i] = kalori / daftar_makanan[i];
		kalori = kalori % daftar_makanan[i];
		total_makanan += temp[i];
	}
	
	//mencetak jumlah makanan yang harus dikonsumsi
	printf("\nJumlah makanan tambahan yang harus dikonsumsi per hari: %d", total_makanan-1);
	
	//mencetak perincian jenis makanan beserta jumlahnya
	for(i = 1; i <= jenis_makanan; i++){
		printf("\nMakanan dengan kalori %d kal = %d buah", daftar_makanan[i], temp[i]);
	}
	
	//mencetak bagaimana pemenuhan kalori dengan makanan yang dipilih
	for(i = 1; i <= jenis_makanan; i++){
		penuh += daftar_makanan[i] * temp[i];
	}
	if(penuh == bb * 7000 / hari){
		printf("\n\nDengan pilihan makanan tambahan tersebut, kalori Anda hari ini akan terpenuhi sempurna :)");
	}
	else{
		printf("\n\nDengan pilihan makanan tambahan tersebut, kalori Anda hari ini belum terpenuhi sempurna, tetapi tidak berlebihan :)");
	}
	
	printf("\n\nSemoga mendapatkan berat badan yang Anda ingin dalam %d hari :D", hari);	

	return 0;
}
