//Author: Piotr Paterek, Kraków 05-08.2016
$fn=50;
module base()
    {
    module cylinder1()
    {
        difference()
        {
            difference()
            {
                difference()
                {
                    cylinder(r=50, h=10, center=true);
                    translate([0,0,5.5])
                    {
                        rotate(a=90, v=[0,0,1])
                        {
                            
                            rotate_extrude()
                            {
                                 translate([-30,0,20])
                                {
                                    circle(r=3);
                                }
                            }
                        }  
                    }
                }
                //fiveangles
                cylinder(r=7,h=5,$fn=5);
            }
            translate([0,0,-5])
            {
                cylinder(r=1.5,h=6);
            }
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
                    cylinder1();
                    translate([35,-20,-5])
                    {
                        cylinder(r=1.5,h=10);
                    }
                }
                 translate([35,20,-5])
                 {
                    cylinder(r=1.5,h=10);
                 }
             }
                translate([-35,20,-5])
                {
                    cylinder(r=1.5,h=10);
                }
        }
        translate([-35,-20,-5])
        {
            cylinder(r=1.5,h=10);
        }
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
    base();
    translate([-35,-20,0])
    {
        cylinder(r=2.5,h=5);
    }
}
    translate([-35,20,0])
    {
        cylinder(r=2.5,h=5);
    }
}
translate([35,-20,0])
    {
        cylinder(r=2.5,h=5);
    }
}
translate([35,20,0])
    {
        cylinder(r=2.5,h=5);
    }
}
translate([0,50,0]){
cube([45,15,10], center=true);
}

    
    
    
    
    
    
    
    
    
    