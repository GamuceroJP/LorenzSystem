<font color='gray' size=4>
    
# The Lorenz System

## How Lorenz came up with this?
Atmospheric scientist E.N. Lorenz considered the Rayleigh-Bénard problem, which concerns a fluid in a container whose top and bottom surfaces are held at different 
temperatures. It had long 
been known that as the difference between these two temperatures is increased, the fluid can undergo transitions from a stationary state (no fluid motion) to steady
flow to chaotic flow. This prompet him to consider a greatly simplified version of the Navier-Stokes equations as applied to this particular problem. Indeed, he 
grossly versimplified the problem as he reduced it to only three equations:

$
\dfrac{dx}{dt}=\sigma(y-x),
$

$
\dfrac{dy}{dt}=-xz+rx-y,
$

$
\dfrac{dz}{dt}=xy-bz,
$
where the Lorenz variables $x,y,z$ are derived from temperature, density and velocity variables in the original Navier-Stokes equations, and $\sigma, r, b$ are
measures of the temperature difference across the fluid and other fluid parameters. 
