//Author: Piotr Paterek, Kraków 05-08.2016
$fn=50;
module bevel()
{
    module base()
    {
        difference()
        {
           difference()
            {
                cube([25,60,3], center=true);
                translate([2.5,-20,-1.5])
                {
                    cylinder(r=1.5, h=3);
                }
            }
            translate([2.5,20,-1.5])
            {
                cylinder(r=1.5, h=3);
            }
        }
    }
    base();
    translate([-1.5,0,26.5])
    {
        cube([3,60,50], center=true);
    }
}

//servo holes
difference()
    {
    difference()
    { 
        difference()
        {
            difference()
            {
                bevel();
                translate([-0,-13.5,30])
                {
                    cube([10,20.4,23],center=true);
                }
            }
            
            rotate(a=90, v=[0,1,0])
            {
                translate([-53.5,0,-2-0])
                {
                    cube([25,60,15], center=true);
                }
            }
        }
        rotate(a=90, v=[0,1,0])
        {
            translate([-16.5,-18.2,0])
            {
                cylinder(r=1.25, h=10, center=true);
            }
        }
        rotate(a=90, v=[0,1,0])
        {
            translate([-16.5,-8.2,0])
            {
                cylinder(r=1.25, h=10, center=true);
            }
        }
    }
    
}
   translate([2,5,-2])
                    {
        
                    rotate(a=90,v=[1,0,0])
                        {
        linear_extrude(height=5, convexity = 10){
        polygon(points=[[-3,15],[8,2],[-3,2]]);
        }
    }
}
   