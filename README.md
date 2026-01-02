# Simple Digital Clock
<h3>A simple digital clock written in C</h3>

<p>Just compile it with clang or gcc and run it from there it should work.
It only works with Linux. Windows support might get added. :)</p>

The clock should look like something like this:
<img width="766" height="291" alt="grafik" src="https://github.com/user-attachments/assets/68d61505-b1c6-46c7-9f65-5df2babd87e3" />

If you want to exit the program just press [ctrl]+[c] or just close the terminal.

How it works:
This Clock gets the time with the help of the <time.h> library in C.
To reduce the use of system ressources it also uses <unistd.h> for the sleep() function.
To only have one version of the clock on the screen this programm uses ANSI Escape Sequences, plus it uses the Escape Sequences for the color too.
Everything else is standard c, like you most of the time need the stdio.h header anyways.

<b>Programm sequence:</b>
I
