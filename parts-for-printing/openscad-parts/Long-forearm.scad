//Author: Piotr Paterek, Kraków 05-08.2016
$fn=50;
module cal()
{
cube([223,15,4], center=true);
translate([223/2,0,0])
                    {
                        cylinder(r=7.5, h=4, center=true);
                    }
                
                translate([-223/2,0,0])
                    {
                        cylinder(r=7.5, h=4, center=true);
                    }
                }
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
                    cal();
                    translate([223/2,0,0])
                    {
                        cylinder(r=1.5, h=4, center=true);
                    }
                }
                translate([-223/2,0,0])
                    {
                        cylinder(r=1.5, h=4, center=true);
                    }
            }
            translate([-32,0,0])
                    {
                        cylinder(r=1.5, h=4, center=true);
                    }
    }
    translate([42,0,0])
                {
                    cylinder(r=1, h=4, center=true);
                }
            }
            translate([27,0,0])
            {
                cylinder(r=1, h=4, center=true);
            }
        }