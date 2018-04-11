# SITrack

## What is SITrack

SITrack is a piece of software intended to help manage GNU/Linux system integrity.
What do I mean by system's integrity? Well, simply put I want my program to help  
avoid any leftover configuration from programs that have been installed and then 
removed later on. SITrack is written in C and tries to utilise tools You'd expect 
to find in every Linux system.

## How does SITrack intend to do its job

SITrack uses md5 hash function to calculate checksums of critical system files. 
Upon first run (prefferably on clean and stable system install) SITrack should 
make templates of those critical system files and use them to measure further 
changes while installing and removing software. Therefore it should live with 
system's package manager in symbiosis.

## Why would SITrack even exist

SITrack is my engineering thesis. It is something I know I would like to use. 
I know that currently used package managers do amazing job at keeping system clean 
yet I still had to remove few lines of leftover configuration after uninstalling 
some software. Kind of like keeping information about differences made to system 
files along the way and undoing these changes while uninstalling software.
> State : failed
> systemctl status, 2017

I want SITrack to help avoid such situations

## Can You try it

Of course. Should You want to (for whatever reason) try this project for Yourself 
at any time during its development git clone and run
> gcc exec.c ./utilities/*.c -o sitrack

in the cloned directory. Be sure to refer to debug info variable that informs 
about current functionalities of the program. Should You find any bugs / errors 
(of course You will :P) please notify me about them.

## Can You help

Since it's my engineering thesis i doubt that's allowed should that help would be 
writing code and all. However any tips, tricks an suggestions are much 
appreciated.

## Additional info

#### Target platform

GNU/Linux systems

#### Current development environment

Arch Linux

#### Used tools

Sublime Text 2 (Couldn't recommend it more, really)
GCC 7.3.1

#Thank You for taking Your time and reading through all this :)
