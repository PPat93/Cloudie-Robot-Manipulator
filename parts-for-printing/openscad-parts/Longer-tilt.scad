//Author: Piotr Paterek, Kraków 05-08.2016
$fn=50;
module cal()
{
cube([150,15,4], center=true);
translate([75,0,-2])
        {
            cylinder(r=7.5, h=4);
        }
translate([-75,0,-2])
        {
            cylinder(r=7.5, h=4);
        }
}

difference()
{
    difference()
    {
        cal();
        translate([75,0,-2])
        {
            cylinder(r=1.5, h=4);
        }
    }
    translate([-75,0,-2])
        {
            cylinder(r=1.5, h=4);
        }
}