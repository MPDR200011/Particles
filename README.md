# Particles

A simple program that places a random distribution of particles on the screen and sets them free, letting the gravity between them decide their course.

At launch, the program will be paused. You can toggle the pause by hitting `p`. To exit the program you can hit the `Esc` key.

## Dependencies

- SFML >= 2.5

## Building

To build use the provided script `build.sh`.

You can also provide the script which type of build you want:

- Release: Build in release mode
- Debug: Build with debug symbols

The default is Release.

## Running

To run use the provided script `run.sh [num_particles]`.
`num_particles` is the number of particles you want on the screen. It is optional and its default value is 200.
