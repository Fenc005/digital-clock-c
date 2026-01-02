# Simple Digital Clock
<h3>A simple digital clock written in C</h3>

<p>Just compile it with clang or gcc and run it from there it should work.
It only works with Linux. Windows support might get added. :)</p>

<h4>The clock should look like something like this:</h4>
<img width="766" height="291" alt="grafik" src="https://github.com/user-attachments/assets/68d61505-b1c6-46c7-9f65-5df2babd87e3" />

<p>If you want to exit the program just press [ctrl]+[c] or just close the terminal.</p>

<h3>How it works:</h3>
<p></p>This Clock gets the time with the help of the <time.h> library in C.</p>
<p></p>To reduce the use of system ressources it also uses <unistd.h> for the sleep() function.</p>
<p></p>To only have one version of the clock on the screen this programm uses ANSI Escape Sequences, plus it uses the Escape Sequences for the color too.</p>
<p></p>Everything else is standard c, like you most of the time need the stdio.h header anyways.

<h3>Programm sequence:</h3>
<p> 1. The programm goes to the Home Position of the Terminal and then Clears the screen using the ANSI Escape Sequences</p>
<p> 2. The Programm gets the time and then with the time() function and then makes a struct tm with the localtime() function </p>
<p> 3. It then converts the integers for hour, minute and seconds into strings</p>
<p> 4. The strings then get converted with simple mathematics and knowledge about the ASCII character table to integers</p>
<p> 5. The Programm then calls the drawClock function which just draws the clock on the screen and then with the help of the ANSI Escape Sequences makes the screen ready for the new time to display</p>
<p> 6. The code repeats itself until it is closed with [ctrl]+[c]</p>
