void lcd_cmd(unsigned char abc)
{
PORTC=abc;
PORTC&=~(1<<0);
PORTC&=~(1<<1);
PORTC|=(1<<2);
_delay_ms(1);
PORTC&=~(1<<2);
}

void dis_cmd(unsigned char abc)
{
unsigned char d=0;
d=(abc&0b11110000);
lcd_cmd(d);
d=((abc<<4)&0b11110000);
lcd_cmd(d);
}

void lcd_data(unsigned char abc)
{
PORTC=abc;
PORTC|=(1<<0);
PORTC&=~(1<<1);
PORTC|=(1<<2);
_delay_ms(1);
PORTC&=~(1<<2);
}

void dis_data(unsigned char abc)
{ 
unsigned char d=0;
d=(abc&0b11110000);
lcd_data(d);
d=((abc<<4)&0b11110000);
lcd_data(d);
}

void lcd_init()
{
   dis_cmd(0X02);
     dis_cmd(0X28);
    dis_cmd(0X0C); //for diplaying cursor(if dis_cmd(0X0C);<<this removes the cursor
     dis_cmd(0X06);
}

void dis_num(unsigned int num)
{
unsigned int d=0;
  dis_cmd(0x04);
  if(num==0)
  {
     dis_data('0');
	 }
  while(num!=0){

d=num%10;
dis_data(d+48);
num=num/10;
	}
}

void dis_str(unsigned char *str)
{
  unsigned char i=0;
  while(str[i]!='\0')
  {
   dis_data(str[i]);
   i++;
   }
}

