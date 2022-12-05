#include "Input_Validation.h"
#include <cmath>
#include <cstdlib>
#include <iomanip>

// physics equations

void Velocity();
void Acceleration();
void Motion();
void Newtons_2nd();
void Weight();
void Momentum();

// motion equations

void velocity_time();
void position_time();
void velocity_position();
void mean_speed();

// print menus

void Print_Menu();
void Print_Submenu();

int main() {
  char option = '\0';
  bool exit = false;

  cout << fixed << setprecision(4);

  while (true) // process main menu options (physics equations)
  {
    Print_Menu();

    Validate_Character(option);

    switch (option) {
    case '1': {
      Velocity();
      break;
    }
    case '2': {
      Acceleration();
      break;
    }
    case '3': {
      Motion();
      break;
    }
    case '4': {
      Newtons_2nd();
      break;
    }
    case '5': {
      Weight();
      break;
    }
    case '6': {
      Momentum();
      break;
    }
    case 'E':
    case 'e': {
      exit = true;
      break;
    }
    case 'X':
    case 'x': {
      system("clear");
      break;
    }
    default: {
      cout << "Please choose a valid option." << endl << endl;
    }
    }

    if (exit) {
      break;
    }
  }

  return 0;
}

void Print_Menu() // main menu
{
  cout << "PHYSICS CALCULATOR" << endl;
  cout << "==================" << endl << endl;
  cout << "1.) velocity" << endl;
  cout << "2.) acceleration" << endl;
  cout << "3.) motion" << endl;
  cout << "4.) newton's 2nd law" << endl;
  cout << "5.) weight" << endl;
  cout << "6.) momentum" << endl;
  cout << "X.) Clear Screen" << endl;
  cout << "E.) Exit" << endl << endl;
  cout << "Please choose an option:" << endl;
}

void Print_Submenu() // submenu
{
  cout << endl << "MOTION" << endl;
  cout << "======" << endl << endl;
  cout << "1.) velocity-time" << endl;
  cout << "2.) position-time" << endl;
  cout << "3.) velocity-position" << endl;
  cout << "4.) mean speed theorem" << endl << endl;
  cout << "Please choose an option:" << endl;
}

void Velocity() {
  double v = 0.0;

  double ds = 0.0;
  double dt = 0.0;

  string ds_units = "";
  string dt_units = "";

  cout << endl << "VELOCITY" << endl;
  cout << "========" << endl << endl;

  cout << "Enter the magnitude of the displacement:" << endl;
  ds = Validate_Rational(ds);
  cout << endl;

  cout << "Enter the amount of time elapsed:" << endl;
  dt = Validate_Rational(dt);
  cout << endl;

  cout << "Enter the unit of measure for displacement:" << endl;
  ds_units = Validate_Word(ds_units);
  cout << endl;

  cout << "Enter the unit of measure for time:" << endl;
  dt_units = Validate_Word(dt_units);
  cout << endl;

  v = ds / dt;

  cout << "v = d / t" << endl;
  cout << "v = " << ds << " / " << dt << endl;
  cout << "v = " << v << ' ' << ds_units << '/' << dt_units << endl << endl;
}

void Acceleration() {
  double a = 0.0;

  double dv = 0.0;
  double dt = 0.0;

  string dv_units = "";
  string dt_units = "";

  cout << endl << "ACCELERATION" << endl;
  cout << "============" << endl << endl;

  cout << "Enter the magnitude of the change in velocity:" << endl;
  dv = Validate_Rational(dv);
  cout << endl;

  cout << "Enter the amount of time elapsed:" << endl;
  dt = Validate_Rational(dt);
  cout << endl;

  cout << "Enter the unit of measure for displacement:" << endl;
  dv_units = Validate_Word(dv_units);
  cout << endl;

  cout << "Enter the unit of measure for time:" << endl;
  dt_units = Validate_Word(dt_units);
  cout << endl;

  a = dv / dt;

  cout << "a = v / t" << endl;
  cout << "a = " << dv << " / " << dt << endl;
  cout << "a = " << a << ' ' << dv_units << '/' << dt_units << endl << endl;
}

