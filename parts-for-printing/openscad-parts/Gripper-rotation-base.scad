    //Author: Piotr Paterek, Kraków 05-08.2016
    $fn=50;
    module base()
    {
        cube([66,60,5], center=true);
        translate([25,22.5,10])
        {
            cube([15,15,20], center=true);
        }
        translate([30.5,0,10])
        {
            cube([5,60,20], center=true);
        }
        translate([-8.5,-20,9])
        {
            cube([5,20,15], center=true);
        }
        translate([28,-13,0])
        {
            cube([5,11,40]);
        }
        translate([-28,22.5,10])
        {
            cube([10,15,20],center=true);
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
                    difference()
                    {
                    base();
                    translate([22.5,30,7.5])
                    {
                        rotate(a=90, v=[1,0,0])
                        {
                            cylinder(r=1,h=4);
                        }
                    }
                }
                translate([-19.5,15,10])
                    {
                        rotate(a=90, v=[1,0,0])
                        {
                            cylinder(r=1,h=4);
                        }
                    }
            }
        translate([-27,-20,10.5])
                    {
                        rotate(a=90, v=[0,1,0])
                        {
                            cylinder(r=1.5,h=60);
                        }
                    }
            }
             translate([28,-7.5,33.5])
                    {
                        rotate(a=90, v=[0,1,0])
                        {
                            cylinder(r=1.5,h=60);
                        }
                    }
            }
            translate([22.5,30,17.5])
                    {
                        rotate(a=90, v=[1,0,0])
                        {
                            cylinder(r=1,h=4);
                        }
                    }
                }
                
            
            translate([-27,30,17.5])
                    {
                        rotate(a=90, v=[1,0,0])
                        {
                            cylinder(r=1,h=4);
                        }
                    }
                }
                translate([-27,30,7.5])
                    {
                        rotate(a=90, v=[1,0,0])
                        {
                            cylinder(r=1,h=4);
                        }
                    }
                }
            }