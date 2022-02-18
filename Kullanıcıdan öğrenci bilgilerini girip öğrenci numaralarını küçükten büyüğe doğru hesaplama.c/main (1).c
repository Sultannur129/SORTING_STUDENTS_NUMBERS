/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct ogrenci{
    char ad[50];
    char soyad[50];
    int no;
    char bolum[30];
}ogr[30];

void sirala(struct ogrenci ogr[],int m){
    
    FILE *fp;
    int i,j;
    struct ogrenci temp;
    for(i=0;i<m;i++){
        for(j=0;j<(m-1);j++){
            if(ogr[j].no>ogr[j+1].no){
                
                temp=ogr[j+1];
                ogr[j+1]=ogr[j];
                ogr[j]=temp;
                
            }
        }
    }
    fp=fopen("a.txt","a");
    fputs("Siralanmis Numaralar:\n",fp);
    for(i=0;i<m;i++){
        fprintf(fp,"%d\n",ogr[i].no);
    }
    fclose(fp);
    
}

int main()
{
    FILE *fp;
    fp=fopen("a.txt","w");
    int s;
    printf("Kac ogrenci bilgisi gireceksiniz:");
    scanf("%d",&s);
    int i;
    
    printf("Ogrenci bilgilerini giriniz:"
            "(Ad Soyad), "
            "(Ogrenci No), "
            "(Bolum)\n");
    for(i=0;i<s;i++){
        scanf("%s %s %d %s",ogr[i].ad,ogr[i].soyad,&ogr[i].no,ogr[i].bolum);
        fprintf(fp,"%s %s %d %s\n",ogr[i].ad,ogr[i].soyad,ogr[i].no,ogr[i].bolum);
    }
    fclose(fp);
    
    fp=fopen("a.txt","r");
    for(i=0;i<s;i++){
        
        fscanf(fp,"%s %s %d %s",ogr[i].ad,ogr[i].soyad,&ogr[i].no,ogr[i].bolum);
    }
    fclose(fp);
    printf("\n\n");
    fputs("\n\n",fp);
    sirala(ogr,s);
    
    
    

    return 0;
}
