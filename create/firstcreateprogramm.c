
void turn_right(int angle);
void turn_left(int angle);

//servos
#define cubeClaw 0
#define botguyClaw 1
#define leftHook 2
#define rightHook 3
#define claw_closed 1860
#define claw_opend 1111
#define hookDown 750
#define hookUp 1450

//motoren
#define motor 1 
#define speed 500

//
#define line_sensor_left 0
#define line_sensor_right 1


void main(){
	enable_servos();
	set_servo_position(leftHook, hookDown);
	set_servo_position(rightHook, hookDown);
	set_servo_position(cubeClaw,claw_closed);
	create_connect();
	create_full();
	printf("start");
	turn_right(70);
	printf("\n jeztz nach hinten");
	create_stop();msleep(100);
	set_create_distance(20);
	create_drive_straight(-100);
	while(get_create_distance()>=0){
	}
	create_stop();msleep(100);
	printf("jetzt nach vorne");
	set_create_distance(0);
	create_drive_straight(speed);
	while(get_create_distance()<500){
	}
	create_stop();msleep(100);
	printf("jeztz nach links");
	turn_right(65);
	set_servo_position(cubeClaw,claw_opend);
	create_drive_straight(-speed);
	set_create_distance(0);
	while(get_create_distance()>-200){
	}
	create_stop();msleep(100);
	set_servo_position(cubeClaw,claw_closed);
	printf("done");
	
}

void turn_right(int angle) {
	set_create_normalized_angle(359);
	create_spin_CW(250);
	while(get_create_normalized_angle()>360-angle){
	}		
}

void turn_left(int angle) {
set_create_normalized_angle(0);
	create_spin_CCW(250);
	while(get_create_normalized_angle()<angle-10){
	}		
}
