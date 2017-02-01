#ifndef KEPALA_FUNGSI_H_INCLUDED
#define KEPALA_FUNGSI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define maks 100

/// BARISAN ADT
typedef struct{
    int D; ///HARI
    int M; ///BULAN
    int Y; ///TAHUN
}Date;

typedef struct{
    int h; ///JAM
    int m; ///MENIT
}Time;

typedef struct{
    char member[maks];
}Anggota;

typedef struct fitur{
    char nama[maks];        ///INPUTAN NAMA KEGIATAN
    char tempat[maks];      ///INPUTAN TEMPAT KEGIATAN
    Time waktu;             ///INPUTAN WAKTU KEGIATAN
    Date tgl;               ///INPUTAN TANGGAL KEGIATAN
    int jmlhmember;         ///SEBAGAI BANYAK MEMBER YANG IKUT
    Anggota member[maks];   ///INPUTAN ORANG YANG TELIBAT DALAM KEGIATAN
}Add;

///BARISAN FUNGSI
void swapstruct(Add *a,Add *b);
int tglbenar(int D,int M,int Y);
int wktbenar(int H,int M);
void input(Add data[],int *idx);
void hapus(Add data[],int *batas,int idx);
int carinama(Add data[],char nama[],int batas);
int caritgl(Add data[],int batas,int D,int M,int Y);
void tampilkansemua(Add data[],int idx);
void tampilkan(Add data[],int idx);
void uruttgl(Add data[],int idx);
void urutnama(Add data[],int idx);
void SaveAsFile(Add data[],int idx);

#endif // KEPALA_FUNGSI_H_INCLUDED
