* Step 1<br>
You'll need to install the xcode command line tools<br>
For < Mavericks you can open XCode->Preferences->Downloads and install Command Line Tools<br>
For >= Mavericks you can run this:<br>
```
$> xcode-select --install
```

* Step 2<br>
You'll need SDL 2.0.1 at the time of writing<br>
[http://www.libsdl.org/release/SDL2-2.0.1.dmg](http://www.libsdl.org/release/SDL2-2.0.1.dmg)<br>

* Step 3<br>
On Mac GLUT.framework isn't compatible with Eclipse as is<br>
Apparently when you use the compiler's -l GLUT, it turns it into libGLUT.dylib<br>
So we'll need to symbolic link GLUT -> libGLUT.dylib<br>
```
$> cd /System/Library/Frameworks/GLUT.framework/Versions/Current
$> ln -s GLUT libGLUT.dylib
```


# Other<br>
When I did "otool -L zombiecraft" on my work laptop it still listed a path that didnt even exist on my work laptop.  I then found that the path was embeded into the libGLFW.dylib :( <br>
This suggests that the path is determined when the dylib is built -- this may help when distributing.

