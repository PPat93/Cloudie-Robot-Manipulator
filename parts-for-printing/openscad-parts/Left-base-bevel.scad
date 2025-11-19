//Author: Piotr Paterek, Kraków 05-08.2016
$fn=20;
module bevel(){
cube([50, 200, 5], center=true);
translate([-15, 0, 15])
{
    cube([20, 200, 25], center=true);
    
}
}
module bevelholes()
{
difference()
{
    difference()
    {
        difference()
            {
            difference()
                {
                difference(){
                    difference()
                    {  
                        bevel();
                        translate([10, -80, -2.5])
                        {
                            cylinder(r=1.5, h=5);
                        }
                    }
                    translate([10, 80, -2.5])
                        {
                        cylinder(r=1.5, h=5);
                        }
                    }
                translate([-15, 80, 17.5])
                    {
                    cylinder(r=1.5, h=10);
                    }
                 }
            translate([-15, -80, 17.5])
                {
                cylinder(r=1.5, h=10);
                }
            }
            translate([-15, -20, 17.5])
                {
                cylinder(r=1.5, h=10);
                }
            }
        }
    }
    
 
difference()
{ 
     difference()
        {   
            difference()
            {
                bevelholes();
                translate([-15,80,-2.5])
                {
                    cylinder(r=5, h=20);
                }
            }
            translate([-15,-80,-2.5])
                {
                    cylinder(r=5, h=20);
                }
            }
            
         translate([-15,-20,-2.5])
                {
                    cylinder(r=5, h=20);
                }
            }