#include "car.h"
#include "track.h"
#include <math.h>
// include typical methods, and look up typical values to assign to them
// contact Caroline or Abdullah for specifics, they have access to the shop and can take measurements

car::car(track* track)
{
    mass = 500; // kg
    gravitational_acceleration = -9.81; // m/s^2
    distance = 0; // m
    velocity = 0; // m/s
    acceleration = 0; // m/s^2
    altitude = 0; // m above starting point?
    orientation = 90; // degrees on flat road
    throttle = 0; // m/s^2?
    engine_force = 0; // N
    gravitational_force = mass * gravitational_acceleration; // N
    normal_force = gravitational_force * -1; // N; need to figure out direction scheme, also not necessarily true, but we'll cross that bridge when we come to it
    net_force_x = 0; // N
    net_force_y = 0; // N
    power = 0; // W or HP?
    c_rr = 0; // unitless
    c_drag = 0; // unitless
    drag_area = 0; // m^2
    m_track = track;
}
//auxillary functions
double car::frictional_force()
{
    if (velocity==0)
        return (-1.0)*(m_track->get_c_static_friction())*normal_force;
    else
        return (-1.0)*(m_track->get_c_dynamic_friction())*normal_force;
}

void car::update_net_force()
{
    //net_force = normal_force + gravitational_force + engine_force + frictional_force();
    net_force_x = 0; //whatever this would be
    net_force_y = 0; //whatever this would be
}

  // accessor methods
double car::get_mass() {return mass;}
double car::get_gravitational_acceleration() {return gravitational_acceleration;}
double car::get_distance() {return distance;}
double car::get_velocity() {return velocity;}
double car::get_acceleration() {return acceleration;}
double car::get_altitude() {return altitude;}
double car::get_orientation() {return orientation;}
double car::get_throttle() {return throttle;}
double car::get_engine_force() {return engine_force;}
double car::get_gravitational_force() {return gravitational_force;}
double car::get_normal_force() {return normal_force;}
double car::get_net_force_x() {return net_force_x;}
double car::get_net_force_y() {return net_force_y;}
double car::get_power() {return power;}
double car::get_c_rr() {return c_rr;}
double car::get_c_drag() {return c_drag;}
double car::get_drag_area() {return drag_area;}

  // mutator methods
void car::set_mass(double m) {mass = m;}
void car::set_altitude(double a) {altitude = a;}
void car::set_orientation(double o)
{
    orientation = o;
    gravitational_acceleration = gravity * sin(orientation);
    gravitational_force = mass * gravitational_acceleration;
    normal_force = (-1.0) * mass * gravity * cos(orientation); //is this true
    update_net_force();
}
void car::set_throttle(double t) {throttle = t;}
void car::set_engine_force(double ef) {engine_force = ef;}
void car::set_power(double p) {power = p;}
void car::set_c_rr(double cr) {c_rr = cr;}
void car::set_c_drag(double cd) {c_drag = cd;}
void car::set_drag_area(double da) {drag_area = da;}
void car::travel(double d) {distance += d;}
void car::set_velocity(double v) {velocity = v;}
