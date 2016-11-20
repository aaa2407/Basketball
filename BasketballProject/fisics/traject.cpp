#include "traject.h"

point point_at_time(const traject& traj, size_t time)
{
    point p;
    double dt = (double)time / 1000;
    p.set_x(traj.pos.x() + traj.napr.x()*dt*_M_);
    p.set_y(traj.pos.y() + traj.napr.y()*dt*_M_);
    p.set_z(traj.pos.z() + traj.napr.z()*dt*_M_ - _G_*dt*dt/2*_M_);
    return p;
}



traject set_traject(const point& p1, const point& p2, double max_z)
{
    if (max_z < p1.z() || max_z < p2.z())
    {
        throw errTraject::errorMaxHigh();
    }
    traject traj;
    double t_max = sqrt(2*(max_z - p1.z())/_M_/_G_);
   // std::cout << t_max << std::endl;
    traj.pos = p1;
    traj.napr.set_z(t_max*_G_);
    double A = 0.5*_G_*_M_;
    double B = -traj.napr.z()*_M_;
    double C = p2.z() - p1.z();
    double D = B*B - 4*A*C;
    double t = (-B+sqrt(D))/2/A;
   // std::cout << (-B)/2/A << std::endl;
   // std::cout << t << std::endl;
    traj.napr.set_x((p2.x() - p1.x())/_M_/t);
    traj.napr.set_y((p2.y() - p1.y())/_M_/t);
    return traj;
}
