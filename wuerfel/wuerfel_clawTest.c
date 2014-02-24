// Created on Fri February 21 2014

int main()
{
	set_b_button_text("drehen");
	int a=0;
	while(1){
		if(b_button()==1){
			if(a==0){
				motor(1,-20);
				msleep(1700);
				motor(1,0);
				a=1;
			}else{
				motor(1,20);
				msleep(1700);
				motor(1,0);
				a=0;
			}
		}
		
	}
}
