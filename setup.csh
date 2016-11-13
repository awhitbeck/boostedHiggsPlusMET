#!/bin/tcsh

if ( ! -d bin ) then 
    mkdir bin
endif


setenv PATH $PWD/bin/:$PATH
