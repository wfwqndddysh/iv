# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# Uncomment the following line if you don't like systemctl's auto-paging feature:
# export SYSTEMD_PAGER=

# User specific aliases and functions

alias c=clear

export PATH=$PATH:/home/missit/bin/racket/bin


#synclient TapButton1=1
#synclient TapButton2=2
#synclient TapButton3=3

export TERM=xterm-256color
