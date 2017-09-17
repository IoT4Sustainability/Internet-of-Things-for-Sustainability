# Introduction to Basic Programming

## Introduction

### Topics for this tutorial
  1. Learn the structure of a basic arduino file
  2. Variables and types
  3. Conditionals and loops (if, else, while)
  4. Include libraries

## Explanation
This tutorial will be a basic crash course into the fundamentals of programming your own arduino programs to run on your Galileo board. We will take a look at the code used in the previous Nightlight program, and work on examples similar to that code. The goal is to learn how to write and read simple arduino programs for our own Galileo board. We will cover how to include pre-made libraries, how to declare and use variables, and the importance of conditional statements and loops. 
An important note is that the code we will be using for our Arduino programs mostly follows the syntax of C, C++, and any languages like them, along with its own Arduino flare. Each piece of code will be shown below and hopefully explained in an easy to understand way.

## Required Materials
  1. Intel Galileo and Grove shield
  2. Arduino IDE

## Basic Arduino Program Structure
We will start by opening up our Arduino Interactive Development Environment, or IDE for short. After opening the Arduino software, we should start a new file by clicking the blue New File button at the top, which will take us to a screen like this. 
![Opening IDE](https://cloud.githubusercontent.com/assets/22579849/23933974/52b7030c-08ff-11e7-945e-995b8be870ee.PNG)
To begin programming our own first arduino program, we need to understand the major components to include in a .ino file. There are two key parts that we need to add to our own program, and fortunately, the IDE has supplied us with both of those things, albeit empty. When the program is uploaded to the Galileo board, the first thing that runs is setup. The code looks like this:
  void setup() {
  // put your setup code here, to run once:
  
  }
As it says, this block of code will run once. 
