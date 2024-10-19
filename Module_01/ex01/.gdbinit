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

set print pretty on
# set print elements 2
set print array on
set print array-indexes on

### main.cpp
define main
	display zombieName
	display chumpName
	display zombie
	display *zombie
end

### Go GDB Go! I Choose YOU! 

# main
break main
run 
fs cmd
rfr

