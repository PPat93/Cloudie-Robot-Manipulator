//Author: Piotr Paterek, Kraków 05-08.2016
$fn=50;
module base()
{
    difference()
    {
    difference()
    {
        difference()
        {
            difference()
            {
            cube([200,200,5], center=true); 
            translate([80,85,0])
                {
                    cylinder(r=1.5, h=10, center=true);
                }
            }
         translate([-80,85,0])
                {
                    cylinder(r=1.5, h=10, center=true);
            }
        }
   translate([-80,-85,0])
                {
                    cylinder(r=1.5, h=10, center=true); 
                }
   }
   translate([80,-85,0])
                {
                    cylinder(r=1.5, h=10, center=true);
                }
            }
 }
    
 base();