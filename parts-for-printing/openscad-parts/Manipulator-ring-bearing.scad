//Author: Piotr Paterek, Kraków 05-08.2016
$fn=40;
difference()
{
    difference()
    {
        cylinder(r=17,h=8, center=true);
        cylinder(r=11.35,h=8, center=true);
    }
    translate([0,14,0])
    {
        rotate(a=90,v=[1,0,0])
        {
            cylinder(r=1,h=8,center=true);
        }
    }
}