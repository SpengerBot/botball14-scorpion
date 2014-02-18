
void turn_right();
void turn_left();
#define cubeClaw 0
#define botguyClaw 1
#define leftHook 2
#define rightHook 3
#define hookDown 750
#define hookUp 1450
#define motor 1 
#define speed 100


void main(){
	enable_servos();
	set_servo_position(leftHook, hookDown);
	set_servo_position(rightHook, hookDown);
	create_connect();
	create_full();
	printf("start");
	turn_left(90);
	printf("nach links gedreht");
	set_create_distance(0);
	create_drive_straight(-speed);
	while(get_create_distance()>-500){
	}
	create_stop();
	printf("done");
	
}

void turn_right(int angle) {
set_create_normalized_angle(359);
	create_spin_CW(100);
	while(get_create_distance()>angle){
	}		
}

void turn_left(int angle) {
set_create_normalized_angle(0);
	create_spin_CCW(100);
	while(get_create_normalized_angle()<angle){
	}		
}
