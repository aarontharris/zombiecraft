Step 1, You'll need to install the xcode command line tools
For < Mavericks you can open XCode->Preferences->Downloads and install Command Line Tools
For >= Mavericks you can run this:
```
$> xcode-select --install
```

Step 2, You'll need SDL 2.0.1 at the time of writing
[http://www.libsdl.org/release/SDL2-2.0.1.dmg](http://www.libsdl.org/release/SDL2-2.0.1.dmg)

- Step 3, On Mac GLUT.framework isn't compatible with Eclipse as is
- Apparently when you use the compiler's -l GLUT, it turns it into libGLUT.dylib
- So we'll need to symbolic link GLUT -> libGLUT.dylib
```
$> cd /System/Library/Frameworks/GLUT.framework/Versions/Current
$> ln -s GLUT libGLUT.dylib
```
