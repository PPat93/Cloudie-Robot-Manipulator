//Author: Piotr Paterek, Kraków 05-08.2016
$fn=50;
module cal()
{
cube([150,20,4], center=true);
translate([75,0,0])
                    {
                        cylinder(r=10, h=4, center=true);
                    }
translate([-75,0,0])
                    {
                        cylinder(r=10, h=4, center=true);
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
                    translate([75,0,0])
                    {
                        cylinder(r=3.5, h=4, center=true);
                    }
                    translate([-75,0,0])
                    {
                        cylinder(r=1.5, h=4, center=true);
                    }
                }
            }
            translate([15,0,0])
             {
                    cylinder(r=1.5,h=4,center=true);
             }
        }
        translate([44,0,0])
                    {
                        cylinder(r=1.5, h=4, center=true);
                    }
    }
     translate([-15,0,0])
             {
                    cylinder(r=1.5,h=4,center=true);
             }
         }