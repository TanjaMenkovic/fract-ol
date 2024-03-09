Hive school project.


You can test it with:

./fractol julia -0.744 0.148
./fractol julia 0 0.8
./fractol julia 0.37 0.1
./fractol julia 0.355 0.355
./fractol julia -0.54 0.54
./fractol julia -0.4 -0.59
./fractol julia 0.355 0.355
./fractol julia 0.355534 -0.337292
./fractol julia -1.34882125854492 -0.454237874348958

./fractol ship

./fractol mandelbrot

Errors:

./fractol 
Error: Too few arguments!

./fractol htdh
Error: Incorrect fractal name!
Correct input: julia, ship or mandelbrot

./fractol julia 0          
Error: Invalid number of arguments!
Correct input: ./fractol julia -0.54 0.54

./fractol julia 5 5
Error: Invalid range for Julia!
Range should be between -2.0 and 2.0

./fractol mandelbrot jkt
Error: Too many arguments!
Correct input: ./fractol mandelbrot

./fractol ship jyj      
Error: Too many arguments!
Correct input: ./fractol ship
