//Author: Piotr Paterek, Kraków 05-08.2016
$fn=40;
module claw()
{

    difference()
    {
        difference()
        {
            cylinder(r=15,h=5, center=true);
            cylinder(r=1.7,h=5, center=true);
        }
        
            for(i=[2.5:1:12.5])
            {
                rotate(a=i*270/11, v=[0,0,1])
                {
                    translate([15,0,0])
        {
                    
                        cylinder(r=2,h=5.2, center=true);
        }
                }
            }
    }
   


translate([31,0,0])
{
    cube([40,10,5], center=true);
}
translate([42,10,0])
{
    cube([40,10,5], center=true);
}
}


        difference()
        {
            claw();
            translate([42,48,0])
            {
                cylinder(r=37.5, h=6, center=true);
            }
        }
    