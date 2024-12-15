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
  display exchange
end

### BitcoinExchange.cpp
define readData
  display file
  display infile
  display input
end

define processData
  display file
  display infile
  display input
end

### Go GDB Go! I Choose YOU! 

# STOP @ main
# break main
# run input.txt
# main
# fs cmd
# rfr

# STOP @ readData
break readData
run input.txt
fs cmd
readData
rfr
