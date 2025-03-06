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
# set print object on
set print static-members on
set print array on
set print array-indexes on

# https://sourceware.org/elfutils/Debuginfod.html
set debuginfod enabled on
set debuginfod urls "https://debuginfod.ubuntu.com/"

### main.cpp
define main
  display *argv@argc
  display insertMerger
end

### PmergeMe.cpp
define parseArgs
  display *argv@argc
  display listIn
  display vectorIn
end

define mergeInsertVector
  display _vector
  display _vectorPair
  display isUneven
  display lastIdx
end

define createVectorPairs
  display _vector
  display _vector.end()
  display _vector.size()
  display vecIt
end 


### Go GDB Go! I Choose YOU! 

# STOP @ main
break main
run 3 5 9 7 4
main
fs cmd
rfr

### STOP @ mergeInsertVector
# break mergeInsertVector
# run "3 5 9 7 4"
# mergeInsertVector
# fs cmd
# rfr

# STOP @ main
# break createVectorPairs
# run "3 5 9 7 4"
# main
# fs cmd
# rfr