void Motion() // process submenu options (equations of motion)
{
  char option = '\0';

  Print_Submenu();

  Validate_Character(option);

  switch (option) {
  case '1': {
    velocity_time();
    break;
  }
  case '2': {
    position_time();
    break;
  }
  case '3': {
    velocity_position();
    break;
  }
  case '4': {
    mean_speed();
    break;
  }
  default: {
    cout << "Please choose a valid option." << endl << endl;
  }
  }
}

void velocity_time() {
  double v = 0.0;

  double v0 = 0.0;
  double a = 0.0;
  double t = 0.0;

  string ds_units = "";
  string dt_units = "";

  cout << endl << "VELOCITY-TIME" << endl;
  cout << "=============" << endl << endl;

  cout << "Enter the initial velocity:" << endl;
  v0 = Validate_Rational(v0);
  cout << endl;

  cout << "Enter the constant acceleration:" << endl;
  a = Validate_Rational(a);
  cout << endl;

  cout << "Enter the time elapsed:" << endl;
  t = Validate_Rational(t);
  cout << endl;

  cout << "Enter the unit of measure for displacement:" << endl;
  ds_units = Validate_Word(ds_units);
  cout << endl;

  cout << "Enter the unit of measure for time:" << endl;
  dt_units = Validate_Word(dt_units);
  cout << endl;

  v = v0 + a * t;

  cout << "v = v0 + a * t" << endl;
  cout << "v = " << v0 << " + " << a << " * " << t << endl;
  cout << "v = " << v << ' ' << ds_units << '/' << dt_units << endl << endl;
}

void position_time() {
  double s = 0.0;

  double s0 = 0.0;
  double v0 = 0.0;
  double a = 0.0;
  double t = 0.0;

  string ds_units = "";

  cout << endl << "POSITION-TIME" << endl;
  cout << "=============" << endl << endl;

  cout << "Enter the initial position:" << endl;
  s0 = Validate_Rational(s0);
  cout << endl;

  cout << "Enter the initial velocity:" << endl;
  v0 = Validate_Rational(v0);
  cout << endl;

  cout << "Enter the constant acceleration:" << endl;
  a = Validate_Rational(a);
  cout << endl;

  cout << "Enter the time elapsed:" << endl;
  t = Validate_Rational(t);
  cout << endl;

  cout << "Enter the unit of measure for displacement:" << endl;
  ds_units = Validate_Word(ds_units);
  cout << endl;

  s = s0 + (v0 * t) + (0.5 * a * pow(t, 2));

  cout << "s = s0 + v0t + 1/2at^2" << endl;
  cout << "s = " << s0 << " + (" << v0 << ")(" << t << ") + (1/2)(" << a << ")("
       << t << ")^2" << endl;
  cout << "s = " << s << ' ' << ds_units << endl << endl;
}

void velocity_position() {
  double v2 = 0.0;

  double v0 = 0.0;
  double s0 = 0.0;
  double s = 0.0;
  double a = 0.0;

  string ds_units = "";
  string dt_units = "";

  cout << endl << "VELOCITY-POSITION" << endl;
  cout << "=================" << endl << endl;

  cout << "Enter the initial velocity:" << endl;
  v0 = Validate_Rational(v0);
  cout << endl;

  cout << "Enter the initial position:" << endl;
  s0 = Validate_Rational(s0);
  cout << endl;

  cout << "Enter the final position:" << endl;
  s = Validate_Rational(s);
  cout << endl;

  cout << "Enter the constant acceleration:" << endl;
  a = Validate_Rational(a);
  cout << endl;

  cout << "Enter the unit of measure for displacement:" << endl;
  ds_units = Validate_Word(ds_units);
  cout << endl;

  cout << "Enter the unit of measure for time:" << endl;
  dt_units = Validate_Word(dt_units);
  cout << endl;

  v2 = pow(v0, 2) + (2 * a) * (s - s0);

  cout << "v^2 = v0^2 + 2a(s - s0)" << endl;
  cout << "v^2 = (" << v0 << ")^2 + 2(" << a << ")(" << s << " - " << s0 << ')'
       << endl;
  cout << "v^2 = " << v2 << ' ' << ds_units << '/' << dt_units << endl << endl;
}

