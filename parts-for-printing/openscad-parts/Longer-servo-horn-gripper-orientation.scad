//Author: Piotr Paterek, Kraków 05-08.2016
$fn=50;
module cal()
{
cube([66,15,4], center=true);
        translate([33,0,0])
                        {
                            cylinder(r=7.5, h=4, center=true);
                        }
    
    translate([-33,0,0])
                        {
                            cylinder(r=7.5,, h=4, center=true);
                        }
                    }

difference()
{
    difference()
    {
        cal();
        translate([33,0,0])
                        {
                            cylinder(r=1.5, h=4, center=true);
                        }
    }
    translate([-33,0,0])
                        {
                            cylinder(r=1.5, h=4, center=true);
                        }
                    }
                     
                    