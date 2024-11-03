#include<stdio.h>
//RCC_AHB1ENR=0x40023800+0x30=0x40023830
//GPIO_MODER=0x40020000+0x00=0x40020000
//GPIO_ODR=0x40020414
//GPIOC_AFRH =0x40020800+0x20=0x40020820
//RCC_APB2ENR=0x40023800+0x44=0x40023844
//USART_CR1=0x4001 1000+0x0c=0x4001100c
//USART_BRR=0x4001 1400+0x08=0x4001 1408
//USART_CR2=0x4001 1400+0x10=0x40011410
//USART_DR=0x4001 1000+0x04=0x40011004
//USART6_SR=0x4001 1400+0x00=0x40011400
//USART6_CR1=0x4001 1400+0x0C=0x4001 140C
#define  RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOC_MODER  (*((int *) 0x40020800))
#define GPIOC_AFRL  (*((int *) 0x40020820))
//#define GPIOB_ODR (*((int *)0x40020414))
#define RCC_APB2ENR (*((int *)0x40023844))
#define USART6_CR1 (*((int *)0x4001140C))
#define USART6_BRR (*((int *)0x40011408))
#define USART6_CR2		 (*((int *)0x40011410))
#define USART6_DR 			(*((int *)0x40011404))
#define USART6_SR 			(*((int *)0x40011400))
#define ADC_SR         (*(int *)0x40012000)
#define ADC_SMPR1      (*(int *)0x4001200C)
#define ADC_SQR3       (*(int *)0x40012034)
#define ADC_CR1        (*(int *)0x40012004)
#define ADC_CR2        (*(int *)0x40012008)
#define ADC_DR         (*(int *)0x4001204C)
#define RCC_AHBIENR    (*(int *)0x40023830)
#define SYSCFG_EXTICR3 (*(int *)0x40013810)
#define EXTI_IMR       (*(int *)0x40013C00)
#define EXTI_FTSR   (*(int *)0x40013C0C)
#define EXTI_PR   (*(int *)0x40013C14)
#define NVIC_ISER1     (*(int *)0xE000E104)
#define GPIOB_MODER    (*(int *)0x40020400)
#define GPIOB_ODR      (*(int *)0x40020414)
char c;
int a,x=0,j=0;
char z[2];
void delay(int a)
{
	int i=0;
	while(a--)
		for(i=4000;i>0;i--);
	
}

void Write_high_nibble(unsigned char data)
{
GPIOB_ODR |= (data >>4);
/* int a=7,b=3;
while(a>3)
{
if(data & 0x1<<a)
GPIOB_ODR |= 0x1<<b;
a--;
b--;
}
*/ GPIOB_ODR |= 0x1<<8;
delay(10);
GPIOB_ODR &= ~(0x1<<8);
GPIOB_ODR &= ~(0x0F);
}

void Write_low_nibble(unsigned char data)
{
int a=0;
data &= ~(0xF0);
GPIOB_ODR |= data;
/* while(a<4)
{
if(data & 0x1<<a)
GPIOB_ODR |= 0x1<<a;
a++; 
}*/
GPIOB_ODR |= 0x1<<8;
delay(10);
GPIOB_ODR &= ~(0x1<<8);
GPIOB_ODR &= ~(0x0F);
}

void SK_LCD_Write_CMD(unsigned char data)
{
GPIOB_ODR &= ~(0x1<<4); //rs=0
Write_high_nibble(data);
Write_low_nibble(data);
}

void SK_LCD_Write_DATA(unsigned char data)
{
GPIOB_ODR |= (0x1<<4);
Write_high_nibble(data);
Write_low_nibble(data);
// GPIOB_ODR &= ~(0x1<<4);
}

void SK_LCD_Write_STR(char * data)
{
int i=0,b=0;
	if(j==1)
	{
for(i=0;data[i];i++);
i--;

while(i>=0)
{
 SK_LCD_Write_DATA(data[i]);
i--;
b++;
}
}
	if(j==0)
	{
while(data[i])
{
SK_LCD_Write_DATA(data[i]);
b++;
	i++;
}
}
/*if(b==16)
SK_LCD_Write_CMD(0xC0);
if(b==32)
SK_LCD_Write_CMD(0x80);*/
}

void SK_LCD_init()
{
delay(20);
SK_LCD_Write_CMD(0x33);
delay(1);
SK_LCD_Write_CMD(0x32);
SK_LCD_Write_CMD(0x0C);
SK_LCD_Write_CMD(0x01);
}


