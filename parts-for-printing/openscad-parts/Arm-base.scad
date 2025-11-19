//Author: Piotr Paterek, Kraków 05-08.2016
$fn=50;
difference()
{
    difference()
    {
        difference()
    {
        difference()
    {
    difference()
    {
        cube([100,60,5], center=true);
        translate([-35,-20,-3])
        {
            cylinder(r=1.5,h=6);
        }
    }
        translate([-35,20,-3])
        {
            cylinder(r=1.5,h=6);
        }
    }
    translate([35,-20,-3])
        {
            cylinder(r=1.5,h=6);
        }
    }
    translate([35,20,-3])
        {
            cylinder(r=1.5,h=6);
        }
    }
    //screw hole
    translate([0,0,-5])
        {
            cylinder(r=3,h=10);
        }
}
difference()
{
    translate([-5,0,21.5])
    {
        cube([3,60,43], center=true);
    }
    translate([-5,15,38.25])
    {
        rotate(a=90, v=[0,1,0])
        {
        cylinder(r=1.5, h=3, center=true);
        }
    }
}
translate([0,-15,0])
{
    
rotate(a=90,v=[1,0,0])
{
    linear_extrude(height=5, convexity = 10){
    polygon(points=[[-5,15],[6,2],[-5,2]]);
    }
}
}
translate([0,20,0])
{
    
rotate(a=90,v=[1,0,0])
{
    linear_extrude(height=5, convexity = 10){
    polygon(points=[[-5,15],[6,2],[-5,2]]);
    }
}
}
translate([0,20,0])
{
    
rotate(a=90,v=[1,0,0])
{
    linear_extrude(height=5, convexity = 10){
    polygon(points=[[-5,15],[-20,2],[-5,2]]);
    }
}
}
translate([0,-15,0])
{
    
rotate(a=90,v=[1,0,0])
{
    linear_extrude(height=5, convexity = 10){
    polygon(points=[[-5,15],[-20,2],[-5,2]]);
    }
}
}