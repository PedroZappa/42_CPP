### GDB Settings
set prompt (zdb) 
set editing on
# set verbose on
set tui border-kind acs
set tui active-border-mode bold-standout
set tui border-mode reverse
set trace-commands on
set logging enabled on
set follow-fork-mode child
# set detach-on-fork off

show follow-fork-mode

# Enable C++ virtual table debugging
set print vtbl on

set print pretty on
# set print elements 2
set print object on
set print static-members on
set print array on
set print array-indexes on

# https://sourceware.org/elfutils/Debuginfod.html
set debuginfod enabled on
set debuginfod urls "https://debuginfod.ubuntu.com/"

### main.cpp
define main
  display argc
  display *argv@argc
end

### ScalarConverter.cpp
define convert
  display input
end

define getType
  display type
end

define isFloat
  disp param
  disp param[i]
  disp i
  disp int_part
  disp frac_part
end

### Go GDB Go! I Choose YOU! 

# main
break main
run 42.42f
main
fs cmd
rfr

# isFloat()
break isFloat
run 42.42f
isFloat
fs cmd
rfr