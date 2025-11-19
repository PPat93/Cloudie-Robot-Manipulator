//Author: Piotr Paterek, Kraków 05-08.2016
$fn=20;
module base()
{
    cube([54,36,7], center=true);
    translate([0,15.5,11.5])
    {   
        cube([54,5,18.5], center=true);
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
                        difference()
                            {
                            difference()
                            {
                                 base();
                                translate([0,15.5,11.5])
                                {
                                    rotate(a=90, v=[1,0,0])
                                    {
                                        cylinder(r=3.5, h=5, center=true);
                                    }
                                }
                            }
                             translate([9,15.5,11.5])
                                {
                                    rotate(a=90, v=[1,0,0])
                                    {
                                        cylinder(r=1, h=5, center=true);
                                    }
                                }
                            }
                        translate([9,15.5,11.5])
                            {
                                rotate(a=90, v=[1,0,0])
                                {
                                    cylinder(r=1, h=5, center=true);
                                }
                            }
                        
                    translate([-9,15.5,11.5])
                            {
                                rotate(a=90, v=[1,0,0])
                                {
                                    cylinder(r=1, h=5, center=true);
                                }
                            }
                        }
                translate([-19,15.5,8.5])
                    {
                        rotate(a=90, v=[1,0,0])
                        {
                            cylinder(r=1.6, h=5, center=true);
                        }
                    }
                }
        translate([19,15.5,8.5])
            {
                rotate(a=90, v=[1,0,0])
                {
                    cylinder(r=1.6, h=5, center=true);
                }
            }
        }
    translate([-12,-14,0])
            {
                
                    cylinder(r=1.7, h=7, center=true);
                
            }
        }
translate([12,-14,0])
        {
            
                cylinder(r=1.7, h=7, center=true);
            
        }
    }