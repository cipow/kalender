#include "kepala_fungsi.h"

int main()
{
    ///DEKALARASI FUNGSI
    Add event[100];
    int pilih,idx,menu,idxcari;
    idx=0;          ///INDEX INPUT DAN BANYAKNYA DATA
    int D,M,Y;      ///UNTUK MENCARI KEGIATAN DENGAN TGL BLN THN
    char yes;       ///SEBAGAI PILIHAN SAAT AKAN MENGHAPUS DATA
    char cari[50];  ///UNTUK MENCARI KEGIATAN DENGAN NAMA KEGIATAN


    ///MENU UTAMA
    ulangi:system("cls"); ///MENGULANGI INPUTAN MENU DAN MENGHAPUS LAYOUT AGAR TIDAK BERTUMPUKKAN
    printf("\t\tKALENDER KEGIATAN\n");
    printf("\t\t-------- --------\n\n");
    printf("1. Tambah\n2. Cari\n3. Hapus\n4. Tampilkan\n5. Simpan di File\n6. Keluar\n\n");
    do{
        printf("Memilih menu: ");
        scanf("%d",&pilih);
    }while(pilih<1 || pilih>6);
    fflush(stdin);
    switch(pilih)
    {
    case 1:
        input(event,&idx);
        goto ulangi; ///KE MENU UTAMA
        break;
    case 2:
        printf("\tBerdasarkan \n\t1.nama \n\t2.tgl\n");
        do{
            printf("\tpilih: ");
            scanf("%d",&menu);
        }while(menu<1 || menu>2);
        fflush(stdin);
        switch(menu)
        {
        case 1:
            printf("\tMasukkan nama kegiatan: ");
            gets(cari);
            idxcari=carinama(event,cari,idx);
            if(idxcari!=(-1))
            {
                printf("\n");tampilkan(event,idxcari);
            }
            else
            {
                printf("\n\t MAAF.. DATA YANG ANDA CARI TIDAK ADA....\n");
            }
            break;
        case 2:
            printf("\tMasukkan tgl bln thn: ");
            scanf("%d %d %d",&D,&M,&Y);
            idxcari=caritgl(event,idx,D,M,Y);
            if(idxcari!=(-1))
            {
                printf("\n");tampilkan(event,idxcari);
            }
            else
            {
                printf("\n\t MAAF.. DATA YANG ANDA CARI TIDAK ADA....\n");
            }
            break;
        }
        printf("\n\t");system("pause");
        goto ulangi; ///KE MENU UTAMA
        break;
    case 3:
        printf("\tCari kegiatan yang akan dihapus\n");
        printf("\tBerdasarkan \n\t1.nama \n\t2.tgl\n");
        do{
            printf("\tpilih: ");
            scanf("%d",&menu);
        }while(menu<1 || menu>2);
        fflush(stdin);
        switch(menu)
        {
        case 1:
            printf("\tMasukkan nama kegiatan: ");
            gets(cari);
            idxcari=carinama(event,cari,idx);
            if(idxcari!=(-1))
            {
                printf("\n");tampilkan(event,idxcari);
                printf("\n\tHapus kegiatan [y | other]: ");
                fflush(stdin);
                scanf("%c",&yes);
                if(yes=='y')
                {
                    hapus(event,&idx,idxcari);
                    printf("\tKegiatan Di HAPUS......");
                }
                else
                {
                    printf("\tKegiatan Tidak DIHAPUS......");
                }
            }
            else
            {
                printf("\n\t MAAF.. DATA YANG ANDA CARI TIDAK ADA....\n");
            }
            break;
        case 2:
            printf("\tMasukkan tgl bln thn: ");
            scanf("%d %d %d",&D,&M,&Y);
            idxcari=caritgl(event,idx,D,M,Y);
            if(idxcari!=(-1))
            {
                printf("\n");tampilkan(event,idxcari);
                printf("\n\tHapus kegiatan [y | other]: ");
                fflush(stdin);
                scanf("%c",&yes);
                if(yes=='y')
                {
                    hapus(event,&idx,idxcari);
                    printf("\tKegiatan Di HAPUS......");
                }
                else
                {
                    printf("\tKegiatan Tidak DIHAPUS......");
                }
            }
            else
            {
                printf("\n\t MAAF.. DATA YANG ANDA CARI TIDAK ADA....\n");
            }
            break;
        }
        printf("\n\n\t");system("pause");
        goto ulangi; ///KE MENU UTAMA
        break;
    case 4:
        printf("\tBerdasarkan \n\t1.nama \n\t2.tgl\n");
        do{
            printf("\tpilih: ");
            scanf("%d",&menu);
        }while(menu<1 || menu>2);
        switch(menu)
        {
        case 1:
            urutnama(event,idx);
            tampilkansemua(event,idx);
            break;
        case 2:
            uruttgl(event,idx);
            tampilkansemua(event,idx);
            break;
        }
        printf("\n\t");system("pause");
        goto ulangi; ///KE MENU UTAMA
        break;
    case 5:
        printf("\tSimpan file [y | other]: ");
        scanf("%c",&yes);
        if(yes=='y')
        {
            SaveAsFile(event,idx);
            printf("\n\tDATA kegiatan di simpan di Kalender_Kegiatan.txt\n");
        }else
        {
            printf("\n\tDATA kegiatan tidak dihapus\n");
        }
        printf("\t");system("pause");
        goto ulangi; ///KE MENU UTAMA
        break;
    case 6:
        printf("\n\tTERIMA KASIH TELAH MENGGUNAKAN APLIKASI INI\n\n");
        printf("\t");system("pause");
        break;
    }
    return 0;
}
