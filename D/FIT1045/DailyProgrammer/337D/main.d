import std.stdio;
import std.math;


//part 1
//area of sector(A) = pi*r^2 * theta/360 (in degrees)
//area of perimeter(P) = 2r + (2*pi*r*theta)/360 (in degrees)
// also --> (360/pi*r)*((p/2) - r) = theta (in degrees)
// therefor A = r((p/2) - r) -> quadratic
// each result returns a quadratic expression and we can capitalise on it by taking shortcuts as max area happens at perm/2/2(radius)

//part 2
// "x" is the disntance from town A to P
// by Using calculas we get that point p = (a*length)/a+b as p cant be negative

void main(){
  // part 1
  int perm = 100;
  float rad = ((perm/2)/2);
  float angle = ((360/(PI*rad))*((perm/2) - rad));
  writeln("~",angle,"*");

  //part 2
  int a=20,b=30,distance=100;
  float P = (a*distance)/(a+b);
  writeln(P);
}
