
#include <iostream>
#include <cmath>
#ifndef MARMOSET_TESTING
int main();
#endif

double horizontal_velocity(double initial_velocity, double launch_angle);
double vertical_velocity(double initial_velocity, double launch_angle);
double gravity();
double computed_range(double horizontal_velocity, double vertical_velocity, double gravity_acceleration, double height);

#ifndef MARMOSET_TESTING
int main() {
	double angles[] = {10, 20, 25.5, 30, 40, 50, 55.5, 60, 70, 75.5, 80, 90 };
	for (int i = 0; i < 12; i++ ){
		std::cout << "The range the banana reaches for the launch angle of "
					<< angles[i]
					<< " degrees is "
					<< computed_range(horizontal_velocity(600, angles[i]), vertical_velocity(600, angles[i]), gravity(), 10 )
					<<std::endl;
	}

	return 0;
}
#endif

double horizontal_velocity(double initial_velocity, double launch_angle){
	double launch_angle_radian = 0.0174532925199*launch_angle;
	double horizontal_velocity = initial_velocity*cos(launch_angle_radian);
	return horizontal_velocity;
}
double vertical_velocity(double initial_velocity, double launch_angle){
	double launch_angle_radian = 0.0174532925199*launch_angle;
	double vertical_velocity = initial_velocity*sin(launch_angle_radian);
	return vertical_velocity;
}
double gravity(){
	double gravity_acceleration = 9.80665;
	return gravity_acceleration;
}
double computed_range(double horizontal_velocity, double vertical_velocity, double gravity_acceleration, double height ){
	double range = horizontal_velocity*vertical_velocity/gravity_acceleration + horizontal_velocity*sqrt(vertical_velocity*vertical_velocity + 2*gravity_acceleration*height)/gravity_acceleration;
	return range;

}
