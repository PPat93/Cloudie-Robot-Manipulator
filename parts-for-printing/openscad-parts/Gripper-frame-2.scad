//Author: Piotr Paterek, Kraków 05-08.2016
$fn=20;
module base()
{
    cube([54,35,4], center=true);
    translate([0,15,10.5])
    {   
        cube([54,5,17.5], center=true);
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
                        base();
                        translate([19,15,12])
                        {
                            rotate(a=90,v=[1,0,0])
                            {
                                cylinder(r=1.6, h=5, center=true);
                            }
                        }
                    }
                translate([-19,15,12])
                    {
                        rotate(a=90,v=[1,0,0])
                        {
                            cylinder(r=1.6, h=5, center=true);
                        }
                    }
                }
            translate([0,15,17])
                {   
                    cube([24,5,26], center=true);
                }
            }
        translate([9.5,-9,0])
        {
            cube([23,12.5,4], center=true);
        }
        }
    translate([-4,-9,0])
    {
        cylinder(r=1, h=4, center=true);
    }
    }
translate([23,-9,0])
{
    cylinder(r=1, h=4, center=true);
}
}