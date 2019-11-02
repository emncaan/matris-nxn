#include <stdio.h>
#include <conio.h>
#include <stdlib.h>




int main(){
	int a,c,k; // de�i�kenleri atiyoruz
	int i,j,islem;
	int topla,carpim;
	int say=0; // saya�.
	
	printf("\t\t-- MATRISLERLE 4 ISLEM PROGRAMI -- \n"); // daha iyi kullanim icin bilgi veriliyor
	printf("\t\t-- DIKKAT: KARE MATRISLERLE ISLEM YAPILMAKTADIR! -- \n");
	
	printf("Dizinin boyutlarini giriniz? (n x n)\n");
	scanf("%d",&a);	// a de�erini al�p...
	
	char dizi1[a][a]; // dizilerim ka�a ka�l�k olaca��n� belirliyor.
	char dizi2[a][a];
	char sonuc[a][a]; // sonuc matrisi
	printf("1. Matris icin degerler:\n");
	for(i=0;i<a;i++){ // i� i�e for d�ng�s�n� kulland�m ��nk� i ve j de�erleri her alinan de�er i�in arttirilmak zorunda. 
		for(j=0;j<a;j++){ // burada istenen elemanlarin dong�s� yap�l�yor.
			printf("\t [%d] [%d] eleman:",i+1,j+1); // burada +1 koymam�n sebebi, 0'a 0 olmas� kafa kar��t�r�r.
			scanf("%d",&dizi1[i][j]);
		}
	}
	printf("2. Matris icin deger: \n"); // 1. matris i�in ge�erli olan �eyler.
	for(i=0;i<a;i++){
		for(j=0;j<a;j++){
			printf("\t [%d] [%d] eleman:",i+1,j+1);
			scanf("%d",&dizi2[i][j]); // tek farki buradaki de�i�ken dizi2
		}
	}
	system("MODE 80"); // ekran� temizledik
	printf("\t 1. matris: \n");
	
	for(i=0;i<a;i++){ // buradaki for d�ng�s�nde satirlari y�netiyor.
		printf("\n"); // burada satir atlatiyor
		for(j=0;j<a;j++){ // buradaki for d�ng�s�de sut�nlari y�netiyor
			printf("%d \t",dizi1[i][j]); // sonra ekrana bir s�tunlari bir tab bo�luk b�rakar ekrana yaz�yor.
			
		}
	}
printf("\n \t 2.matris \n"); // 1. matristeki gibi...
	
	for(i=0;i<a;i++){
		printf("\n");
		for(j=0;j<a;j++){
			printf("%d \t",dizi2[i][j]); // sadece de�i�ken de�i�tirip dizi2 yapt�k
			
		}
	}
	
	menu: // menu yazdim cunku asagida switch case kulland�m.
 	printf("\n \n \t \t === Hangi islemi yapalim? === \n"); // daha iyi i�lem yapabilmek menu yapt�m.
	printf("\t \t 1- Toplama\n");
	printf("\t \t 2- Cikarma\n");
	printf("\t \t 3- Carpma\n");
	printf("\t \t 4- Transpoze\n");
	islem=getch(); // i�lem yapt�rabilmek i�in ve bu menuden sonra kapanmamas� i�in getch komutunu kulland�m.
	switch(islem){ // switch case kullanarak menude atad���m say�lar�n komutlar�n� olu�turdum.
    case '1'  :
    	goto topla; // goto kulland�m, void kullanarak da yapabilirdim ama bu y�ntemi d���nd�m. 
       printf("topla"); // her goto kulland���m sat�r i�in ayr� bir b�lge olu�turdum. bkz. topla, carp vsvs.
       break; 
    case  '2':
    	goto cikar;
       printf("cikar");
       break; 
       
    case  '3':
    	goto carpma;
       printf("cikar");
       break; 
  
    case  '4':
    	goto transpoz;
    	printf("transpoz");
    	break;
    	
    default : // eger kullan�c� 1-4 aras� farkl� de�er girerse a�a��daki yaz�y� ekrana yazd�racak.
    	printf("\t \t Yanlis giris yaptiniz! :( /n)");
  break;
    }
    
    topla:
    	for(i=0;i<a;i++){		// dizi1'i sonuc dizisine e�itliyorum ��nk� sonuc iki dizenin direkt toplamiyla ortaya ��km�yor ve dizilerin de�i�kenleri dizi1 ve dizi2 ile e�itleniyor.
		for(j=0;j<a;j++){
			sonuc[i][j]=dizi1[i][j];			
		}
	}
	for(i=0;i<a;i++){	// burada toplama i�lemi yaptiriyorum	
		for(j=0;j<a;j++){
			sonuc[i][j]=sonuc[i][j]+dizi2[i][j];			
		}
	}
	printf("\t \t \n Sonuc: \n");
	
	for(i=0;i<a;i++){ // sonucu ekrana yazdiriyorum.
		printf("\n");
		for(j=0;j<a;j++){
			printf("%d \t",sonuc[i][j]);
			
		}
	}
	goto menu; // i�lem sonucunda menuye geri donduruyorum.
	
	cikar: // burada cikarma i�lemi komutu atad�m
			for(i=0;i<a;i++){		
		for(j=0;j<a;j++){
			sonuc[i][j]=dizi1[i][j];			 // toplamada oldu�u gibi, ayn� mant�k.
		}
	}
	for(i=0;i<a;i++){		
		for(j=0;j<a;j++){
			sonuc[i][j]=sonuc[i][j]-dizi2[i][j];			// sadece ��karma i�lemi yapt�r�yorum, toplamadan farkl� olarak.
		}
	}
	printf("\t \t \n Sonuc: \n"); // sonucu ekrana yazdiriyorum.
	
	for(i=0;i<a;i++){
		printf("\n");
		for(j=0;j<a;j++){
			printf("%d \t",sonuc[i][j]);
			
		}
	}
	goto menu; // tekrar menuye donduruyorum.
	
	carpma:
	for(i=0;i<a;i++){ // bu d�ng�lerden d��taki iki tanesi, sat�r ve s�tun takibi, i�teki d�ng� ise toplama i�lemi i�in kullan�lm��t�r.
	for(j=0;j<a;j++){
	topla=0;
	for(k=0;k<a;k++){	// boyutlar�n �arpma i�lemine uygunlu�u kontrol ediliyor. 
	 topla = topla + dizi1[i][k]*dizi2[k][j]; // aha sonra uygun olan boyutlar ile dizi tan�mlamalar� yap�larak, matris de�erleri dizilere al�n�yor. 
sonuc[i][j]=topla;
printf("Carpim Matrisi[%d][%d] = %d ",i+1,j+1,sonuc[i][j]); //  Matris �arp�m� 3 adet for d�ng�s� ile ger�ekle�tirilip ekrana sonu�lar bas�l�yor.
}
printf("\n");
}
}
	printf("\t \t \n Sonuc: \n");
	
	for(i=0;i<a;i++){
		printf("\n");
		for(j=0;j<a;j++){
			printf("%d \t",sonuc[i][j]);
			
		}
	}
	goto menu;
		
		transpoz: // transpoz satir ile sut�n�n yer de�i�tirmesidir. 
{
    printf("1. matrisin transpozu: \n"); // sadece i ve j'leri yer de�i�tirdim. 
    for(i=0;i<a;i++){
        for(j=0;j<a;j++){
            printf("%6d",dizi1[j][i]);
            if(j==a-1) // eger j, dizinin icindeki a-1'e e�itse satir atlatiyor. burada a ilk ba�ta atadi�imiz satir ve sutun sayilari.
                printf("\n");}}
}

    printf("2. matrisin transpozu: \n"); // 1 matriste oldu�u gibi
    for(j=0;j<a;j++)
        for(i=0;i<a;i++){
            printf("%6d",dizi2[i][j]);
            if(i==a-1)
                printf("\n");}

goto menu; // menuye donuyor.
    	
    	return 1; // sonland�r�yor.
    	
	
	
}