void mean_speed() {
  double v_bar = 0.0;

  double v0 = 0.0;
  double v = 0.0;

  string v_units = "";

  cout << endl << "MEAN SPEED THEOREM" << endl;
  cout << "==================" << endl << endl;

  cout << "Enter the initial velocity:" << endl;
  v0 = Validate_Rational(v0);
  cout << endl;

  cout << "Enter the final velocity:" << endl;
  v = Validate_Rational(v);
  cout << endl;

  cout << "Enter the unit of measure for velocity:" << endl;
  v_units = Validate_Word(v_units);
  cout << endl;

  v_bar = 0.5 * (v + v0);

  cout << "v_bar = 1/2(v + v0)" << endl;
  cout << "v_bar = 1/2(" << v << " + " << v0 << ')' << endl;
  cout << "v_bar = " << v_bar << ' ' << v_units << endl << endl;
}

void Newtons_2nd() {
  double f = 0.0;

  double m = 0.0;
  double a = 0.0;

  string m_units = "";
  string a_units = "";

  cout << endl << "NEWTON'S 2ND LAW" << endl;
  cout << "================" << endl << endl;

  cout << "Enter the mass:" << endl;
  m = Validate_Rational(m);
  cout << endl;

  cout << "Enter the acceleration:" << endl;
  a = Validate_Rational(a);
  cout << endl;

  cout << "Enter the unit of measure for mass:" << endl;
  m_units = Validate_Word(m_units);
  cout << endl;

  cout << "Enter the unit of measure for acceleration:" << endl;
  a_units = Validate_Word(a_units);
  cout << endl;

  f = m * a;

  cout << "N = ma" << endl;
  cout << "N = (" << m << ")(" << a << ')' << endl;
  cout << "N = " << f << ' ' << m_units << ' ' << a_units << endl << endl;
}

void Weight() {
  double w = 0.0;

  const double GRAVITY = 9.80665;
  double m = 0.0;

  const string a_units = "m/s^2";
  string m_units = "";

  cout << endl << "WEIGHT" << endl;
  cout << "======" << endl << endl;

  cout << "Enter the mass:" << endl;
  m = Validate_Rational(m);
  cout << endl;

  cout << "Enter the unit of measure for mass:" << endl;
  m_units = Validate_Word(m_units);
  cout << endl;

  w = m * GRAVITY;

  cout << "W = mg" << endl;
  cout << "W = (" << m << ")(" << GRAVITY << ')' << endl;
  cout << "W = " << w << ' ' << m_units << ' ' << a_units << endl << endl;
}

void Momentum() {
  double p = 0.0;

  double m = 0.0;
  double v = 0.0;

  const string VELOCITY = "m/s";
  string m_units = "";

  cout << endl << "MOMENTUM" << endl;
  cout << "========" << endl << endl;

  cout << "Enter the mass:" << endl;
  m = Validate_Rational(m);
  cout << endl;

  cout << "Enter the change in velocity:" << endl;
  v = Validate_Rational(v);
  cout << endl;

  cout << "Enter the unit of measure for mass:" << endl;
  m_units = Validate_Word(m_units);
  cout << endl;

  p = m * v;

  cout << "p = mv" << endl;
  cout << "p = (" << m << ")(" << v << ')' << endl;
  cout << "p = " << p << ' ' << m_units << ' ' << VELOCITY << endl << endl;
}