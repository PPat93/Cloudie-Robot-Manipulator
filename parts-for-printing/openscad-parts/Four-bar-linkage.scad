//Author: Piotr Paterek, Kraków 05-08.2016
$fn=50;
module fourangle()
{
    translate([29, 7, 0])
    {
        cylinder(r=6, h=4, center=true);
    }
    translate([-29, 7, 0])
    {
        cylinder(r=6, h=4, center=true);
    }
    translate([16,-15, 0])
    {
        cylinder(r=6, h=4, center=true);
    }
    translate([0,0,-2])
    {
        linear_extrude(height=4, convexity = 10){
        polygon(points=[[32,9],[-34,9],[16,-15]]);
        }
    }
}
//holes
difference()
{
    difference()
{
    difference()
{
    fourangle();
    translate([29, 7, 0])
    {
        cylinder(r=1.5, h=4, center=true);
    }
    translate([-29, 7, 0])
    {
        cylinder(r=1.5, h=4, center=true);
    }
    translate([16,-15, 0])
    {
        cylinder(r=1.5, h=4, center=true);
    }
}
}
}