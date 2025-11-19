//Author: Piotr Paterek, Kraków 05-08.2016
$fn=50;
module cal(){
cube([150,15,4], center=true);
translate([75,0,0])
                {
                    cylinder(r=7.5, h=4, center=true);
                }
translate([-75,0,0])
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
                cal();
                translate([75,0,0])
                {
                    cylinder(r=1.5, h=4, center=true);
                }
            }
            translate([-75,0,0])
                {
                    cylinder(r=1.5, h=4, center=true);
                }
        }
        translate([3,0,0])
            {
                cylinder(r=1, h=4, center=true);
            }
    }
    translate([-12,0,0])
                {
                    cylinder(r=1, h=4, center=true);
                }
        }
        