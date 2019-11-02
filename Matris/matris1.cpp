#include <stdio.h>
#include <conio.h>
#include <stdlib.h>




int main(){
	int a,c,k; // deðiþkenleri atiyoruz
	int i,j,islem;
	int topla,carpim;
	int say=0; // sayaç.
	
	printf("\t\t-- MATRISLERLE 4 ISLEM PROGRAMI -- \n"); // daha iyi kullanim icin bilgi veriliyor
	printf("\t\t-- DIKKAT: KARE MATRISLERLE ISLEM YAPILMAKTADIR! -- \n");
	
	printf("Dizinin boyutlarini giriniz? (n x n)\n");
	scanf("%d",&a);	// a deðerini alýp...
	
	char dizi1[a][a]; // dizilerim kaça kaçlýk olacaðýný belirliyor.
	char dizi2[a][a];
	char sonuc[a][a]; // sonuc matrisi
	printf("1. Matris icin degerler:\n");
	for(i=0;i<a;i++){ // iç içe for döngüsünü kullandým çünkü i ve j deðerleri her alinan deðer için arttirilmak zorunda. 
		for(j=0;j<a;j++){ // burada istenen elemanlarin dongüsü yapýlýyor.
			printf("\t [%d] [%d] eleman:",i+1,j+1); // burada +1 koymamýn sebebi, 0'a 0 olmasý kafa karýþtýrýr.
			scanf("%d",&dizi1[i][j]);
		}
	}
	printf("2. Matris icin deger: \n"); // 1. matris için geçerli olan þeyler.
	for(i=0;i<a;i++){
		for(j=0;j<a;j++){
			printf("\t [%d] [%d] eleman:",i+1,j+1);
			scanf("%d",&dizi2[i][j]); // tek farki buradaki deðiþken dizi2
		}
	}
	system("MODE 80"); // ekraný temizledik
	printf("\t 1. matris: \n");
	
	for(i=0;i<a;i++){ // buradaki for döngüsünde satirlari yönetiyor.
		printf("\n"); // burada satir atlatiyor
		for(j=0;j<a;j++){ // buradaki for döngüsüde sutünlari yönetiyor
			printf("%d \t",dizi1[i][j]); // sonra ekrana bir sütunlari bir tab boþluk býrakar ekrana yazýyor.
			
		}
	}
printf("\n \t 2.matris \n"); // 1. matristeki gibi...
	
	for(i=0;i<a;i++){
		printf("\n");
		for(j=0;j<a;j++){
			printf("%d \t",dizi2[i][j]); // sadece deðiþken deðiþtirip dizi2 yaptýk
			
		}
	}
	
	menu: // menu yazdim cunku asagida switch case kullandým.
 	printf("\n \n \t \t === Hangi islemi yapalim? === \n"); // daha iyi iþlem yapabilmek menu yaptým.
	printf("\t \t 1- Toplama\n");
	printf("\t \t 2- Cikarma\n");
	printf("\t \t 3- Carpma\n");
	printf("\t \t 4- Transpoze\n");
	islem=getch(); // iþlem yaptýrabilmek için ve bu menuden sonra kapanmamasý için getch komutunu kullandým.
	switch(islem){ // switch case kullanarak menude atadýðým sayýlarýn komutlarýný oluþturdum.
    case '1'  :
    	goto topla; // goto kullandým, void kullanarak da yapabilirdim ama bu yöntemi düþündüm. 
       printf("topla"); // her goto kullandýðým satýr için ayrý bir bölge oluþturdum. bkz. topla, carp vsvs.
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
    	
    default : // eger kullanýcý 1-4 arasý farklý deðer girerse aþaðýdaki yazýyý ekrana yazdýracak.
    	printf("\t \t Yanlis giris yaptiniz! :( /n)");
  break;
    }
    
    topla:
    	for(i=0;i<a;i++){		// dizi1'i sonuc dizisine eþitliyorum çünkü sonuc iki dizenin direkt toplamiyla ortaya çýkmýyor ve dizilerin deðiþkenleri dizi1 ve dizi2 ile eþitleniyor.
		for(j=0;j<a;j++){
			sonuc[i][j]=dizi1[i][j];			
		}
	}
	for(i=0;i<a;i++){	// burada toplama iþlemi yaptiriyorum	
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
	goto menu; // iþlem sonucunda menuye geri donduruyorum.
	
	cikar: // burada cikarma iþlemi komutu atadým
			for(i=0;i<a;i++){		
		for(j=0;j<a;j++){
			sonuc[i][j]=dizi1[i][j];			 // toplamada olduðu gibi, ayný mantýk.
		}
	}
	for(i=0;i<a;i++){		
		for(j=0;j<a;j++){
			sonuc[i][j]=sonuc[i][j]-dizi2[i][j];			// sadece çýkarma iþlemi yaptýrýyorum, toplamadan farklý olarak.
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
	for(i=0;i<a;i++){ // bu döngülerden dýþtaki iki tanesi, satýr ve sütun takibi, içteki döngü ise toplama iþlemi için kullanýlmýþtýr.
	for(j=0;j<a;j++){
	topla=0;
	for(k=0;k<a;k++){	// boyutlarýn çarpma iþlemine uygunluðu kontrol ediliyor. 
	 topla = topla + dizi1[i][k]*dizi2[k][j]; // aha sonra uygun olan boyutlar ile dizi tanýmlamalarý yapýlarak, matris deðerleri dizilere alýnýyor. 
sonuc[i][j]=topla;
printf("Carpim Matrisi[%d][%d] = %d ",i+1,j+1,sonuc[i][j]); //  Matris çarpýmý 3 adet for döngüsü ile gerçekleþtirilip ekrana sonuçlar basýlýyor.
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
		
		transpoz: // transpoz satir ile sutünün yer deðiþtirmesidir. 
{
    printf("1. matrisin transpozu: \n"); // sadece i ve j'leri yer deðiþtirdim. 
    for(i=0;i<a;i++){
        for(j=0;j<a;j++){
            printf("%6d",dizi1[j][i]);
            if(j==a-1) // eger j, dizinin icindeki a-1'e eþitse satir atlatiyor. burada a ilk baþta atadiðimiz satir ve sutun sayilari.
                printf("\n");}}
}

    printf("2. matrisin transpozu: \n"); // 1 matriste olduðu gibi
    for(j=0;j<a;j++)
        for(i=0;i<a;i++){
            printf("%6d",dizi2[i][j]);
            if(i==a-1)
                printf("\n");}

goto menu; // menuye donuyor.
    	
    	return 1; // sonlandýrýyor.
    	
	
	
}
