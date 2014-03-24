/**
* Author: Alexander Halbarth
* Function: Sends Stop command to the Create.
*/
void stop() {
	create_write_byte(137);        // stop move by changing speed and radius to 0
	create_write_byte(0);          // send high byte (0 speed)
	create_write_byte(0);          // send low byte (0 speed)
	create_write_byte(0);          // null turn radius
	create_write_byte(0);          // null turn radius
}

/**
* Author: Alexander Halbarth
* Function: Let the Create drive withe the given speed for a specific Distance
* Arguments:
*   - speed: The Speed in mm/s
*   - dist: The Distance in mm the Create should driv
*/
void create_drive_distance(int speed, int dist) {
	if(speed*dist<0) {
		printf("\nSpeed & Distance must be positive or negative!\nDistance will be corrected!\n");
		dist = dist*-1;
	}
	create_write_byte(152);        // specifies start of script definition
	create_write_byte(13);         // specifies number of bytes to follow,(defining the script)
	create_write_byte(137);        // drive command (speed and turn radius in next 4 bytes)
	create_write_byte(speed >> 8); // send speed high byte (bits 8-15 shifted to 0-7)
	create_write_byte(speed);      // send speed low byte
	create_write_byte(128);        // send hex 80
	create_write_byte(0);          // send hex 00 (special case: turn radius hex 8000 or 7FFF is straight)
	create_write_byte(156);        // wait for distance done (in mm)
	create_write_byte(dist >> 8);  // send dist high byte
	create_write_byte(dist);       // send dist low byte
	stop();
	create_write_byte(153);        //start script
}

/**
* Author: Alexander Halbarth
* Function: Let the Create drive withe the given speed for a specific Distance
*     The Method returns after the Create finished driving.
* Arguments:
*   - speed: The Speed in mm/s
*   - dist: The Distance in mm the Create should driv
*/
void create_drive_distance_wait(int speed, int dist) {  //dist in mm, speed in mm/s   invertiert fuer create roboter
	create_drive_distance(speed, dist);
	double d = dist;
	double s = speed;
	msleep((int)(d/s*1000.0));		//calculate the estimated duration
}

/**
* Author: Alexander Halbarth
* Function: Let the Create rotate to the specific angle.
* Arguments:
*   - speed: The Speed in mm/s
*   - angle: The angle to which the Create should rotate
*       - positive Value means turning right
*       - negative Value means turning left
*/
void create_spin_angle(int speed, int angle) {
	int rad = 0xFFFF;			   //Maximum Radius means turning left
	angle = angle * -1;			   //Correction of the angle
	if(angle>0) {
		rad = 0x0001;			   //When Radius is positive -> min Radius means turning right
	}
	create_write_byte(152);        // specifies start of script definition
	create_write_byte(13);         // specifies number of bytes to follow,(defining the script)
	create_write_byte(137);        // drive command (speed and turn radius in next 4 bytes)
	create_write_byte(speed >> 8); // send speed high byte (bits 8-15 shifted to 0-7)
	create_write_byte(speed);      // send speed low byte
	create_write_byte(rad >> 8);   // send radius high byte (bits 8-15 shifted to 0-7)
	create_write_byte(rad);        // send radius low byte
	create_write_byte(157);        // wait for angle done
	create_write_byte(angle >> 8); // send angle high byte
	create_write_byte(angle);      // send angle low byte
	stop();
	create_write_byte(153);        //start script
}

/**
* Author: Alexander Halbarth
* Function: Let the Create rotate to the specific angle.
*     The Method returns after the Create finished driving.
* Arguments:
*   - speed: The Speed in mm/s
*   - angle: The angle to which the Create should rotate
*       - positive Value means turning right
*       - negative Value means turning left
*/
void create_spin_angle_wait(int speed, int angle) {
	create_spin_angle(speed, angle);
	if(angle*speed < 0) {			 //Correction of the angle
		angle = angle * -1;
	}
	double a = angle;
	double s = speed;
	msleep((int)(2268.9280275*a/s)); //calculate the estimated duration (d*pi*angle/360/speed)
}
