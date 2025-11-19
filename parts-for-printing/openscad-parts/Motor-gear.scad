//Author: Piotr Paterek, Kraków 05-08.2016
$fn=50;
module gear()
{
   
        cylinder(r=11.17,h=4, center=true);
        translate([0,0,6])
        {
            cylinder(r=10.5,h=8, center=true);
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
                    gear();
                    for(i=[0:1:23])
                    {
                        rotate(a=i*360/23, v=[0,0,1])
                        {
                            translate([10.5,0,6])
                            {
                                cylinder(r=1,h=8.5, center=true);
                            }
                        }
                    }
        
        
            }
            translate([0,0,6.5])
            {
                cylinder(r=7.216,h=7,$fn=6, center=true); 
            }
        }
        translate([0,0,-0.5])
        {
            cylinder(r=5.77,h=3.5,$fn=6,center=true);
        }
    }
    cylinder(r=1.5,h=7,center=true);
}