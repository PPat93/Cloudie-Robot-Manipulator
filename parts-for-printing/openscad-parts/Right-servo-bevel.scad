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
    translate([-11,0,26.5])
    {
        cube([3,60,50], center=true);
    }
}

//holes for servos
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
                        bevel();
                        translate([-7.5,13.2,30])
                        {
                            cube([10,20.4,23],center=true);
                            }
                                }
                                
                                rotate(a=90, v=[0,1,0])
                                {
                                translate([-53.5,0,-7.5])
                                {
                                    cube([25,60,15], center=true);
                                }
                                    }
                                    }
                                        rotate(a=90, v=[0,1,0])
                                        {
                                            translate([-16.5,18.2,-7.5])
                                            {
                                                cylinder(r=1.25, h=10, center=true);
                                                }
                                            }
                                            rotate(a=90, v=[0,1,0])
                                            {
                                                translate([-16.5,8.2,-7.5])
                                                {
                                                     cylinder(r=1.25, h=10, center=true);
                                                    }
                                                }
                                            rotate(a=90, v=[0,1,0])
                                            {
                                                translate([-16.5,-8.2,-7.5])
                                                {
                                                    cylinder(r=1.25, h=10, center=true);
                                                }
                                               }
                                            }
                                            rotate(a=90, v=[0,1,0])
                                            {
                                                translate([-16.5,-18.2,-7.5])
                                                {
                                                    cylinder(r=1.25, h=10, center=true);
                                                    }
                                                }
                                            }
                                        translate([-7.5,-13.2,30])
                                        {
                                            cube([10,20.4,23],center=true);
                                        }
                                    }
                                }
                            }
                        translate([2,15,-2])
                        {
                    
                            rotate(a=90,v=[1,0,0])
                            {
                                linear_extrude(height=5, convexity = 10){
                                polygon(points=[[-13,15],[6,2],[-13,2]]);
                            }
                        }
                    }
                    translate([2,-10,-2])
                    {
        
                    rotate(a=90,v=[1,0,0])
                        {
        linear_extrude(height=5, convexity = 10){
        polygon(points=[[-13,15],[6,2],[-13,2]]);
        }
    }
} 