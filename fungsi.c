#include "kepala_fungsi.h"
/*MENUKAR NILAI DALAM STRUCT*/
void swapstruct(Add *a,Add *b)
{
    Add x;
    x=*a;
    *a=*b;
    *b=x;
}
/*MENGECEK INPUTAN TANGGAL YANG BENAR */
int tglbenar(int D,int M,int Y)
{
    int benar=0;
    if(Y>0)
    {
        if(M>0 && M<=12)
        {
            if(M==2)
            {
                if(Y%4==0)
                {
                    if(D>0 && D<=28)
                    {
                        benar=1;
                    }
                }
                else
                {
                    if(D>0 && D<=29)
                    {
                        benar=1;
                    }
                }

            }
            else if(M==4 || M==6 || M==9 || M==11)
            {
                if(D>0 && D<=30)
                {
                    benar=1;
                }
            }
            else
            {
                if(D>0 && D<=31)
                {
                    benar=1;
                }
            }
        }
    }
    return benar;
}
/*MENGECEK WAKTU YANG BENAR*/
int wktbenar(int H,int M)
{
    int benar=0;
    if(H>=0 && H<=23)
    {
        if(M>=0 && M<60)
        {
            benar=1;
        }
    }
    return benar;
}
/*INPUT KEGIATAN BARU*/
void input(Add data[],int *idx)
{
    int i;
    printf("\tInput nama kegiatan  : ");gets(data[*idx].nama);
    strlwr(data[*idx].nama);
    printf("\tInput Tempat kegiatan: ");gets(data[*idx].tempat);
    do{
        printf("\tInput Tgl Bln Thn    : ");scanf("%d %d %d",&data[*idx].tgl.D,&data[*idx].tgl.M,&data[*idx].tgl.Y);
    }while(tglbenar(data[*idx].tgl.D,data[*idx].tgl.M,data[*idx].tgl.Y)==0);
    do{
        printf("\tInput Jam Menit      : ");scanf("%d %d",&data[*idx].waktu.h,&data[*idx].waktu.m);
    }while(wktbenar(data[*idx].waktu.h,data[*idx].waktu.m)==0);
    printf("\tBanyak orang yang ikut   : ");scanf("%d",&data[*idx].jmlhmember);
    fflush(stdin);
    for(i=0;i<data[*idx].jmlhmember;i++)
    {
        printf("\t\t  %d. ",i+1);
        gets(data[*idx].member[i].member);
    }
    *idx+=1; //MENAMBAH BANYAK DATA
}
/*MENAMPILKAN SEMUA KEGIATAN*/
void tampilkansemua(Add data[],int idx)
{
    int i,j;
    char bulan[12][12]={"Jan","Feb","Mar","Apr","Mei","Jun","Jul","Ags","Sep","Okt","Nov","Des"};
    for(i=0;i<idx;i++)
    {
        printf("\t%d. Nama kegiatan  : %s\n",i+1,data[i].nama);
        printf("\t   Tempat kegiatan: %s\n",data[i].tempat);
        printf("\t   Tgl kegiatan   : %d %s %d\n",data[i].tgl.D,bulan[data[i].tgl.M-1],data[i].tgl.Y);
        printf("\t   Waktu          : %d:%d\n",data[i].waktu.h,data[i].waktu.m);
        printf("\t   Orang yang terlibat\n");
        if(data[i].jmlhmember==0)
        {
            printf("\t\t  Tidak ada orang yang terlibat\n\n");
        }
        else
        {
            for(j=0;j<data[i].jmlhmember;j++)
            {
                printf("\t\t   %d. %s\n",j+1,data[i].member[j].member);
            }
        }
    }
}
/*MENAMPILKAN KEGIATAN YANG DICARI*/
void tampilkan(Add data[],int idx)
{
    int j;
    char bulan[12][12]={"Jan","Feb","Mar","Apr","Mei","Jun","Jul","Ags","Sep","Okt","Nov","Des"};
    printf("\t%d. Nama kegiatan  : %s\n",idx+1,data[idx].nama);
    printf("\t   Tempat kegiatan: %s\n",data[idx].tempat);
    printf("\t   Tgl kegiatan   : %d %s %d\n",data[idx].tgl.D,bulan[data[idx].tgl.M-1],data[idx].tgl.Y);
    printf("\t   Waktu          : %d:%d\n",data[idx].waktu.h,data[idx].waktu.m);
    printf("\t   Orang yang terlibat\n");
    if(data[idx].jmlhmember==0)
    {
        printf("\t\tTidak ada orang yang terlibat\n");
    }
    else
    {
        for(j=0;j<data[idx].jmlhmember;j++)
        {
            printf("\t\t     %d. %s\n",j+1,data[idx].member[j].member);
        }
    }
}
/* MENGHAPUS DATA */
void hapus(Add data[],int *batas,int idx)
{
    int i;
    *batas-=1;
    for(i=idx;i<*batas;i++)
    {
        data[i]=data[i+1];
    }
}
/*MENCARI KEGIATAN BERDASARKAN NAMA*/
int carinama(Add data[],char nama[],int batas)
{
    int i;
    strlwr(nama);
    for(i=0;i<batas;i++)
    {
        if(strcmp(data[i].nama,nama)==0)
            break;
    }
    if(i<batas)
        return i;
    else
        return -1;
}
/*MENCARI KEGIATAN BERDASARKAN TANGGAL*/
int caritgl(Add data[],int batas,int D,int M,int Y)
{
    int i;
    for(i=0;i<batas;i++)
    {
        if(data[i].tgl.D==D && data[i].tgl.M==M && data[i].tgl.Y==Y)
            break;
    }
    if(i<batas)
        return i;
    else
        return -1;
}
/*MENGURUTKAN KEGIATAN SESUAI TANGGAL TERKECIL KE BESAR*/
void uruttgl(Add data[],int idx)
{
    int i,j;
    ///MENGGUNAKAN BUBBLE SORT
    for(i=0;i<idx-1;i++)
    {
        for(j=0;j<idx-1;j++)
        {
            if(data[j+1].tgl.D<data[j].tgl.D && data[j+1].tgl.M<=data[j].tgl.M && data[j+1].tgl.Y<=data[j].tgl.Y)
            {
                swapstruct(&data[j],&data[j+1]);
            }
            else if(data[j+1].tgl.D<=data[j].tgl.D && data[j+1].tgl.M<data[j].tgl.M && data[j+1].tgl.Y<=data[j].tgl.Y)
            {
                swapstruct(&data[j],&data[j+1]);
            }
            else if(data[j+1].tgl.D<=data[j].tgl.D && data[j+1].tgl.M<= data[j].tgl.M && data[j+1].tgl.Y<data[j].tgl.Y)
            {
                swapstruct(&data[j],&data[j+1]);
            }
        }
    }
}
void urutnama(Add data[],int idx)
{
    int i,j;
    ///MENGGUNAKAN BUBBLE SORT
    for(i=0;i<idx-1;i++)
    {
        for(j=0;j<idx-1;j++)
        {
            if(strcmp(data[j+1].nama,data[j].nama)<0)
            {
                swapstruct(&data[j],&data[j+1]);
            }
        }
    }
}
/*MENYIMPAN DATA KEGIATAN KE SEBAUAH FILE*/
void SaveAsFile(Add data[],int idx)
{
    FILE* f;
    int i,j;
    time_t waktu;time(&waktu);
    f=fopen("Kalender_Kegiatan.txt","a");
    fprintf(f,"============ Disimpan pada %s\n",ctime(&waktu));
    for(i=0;i<idx;i++)
    {
        fprintf(f,"%d. Nama kegiatan  : %s\n",i+1,data[i].nama);
        fprintf(f,"   Tempat kegiatan: %s\n",data[i].tempat);
        fprintf(f,"   Tgl kegiatan   : %d-%d-%d\n",data[i].tgl.D,data[i].tgl.M,data[i].tgl.Y);
        fprintf(f,"   Waktu          : %d:%d\n",data[i].waktu.h,data[i].waktu.m);
        fprintf(f,"   Orang yang terlibat\n");
        if(data[i].jmlhmember==0)
        {
            fprintf(f,"\tTidak ada orang yang terlibat\n\n");
        }
        else
        {
            for(j=0;j<data[i].jmlhmember;j++)
            {
                fprintf(f,"\t     %d. %s\n",j+1,data[i].member[j].member);
            }
        }
        fprintf(f,"\n");
    }
    fclose(f);
}
