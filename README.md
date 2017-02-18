# jtimetools

## libtimewarp

libtimewarp is an LD_PRELOADable library which hooks the functions
time(2) and gettimeofday(2), making them return fake time.

This version is not very sophisticated, but it's a simple example of
how to hook standard library functions, which is often useful for
debugging and test harnesses.  Also, using this library with certain
world clock programs makes a nice visual demo.


## topofsec

topofsec is a simple terminal clock which attempts to tick as close as
possible to the beginning of each second.  It's extremely trivial, but
I wrote it after discovering that none of the standard clock widgets
on my system did anything smarter than a sleep(1) loop.  Since then
it's come in handy as a reference clock in a number of situations
where I've needed sub-second synchronization.


## Usage

```
make
LD_PRELOAD=./libtimewarp.so ./topofsec
```


## Bugs

libtimewarp currently only hooks time(2) and gettimeofday(2), not
other calls such as clock_gettime(2).

## License

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
