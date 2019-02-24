# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# Uncomment the following line if you don't like systemctl's auto-paging feature:
# export SYSTEMD_PAGER=

# User specific aliases and functions
alias pd=pushd
alias bd=popd

export PATH="$HOME/bin:$PATH"
export PS1="\e[1;36m[\u@\h \W]\$ \e[m"