void outchar(char * c)
{
	int i=0;
	while(c[i])
	{
	while(!((USART6_SR & 0x1<<7)!=0)){};
			USART6_DR=c[i];
		i++;
	}
}
void usart_init(void)
{
	delay(500);
	outchar("AT+RST\r\n");
	delay(500);
	outchar("AT+CWMODE=3\r\n") ;
	delay(500);
	outchar("AT+CWLAP\r\n");
	delay(500);
		outchar("AT+CWJAP=\"KM-2.4G\",\"9963111084\"\r\n");
	delay(500);
	outchar("AT+CIFSR\r\n");
	delay(500);
outchar("AT+CIPMUX=0\r\n");
	delay(500);
	outchar("AT+CWLAP\r\n");
	delay(500);
	outchar("AT+CIPMODE=0\r\n");
	delay(500);
}
char Fetch[50]={0};
float temp=38,hum=11;
int main()
{
	RCC_AHB1ENR |= 0x3<<1; // set clock to 1 for GPIOC and GPIOB
	while(!((RCC_AHB1ENR & 0x6)==6));	//checking for clock set or not
	GPIOC_MODER  |= 0x5<<13; //set port mode TO altarnat functionality(USART6) mode 15 and 13 pins.
	GPIOC_MODER |= 0x3<<0;//SETING 0 AND 1ST bit for analog mode of ADC
	GPIOC_AFRL |=0x8<<24;//pin 24 set to UART6 mode
	GPIOC_AFRL |=0x8<<28;//pin 28 set to UART6 mode
	RCC_APB2ENR |=0x1<<5;//set clock to 1 for UART6
	RCC_APB2ENR |=0x1<<8;//set clock to 1 for ADC
	while(!(RCC_APB2ENR & 0x1<<8));
	while(!(RCC_APB2ENR & 0x1<<5));
	USART6_CR1 |=0x3<<2;//enble TE and RE
	USART6_CR1 |=0x1<<13;//enble UE 
	USART6_BRR=0x8B;//TE AND RE bits per sec.
	USART6_CR2 &=0x0<<12;// 1 bit stop
	ADC_SMPR1 |= 0x7<<0;// 480cycles.
	ADC_SQR3 |= 0xA;//ADC will have 1st squence so 1st pin is set to 10;
	ADC_CR1 &= ~(0x3<<24);//clearing 12th pin for 15adcclks of resolution
	ADC_CR2 |= 0x0401;//1OTH bit for A/D ON / OFF->ON and 1st bit for end of conversion enble EOC
	GPIOB_MODER &= (0x0);//clearing all the bits
	GPIOB_MODER |=0x55<<0;//1st 4pins set to output mode of d1 d2 d3 d4.
	GPIOB_MODER |=0x1<<8;//LCD set reset -> set
	GPIOB_MODER |=0x1<<10;//LCD read write 10bit is set
	GPIOB_MODER |=0x1<<16;//LCD enble 16 bit set for enble
	GPIOB_ODR &=0x0<<0;
GPIOB_ODR &= (0x0);
SK_LCD_init();
	usart_init();
	while(1)
	{
		
		x=0;
	SK_LCD_Write_STR("temp = ");
	ADC_CR2 |= 0x1<<30;//30th bit for start conversion (power consumption is high)
	while(!(ADC_SR & 0x2)){};
		a = ADC_DR;	
		a/=10;
		temp=a;
while(a)
{
z[x]=(a%10)+48;//int str conversion start
a/=10;
x++;
}								//end 
j=1;
SK_LCD_Write_STR(z);//sending str to LCD
j=0;

ADC_CR2 &= ~(0x1<<30);
		outchar("AT+CIPSTATUS\r\n");
		delay(50);
		outchar("AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n\"");
		delay(500);
sprintf(Fetch,"GET /page.php?temp=%f&hum=10&dev=11\r\n\r\n",temp);
outchar("AT+CIPSEND=45\r\n");
delay(500);
outchar(Fetch);

delay(3500);
SK_LCD_Write_CMD(0x01);
SK_LCD_Write_CMD(0x80);
//outchar("AT+CIPCLOSE\r\n");
//delay(500);
//outchar("AT+CIPSTATUS\r\n");
		
	}
	return 0;
}
