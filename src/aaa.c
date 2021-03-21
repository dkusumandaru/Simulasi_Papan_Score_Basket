#include  <mega128.h>
#include  <delay.h>

unsigned char poin[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char point[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char det1[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char det[6]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,};
unsigned char mnt[2]={0x3f,0x06};

int satuan,puluhan,data,data_temp,x;
int satuan2,puluhan2,data2,data_temp2;
int detik,detik2,menit,menit2,data0,data_temp0;



void count(){
  data_temp=data;
  satuan=data_temp%10;
  puluhan=(data_temp/10)%10;
}

void count2(){
  data_temp2=data2;
  satuan2=data_temp2%10;
  puluhan2=(data_temp2/10)%10;
}

void timer(){
data_temp0=data0;
detik=data_temp0%10;
detik2=(data_temp0/10)%6;
menit=(data_temp0/60)%10;
menit2=(data_temp0/1000)%10;
}   

void hasil(){
//poin team 1
  PORTE.0=0;
  PORTE.1=1;
  PORTE.2=1;
  PORTE.3=1;
  PORTE.4=1;
  PORTE.5=1;
  PORTE.6=1;
  PORTE.7=1;
  PORTD=poin[satuan];
  delay_ms(1);
             
  PORTE.0=1;
  PORTE.1=0;
  PORTE.2=1;
  PORTE.3=1;
  PORTE.4=1;
  PORTE.5=1;
  PORTE.6=1;
  PORTE.7=1;
  PORTD=poin[puluhan];
  delay_ms(1);

//point team 2
  PORTE.0=1;
  PORTE.1=1;
  PORTE.2=0;
  PORTE.3=1;
  PORTE.4=1;
  PORTE.5=1;
  PORTE.6=1;
  PORTE.7=1;
  PORTD=point[satuan2];
  delay_ms(1);

  PORTE.0=1;
  PORTE.1=1;             
  PORTE.2=1;
  PORTE.3=0;
  PORTE.4=1;
  PORTE.5=1;
  PORTE.6=1;
  PORTE.7=1;
  PORTD=point[puluhan2];
  delay_ms(1);

//waktu bertanding
  PORTE.0=1;
  PORTE.1=1;
  PORTE.2=1;
  PORTE.3=1;
  PORTE.4=0;
  PORTE.5=1;
  PORTE.6=1;
  PORTE.7=1;
  PORTD=det1[detik];
  delay_ms(1);
           
  PORTE.0=1;
  PORTE.1=1;
  PORTE.2=1;
  PORTE.3=1;
  PORTE.4=1;
  PORTE.5=0;
  PORTE.6=1;
  PORTE.7=1;
  PORTD=det[detik2];
  delay_ms(1);
             
  PORTE.0=1;
  PORTE.1=1;
  PORTE.2=1;
  PORTE.3=1;
  PORTE.4=1;
  PORTE.5=1;
  PORTE.6=0;
  PORTE.7=1;
  PORTD=det1[menit];
  delay_ms(1);
            
  PORTE.0=1;
  PORTE.1=1;
  PORTE.2=1;
  PORTE.3=1;
  PORTE.4=1;
  PORTE.5=1;
  PORTE.6=1;
  PORTE.7=0;
  PORTD=mnt[menit2];
  delay_ms(1);
}

void main(void){
data=0;
data2=0;
data0=1000-400;

PORTA=0xFF;
DDRA=0x00;

PORTB=0xFF;
DDRB=0x00;

PORTD=0x00;
DDRD=0xFF;

PORTE=0xFF;
DDRE=0xFF;

DDRF=0xFF;


  while (1){  
      for(x=0;x<5;x++){
        count();
        count2();
        hasil();
        timer(); 
      }

      if (PINB.0==0){
        data0--;
        if (data0<=0){       
            data0=0;
            }
      } 
      
      if (data0==0000){
        PORTF=1;
           delay_ms(100);
        PORTF=0;
      }

      if (PINB.1==0){
        PORTF=1;
           delay_ms(30);
        PORTF=0;
        data++;
        if (data>99){
            data=data+3;
            }
      }     
      
      if (PINB.2==0){
        PORTF=1;
           delay_ms(30);
        PORTF=0;
        data2++;
        if (data2>99){
            data2=0;
            }
      }
    
  };
}