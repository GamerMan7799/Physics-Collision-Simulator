# Change Log

All notable changes to this project will be documented here.
This project adheres to [Semantic Versioning](http://semver.org/)

## [1.2.5-Beta] - 2015-09-23
### Added
* Doxygen Support
* Doxygen Documentation
* Makefile

### Changed
* Change log format to be markdown
* License format to be markdown

### Removed
* Autoversioning support
* clsCannonball::enableDrag (pointless now, it is just enabled in another function)


## [1.2.4-Beta] - 2015-09-21
### Added
* Cannonballs are now different colors

### Changed
* Ball ID is now set in Screen set
* Unrealistic method added in 1.1.9-Beta can be toggled easier (with define). Its funny to enable and watch even if it doesn't do what it is supposed to


## [1.2.3-Beta] - 2015-09-21
### Added
* Cannonballs are now more transparent the less mass they have
* Namespace Equations to hold equation values
* Ball Path is now drawn on screen (holds so many past points, can be enabled in config file)

### Changed
* Reduced fTimetoSizeRatio from 1.2458 to 0.0124
* Screen background color from White to Black
* Ball color from Black to White
* Pixel color from Black to White

### Removed
* Sky image (replaced with SDL_SetRenderDrawColor)
* My attempt at making parts of the ball image transparent (it wasn't working)


## [1.2.2-Beta] - 2015-09-18
### Fixed
* Mouse line getting thinner the closer to vertical it gets

### Cleaned
* Up a lot of code; made things simpler

### Changed
* All angles are now in radians so I don't have to worry about converting
* Ball radius (and therefore mass) is now proportional to the amount of time you held down the mouse button for.
* Upped default allowable number of cannonballs from 10 to 20


## [1.2.1-Beta] - 2015-09-17
### Fixed
* An issue with mass not being set causing values to being NaN, if drag was not enabled


## [1.2.0-Beta] - 2015-09-17
### Fixed
* The Collision equations a bit more
* Drag update acc would sometimes divide by 0

### Added
* Cannonball now holds its own box
* Keyboard Press events, (Q/ESC to quit, K to kill all balls, and R to stop all motion)
* Friction between the ball and floor / wall

### Updated
* Readme

### Changed
* Attempted to make the code more efficient 
* Default Min Velocity from 0.5 to 0.0 (basically disabling it)
* Disabled the Unrealistic method I added in 1.1.9-beta as it did not help.
* Default Collision Method from Elastic to Inelastic
* fMomentumLoss name to fCoefficientRestitution to be named after its real life counter part


## [1.1.9-Beta] - 2015-09-16
### Fixed
* Log file is now cleared at start

### Added
* Cannonballs now keep track of ID for logging purposes
* Clearer Debug Message if a ball was killed because of speed or NaN
* Unrealistic method where velocity is modified with the inverse root of the distance between the points (this was an attempt to prevent the balls from sticking together as they have been)


## [1.1.8-Beta] - 2015-09-16
### Fixed
* You can now properly fire a cannonball in all directions
* Balls that have velocity as NaN will be removed (I should have fixed the equations so this doesn't happen, but just is cause)

### Added
* More collision methods (Inelastic, Elastic, Perfect Inelastic, and No Collisions)

### Improved
* Collision equations


## [1.1.7-Beta] - 2015-09-15
### Fixed
* Bug with mouse keeping old coordinates
* X Fire velocity not being right

### Added
* Collisions


## [1.1.6-Beta] - 2015-09-15
### Fixed
* Y velocity being flipped
* Bug with balls not correctly bouncing at certain velocities

### Added
* Support for adding multiple cannonballs (no collision between them yet)

### Removed
* Ball position updating on debug mode (too many balls)

### Updated
* Ball will now be removed if their velocity drops below a certain value.

### Note
* Currently the array holding multiple cannonball is NOT dynamic I still have to figure that out.


## [1.1.5-Beta] - 2015-09-15
### Added
* Global.h to hold the externs of the globals
* Balls with bounce off of screen edges

### Removed
* Cannon image

### Cleaned
* General code

### Changed
* You add a ball by clicking and dragging then releasing the button. (Only one ball supported at the moment)
* How cannonballs are applied to screen
* Method to add cannonballs
* Drag mode now enabled in config file.


## [1.1.4-Beta] - 2015-09-15
### Fixed
* Some build issues between Windows and Unix

### Added
* Proper quitting by click X on SDL window


## [1.1.3-Beta] - 2015-09-01
### Added
* Cleanup.bat for deleting useless files
* Cannon Image

### Changed
* Log file to print out floating values


## [1.1.2-Beta] - 2015-08-28
### Added
* Config value that holds OS (kinda pointless at the moment; mostly just so I have a reference of how to do this in the future).

### Changed
* Sky picture to be smaller (64x48 instead of 640x480) since I'm embedding so that file size will be smaller.
* Embedded Images as XPMs

### Removed
*  All but 1 ball size (since I am now embedding the images it didn't make sense; nor was it really all that useful).


## [1.1.1-Beta] - 2015-08-27
### Fixed
* Various issues on Unix systems

### Added
* SDL Images
* General Linux support
* OS support for default path to images
* Linux Build options

### Changed
* Build options for Windows Versions
* Pictures from BMP to PNG


## [1.1.0-beta] - 2015-08-27
### Fixed
* A few bugs
* Some Debug message appearing when not in debug mode

### Changed
* Deltat is now variable on the time since the last update.


## [1.0.2-Beta] - 2015-08-27
### Fixed
* Several Bugs.

### Removed
* Version info including software status (not working)
* Loading of Images path (was causing issues)


## [1.0.1-Beta] - 2015-08-27
### Added
* Config file
* Software state being added to boilerplate
* Logging of ball location to a file
* Easier way to change images path (config file)


## [1.0.0-Beta] - 2015-08-27
### Added
* Various ball sizes that are pulled when radius is entered

### Removed
* Old sky bitmap

### Notes
* Moved to beta


## [1.1.6-Alpha] - 2015-08-26
### Fixed
* Autoversioning stuff (hopefully)


## [1.1.5-Alpha] - 2015-08-26
### Changed
* Reduced FPS from 120 to 80


## [1.1.4-Alpha] - 2015-08-26
### Fixed 
* Bug where loop wouldn't end properly because x/y were uint

### Added
* Debug mode
* Debug messages

### Changed
* Sky.bmp to white picture
* Upped default FPS from 60 to 120

### Removed
* Message about the ball position


## [1.1.3-Alpha] - 2015-08-25
### Added
* Drag mode can now be enabled by user

### Removed
* Wait time message


## [1.1.2-Alpha] - 2015-08-25
### Fixed
* Several bugs


## [1.1.1-Alpha] - 2015-08-25
### Added
* Location Structure
* Other structures to make things nicer
* User now prompted for values.
* Cannonball class

### Cleaned
* main.cpp (only has main now)

### Changed
* Icon.rc merged to boilerplate.rc

### Removed
* Compile.bat (couldn't get it working)


## [1.0.3-Alpha] - 2015-08-25
### Fixed
* Incorrect path format
* Sky now loaded before ball
* Bug with the location of the ball while updating
* Ball position bug
* Physics equation mistake

### Added
* Tick Class
* Console messages about where the program is at.
* Getchar just before program closes

### Changed
* Clean up is now done before error message
* Drag is now off by default
* Ball.bmp picture


## [1.0.2-Alpha] - 2015-08-25
### Added
* Define of image path so people can change it easier


## [1.0.1-Alpha] - 2015-08-25
### Fixed
* SDL Referencing

### Added
* Version.h
* Code Block Support
* Boilerplate.rc
* Skybox
* Windows Class

### Changed
* SDL Stuff to SDL2


## [1.0.0-Alpha] - 2015-08-11
### Notes
* Inital