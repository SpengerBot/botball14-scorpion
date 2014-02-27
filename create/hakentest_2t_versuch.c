//servos
#define leftHook 1
#define rightHook 0
#define claw_closed 1860
#define claw_opend 1111
#define hookDown 750
#define hookUp_old 1450
#define hookUp 1650 // Created on Wed February 19 2014

void old_main()
{
	enable_servos();
	printf("start");
	set_servo_position(leftHook, hookDown);
	set_servo_position(rightHook, hookDown);
	msleep(1000);
		printf("\n down");
	int servo_pos=hookDown;
	set_servo_position(leftHook, hookUp);
	set_servo_position(rightHook, hookUp);
	msleep(2000);
	servo_pos=hookUp;
	while(servo_pos>hookDown){
		set_servo_position(leftHook, servo_pos);
		set_servo_position(rightHook, servo_pos);
		servo_pos-=5;
		msleep(20);
		printf("\n more down");
	}
		printf("\n done");
}
