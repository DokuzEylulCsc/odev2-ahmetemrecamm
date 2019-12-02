#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROMA 20
#define DECIMAL 100
int cevir(char);//Donusturme fonksiyonu
int cevir(char roma)//Roma rakamini sayiya cevirme fonksiyonu
{
   int degeri = 0;
   switch(roma)
   {
      case 'I': degeri = 1; break;//Gelen Roma rakamlarina göre karsýlýgýna bakarak sayiyi gonderme
      case 'V': degeri = 5; break;
      case 'X': degeri = 10; break;
      case 'L': degeri = 50; break;
      case 'C': degeri = 100; break;
      case 'D': degeri = 500; break;
      case 'M': degeri = 1000; break;
      case '\0': degeri = 0; break;
      default: degeri = -1;
   }
   return degeri;
}

void cevirRomaya(char *r,int j)//Sayiyi Roma rakamina Cevirme fonksiyonu
	{
	    int temp = 0;	
	    while(j)
	    {
	    	if(j >= 1000)//Sayiyin degerini cikartarak roma rakami karsýlýgýný bulma yeri
	        {
	            *(r+temp) = 'M';
	            temp++;
	            j -= 1000;
	        }
		        else if(j >= 500)
		        {
		            *(r+temp) = 'D';
		            temp++;
		            j -= 500;
		        }
			        else if(j >= 100)
			        {
			            *(r+temp) = 'C';
			            temp++;
			            j -= 100;
			        }
				        else if(j >= 50)
				        {
				            *(r+temp) = 'L';
				            temp++;
				            j -= 50;
				        }
					        else if(j >= 10)
					        {
					            *(r+temp) = 'X';
					            temp++;
					            j -= 10;
					        }
						        else if(j >= 5)
						        {
						            *(r+temp) = 'V';
						            temp++;
						            j -= 5;
						        }
							        else
							        {
							            *(r+temp) = 'I';
							            temp++;
							            j--;
							        }
								        if(temp == ROMA)
								            break;
	    }
	
	    *(r+temp) = '\0';
	}
main(){
    int secim,sayi,i=0;
    char romaRakami[ROMA];
    char sayiSonuc[DECIMAL];
    printf("Ahmet Emre Cam 2013280043\n");
    do{printf("\n1 - Sayiyi Roma Rakamina Cevir \n2 - Roma Rakamini Sayiyaya Cevir \n3 - Cikis \n\n");  //Menu olusturma
    scanf("%d",&secim);  
    switch(secim)
    {
        case 1 : printf("Sayiyi Giriniz= ");
			    scanf("%d",&sayi);
			    if(sayi < 1 || sayi > 3999)
			    {
			        puts("sayiniz 1 - 3999 arasýnda degil");
			        return(1);
			    }
			    	cevirRomaya(romaRakami,sayi);
			    	printf("Sayinizin= %d Roma rakami karsiligi= %s\n",sayi,romaRakami);
			    	return(0); break;  
		case 2 : printf("Roma Rakamini Lutfen Buyuk Harflerle Giriniz : ");
				   scanf("%s", romaRakami);
				   while(romaRakami[ i ])
				   {
				    if(cevir(romaRakami[ i ]) < 0 )//Roma Rakaminin kontrolunu saglayýp dogruysa cevir fonksiyonuna gonderme
				    {
				    	printf("\nGecersiz Roma Rakami.\n");
				        return 0;
				    }				
				    if((strlen(romaRakami) - i ) > 2)
				    {
				 		if(cevir(romaRakami[ i ]) < cevir(romaRakami[i + 2]))//Roma Rakaminin kontrolunu saglayýp dogruysa cevir fonksiyonuna gonderme
				  	    {
				  	      printf("\nGecersiz Roma Rakami.\n");
				  	      return 0;
				   		}
				    }
				    if(cevir(romaRakami[ i ]) >= cevir(romaRakami[i + 1]))//Cevir fonksiyonundan gelen degerleyi toplayýp sonucu yazdirma
				        sayi = sayi + cevir(romaRakami[ i ]);
				    else
				    {
				        sayi = sayi + (cevir(romaRakami[i + 1]) - cevir(romaRakami[ i ]));
				        i++;
				    }
				    i++;
				    }
				   printf("\nSayinizin Roma Rakami Karsiligi: %d\n", sayi);
				   return 0;
	    break;
    	case 3 :
		break;		
        default : 
	    printf("Gecersiz secim\n"); 	   
	    break; 
    }
    }while(secim!=3);
    getch();      
}

