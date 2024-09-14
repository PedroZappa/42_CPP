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

##
### Custom Commands
##

### megaphone.cpp
define main
	display argc
	display *argv@argc
	display out
end

define capitalize
	display str
	display ret
end

### Go GDB Go! I Choose YOU! 
##
#
### 000_main.c
## main()
break main
run Damnit " ! " "Sorry students, I thought this thing was off."
main
fs cmd
rfr


### Info Stats
info break
info watch

