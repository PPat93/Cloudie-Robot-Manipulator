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
                                    difference()
                                    {
                                        difference()
                                        {
                                        cube([140,200,5], center=true); 
                                        translate([60,80,0])
                                            {
                                                cylinder(r=1.5, h=10, center=true);
                                            }
                                        }
                                     translate([-60,80,0])
                                            {
                                                cylinder(r=1.5, h=10, center=true);
                                        }
                                    }
                               translate([-60,-80,0])
                                            {
                                                cylinder(r=1.5, h=10, center=true); 
                                            }
                               }
                           translate([60,-80,0])
                                        {
                                            cylinder(r=1.5, h=10, center=true);
                                        }
                                    }
                        translate([60,-20,0])
                            {
                                cylinder(r=1.5, h=10, center=true);
                            }
                        }
                    translate([-60,-20,0])
                        {
                            cylinder(r=1.5, h=10, center=true);
                        }
                    }
                 translate([0,-50,0])
                        {
                            cylinder(r=10, h=10, center=true);
                        }
                    }
            translate([0,-5,0])
                {
                    cylinder(r=1.5, h=10, center=true);
                }
            }
        translate([0,66,0])
            {
                cube([8,44,5], center=true);
            }
        }
    translate([8.2,66,0])
        {
            cube([3.4,31,5], center=true);
        }
    }
translate([-8.2,66,0])
    {
        cube([3.4,31,5], center=true);
    }
}
}
 
    
 base();