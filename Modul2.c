/*Program kalkulator modul 2 Uro
Nama : Ar Ryan Shifa Izzati
NIM : 13219026
Hari dan tanggal : Minggu, 28 Maret 2020*/
#include<stdio.h>
#include<math.h>
float b , operator, hasil;
char c;
int d;

float bawah,atas,lebar,luas;

float riemankanan(float bawah, float lebar, float atas, float rumus,float pembilang, float penyebut, float x,float sisi1,float sisi2);
float riemankanan(float bawah, float lebar, float atas,float rumus, float pembilang, float penyebut, float x,float sisi1,float sisi2){
    x = bawah + lebar; 
    if(x > atas){
        pembilang = (10 * bawah * bawah) - (7 * bawah * sin(bawah));
        penyebut = (bawah*bawah) + bawah + 1 ;
        sisi1 = pembilang/penyebut; //Nilai bawah fungsi
        pembilang = (10 * atas * atas) - (7 * atas * sin(atas));
        penyebut = (atas*atas) + atas + 1 ;
        sisi2 = pembilang/penyebut; // Nilai atas fungsi
        rumus = ((sisi1 + sisi2) * (atas - bawah))/2;//kalau nilai delta nya udah lebih dari atas, berarti tinggi trapesiumnya atas - bawah
        return(rumus);
    }else{
        pembilang = (10 * bawah * bawah) - (7 * bawah * sin(bawah));
        penyebut = (bawah*bawah) + bawah + 1 ;
        sisi1 = pembilang/penyebut;
        pembilang = (10 * x * x) - (7 * x * sin(x));
        penyebut = (x*x) + x + 1 ;
        sisi2 = pembilang/penyebut;
        rumus = ((sisi1 + sisi2) * lebar)/2;
        return(rumus + riemankanan(x,lebar,atas,0,0,0,0,0,0)); //nilai bawah selalu berubah sebagai perhitungan maju
    }
}

float penjumlahan(float a, float b);
float penjumlahan(float a, float b){
    printf("Hasilnya adalah : %0.3f \n",(a + b));
    return(a+b);
}
float pengurangan(float a, float b);
float pengurangan(float a, float b){
    printf("Hasilnya adalah : %0.3f \n",(a - b));
    return(a-b);
}
float pembagian(float a, float b);
float pembagian(float a, float b){
    printf("Hasilnya adalah : %0.3f \n",(a / b));
    return(a/b);
}
float perkalian(float a, float b);
float perkalian(float a, float b){
    printf("Hasilnya adalah : %0.3f \n",(a * b));
    return(a*b);
}
float pangkat(float a, float b);
float pangkat(float a, float b){
    if (b < 1){
      return(1);
    }
    else{
      return(a * pangkat(a,(b-1)));
    }
}
int main()
{   
    c = 'Y'; //Faktor untuk keluar dari perulangan
    hasil = 0; // Nilai agar tetap berlanjut untuk setiap saat
    printf("Apakah ingin menggunakan kalkulator? (Y/N) \n");
    scanf("%c", &c);
    while (c == 'Y')
    {
      printf("Masukkan angka untuk operasi yang diinginkan (a (default = 0) <operator> b):\n");
      printf("1. Penjumlahann \n");
      printf("2. Pengurangan\n");
      printf("3. Perkalian\n");
      printf("4. Pembagian\n");
      printf("5. Pangkat\n");
      printf("6. Integral dari fungsi ((10 * x * x) - (7 * x * sin(x))) : (x*x + x + 1) \n");
      scanf("%f", &operator ); //Menentukan jenis operator yang dipilih, proses kalkulasi yaitu hasil akhir <operator> b
      if (operator == 1)
      {
        printf("Masukkan nilai penjumlahan (b) \n");
        scanf("\n %f", &b );
        hasil = penjumlahan(hasil,b);
      }
      else if (operator == 2)
      {
        printf("Masukkan nilai pengurangan (b)\n");
        scanf("\n %f", &b );
        hasil = pengurangan(hasil,b);
      }
      else if (operator == 3)
      {
        printf("Masukkan nilai perkalian (b) \n");
        scanf("\n %f", &b );
        hasil = perkalian(hasil,b);
      }
      else if (operator == 4)
      {
        printf("Masukkan nilai pembagian (b) \n");
        scanf("\n %f", &b );
        hasil = pembagian(hasil,b);
      }
      else if (operator == 5)
      {
        printf("Masukkan nilai pangkat (b) \n");
        scanf("\n %f", &b );
        hasil = pangkat(hasil,b);
        printf("Hasilnya adalah : %0.3f \n",hasil);
      }
      else if (operator == 6)
      {
        printf("Masukkan Batas Bawah: ");
        scanf("%f",&bawah);
        printf("Masukkan Batas Atas: ");
        scanf("%f",&atas);
        printf("Masukkan Lebar Partisi: ");
        scanf("%f",&lebar);
        luas = riemankanan(bawah,lebar,atas,0,0,0,0,0,0);
        printf("Jumlah riemann trapesium dari fungsi tersebut dengan batas bawah %0.3f dan atas %0.3f adalah: %0.3f\n",bawah,atas,luas);
      }
      else{
        printf("Salah Masukan \n");
      }

      printf("Apakah ingin melanjutkan?\nMasukkan angka untuk :\n");
      printf("1. Y  2. N \n");
      scanf("%d", &d); //Sebagai faktor keluar dari loop dengan merubah nilai c
      if (d == 1)
      {
       c = 'Y';   
      }
      else{
        c = 'N';
      }



      
      

    }
    printf("Terimakasih Telah Menggunakan Kalkulator:)\n");
    
} 