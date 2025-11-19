//Author: Piotr Paterek, Kraków 05-08.2016
$fn=20;
module cog(){
    
    translate([0,0,-6])
    {
    cylinder(r=21.34,h=2,center=true); 
    }
    cylinder(r=20.34, h=10, center=true);
    
        
    cylinder(r=7,h=18);
}

difference()
{
    difference()
    {   union(){
        cog();

     
        difference()
        {
            translate([0,0,18])
            {
                cylinder(r=7,h=5,$fn=5);
            }
            translate([0,0,33])
                {
                    cylinder(r=1.5,h=5);
                }
        }}
    translate([0,0,-5])
        {
            cylinder(r=7,h=5,$fn=5);
        }
    }
for(i=[1:1:45])
        {
            rotate(a=i*360/45, v=[0,0,1])
            {
                translate([20.34,0,0])
                {
                    cylinder(r=1,h=11, center=true);
                }
        }
    }
}