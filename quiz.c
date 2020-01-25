#include <stdio.h>
#include <string.h>
#include <windows.h>

int chance = 20;
time_t seconds;

int main() {
    mulai();
}

int random_number(int min_num, int max_num) {
    //from http://stackoverflow.com/users/90848/laurence-gonsalves

    int result=0,low_num=0,hi_num=0;
    if(min_num<max_num) {
        low_num=min_num;
        hi_num=max_num+1; // this is done to include max_num in output.
    }else{
        low_num=max_num+1;// this is done to include max_num in output.
        hi_num=min_num;
    }
        srand( time(seconds) * (time(seconds) * 60) );
        result = (rand()%(hi_num-low_num))+low_num;
        return result;
}

void jawab(int** number[128], char** pertanyaan, char** jawaban_asli) {
    char jawaban_user[128];
    int a;

    do {
        printf("%s\n Jawaban Anda: ", pertanyaan);
        gets(jawaban_user); fflush(stdin);
        jawaban(number, jawaban_user, jawaban_asli);
    } while(a=0);
}

void jawaban(char** number[128],char jawaban_user[128], char** jawaban_asli[128]) {
    char lastch;
    int a;

    do {
        printf("Apa Anda yakin jawaban Anda ini: benar? [masukkan y jika yakin, dan tombol lainnya jika tidak yakin]: ");
        scanf("%c", &lastch); fflush(stdin);

        switch(lastch) {
        case 'y':

            if(strcmp(jawaban_asli, jawaban_user)==0) {
                printf("Anda benar!!!...");
            getch();
            mulai();
            } else {
                chance--;
                printf("Anda salah!!! Kesempatan Anda %d lagi...", chance);

            }

        break;
        default:
                printf("Anda rupanya tidak yakin.\nKembali ke pertanyaan...");
                getch();
                materi(number);
                break;
        }

    } while (a=0);
}

void mulai() {
    materi(random_number(1,3));
}

void materi(int questions) {

    switch(questions) {
    case 1:
        jawab(1, "A huruf kecilnya adalah...", "a");
        break;
    case 2:
        jawab(2, "Angka yang bisa dibagi dua adalah", "ganjil");
        break;
    case 3:
        jawab(3, "Internet semula bernama...", "ARPANET");
    }
}
