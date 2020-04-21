# Installation

## Supported Platforms

Mingw32 and Windows

## Prerequisite

GCC Compiler, GNU make, download utilities such as wget or curl. If using Cygwin, dos2unix will be required

## Installing Git Bash

#### For Linux:
If you want to install the basic Git tools on Linux via a binary installer, you can generally do so through the package management tool that comes with your distribution. If you’re on Fedora (or any closely related RPM-based distribution, such as RHEL or CentOS), you can use dnf:

**$ sudo dnf install git-all**

If you are on a Debian-based distribution, such as Ubuntu, try apt:
$ sudo apt install git-all

For more options, there are instructions for installing on several different Unix distributions on the website, at https://git-scm.com/download/linux.

#### For macOS
There are several ways to install Git on a Mac. The easiest is probably to install the Xcode Command Line Tools. On Mavericks (10.9) or above you can do this simply by trying to run git from the Terminal the very first time.

**$ git –version**

#### Installing on Windows
There are also a few ways to install Git on Windows. The most official build is available for download on the Git website. Just go to https://git-scm.com/download/win and the download will start automatically. Note that this is a project called Git for Windows, which is separate from Git itself; for more information on it, go to https://gitforwindows.org.

 After downloading git bash on the operating system clone the GitHub repository using the following command.
  
  $ git clone https://github.com/praneethdoppalapudi/Stay-and-Dine-Management.git


## Build Project

make clean

make

Executable binary Stay_and_Dine_Management file will be placed in bin directory.
