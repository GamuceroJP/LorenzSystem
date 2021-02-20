<font color='gray' size=4>
    
# The Lorenz System

## How Lorenz came up with this?
Atmospheric scientist E.N. Lorenz considered the Rayleigh-Bénard problem, which concerns a fluid in a container whose top and bottom surfaces are held at different 
temperatures. It had long 
been known that as the difference between these two temperatures is increased, the fluid can undergo transitions from a stationary state (no fluid motion) to steady
flow to chaotic flow. This prompted him to consider a greatly simplified version of the Navier-Stokes equations as applied to this particular problem. Indeed, he 
grossly versimplified the problem as he reduced it to only three equations:

<img src="https://render.githubusercontent.com/render/math?math=\dfrac{dx}{dt}=\sigma(y-x)">
<img src="https://render.githubusercontent.com/render/math?math=\dfrac{dy}{dt}=-xz+rx-y">
<img src="https://render.githubusercontent.com/render/math?math=\dfrac{dz}{dt}=xy-bz">

where the Lorenz variables 
<img src="https://render.githubusercontent.com/render/math?math=x, y, z">
are derived from temperature, density and velocity variables in the original Navier-Stokes equations, and 
<img src="https://render.githubusercontent.com/render/math?math=\sigma, r, b"> 
are measures of the temperature difference across the fluid and other fluid parameters. 
